/*-----------------------------------------------------------------------------

� 1999, Steinberg Soft und Hardware GmbH, All Rights Reserved

-----------------------------------------------------------------------------*/

#include <stddef.h>
#include "vstkarma.h"

static AudioEffect *effect = 0;
bool oome = false;

#if MAC
#pragma export on
#endif

//------------------------------------------------------------------------
// prototype of the export function main
#if BEOS
#define main main_plugin
extern "C" __declspec(dllexport) AEffect *main_plugin (audioMasterCallback audioMaster);

#else
extern "C" __declspec(dllexport) AEffect *main (audioMasterCallback audioMaster);
#endif

extern "C" {
AEffect *main (audioMasterCallback audioMaster)
{
	// get vst version
	if(!audioMaster (0, audioMasterVersion, 0, 0, 0, 0))
		return 0;  // old version

	VstKarma::Debug("trying to create...\n");
	effect = new VstKarma (audioMaster);
	VstKarma::Debug("created...\n");
	if (!effect)
		return 0;
	if (oome)
	{
		delete effect;
		return 0;
	}
	VstKarma::Debug("returning getAeffect...\n");
	return effect->getAeffect ();
}
}

#if MAC
#pragma export off
#endif

#if WIN32
#include <windows.h>
void* hInstance;
BOOL WINAPI DllMain (HINSTANCE hInst, DWORD dwReason, LPVOID lpvReserved)
{
	VstKarma::Debug("DllMain...\n");
	hInstance = hInst;
	return 1;
}
#endif
