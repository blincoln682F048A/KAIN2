#ifndef AADSFX_H
#define AADSFX_H

#include "G2TYPES.H"

extern unsigned long aadPlaySfx(unsigned short toneID, unsigned short volume, unsigned short pan, short pitchOffset);
extern unsigned long aadStopSfx(unsigned long handle);
extern unsigned short aadStopAllSfx();
extern unsigned short aadIsSfxPlaying(unsigned long handle);
extern unsigned short aadIsSfxPlayingOrRequested(unsigned long handle);
extern unsigned long aadSetSfxVolPanPitch(unsigned long handle, unsigned short volume, unsigned short pan, short pitch);
extern unsigned long createSfxHandle(unsigned short toneID);
extern void aadPutSfxCommand(unsigned char statusByte, unsigned char dataByte0, unsigned char dataByte1, unsigned long ulongParam, int shortParam);
extern void aadExecuteSfxCommand(struct AadSfxCommand* sfxCmd);
extern void sfxCmdPlayTone(struct AadSfxCommand* sfxCmd);
extern void sfxCmdStopTone(struct AadSfxCommand* sfxCmd);
extern void sfxCmdStopAllTones(struct AadSfxCommand* sfxCmd);
extern void sfxCmdSetToneVolumeAndPan(struct AadSfxCommand* sfxCmd);
extern void sfxCmdSetToneVolPanPitch(struct AadSfxCommand* sfxCmd);
extern void sfxCmdLockVoice(struct AadSfxCommand* sfxCmd);
extern void sfxCmdSetVoiceAttr(struct AadSfxCommand* sfxCmd);
extern void sfxCmdSetVoiceKeyOn(struct AadSfxCommand* sfxCmd);
extern void sfxCmdSetVoiceKeyOff(struct AadSfxCommand* sfxCmd);

#endif