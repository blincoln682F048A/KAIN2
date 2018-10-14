#include "AADSFX.H"

#include "G2TYPES.H"
#include <LIBSPU.H>
#include <LIBAPI.H>

unsigned long aadPlaySfx(unsigned short toneID, unsigned short volume, unsigned short pan, short pitchOffset)
{
	unsigned long handle;

	handle = createSfxHandle(toneID);
	aadPutSfxCommand(0, volume, pan, handle, 0);

	return handle;
}

unsigned long aadStopSfx(unsigned long handle)
{
	aadPutSfxCommand(1, 0, 0, handle, 0);
	return handle;
}

unsigned short aadStopAllSfx()
{
	aadPutSfxCommand(4, 0, 0, 0, 0);
	return 0;
}

unsigned short aadIsSfxPlaying(unsigned long handle)
{
	struct AadSynthVoice* voice;
	unsigned short i;

	//loc_800569B4
	for(i = 0; i < 0x18; i++)
	{
		voice = &aadMem->synthVoice[i];
		if (voice->voiceID == 0xD0)
		{
			if (aadMem->voiceStatus[i] != 0)
			{
				if (aadMem->voiceStatus[i] != 2)
				{
					if (voice->handle == handle)
					{
						return 1;
					}
				}//loc_80056A08
			}//loc_80056A08
		}//loc_80056A08
	}

	return 0;
}

unsigned short aadIsSfxPlayingOrRequested(unsigned long handle /*$s0*/)
{
	short commandOut; // $a0
	short i; // $a1
	struct AadSfxCommand *sfxCmd; // $v1
}

unsigned long aadSetSfxVolPanPitch(unsigned long handle, unsigned short volume, unsigned short pan, short pitch)
{
	aadPutSfxCommand(3, 0xFF, 0xFF, handle, pitch);
	return handle;
}

unsigned long createSfxHandle(unsigned short toneID)
{
	if ((++aadMem->sfxSlot.handleCounter) & 0xFFFF == 0)
	{
		++aadMem->sfxSlot.handleCounter;
	}
	//loc_80056B60
	return aadMem->sfxSlot.handleCounter << 16 | toneID & 0xFFFF;
}

void aadPutSfxCommand(unsigned char statusByte, unsigned char dataByte0, unsigned char dataByte1, unsigned long ulongParam, int shortParam)
{
	struct AadSfxCommand* sfxCmd;

	if (aadMem->sfxSlot.commandsInQueue > 0x1D)
	{
		statusByte = 4;

		if (aadMem->sfxSlot.commandsInQueue > 0x1E)
		{
			return;
		}
	}//loc_80056BC8

	EnterCriticalSection();

	sfxCmd = &aadMem->sfxSlot.commandQueue[aadMem->sfxSlot.commandIn];
	sfxCmd->statusByte = statusByte;
	sfxCmd->dataByte[0] = dataByte0;
	sfxCmd->dataByte[1] = dataByte1;
	sfxCmd->ulongParam = ulongParam;
	sfxCmd->shortParam = shortParam;
	
	//Max
	if ((++aadMem->sfxSlot.commandIn) & 0xFF == 0x20)
	{
		//Reset
		aadMem->sfxSlot.commandIn = 0;
	}
	//loc_80056C34
	
	++aadMem->sfxSlot.commandsInQueue;
	
	ExitCriticalSection();

	return;
}

void aadExecuteSfxCommand(struct AadSfxCommand* sfxCmd)
{
	if (sfxCmd->statusByte < 9)
	{
		sfxCmdFunction[sfxCmd->statusByte]();//sfxCmdFunction = functionTbl, statusByte = Index
	}
	//loc_80056CB0
	return;
}

void sfxCmdPlayTone(struct AadSfxCommand* sfxCmd /*$s4*/)
{
	unsigned long handle; // $s7
	struct AadProgramAtr* progAtr; // $fp
	struct AadToneAtr* toneAtr; // $s2
	struct AadSynthVoice* voice; // $s1
	unsigned short midiNote; // $s5
	unsigned long waveAddr; // $s6
	struct AadLoadedSfxToneAttr* sfxToneAttr; // $s3
	struct AadLoadedSfxWaveAttr* sfxWaveAttr; // $v0
	int i; // $v1
}

void sfxCmdStopTone(struct AadSfxCommand* sfxCmd /*$a0*/)
{
	unsigned long handle; // $t0
	struct AadSynthVoice* voice; // $a0
	unsigned short i; // $a3
	unsigned long vmask; // $v1
}

void sfxCmdStopAllTones(struct AadSfxCommand* sfxCmd /*$a0*/)
{
	struct AadSynthVoice* voice; // $a0
	unsigned long vmask; // $v1
	unsigned short i; // $a3
}

void sfxCmdSetToneVolumeAndPan(struct AadSfxCommand* sfxCmd /*$a0*/)
{
	/*unsigned long handle; // $a3
	struct AadSynthVoice *voice; // $t1
	unsigned short i; // $t2
	struct AadVolume newVoiceVol; // stack offset -16
	{ // line 19, offset 0x8005703c
		unsigned char tmp; // $v1
	} // line 19, offset 0x8005703c
	{ // line 20, offset 0x800570a4
		unsigned long masterVolumeSquared; // $v1
	} // line 20, offset 0x800570a4
	{ // line 21, offset 0x80057124
		unsigned char tmp; // $v1
	} // line 21, offset 0x80057124
	{ // line 22, offset 0x8005718c
		unsigned long masterVolumeSquared; // $v1
	} // line 22, offset 0x8005718c
	{ // line 22, offset 0x8005718c
		unsigned long masterVolumeSquared; // $v1
	} // line 22, offset 0x8005718c
	{ // line 22, offset 0x8005718c
		unsigned long masterVolumeSquared; // $v0
	} // line 22, offset 0x8005718c
	{ // line 22, offset 0x8005718c
		unsigned long masterVolumeSquared; // $v1
	} // line 22, offset 0x8005718c*/
}

void sfxCmdSetToneVolPanPitch(struct AadSfxCommand* sfxCmd /*$s2*/)
{
	/*unsigned long handle; // $a2
	struct AadSynthVoice *voice; // $s0
	unsigned short i; // $s1
	struct AadVolume newVoiceVol; // stack offset -24
	unsigned short newPitch; // $a1
	unsigned short finePitch; // $a1
	unsigned short pitchIndex; // $a0
	{ // line 20, offset 0x800573a8
		unsigned char tmp; // $v1
	} // line 20, offset 0x800573a8
	{ // line 21, offset 0x80057410
		unsigned long masterVolumeSquared; // $v1
	} // line 21, offset 0x80057410
	{ // line 22, offset 0x80057490
		unsigned char tmp; // $v1
	} // line 22, offset 0x80057490
	{ // line 23, offset 0x800574f8
		unsigned long masterVolumeSquared; // $v1
	} // line 23, offset 0x800574f8
	{ // line 23, offset 0x800574f8
		unsigned long masterVolumeSquared; // $v1
	} // line 23, offset 0x800574f8
	{ // line 23, offset 0x800574f8
		unsigned long masterVolumeSquared; // $v0
	} // line 23, offset 0x800574f8
	{ // line 23, offset 0x800574f8
		unsigned long masterVolumeSquared; // $v1
	} // line 23, offset 0x800574f8*/
}

void sfxCmdLockVoice(struct AadSfxCommand* sfxCmd /*$a0*/)
{
	void(*callbackProc)(); // $s0
	struct AadSynthVoice *voice; // $v1
}

void sfxCmdSetVoiceAttr(struct AadSfxCommand* sfxCmd /*$a0*/)
{
	unsigned long v; // $s0
	unsigned long vmask; // $v1
	struct SpuVoiceAttr *voiceAttr; // $s1
}

void sfxCmdSetVoiceKeyOn(struct AadSfxCommand* sfxCmd)
{
	aadMem->voiceKeyOnRequest |= sfxCmd->ulongParam;
}

void sfxCmdSetVoiceKeyOff(struct AadSfxCommand* sfxCmd)
{
	aadMem->voiceKeyOffRequest |= sfxCmd->ulongParam;
	aadMem->voiceKeyOnRequest &= -1;

	return;
}