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

unsigned long aadStopSfx(unsigned long handle /*$s0*/)
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

unsigned short aadStopAllSlots()
{
	struct _AadSequenceSlot* slot;
	unsigned short slotNumber;

	slotNumber = 0;
	if (aadMem->numSlots != 0)
	{
		//loc_80054638
		for (slotNumber = 0; slotNumber < aadMem->numSlots; slotNumber++)
		{
			slot = aadMem->sequenceSlots[slotNumber];

			if ((slot->status & 1))
			{
				aadStopSlot(slotNumber);
			}
			//loc_80054664
			slot->sequenceNumberAssigned = 255;
		}
	}
	//loc_80054684

	return 0;
}

unsigned short aadStopSlot(unsigned short slotNumber)
{
	struct _AadSequenceSlot* slot;

	if (slotNumber < aadMem->numSlots)
	{
		slot = aadMem->sequenceSlots[slotNumber];

		if (slot->sequenceNumberAssigned != 0xFF)
		{
			slot->status &= 0xFFFE;
			aadInitSequenceSlot(slot);
			aadAllNotesOff(slotNumber);
		}//loc_800545F4
	}//loc_800545F4

	return 0;
}

unsigned short aadShutdownReverb()
{
	if (aadWaitForSramTransferComplete() != 0)
	{
		SpuClearReverbWorkArea(aadGetReverbMode());

	}
	
	//loc_80054290
	return 0;
}

unsigned short aadCancelPauseSound()
{
	aadMem->flags &= 0xFFF3;
	return 0;
}