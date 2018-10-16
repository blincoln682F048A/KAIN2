#ifndef AADLIB_H
#define AADLIB_H

#include "G2TYPES.H"

extern unsigned long aadGetMemorySize(struct AadInitAttr* attributes);
extern unsigned short aadInit(struct AadInitAttr*attributes, unsigned char*memoryPtr);
extern void aadInstallUpdateFunc(long(*updateFuncPtr)(), unsigned short hblanksPerUpdate);
extern unsigned short aadInitVolume();
extern unsigned short aadSetMasterVolume(short volume);
extern unsigned short aadStartMasterVolumeFade(short targetVolume, short volumeStep, void(*fadeCompleteCallback)());
extern unsigned short aadSetSfxMasterVolume(unsigned short volume);
extern unsigned short aadSetMusicMasterVolume(unsigned short volume);
extern unsigned short aadStartMusicMasterVolFade(short targetVolume, short volumeStep, void(*fadeCompleteCallback)());
extern unsigned short aadSetSlotMasterVolumeType(unsigned short slotNumber, unsigned short masterVolType);
extern unsigned short aadShutdown();
extern long aadSlotUpdateWrapper();
extern long aadSlotUpdate();
extern unsigned long aadCreateFourCharID(char a, char b, char c, char d);
extern unsigned short aadLoadDynamicSoundBank(char*sndFileName, char*smpFileName, unsigned short dynamicBankIndex, unsigned short loadOption, void(*retProc)());
extern void aadLoadDynamicSoundBankReturn(void*loadedDataPtr, void*data, void*data2);
extern void aadLoadDynamicSoundBankReturn2(void*loadedDataPtr, long loadedDataSize, short status, void*data1, void*data2);
extern void aadFreeLoadBuffer();
extern unsigned short aadFreeDynamicSoundBank(unsigned short dynamicBankIndex);
extern unsigned short aadOpenDynamicSoundBank(unsigned char*soundBank, unsigned short dynamicBankIndex);
extern unsigned short aadLoadDynamicSfx(char*fileName, unsigned long userData, void(*userReturnProc)());
extern void aadProcessLoadQueue();
extern void aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo* info, unsigned short error);
extern void aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo* info);
extern void aadLoadDynamicSfxReturn(void*loadedDataPtr, void*data, void*data2);
extern unsigned char aadWaveMalloc(unsigned short waveID, unsigned long waveSize);
extern unsigned long aadGetSramBlockAddr(unsigned char handle);
extern void aadWaveFree(unsigned char handle);
extern void aadFreeSingleDynSfx(unsigned short sfxID);
extern void aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo* info);
extern void aadLoadDynamicSfxReturn2(void*loadedDataPtr, long loadedDataSize, short status, void*data1, void*data2);
extern unsigned short aadFreeDynamicSfx(unsigned short snfFileID);
extern void aadInitSequenceSlot(struct _AadSequenceSlot* slot);
extern int aadWaitForSramTransferComplete();
extern unsigned short aadInitReverb();
extern unsigned short aadShutdownReverb();
extern unsigned short aadGetReverbMode();
extern unsigned long aadGetReverbSize();
extern short aadGetReverbDepth();
extern unsigned short aadGetDynamicBankStatus(unsigned short bank);
extern unsigned short aadGetNumDynamicSequences(unsigned short bank);
extern unsigned short aadAssignDynamicSequence(unsigned short bank, unsigned short sequenceNumber, unsigned short slotNumber);
extern struct AadTempo* aadGetTempoFromDynamicSequence(unsigned short bank, unsigned short sequenceNumber, struct AadTempo* tempo);
extern unsigned short aadSetSlotTempo(unsigned short slotNumber, struct AadTempo* tempo);
extern unsigned short aadStartSlot(unsigned short slotNumber);
extern unsigned short aadStopSlot(unsigned short slotNumber);
extern unsigned short aadStopAllSlots();
extern unsigned short aadDisableSlot(unsigned short slotNumber);
extern unsigned short aadEnableSlot(unsigned short slotNumber);
extern unsigned short aadPauseSlot(unsigned short slotNumber);
extern unsigned short aadResumeSlot(unsigned short slotNumber);
extern unsigned short aadGetSlotStatus(unsigned short slotNumber);
extern unsigned short aadAllNotesOff(unsigned short slotNumber);
extern void aadGetVoiceStatus(char*voiceStatusArray);
extern struct AadSynthVoice* aadGetVoicePointer(unsigned short voiceIndex);
extern unsigned short aadMuteChannels(unsigned short slotNumber, unsigned short channelList);
extern unsigned short aadUnMuteChannels(unsigned short slotNumber, unsigned short channelList);
extern unsigned short aadSetUserVariable(unsigned short variableNumber, unsigned short value);
extern unsigned short aadGetUserVariable(unsigned short variableNumber);
extern unsigned short aadSetNoUpdateMode(short noUpdate);
extern unsigned short aadCancelPauseSound();

#endif