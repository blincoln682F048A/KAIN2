#ifndef SOUND_H
#define SOUND_H

#include "G2TYPES.H"

extern struct SoundEffectChannel* SndOpenSfxChannel(unsigned char* channelNum);
extern void SndCloseSfxChannel(unsigned char channelNum);
extern struct SoundEffectChannel* SndGetSfxChannel(unsigned char channelNum);
extern void SOUND_ProcessInstanceSounds(struct _Instance* instance);
extern void SOUND_EndInstanceSounds(struct _Instance* instance);
extern void setPeriodicSoundStateOff(struct SoundInstance* soundInst, struct ObjectPeriodicSound* sound);
extern void processPeriodicSound(struct _Instance* instance, struct SoundInstance* soundInst, struct ObjectPeriodicSound* sound);
extern unsigned long SOUND_Play3dSound(struct _Instance* instance, unsigned short sfxToneID, short pitch, short maxVolume, int minVolDist);
extern unsigned long SOUND_Update3dSound(struct _Instance* instance, unsigned long handle, short pitch, short maxVolume, int minVolDist);
extern struct Signal* SOUND_HandleSignal(struct _Instance* instance, struct Signal* signal);
extern void SOUND_HandleGlobalValueSignal(int name, long data);
extern void SOUND_Init();
extern void SOUND_Free();
extern void SOUND_SetMusicVariable(short variable, short value);
extern void SOUND_SetMusicVolume(int newVolume);
extern void SOUND_SetSfxVolume(int newVolume);
extern void SOUND_SetVoiceVolume(int newVolume);
extern void SOUND_StopAllSound();
extern void SOUND_ResetAllSound();
extern void SOUND_MusicOff();
extern void SOUND_MusicOn();
extern void SOUND_SfxOff();
extern void SOUND_SfxOn();
extern int SndIsPlaying(unsigned long handle);
extern int SndIsPlayingOrRequested(unsigned long handle);
extern unsigned long SndPlay(unsigned short sample);
extern void SndEndLoop(unsigned long handle);
extern unsigned long SndPlayVolPan(unsigned short sample, unsigned short vol, unsigned short pan, short pitch);
extern unsigned long SndUpdateVolPanPitch(unsigned long handle, unsigned short vol, unsigned short pan, short pitch);
extern void SOUND_DynamicMusicReturn(unsigned short dynamicBankIndex, unsigned short errorStatus);
extern void SOUND_ExtractName(char* outString, char* inString);
extern void SOUND_ExtractNum(char* outNum, char* inString);
extern void SOUND_LoadDynamicMusic(char* baseMusicName);
extern void SOUND_FreeDynamicMusic();
extern void SOUND_SetMusicModifier(long modifier);
extern void SOUND_ResetMusicModifier(long modifier);

#endif