#include "AADLIB.H"

#include "G2TYPES.H"
#include <LIBSPU.H>

unsigned long aadGetMemorySize(struct AadInitAttr* attributes)
{
	return ((((attributes->numSlots << 1) + attributes->numSlots) << 5) - (attributes->numSlots << 1) + attributes->numSlots) << 2) + 0x1C14;
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