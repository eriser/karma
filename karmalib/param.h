#ifndef __INCLUDED_KARMA_PARAM_H
#define __INCLUDED_KARMA_PARAM_H

#define BUFFERSIZE 16384
#define MAX_ECHO 44100 * 2

enum {
	kWaveform1 = 0,
	kFreq1,
	kWaveLen1,

	kWaveform2,
	kFreq2,
	kWaveLen2,

	kWaveformMix,

	kModEnvA,
	kModEnvD,
	kModEnvAmount,

	kLFO1,
	kLFO1rate,
	kLFO1amount,

	kLFO2,
	kLFO2rate,
	kLFO2amount,

	kFilterType,
	kFilterRes,
	kFilterCut,
	kFilterADSRAmount,

	kFilterCutA,
	kFilterCutD,
	kFilterCutS,
	kFilterCutR,

	kDistortion,
	kAmplifierA,
	kAmplifierD,
	kAmplifierS,
	kAmplifierR,
	kGain,

	kEchoDelay,
	kEchoAmount,
	kPan,

	kParamEnd
};

#endif

