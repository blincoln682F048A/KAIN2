#include "AADLIB.H"

#include "G2TYPES.H"
#include <LIBSPU.H>

unsigned long aadGetMemorySize(struct AadInitAttr* attributes)
{
	return ((((attributes->numSlots << 1) + attributes->numSlots) << 5) - (attributes->numSlots << 1) + attributes->numSlots) << 2) + 0x1C14;
}

unsigned short /*$ra*/ aadInit(struct AadInitAttr *attributes /*$s1*/, unsigned char *memoryPtr /*$s0*/)
{ // line 1, offset 0x80051f0c
	struct _AadSequenceSlot *slot; // $a0
	unsigned long size; // $v0
	unsigned short slotNumber; // $a3
	unsigned short i; // $a2
} // line 161, offset 0x8005223c
  /*
  * Offset 0x80052250
  * C:\kain2\game\PSX\AADLIB.C (line 221)
  * Stack frame base $sp, size 32
  * Saved registers at offset -8: s0 s1 ra
  */
void /*$ra*/ aadInstallUpdateFunc(long(*updateFuncPtr)() /*$s0*/, unsigned short hblanksPerUpdate /*$s1*/)
{
}
/*
* Offset 0x800522CC
* C:\kain2\game\PSX\AADLIB.C (line 234)
* Stack frame base $sp, size 24
* Saved registers at offset -8: ra
*/
unsigned short /*$ra*/ aadInitVolume()
{
}
/*
* Offset 0x80052300
* C:\kain2\game\PSX\AADLIB.C (line 248)
* Stack frame base $sp, size 24
* Saved registers at offset -8: ra
*/
unsigned short /*$ra*/ aadSetMasterVolume(short volume /*$a0*/)
{
}
/*
* Offset 0x80052330
* C:\kain2\game\PSX\AADLIB.C (line 257)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadStartMasterVolumeFade(short targetVolume /*$a0*/, short volumeStep /*$a1*/, void(*fadeCompleteCallback)() /*$a2*/)
{
}
/*
* Offset 0x8005234C
* C:\kain2\game\PSX\AADLIB.C (line 267)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadSetSfxMasterVolume(unsigned short volume /*$a0*/)
{
}
/*
* Offset 0x80052360
* C:\kain2\game\PSX\AADLIB.C (line 275)
* Stack frame base $sp, size 24
* Saved registers at offset -4: s0 ra
*/
unsigned short /*$ra*/ aadSetMusicMasterVolume(unsigned short volume /*$a0*/)
{ // line 1, offset 0x80052360
	unsigned short slotNumber; // $s0
} // line 9, offset 0x800523c0
  /*
  * Offset 0x800523D4
  * C:\kain2\game\PSX\AADLIB.C (line 288)
  * Stack frame base $sp, size 0
  */
unsigned short /*$ra*/ aadStartMusicMasterVolFade(short targetVolume /*$a0*/, short volumeStep /*$a1*/, void(*fadeCompleteCallback)() /*$a2*/)
{
}
/*
* Offset 0x800523F0
* C:\kain2\game\PSX\AADLIB.C (line 298)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadSetSlotMasterVolumeType(unsigned short slotNumber /*$a0*/, unsigned short masterVolType /*$a1*/)
{ // line 2, offset 0x800523f0
	struct _AadSequenceSlot *slot; // $a0
} // line 10, offset 0x80052420
  /*
  * Offset 0x80052428
  * C:\kain2\game\PSX\AADLIB.C (line 324)
  * Stack frame base $sp, size 24
  * Saved registers at offset -8: ra
  */
unsigned short /*$ra*/ aadShutdown()
{
}
/*
* Offset 0x800524B4
* C:\kain2\game\PSX\AADLIB.C (line 360)
* Stack frame base $sp, size 24
* Saved registers at offset -4: s0 ra
*/
long /*$ra*/ aadSlotUpdateWrapper()
{ // line 1, offset 0x800524b4
	unsigned long curGp; // $s0
} // line 1, offset 0x800524b4
  /*
  * Offset 0x800524F8
  * C:\kain2\game\PSX\AADLIB.C (line 377)
  * Stack frame base $sp, size 48
  * Saved registers at offset -4: s0 s1 s2 ra
  */
long /*$ra*/ aadSlotUpdate()
{ // line 1, offset 0x800524f8
	struct _AadSequenceSlot *slot; // $s0
	struct AadSeqEvent seqEvent; // stack offset -32
	struct AadSeqEvent *seqEventPtr; // $a0
	unsigned short slotNumber; // $s1
	int i; // $a3
	int fadeComplete; // $a0
	unsigned long vmask; // $a2
	short newVol; // $s0
} // line 194, offset 0x800529e0
  /*
  * Offset 0x800529F8
  * C:\kain2\game\PSX\AADLIB.C (line 611)
  * Stack frame base $sp, size 0
  */
unsigned long /*$ra*/ aadCreateFourCharID(char a /*$a0*/, char b /*$a1*/, char c /*$a2*/, char d /*$a3*/)
{
}
/*
* Offset 0x80052A20
* C:\kain2\game\PSX\AADLIB.C (line 619)
* Stack frame base $sp, size 48
* Saved registers at offset -8: s0 s1 s2 s3 ra
*/
unsigned short /*$ra*/ aadLoadDynamicSoundBank(char *sndFileName /*$s2*/, char *smpFileName /*$s3*/, unsigned short dynamicBankIndex /*$s0*/, unsigned short loadOption /*$s1*/, void(*retProc)() /*stack 16*/)
{ // line 1, offset 0x80052a20
	unsigned short i; // $v1
} // line 53, offset 0x80052b44
  /*
  * Offset 0x80052B60
  * C:\kain2\game\PSX\AADLIB.C (line 677)
  * Stack frame base $sp, size 40
  * Saved registers at offset -8: s0 s1 s2 s3 ra
  */
void /*$ra*/ aadLoadDynamicSoundBankReturn(void *loadedDataPtr /*$a0*/, void *data /*$s2*/, void *data2 /*$a2*/)
{ // line 1, offset 0x80052b60
	unsigned short error; // $v1
} // line 71, offset 0x80052c30
  /*
  * Offset 0x80052C4C
  * C:\kain2\game\PSX\AADLIB.C (line 758)
  * Stack frame base $sp, size 40
  * Saved registers at offset -4: s0 s1 s2 s3 s4 ra
  */
void /*$ra*/ aadLoadDynamicSoundBankReturn2(void *loadedDataPtr /*$a0*/, long loadedDataSize /*$s2*/, short status /*$s4*/, void *data1 /*$a3*/, void *data2 /*stack 16*/)
{ // line 1, offset 0x80052c4c
	unsigned char *dataPtr; // $s1
	struct AadDynamicBankLoadInfo *info; // $s0
	unsigned short dynamicBankIndex; // $s3
	{ // line 100, offset 0x80052e70
		int i; // $a2
	} // line 114, offset 0x80052f04
} // line 116, offset 0x80052f04
  /*
  * Offset 0x80052F24
  * C:\kain2\game\PSX\AADLIB.C (line 880)
  * Stack frame base $sp, size 24
  * Saved registers at offset -8: ra
  */
void /*$ra*/ aadFreeLoadBuffer()
{
}
/*
* Offset 0x80052F6C
* C:\kain2\game\PSX\AADLIB.C (line 890)
* Stack frame base $sp, size 40
* Saved registers at offset -8: s0 s1 s2 s3 ra
*/
unsigned short /*$ra*/ aadFreeDynamicSoundBank(unsigned short dynamicBankIndex /*$s2*/)
{
}
/*
* Offset 0x800530A0
* C:\kain2\game\PSX\AADLIB.C (line 935)
* Stack frame base $sp, size 32
* Saved registers at offset -8: s0 s1 ra
*/
unsigned short /*$ra*/ aadOpenDynamicSoundBank(unsigned char *soundBank /*$a0*/, unsigned short dynamicBankIndex /*$a1*/)
{ // line 1, offset 0x800530a0
	struct AadSoundBankHdr *soundBankHdr; // $s0
	struct AadProgramAtr *programAtr; // $v0
	struct AadToneAtr *toneAtr; // $v0
	unsigned long *waveAddr; // $v0
	unsigned long *sequenceOffsetTbl; // $a2
	unsigned long *sequenceLabelOffsetTbl; // $a1
	unsigned char *sequenceBase; // $a1
	unsigned short i; // $t2
} // line 49, offset 0x800531b4
  /*
  * Offset 0x800531C8
  * C:\kain2\game\PSX\AADLIB.C (line 1030)
  * Stack frame base $sp, size 32
  * Saved registers at offset -4: s0 s1 s2 ra
  */
unsigned short /*$ra*/ aadLoadDynamicSfx(char *fileName /*$a3*/, unsigned long userData /*$s1*/, void(*userReturnProc)() /*$s2*/)
{ // line 1, offset 0x800531c8
	struct AadDynamicLoadRequest *loadReq; // $s0
} // line 25, offset 0x80053284
  /*
  * Offset 0x8005329C
  * C:\kain2\game\PSX\AADLIB.C (line 1060)
  * Stack frame base $sp, size 40
  * Saved registers at offset -4: s0 s1 s2 ra
  */
void /*$ra*/ aadProcessLoadQueue()
{ // line 1, offset 0x8005329c
	unsigned short i; // $v1
	struct AadDynamicLoadRequest *loadReq; // $s1
	{ // line 9, offset 0x800532c4
		struct AadDynamicSfxLoadInfo *info; // $s2
	} // line 57, offset 0x80053428
} // line 59, offset 0x80053428
  /*
  * Offset 0x80053440
  * C:\kain2\game\PSX\AADLIB.C (line 1122)
  * Stack frame base $sp, size 32
  * Saved registers at offset -8: s0 s1 ra
  */
void /*$ra*/ aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info /*$s0*/, unsigned short error /*$s1*/)
{
}
/*
* Offset 0x800534EC
* C:\kain2\game\PSX\AADLIB.C (line 1148)
* Stack frame base $sp, size 24
* Saved registers at offset -8: ra
*/
void /*$ra*/ aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info /*$v1*/)
{
}
/*
* Offset 0x80053530
* C:\kain2\game\PSX\AADLIB.C (line 1163)
* Stack frame base $sp, size 32
* Saved registers at offset -8: s0 s1 ra
*/
void /*$ra*/ aadLoadDynamicSfxReturn(void *loadedDataPtr /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
{ // line 1, offset 0x80053530
	struct _AadDynSfxFileHdr *p; // $v1
	struct AadDynamicSfxLoadInfo *info; // $s0
} // line 74, offset 0x800536a0
  /*
  * Offset 0x800536B4
  * C:\kain2\game\PSX\AADLIB.C (line 1391)
  * Stack frame base $sp, size 0
  */
unsigned char /*$ra*/ aadWaveMalloc(unsigned short waveID /*$t4*/, unsigned long waveSize /*$a1*/)
{ // line 1, offset 0x800536b4
	struct AadNewSramBlockDesc *sramDesc; // $a2
	struct AadNewSramBlockDesc *bestFit; // $t1
	struct AadNewSramBlockDesc *next; // $a2
	struct AadNewSramBlockDesc *sramDescTbl; // $t2
	unsigned char i; // $a0
	unsigned char sramDescIndex; // $t0
	unsigned char bestFitIndex; // $t3
} // line 99, offset 0x800538c0
  /*
  * Offset 0x800538C8
  * C:\kain2\game\PSX\AADLIB.C (line 1494)
  * Stack frame base $sp, size 0
  */
unsigned long /*$ra*/ aadGetSramBlockAddr(unsigned char handle /*$v0*/)
{ // line 1, offset 0x800538c8
	struct AadNewSramBlockDesc *sramDesc; // $v0
} // line 12, offset 0x800538f0
  /*
  * Offset 0x800538F8
  * C:\kain2\game\PSX\AADLIB.C (line 1527)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ aadWaveFree(unsigned char handle /*$v1*/)
{ // line 1, offset 0x800538f8
	struct AadNewSramBlockDesc *sramDesc; // $a1
	struct AadNewSramBlockDesc *sramDescTbl; // $a3
	{ // line 13, offset 0x8005392c
		struct AadNewSramBlockDesc *next; // $a2
	} // line 22, offset 0x80053974
	{ // line 26, offset 0x80053984
		struct AadNewSramBlockDesc *prev; // $a0
	} // line 35, offset 0x800539e8
} // line 38, offset 0x800539e8
  /*
  * Offset 0x800539F0
  * C:\kain2\game\PSX\AADLIB.C (line 1570)
  * Stack frame base $sp, size 24
  * Saved registers at offset -8: ra
  */
void /*$ra*/ aadFreeSingleDynSfx(unsigned short sfxID /*$a0*/)
{ // line 1, offset 0x800539f0
	struct AadLoadedSfxToneAttr *toneAttr; // $a1
	struct AadLoadedSfxWaveAttr *waveAttr; // $v1
} // line 24, offset 0x80053aa4
  /*
  * Offset 0x80053AB4
  * C:\kain2\game\PSX\AADLIB.C (line 1605)
  * Stack frame base $sp, size 40
  * Saved registers at offset -8: s0 s1 s2 s3 ra
  */
void /*$ra*/ aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info /*$s3*/)
{ // line 1, offset 0x80053ab4
	unsigned short i; // $s1
	struct AadLoadedSfxToneAttr *toneAttr; // $a0
	struct AadLoadedSfxWaveAttr *waveAttr; // $s0
	struct AadDynSfxAttr *attr; // $s2
} // line 96, offset 0x80053d14
  /*
  * Offset 0x80053D30
  * C:\kain2\game\PSX\AADLIB.C (line 1704)
  * Stack frame base $sp, size 48
  * Saved registers at offset -4: s0 s1 s2 s3 s4 s5 s6 ra
  */
void /*$ra*/ aadLoadDynamicSfxReturn2(void *loadedDataPtr /*$a0*/, long loadedDataSize /*$a1*/, short status /*$a2*/, void *data1 /*$a3*/, void *data2 /*stack 16*/)
{ // line 1, offset 0x80053d30
	unsigned char *dataPtr; // $s4
	unsigned long dataOffset; // $s3
	unsigned long bytesRemaining; // $s2
	struct AadDynamicSfxLoadInfo *info; // $s1
	unsigned long n; // $s0
} // line 137, offset 0x80053fa0
  /*
  * Offset 0x80053FC8
  * C:\kain2\game\PSX\AADLIB.C (line 1846)
  * Stack frame base $sp, size 32
  * Saved registers at offset -4: s0 s1 s2 ra
  */
unsigned short /*$ra*/ aadFreeDynamicSfx(unsigned short snfFileID /*$a0*/)
{ // line 1, offset 0x80053fc8
	unsigned short i; // $s1
	struct _AadDynSfxFileHdr *snfFile; // $s0
	unsigned short *sfxIDListPtr; // $s2
} // line 41, offset 0x800540d4
  /*
  * Offset 0x800540EC
  * C:\kain2\game\PSX\AADLIB.C (line 1986)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ aadInitSequenceSlot(struct _AadSequenceSlot *slot /*$a1*/)
{ // line 1, offset 0x800540ec
	unsigned short i; // $a2
} // line 39, offset 0x80054194
  /*
  * Offset 0x800541A4
  * C:\kain2\game\PSX\AADLIB.C (line 2031)
  * Stack frame base $sp, size 24
  * Saved registers at offset -4: s0 ra
  */
int /*$ra*/ aadWaitForSramTransferComplete()
{ // line 1, offset 0x800541a4
	int n; // $s0
} // line 8, offset 0x800541d0
  /*
  * Offset 0x800541E0
  * C:\kain2\game\PSX\AADLIB.C (line 2042)
  * Stack frame base $sp, size 24
  * Saved registers at offset -4: s0 ra
  */
unsigned short /*$ra*/ aadInitReverb()
{
}
/*
* Offset 0x80054268
* C:\kain2\game\PSX\AADLIB.C (line 2058)
* Stack frame base $sp, size 24
* Saved registers at offset -8: ra
*/
unsigned short aadShutdownReverb()
{
	if (aadWaitForSramTransferComplete() != 0)
	{
		SpuClearReverbWorkArea(aadGetReverbMode());
	}

	//loc_80054290
	return 0;
}
/*
* Offset 0x800542A0
* C:\kain2\game\PSX\AADLIB.C (line 2072)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadGetReverbMode()
{
}
/*
* Offset 0x800542A8
* C:\kain2\game\PSX\AADLIB.C (line 2094)
* Stack frame base $sp, size 24
* Saved registers at offset -8: ra
*/
unsigned long /*$ra*/ aadGetReverbSize()
{
}
/*
* Offset 0x800542E0
* C:\kain2\game\PSX\AADLIB.C (line 2099)
* Stack frame base $sp, size 0
*/
short /*$ra*/ aadGetReverbDepth()
{
}
/*
* Offset 0x800542E8
* C:\kain2\game\PSX\AADLIB.C (line 2105)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadGetDynamicBankStatus(unsigned short bank /*$a0*/)
{
}
/*
* Offset 0x80054300
* C:\kain2\game\PSX\AADLIB.C (line 2112)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadGetNumDynamicSequences(unsigned short bank /*$a0*/)
{
}
/*
* Offset 0x8005433C
* C:\kain2\game\PSX\AADLIB.C (line 2126)
* Stack frame base $sp, size 48
* Saved registers at offset -8: s0 s1 s2 s3 ra
*/
unsigned short /*$ra*/ aadAssignDynamicSequence(unsigned short bank /*$t0*/, unsigned short sequenceNumber /*$s3*/, unsigned short slotNumber /*$a2*/)
{ // line 1, offset 0x8005433c
	struct AadTempo tempo; // stack offset -32
	struct _AadSequenceSlot *slot; // $s0
} // line 33, offset 0x800543e0
  /*
  * Offset 0x800543FC
  * C:\kain2\game\PSX\AADLIB.C (line 2162)
  * Stack frame base $sp, size 0
  */
struct AadTempo * /*$ra*/ aadGetTempoFromDynamicSequence(unsigned short bank /*$a0*/, unsigned short sequenceNumber /*$a1*/, struct AadTempo *tempo /*$a2*/)
{ // line 1, offset 0x800543fc
	struct AadNewSequenceHdr *seqHdr; // $v1
} // line 15, offset 0x8005444c
  /*
  * Offset 0x80054454
  * C:\kain2\game\PSX\AADLIB.C (line 2286)
  * Stack frame base $sp, size 0
  */
unsigned short /*$ra*/ aadSetSlotTempo(unsigned short slotNumber /*$a0*/, struct AadTempo *tempo /*$a1*/)
{ // line 2, offset 0x80054454
	struct _AadSequenceSlot *slot; // $a0
	unsigned long tickTime; // $v1
	unsigned long tickTimeRemainder; // $a2

} // line 8, offset 0x80054454
  /*
  * Offset 0x80054518
  * C:\kain2\game\PSX\AADLIB.C (line 2308)
  * Stack frame base $sp, size 24
  * Saved registers at offset -4: s0 ra
  */
unsigned short aadStartSlot(unsigned short slotNumber)
{
	struct _AadSequenceSlot* slot; // $s0

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
  /*
  * Offset 0x800546A0
  * C:\kain2\game\PSX\AADLIB.C (line 2360)
  * Stack frame base $sp, size 24
  * Saved registers at offset -8: ra
  */
unsigned short /*$ra*/ aadDisableSlot(unsigned short slotNumber /*$a0*/)
{
}
/*
* Offset 0x800546F0
* C:\kain2\game\PSX\AADLIB.C (line 2371)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadEnableSlot(unsigned short slotNumber /*$a0*/)
{
}
/*
* Offset 0x80054730
* C:\kain2\game\PSX\AADLIB.C (line 2379)
* Stack frame base $sp, size 24
* Saved registers at offset -8: ra
*/
unsigned short /*$ra*/ aadPauseSlot(unsigned short slotNumber /*$a0*/)
{
}
/*
* Offset 0x80054780
* C:\kain2\game\PSX\AADLIB.C (line 2390)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadResumeSlot(unsigned short slotNumber /*$a0*/)
{ // line 2, offset 0x80054780
	struct _AadSequenceSlot *slot; // $a0
} // line 12, offset 0x800547d0
  /*
  * Offset 0x800547D8
  * C:\kain2\game\PSX\AADLIB.C (line 2406)
  * Stack frame base $sp, size 0
  */
unsigned short /*$ra*/ aadGetSlotStatus(unsigned short slotNumber /*$a0*/)
{
}
/*
* Offset 0x800547FC
* C:\kain2\game\PSX\AADLIB.C (line 2430)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadAllNotesOff(unsigned short slotNumber /*$a0*/)
{ // line 2, offset 0x800547fc
	struct AadSynthVoice *voice; // $a0
	unsigned long vmask; // $a2
	unsigned short i; // $a1
	struct _AadSequenceSlot *slot; // $a3
} // line 25, offset 0x800548a8
  /*
  * Offset 0x800548B0
  * C:\kain2\game\PSX\AADLIB.C (line 2459)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ aadGetVoiceStatus(char *voiceStatusArray /*$a0*/)
{
}
/*
* Offset 0x80054920
* C:\kain2\game\PSX\AADLIB.C (line 2466)
* Stack frame base $sp, size 0
*/
struct AadSynthVoice * /*$ra*/ aadGetVoicePointer(unsigned short voiceIndex /*$a0*/)
{
}
/*
* Offset 0x80054940
* C:\kain2\game\PSX\AADLIB.C (line 2473)
* Stack frame base $sp, size 0
*/
unsigned short /*$ra*/ aadMuteChannels(unsigned short slotNumber /*$a0*/, unsigned short channelList /*$a1*/)
{ // line 2, offset 0x80054940
	struct AadSynthVoice *voice; // $a0
	unsigned long vmask; // $a3
	unsigned short channel; // $a2
	unsigned short i; // $a1
	struct _AadSequenceSlot *slot; // $t1
} // line 32, offset 0x80054a20

unsigned short aadUnMuteChannels(unsigned short slotNumber, unsigned short channelList)
{
}

unsigned short aadSetUserVariable(unsigned short variableNumber, unsigned short value)
{
	aadMem->userVariables[variableNumber] = value;
	return 0;
}

unsigned short aadGetUserVariable(unsigned short variableNumber)
{
	return aadMem->userVariables[variableNumber];
}

unsigned short aadSetNoUpdateMode(short noUpdate)
{
	if ((noUpdate << 16) != 0)
	{
		aadMem->flags |= 2;
	}
	else
	{
		//loc_80054AA8
		aadMem->flags &= 0xFFFD;
	}

	return 0;
}

unsigned short aadCancelPauseSound()
{
	aadMem->flags &= 0xFFF3;
	return 0;
}





