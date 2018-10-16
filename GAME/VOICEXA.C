#include "VOICEXA.H"

#include "G2TYPES.H"

void VOICEXA_Init()
{
	int i; // $s2
	struct CdlFILE fp; // stack offset -40
	struct XAVoiceTracker *vt; // $a0
}
  /*
  * Offset 0x800A6974
  * C:\kain2\game\VOICEXA.C (line 86)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ putCdCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char cdCommand /*$a1*/, int numParams /*$a2*/, unsigned char *params /*$a3*/)
{ // line 1, offset 0x800a6974
	int i; // $t0
} // line 14, offset 0x800a69f0
  /*
  * Offset 0x800A69F8
  * C:\kain2\game\VOICEXA.C (line 103)
  * Stack frame base $sp, size 24
  * Saved registers at offset -8: ra
  */
void /*$ra*/ VOICEXA_CdSyncCallback(unsigned char status /*$a0*/, unsigned char *result /*$a1*/)
{ // line 1, offset 0x800a69f8
	struct XAVoiceTracker *vt; // $a1
} // line 22, offset 0x800a6a58
  /*
  * Offset 0x800A6A68
  * C:\kain2\game\VOICEXA.C (line 129)
  * Stack frame base $sp, size 32
  * Saved registers at offset -8: s0 s1 ra
  */
void /*$ra*/ processCdCommands(struct XAVoiceTracker *vt /*$s1*/)
{ // line 1, offset 0x800a6a68
	struct CdCommand *cmd; // $s0
} // line 22, offset 0x800a6afc
  /*
  * Offset 0x800A6B10
  * C:\kain2\game\VOICEXA.C (line 174)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ putVoiceCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char voiceCmd /*$a1*/, unsigned char nextVoiceStatus /*$a2*/, unsigned char voiceCmdParam /*$a3*/)
{
}
/*
* Offset 0x800A6B8C
* C:\kain2\game\VOICEXA.C (line 191)
* Stack frame base $sp, size 32
* Saved registers at offset -8: s0 s1 ra
*/
void /*$ra*/ processVoiceCommands(struct XAVoiceTracker *vt /*$s1*/)
{ // line 1, offset 0x800a6b8c
	struct VoiceCommand *cmd; // $s0
} // line 18, offset 0x800a6c2c
  /*
  * Offset 0x800A6C40
  * C:\kain2\game\VOICEXA.C (line 214)
  * Stack frame base $sp, size 104
  * Saved registers at offset -8: s0 s1 s2 s3 ra
  */
void /*$ra*/ voiceCmdPlay(struct XAVoiceTracker *vt /*$s1*/, short voiceIndex /*$s2*/)
{ // line 1, offset 0x800a6c40
	struct CdlFILTER filter; // stack offset -88
	struct CdlLOC pos; // stack offset -80
	unsigned char mode; // stack offset -32
	struct SpuCommonAttr spuattr; // stack offset -72
	struct XAVoiceListEntry *voice; // $s3
	struct XAFileInfo *file; // $s0
} // line 62, offset 0x800a6d90

void voiceCmdStop(struct XAVoiceTracker* vt /*$a0*/, short cmdParam /*$a1*/)
{
	struct SpuCommonAttr spuattr; // stack offset -48
}

void voiceCmdPause(struct XAVoiceTracker* vt /*$a0*/, short cmdParam /*$a1*/)
{
}

void voiceCmdResume(struct XAVoiceTracker* vt /*$a0*/, short cmdParam /*$a1*/)
{
}

void voiceCmdNull(struct XAVoiceTracker* vt /*$a0*/, short cmdParam /*$a1*/)
{
}

void VOICEXA_Play(int voiceIndex /*$a3*/, int queueRequests /*$a1*/)
{
	struct XAVoiceTracker *vt; // $a0
	struct XAFileInfo *file; // $a2
}

void VOICEXA_Tick()
{
	struct XAVoiceTracker *vt; // $s0
}

int VOICEXA_IsPlaying()
{
	return (voiceTracker.voiceStatus ^ 1) < 1 ? 1 : 0;
}