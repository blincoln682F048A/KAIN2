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

	EnterCriticalSection();

#if 0
	//v0 = aadMem

		lw      $v0, aadMem
		nop
		lh      $v1, 0x1BE($v0)
		lbu     $a0, 0x1BD($v0)
		beqz    $v1, loc_80056ACC
		move    $a1, $v1
		li      $a2, 0x20
		sll     $v1, $a0, 16

		loc_80056A58:
	sra     $v1, 16
		sll     $v0, $v1, 1
		addu    $v0, $v1
		sll     $v0, 2
		lw      $v1, aadMem
		addiu   $v0, 0x3C
		addu    $v1, $v0
		lbu     $v0, 0($v1)
		nop
		bnez    $v0, loc_80056AA4
		addiu   $v0, $a0, 1
		lw      $v0, 4($v1)
		nop
		bne     $v0, $s0, loc_80056AA4
		addiu   $v0, $a0, 1
		jal     ExitCriticalSection
		nop
		j       loc_80056AE0
		li      $v0, 1

		loc_80056AA4:
	move    $a0, $v0
		sll     $v0, 16
		sra     $v0, 16
		bne     $v0, $a2, loc_80056ABC
		addiu   $v0, $a1, -1
		move    $a0, $zero

		loc_80056ABC :
	move    $a1, $v0
		sll     $v0, 16
		bnez    $v0, loc_80056A58
		sll     $v1, $a0, 16

		loc_80056ACC :
		jal     ExitCriticalSection
		nop
		jal     sub_800569A0
		move    $a0, $s0
		andi    $v0, 0xFFFF

		loc_80056AE0 :
		lw      $ra, 0x18 + var_4($sp)
		lw      $s0, 0x18 + var_8($sp)
		jr      $ra
		addiu   $sp, 0x18
#endif
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
	aadMem[0].flags &= 0xFFF3;
	return 0;
}