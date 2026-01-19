#include "faust_common.h"
// generated from file './/ampegsvtp2_h.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace ampegsvtp2_h {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	float 	fConst0;
	float 	fConst1;
	float 	fConst2;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	float 	fRec0[2];
	float 	fConst3;
	float 	fConst4;
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
	float 	fRec1[4];
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
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
	id = "ampegsvtp2_h";
	name = N_("ampegsvtp2_h");
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
	for (int i=0; i<4; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = float(min(192000, max(1, fSamplingFreq)));
	fConst1 = (4.88131326822851e-11 * fConst0);
	fConst2 = (2.77230742298414e-08 + fConst1);
	fConst3 = (3.25420884548567e-14 * fConst0);
	fConst4 = (fConst0 * (0 - (9.16162400193039e-12 + fConst3)));
	fConst5 = ((fConst0 * (fConst3 - 7.10942022549798e-12)) - 2.2904060004826e-09);
	fConst6 = (3.25420884548567e-11 - fConst3);
	fConst7 = (fConst0 * (fConst3 - 9.16162400193039e-12));
	fConst8 = (2.2904060004826e-09 + (fConst0 * (0 - (7.10942022549798e-12 + fConst3))));
	fConst9 = (fConst1 - 2.77230742298414e-08);
	fConst10 = (0 - fConst2);
	fConst11 = (9.76262653645702e-14 * fConst0);
	fConst12 = (fConst0 * (9.16162400193039e-12 - fConst11));
	fConst13 = (2.2904060004826e-09 + (fConst0 * (7.10942022549798e-12 + fConst11)));
	fConst14 = (2.77230742298414e-08 - fConst1);
	fConst15 = (fConst0 * (9.16162400193039e-12 + fConst11));
	fConst16 = ((fConst0 * (7.10942022549798e-12 - fConst11)) - 2.2904060004826e-09);
	fConst17 = (fConst11 - 3.25420884548567e-11);
	fConst18 = (0 - (3.25420884548567e-11 + fConst11));
	fConst19 = (3.25420884548567e-11 + fConst3);
	fConst20 = faustpower<2>(fConst0);
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
		float fTemp0 = (2.2904060004826e-06 + (fConst0 * ((fRec0[0] * (fConst5 + (fConst4 * fRec0[0]))) + fConst2)));
		fRec1[0] = ((float)input0[i] - ((((fRec1[1] * (6.87121800144779e-06 + (fConst0 * ((fRec0[0] * (fConst16 + (fConst15 * fRec0[0]))) + fConst14)))) + (fRec1[2] * (6.87121800144779e-06 + (fConst0 * ((fRec0[0] * (fConst13 + (fConst12 * fRec0[0]))) + fConst10))))) + (fRec1[3] * (2.2904060004826e-06 + (fConst0 * (fConst9 + (fRec0[0] * (fConst8 + (fConst7 * fRec0[0])))))))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(fConst20 * ((fRec0[0] * ((((fRec1[0] * (fConst19 + (fConst0 * (0 - (3.25420884548567e-14 * fRec0[0]))))) + (fRec1[1] * (fConst18 + (fConst11 * fRec0[0])))) + (fRec1[2] * (fConst17 + (fConst0 * (0 - (9.76262653645702e-14 * fRec0[0])))))) + (fRec1[3] * (fConst6 + (fConst3 * fRec0[0]))))) / fTemp0));
		// post processing
		for (int i=3; i>0; i--) fRec1[i] = fRec1[i-1];
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
	case VOLUME: 
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
   VOLUME, 
} PortIndex;
*/

} // end namespace ampegsvtp2_h
