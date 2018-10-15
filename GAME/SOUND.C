#include "SOUND.H"

#include "G2TYPES.H"

#include <STDLIB.H>
#include <STDIO.H>

struct SoundEffectChannel * /*$ra*/ SndOpenSfxChannel(unsigned char *channelNum /*$a0*/)
{ // line 2, offset 0x80041760
    short i; // $a1
} // line 14, offset 0x800417b4

void /*$ra*/ SndCloseSfxChannel(unsigned char channelNum /*$a0*/)
{
}

struct SoundEffectChannel * /*$ra*/ SndGetSfxChannel(unsigned char channelNum /*$a0*/)
{
}

void /*$ra*/ SOUND_ProcessInstanceSounds(struct _Instance *instance /*$s2*/)
{ // line 1, offset 0x8004180c
    unsigned char *p; // $s0
    unsigned char numSounds; // $v0
    unsigned short i; // $s1
} // line 32, offset 0x800418c8

void /*$ra*/ SOUND_EndInstanceSounds(struct _Instance *instance /*$s3*/)
{ // line 1, offset 0x800418e4
    unsigned char *p; // $a0
    unsigned short i; // $s1
    struct SoundInstance *soundInst; // $s0
    struct SoundEffectChannel *channel; // $v0
} // line 32, offset 0x800419ac

void /*$ra*/ setPeriodicSoundStateOff(struct SoundInstance *soundInst /*$s0*/, struct ObjectPeriodicSound *sound /*$s1*/)
{
}

void /*$ra*/ processPeriodicSound(struct _Instance *instance /*$s3*/, struct SoundInstance *soundInst /*$s2*/, struct ObjectPeriodicSound *sound /*$s1*/)
{ // line 1, offset 0x80041a58
    struct SoundEffectChannel *channel; // $s0
    unsigned short sfxIDNum; // $v0
} // line 116, offset 0x80041e1c

unsigned long /*$ra*/ SOUND_Play3dSound(struct _Instance *instance /*$t0*/, unsigned short sfxToneID /*$s7*/, short pitch /*$s4*/, short maxVolume /*$s6*/, int minVolDist /*stack 16*/)
{ // line 1, offset 0x80041e38
    long dx; // $s1
    long dy; // $s0
    long dz; // $a0
    long objDist; // $s5
    long workMinVolDist; // $s3
    struct Camera *camera; // $s2
    short position; // $a2
    short pan; // $a2
    short volume; // $a1
} // line 91, offset 0x800420b0

unsigned long /*$ra*/ SOUND_Update3dSound(struct _Instance *instance /*$t0*/, unsigned long handle /*$s7*/, short pitch /*$s4*/, short maxVolume /*$s6*/, int minVolDist /*stack 16*/)
{ // line 1, offset 0x800420dc
    long dx; // $s1
    long dy; // $s0
    long dz; // $a0
    long objDist; // $s5
    long workMinVolDist; // $s3
    struct Camera *camera; // $s2
    short position; // $a2
    short pan; // $a2
    short volume; // $a1
} // line 91, offset 0x80042354

struct Signal * /*$ra*/ SOUND_HandleSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$s0*/)
{ // line 1, offset 0x80042380
    int params; // $v0
} // line 22, offset 0x800423bc

void /*$ra*/ SOUND_HandleGlobalValueSignal(int name /*$a0*/, long data /*$a1*/)
{
}

void /*$ra*/ SOUND_Init()
{ // line 1, offset 0x800423e0
    struct AadInitAttr initAttr; // stack offset -32
} // line 1, offset 0x800423e0

void SOUND_Free()
{
	gameTrackerX.sound.soundsLoaded = 0;
	aadShutdown();
}

void /*$ra*/ SOUND_SetMusicVariable(short variable /*$a0*/, short value /*$a1*/)
{
}

void /*$ra*/ SOUND_SetMusicVolume(int newVolume /*$a0*/)
{
}

void /*$ra*/ SOUND_SetSfxVolume(int newVolume /*$a0*/)
{
}

void /*$ra*/ SOUND_SetVoiceVolume(int newVolume /*$a0*/)
{
}

void SOUND_StopAllSound()
{
	if (gameTrackerX.sound.soundsLoaded != 0)
	{
		aadStopAllSfx();
		aadStopAllSlots();
		aadShutdownReverb();
		aadCancelPauseSound();
	}
	//loc_800425A0
}

void /*$ra*/ SOUND_ResetAllSound()
{
}

void /*$ra*/ SOUND_MusicOff()
{ // line 1, offset 0x800425e0
    unsigned short slotNumber; // $s1
} // line 16, offset 0x80042640

void /*$ra*/ SOUND_MusicOn()
{ // line 1, offset 0x80042658
    unsigned short slotNumber; // $s0
} // line 6, offset 0x80042684

void /*$ra*/ SOUND_SfxOff()
{
}

void /*$ra*/ SOUND_SfxOn()
{
}

int /*$ra*/ SndIsPlaying(unsigned long handle /*$a0*/)
{
}

int /*$ra*/ SndIsPlayingOrRequested(unsigned long handle /*$a0*/)
{
}

unsigned long /*$ra*/ SndPlay(unsigned short sample /*$a0*/)
{
}

void /*$ra*/ SndEndLoop(unsigned long handle /*$a0*/)
{
}

unsigned long /*$ra*/ SndPlayVolPan(unsigned short sample /*$a0*/, unsigned short vol /*$a1*/, unsigned short pan /*$a2*/, short pitch /*$a3*/)
{ // line 1, offset 0x80042778
} // line 11, offset 0x800427a8

unsigned long /*$ra*/ SndUpdateVolPanPitch(unsigned long handle /*$a0*/, unsigned short vol /*$a1*/, unsigned short pan /*$a2*/, short pitch /*$a3*/)
{
}

void /*$ra*/ SOUND_DynamicMusicReturn(unsigned short dynamicBankIndex /*$a0*/, unsigned short errorStatus /*$a1*/)
{ // line 1, offset 0x80042800
    long error; // $a1
} // line 14, offset 0x8004283c

void /*$ra*/ SOUND_ExtractName(char *outString /*$a0*/, char *inString /*$a1*/)
{
}

void /*$ra*/ SOUND_ExtractNum(char *outNum /*$a0*/, char *inString /*$a1*/)
{
}

void SOUND_LoadDynamicMusic(char* baseMusicName)
{
	char soundName[32];
	char soundNumber[16];
	char sndFileName[64];
	static char smpFileName[64];

	if (baseMusicName != NULL)
	{
		if (strcmpi(baseMusicName, &gameTrackerX.curDynamicSoundName[0]))
		{
			SOUND_ExtractName(&soundName[0], baseMusicName);
			SOUND_ExtractNum(&soundNumber[0], baseMusicName);
		}//loc_800429D4
	}//loc_800429D4

	sprintf(&sndFileName[0], "\\kain2\\music\\%s%s\\%s%s.snd", &soundName[0], &soundNumber[0], &soundName[0], &soundNumber[0]);
	sprintf(&smpFileName[0], "\\kain2\\music\\%s%s\\%s%s.smp", &soundName[0], &soundNumber[0], &soundName[0], &soundNumber[0]);
	aadLoadDynamicSoundBank(&sndFileName[0], &smpFileName[0], 1, &soundNumber[0], SOUND_DynamicMusicReturn);
	strcpy(gameTrackerX.curDynamicSoundName, &baseMusicName[0]);

	return;
}

void SOUND_FreeDynamicMusic()
{
	if (aadGetDynamicBankStatus(1) != 0)
	{
		aadStopAllSlots();
		aadFreeDynamicSoundBank();
		gameTrackerX.curDynamicSoundName[0] = 0;
	}//loc_80042A20
}

void /*$ra*/ SOUND_SetMusicModifier(long modifier /*$a0*/)
{
}

void /*$ra*/ SOUND_ResetMusicModifier(long modifier /*$a0*/)
{
}

