# Problemas de compilación con lv2-dev de KXStudio

## Error original

Al intentar compilar el plugin GxSVT.lv2, aparecen errores de找不到 archivos de cabecera LV2:

```
fatal error: lv2.h: No existe el archivo o el directorio
fatal error: lv2/lv2plug.in/ns/lv2core/lv2.h: No existe el archivo o el directorio
fatal error: lv2/lv2plug.in/ns/extensions/ui/ui.h: No existe el archivo o el directorio
```

## Causa principal

El repositorio KXStudio proporciona su propia versión de `lv2-dev` (`6:1.18.10-1kxstudio2`) que tiene symlinks rotos o una estructura de directorios incompatible.

**Versión instalada:**
```
lv2-dev:amd64  6:1.18.10-1kxstudio2  (KXStudio)
```

**Versión oficial de Ubuntu:**
```
lv2-dev:amd64  1.18.10-2build1  (Ubuntu noble)
```

### 1. Paquete incorrecto

El paquete correcto es `lv2-dev`, NO `liblv2-dev`.

### 2. Bug en pkg-config

El pkg-config de Ubuntu 24.04 (versión 1.8.1 con libpkgconf) tiene un bug que devuelve una cadena vacía al ejecutar `pkg-config --cflags lv2`, aunque la búsqueda del paquete es exitosa. Symlinks rot.

### 3. Symlinks rotos en lv2-dev

El paquete `lv2-dev` tiene symlinks incorrectos o faltantes:

- `/usr/include/lv2.h` apunta a un archivo inexistente
- Falta la estructura de directorios `lv2/lv2plug.in/ns/lv2core/`
- Falta la estructura de directorios `lv2/lv2plug.in/ns/extensions/ui/`

## Solución

### 1. Instalar dependencias correctas

```bash
sudo apt install lv2-dev libcairo2-dev libx11-dev
```

### 2. Corregir los symlinks

```bash
# Corregir lv2.h principal
sudo rm /usr/include/lv2.h
sudo ln -s /usr/include/lv2/core/lv2.h /usr/include/lv2.h

# Crear estructura de directorios para lv2plug.in
sudo mkdir -p /usr/include/lv2/lv2plug.in/ns
sudo ln -s /usr/include/lv2/core /usr/include/lv2/lv2plug.in/ns/lv2core

# Crear symlink para UI extension
sudo mkdir -p /usr/include/lv2/lv2plug.in/ns/extensions
sudo ln -s /usr/include/lv2/ui /usr/include/lv2/lv2plug.in/ns/extensions/ui
```

### 3. Modificar el Makefile

Editar el archivo `Makefile` para incluir las rutas correctas (líneas ~86-88):

Cambiar:
```makefile
`$(PKGCONFIG) $(PKGCONFIG_FLAGS) --cflags lv2`
```

Por:
```makefile
-I/usr/include -I/usr/include/lv2
```

O equivalentemente:
```makefile
-I/usr/include -I/usr/include/lv2 -I/usr/include/lv2/lv2plug.in/ns/lv2core -I/usr/include/lv2/lv2plug.in/ns/extensions/ui
```

## Compilación

### Ubuntu normal

```bash
make clean
make
make install
```

### KXStudio (workaround)

```bash
make -f Makefile.kxstudio clean
make -f Makefile.kxstudio
make -f Makefile.kxstudio install
```

## Notas

- Esta solución fue probada en Ubuntu 24.04
- El bug de pkg-config puede variar según la versión del sistema
- Alternativamente, se puede intentar reinstalar pkg-config: `sudo apt install --reinstall pkg-config`
