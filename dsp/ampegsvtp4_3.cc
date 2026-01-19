#include "faust_common.h"
// generated from file './/ampegsvtp4_3.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace ampegsvtp4_3 {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	float 	fConst0;
	float 	fConst1;
	float 	fConst2;
	float 	fConst3;
	float 	fConst4;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	float 	fRec0[2];
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fConst8;
	float 	fConst9;
	float 	fConst10;
	float 	fConst11;
	float 	fConst12;
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fConst24;
	float 	fConst25;
	float 	fConst26;
	float 	fConst27;
	float 	fConst28;
	float 	fConst29;
	float 	fConst30;
	float 	fConst31;
	float 	fConst32;
	float 	fConst33;
	float 	fRec1[6];
	float 	fConst34;
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	float 	fConst38;
	float 	fConst39;
	float 	fConst40;
	float 	fConst41;
	float 	fConst42;
	float 	fConst43;
	float 	fConst44;
	float 	fConst45;
	float 	fConst46;
	float 	fConst47;
	float 	fConst48;
	float 	fConst49;
	float 	fConst50;
	float 	fConst51;
	float 	fConst52;
	float 	fConst53;
	float 	fConst54;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "ampegsvtp4_3";
	name = N_("ampegsvtp4_3");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<6; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = float(min(192000, max(1, fSamplingFreq)));
	fConst1 = (2.89950934514663e-27 * fConst0);
	fConst2 = (2.35080908508478e-15 + (fConst0 * (1.73862614139277e-14 + (fConst0 * (6.36004087941169e-15 + (fConst0 * (2.34031496040998e-16 + (fConst0 * (7.34673015185158e-20 + fConst1)))))))));
	fConst3 = (5.04063073961903e-19 * fConst0);
	fConst4 = (2.67137396032476e-16 + (fConst0 * (1.89772343279171e-15 + (fConst0 * (1.78644933526449e-16 + (fConst0 * (3.69097321591348e-17 + fConst3)))))));
	fConst5 = (5.69226373945622e-19 * fConst0);
	fConst6 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (4.11315936396856e-17 + fConst5))) - 1.33092639833853e-16)) - 1.81653429302091e-17)) - 8.96052375163714e-32);
	fConst7 = (2.53102748841079e-27 * fConst0);
	fConst8 = (4.56897244708245e-19 + (fConst0 * ((fConst0 * (5.65422610590237e-15 + (fConst0 * ((fConst0 * (7.02319822831898e-21 - fConst7)) - 2.00646893072806e-16)))) - 1.46647812765287e-14)));
	fConst9 = (5.61859283489783e-19 * fConst0);
	fConst10 = (5.19201414441412e-20 + (fConst0 * ((fConst0 * (1.55970609841376e-16 + (fConst0 * (fConst9 - 4.06089007197579e-17)))) - 1.66643726022195e-15)));
	fConst11 = (4.93681836037819e-19 * fConst0);
	fConst12 = ((fConst0 * (3.53056961876058e-21 + (fConst0 * ((fConst0 * (3.5645511017226e-17 - fConst11)) - 1.13318547706049e-16)))) - 1.74154449174173e-35);
	fConst13 = (2.35080908508478e-15 + (fConst0 * ((fConst0 * (6.36004087941169e-15 + (fConst0 * ((fConst0 * (7.34673015185158e-20 - fConst1)) - 2.34031496040998e-16)))) - 1.73862614139277e-14)));
	fConst14 = (2.67137396032476e-16 + (fConst0 * ((fConst0 * (1.78644933526449e-16 + (fConst0 * (fConst3 - 3.69097321591348e-17)))) - 1.89772343279171e-15)));
	fConst15 = ((fConst0 * (1.81653429302091e-17 + (fConst0 * ((fConst0 * (4.11315936396856e-17 - fConst5)) - 1.33092639833853e-16)))) - 8.96052375163714e-32);
	fConst16 = (1.44975467257332e-26 * fConst0);
	fConst17 = (1.17540454254239e-14 + (fConst0 * ((fConst0 * (6.36004087941169e-15 + (fConst0 * (2.34031496040998e-16 + (fConst0 * (fConst16 - 2.20401904555548e-19)))))) - 5.21587842417832e-14)));
	fConst18 = (1.51218922188571e-18 * fConst0);
	fConst19 = (1.33568698016238e-15 + (fConst0 * ((fConst0 * (1.78644933526449e-16 + (fConst0 * (3.69097321591348e-17 - fConst18)))) - 5.69317029837513e-15)));
	fConst20 = (1.70767912183687e-18 * fConst0);
	fConst21 = ((fConst0 * (5.44960287906272e-17 + (fConst0 * ((fConst0 * (fConst20 - 4.11315936396856e-17)) - 1.33092639833853e-16)))) - 4.48026187581857e-31);
	fConst22 = (2.89950934514663e-26 * fConst0);
	fConst23 = (2.35080908508478e-14 + (fConst0 * ((fConst0 * ((fConst0 * (4.68062992081996e-16 + (fConst0 * (1.46934603037032e-19 - fConst22)))) - 1.27200817588234e-14)) - 3.47725228278555e-14)));
	fConst24 = (1.00812614792381e-18 * fConst0);
	fConst25 = (2.67137396032476e-15 + (fConst0 * ((fConst0 * ((fConst0 * (7.38194643182696e-17 + fConst24)) - 3.57289867052898e-16)) - 3.79544686558342e-15)));
	fConst26 = (1.13845274789124e-18 * fConst0);
	fConst27 = ((fConst0 * (3.63306858604181e-17 + (fConst0 * (2.66185279667706e-16 + (fConst0 * (0 - (8.22631872793713e-17 + fConst26))))))) - 8.96052375163714e-31);
	fConst28 = (2.35080908508478e-14 + (fConst0 * (3.47725228278555e-14 + (fConst0 * ((fConst0 * ((fConst0 * (1.46934603037032e-19 + fConst22)) - 4.68062992081996e-16)) - 1.27200817588234e-14)))));
	fConst29 = (2.67137396032476e-15 + (fConst0 * (3.79544686558342e-15 + (fConst0 * ((fConst0 * (fConst24 - 7.38194643182696e-17)) - 3.57289867052898e-16)))));
	fConst30 = ((fConst0 * ((fConst0 * (2.66185279667706e-16 + (fConst0 * (8.22631872793713e-17 - fConst26)))) - 3.63306858604181e-17)) - 8.96052375163714e-31);
	fConst31 = (1.17540454254239e-14 + (fConst0 * (5.21587842417832e-14 + (fConst0 * (6.36004087941169e-15 + (fConst0 * ((fConst0 * (0 - (2.20401904555548e-19 + fConst16))) - 2.34031496040998e-16)))))));
	fConst32 = (1.33568698016238e-15 + (fConst0 * (5.69317029837513e-15 + (fConst0 * (1.78644933526449e-16 + (fConst0 * (0 - (3.69097321591348e-17 + fConst18))))))));
	fConst33 = ((fConst0 * ((fConst0 * ((fConst0 * (4.11315936396856e-17 + fConst20)) - 1.33092639833853e-16)) - 5.44960287906272e-17)) - 4.48026187581857e-31);
	fConst34 = (1.26551374420539e-26 * fConst0);
	fConst35 = (2.28448622354123e-18 + (fConst0 * ((fConst0 * (5.65422610590237e-15 + (fConst0 * (2.00646893072806e-16 + (fConst0 * (fConst34 - 2.10695946849569e-20)))))) - 4.39943438295861e-14)));
	fConst36 = (1.68557785046935e-18 * fConst0);
	fConst37 = (2.59600707220706e-19 + (fConst0 * ((fConst0 * (1.55970609841376e-16 + (fConst0 * (4.06089007197579e-17 - fConst36)))) - 4.99931178066586e-15)));
	fConst38 = (1.48104550811346e-18 * fConst0);
	fConst39 = ((fConst0 * (1.05917088562817e-20 + (fConst0 * ((fConst0 * (fConst38 - 3.5645511017226e-17)) - 1.13318547706049e-16)))) - 8.70772245870863e-35);
	fConst40 = (2.53102748841079e-26 * fConst0);
	fConst41 = (4.56897244708245e-18 + (fConst0 * ((fConst0 * ((fConst0 * (4.01293786145611e-16 + (fConst0 * (1.4046396456638e-20 - fConst40)))) - 1.13084522118047e-14)) - 2.93295625530574e-14)));
	fConst42 = (1.12371856697957e-18 * fConst0);
	fConst43 = (5.19201414441412e-19 + (fConst0 * ((fConst0 * ((fConst0 * (8.12178014395158e-17 + fConst42)) - 3.11941219682751e-16)) - 3.33287452044391e-15)));
	fConst44 = (9.87363672075638e-19 * fConst0);
	fConst45 = ((fConst0 * (7.06113923752116e-21 + (fConst0 * (2.26637095412098e-16 + (fConst0 * (0 - (7.12910220344521e-17 + fConst44))))))) - 1.74154449174173e-34);
	fConst46 = (4.56897244708245e-18 + (fConst0 * (2.93295625530574e-14 + (fConst0 * ((fConst0 * ((fConst0 * (1.4046396456638e-20 + fConst40)) - 4.01293786145611e-16)) - 1.13084522118047e-14)))));
	fConst47 = (5.19201414441412e-19 + (fConst0 * (3.33287452044391e-15 + (fConst0 * ((fConst0 * (fConst42 - 8.12178014395158e-17)) - 3.11941219682751e-16)))));
	fConst48 = ((fConst0 * ((fConst0 * (2.26637095412098e-16 + (fConst0 * (7.12910220344521e-17 - fConst44)))) - 7.06113923752116e-21)) - 1.74154449174173e-34);
	fConst49 = (2.28448622354123e-18 + (fConst0 * (4.39943438295861e-14 + (fConst0 * (5.65422610590237e-15 + (fConst0 * ((fConst0 * (0 - (2.10695946849569e-20 + fConst34))) - 2.00646893072806e-16)))))));
	fConst50 = (2.59600707220706e-19 + (fConst0 * (4.99931178066586e-15 + (fConst0 * (1.55970609841376e-16 + (fConst0 * (0 - (4.06089007197579e-17 + fConst36))))))));
	fConst51 = ((fConst0 * ((fConst0 * ((fConst0 * (3.5645511017226e-17 + fConst38)) - 1.13318547706049e-16)) - 1.05917088562817e-20)) - 8.70772245870863e-35);
	fConst52 = (4.56897244708245e-19 + (fConst0 * (1.46647812765287e-14 + (fConst0 * (5.65422610590237e-15 + (fConst0 * (2.00646893072806e-16 + (fConst0 * (7.02319822831898e-21 + fConst7)))))))));
	fConst53 = (5.19201414441412e-20 + (fConst0 * (1.66643726022195e-15 + (fConst0 * (1.55970609841376e-16 + (fConst0 * (4.06089007197579e-17 + fConst9)))))));
	fConst54 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (3.5645511017226e-17 + fConst11))) - 1.13318547706049e-16)) - 3.53056961876058e-21)) - 1.74154449174173e-35);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
	float 	fSlow0 = (0.007000000000000006 * float(fslider0));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		float fTemp0 = ((fRec0[0] * ((fConst6 * fRec0[0]) + fConst4)) + fConst2);
		fRec1[0] = ((float)input0[i] - ((((((fRec1[1] * ((fRec0[0] * ((fConst33 * fRec0[0]) + fConst32)) + fConst31)) + (fRec1[2] * ((fRec0[0] * ((fConst30 * fRec0[0]) + fConst29)) + fConst28))) + (fRec1[3] * ((fRec0[0] * ((fConst27 * fRec0[0]) + fConst25)) + fConst23))) + (fRec1[4] * ((fRec0[0] * ((fConst21 * fRec0[0]) + fConst19)) + fConst17))) + (fRec1[5] * ((fRec0[0] * ((fConst15 * fRec0[0]) + fConst14)) + fConst13))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(((((((fRec1[0] * ((fRec0[0] * ((fConst54 * fRec0[0]) + fConst53)) + fConst52)) + (fRec1[1] * ((fRec0[0] * ((fConst51 * fRec0[0]) + fConst50)) + fConst49))) + (fRec1[2] * ((fRec0[0] * ((fConst48 * fRec0[0]) + fConst47)) + fConst46))) + (fRec1[3] * ((fRec0[0] * ((fConst45 * fRec0[0]) + fConst43)) + fConst41))) + (fRec1[4] * ((fRec0[0] * ((fConst39 * fRec0[0]) + fConst37)) + fConst35))) + (fRec1[5] * ((fRec0[0] * ((fConst12 * fRec0[0]) + fConst10)) + fConst8))) / fTemp0);
		// post processing
		for (int i=5; i>0; i--) fRec1[i] = fRec1[i-1];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case MIDDLE: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   MID, 
} PortIndex;
*/

} // end namespace ampegsvtp4_3
