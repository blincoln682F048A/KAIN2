#include "AADSFX.H"

#include "G2TYPES.H"
#include <LIBSPU.H>

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

unsigned short aadStopAllSlots()
{
	struct _AadSequenceSlot* slot;
	unsigned short slotNumber;

	slotNumber = 0;
	if (aadMem[0].numSlots != 0)
	{
		//loc_80054638
		for (slotNumber = 0; slotNumber < aadMem->numSlots; slotNumber++)
		{
			slot = aadMem[0].sequenceSlots[slotNumber];

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
	aadMem[0].flags &= 0xFFF3;
	return 0;
}