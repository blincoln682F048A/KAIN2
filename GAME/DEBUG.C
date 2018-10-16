#include "DEBUG.H"

#include "G2TYPES.H"

#include <SYS\TYPES.H>
#include <LIBCD.H>
#include <LIBETC.H>
#include <LIBGPU.H>
#include <STDLIB.H>

void DEBUG_SetGameTime(long* var)
{
	long tim; // $v1
}

void DEBUG_KeepGameTime(long* var)
{
	long curTOD;
}

void DEBUG_UpdateFog(long* var)
{
    struct _StreamUnit* currentUnit;
}

void DEBUG_FogLoad()
{
    struct _StreamUnit* currentUnit;
}

void DEBUG_FogRestore()
{
}

void DEBUG_ForceRearrangeVram()
{
}

void DEBUG_Process(struct GameTracker* gameTracker)
{
    long *controlCommand;
    long oldFlags;
    long oldFlags2;
    { // line 40, offset 0x80012a20
        struct Camera *camera; // $v0
    } // line 40, offset 0x80012a20
}

void DEBUG_VoiceTest()
{
}

void DEBUG_Draw(struct GameTracker* gameTracker, unsigned long** ot)
{
}

long DEBUG_MenuCountLength(struct DebugMenuLine* menu)
{
    int length;
    struct DebugMenuLine* curLine;
} // line 11, offset 0x80012bc8
/*
 * Offset 0x80012BD0
 * C:\kain2\game\DEBUG.C (line 992)
 * Stack frame base $sp, size 24
 * Saved registers at offset -8: ra
 */
void /*$ra*/ DEBUG_ExitMenus()
{ // line 1, offset 0x80012bd0
} // line 25, offset 0x80012c50
/*
 * Offset 0x80012C60
 * C:\kain2\game\DEBUG.C (line 1021)
 * Stack frame base $sp, size 56
 * Saved registers at offset -8: s0 s1 s2 s3 s4 s5 s6 s7 ra
 */
void /*$ra*/ DEBUG_Menu(struct GameTracker *gameTracker /*$s6*/)
{ // line 1, offset 0x80012c60
    long *controlCommand; // $s5
    long i; // $s1
    long lastChoice; // $s7
    long numChoices; // $s2
    long incr; // $s4
    struct DebugMenuLine *debugLine; // $s3
} // line 209, offset 0x800131d0
/*
 * Offset 0x800131FC
 * C:\kain2\game\DEBUG.C (line 1234)
 * Stack frame base $sp, size 96
 * Saved registers at offset -4: s0 s1 s2 s3 s4 ra
 */
void /*$ra*/ DEBUG_ProcessCheat(struct GameTracker *gameTracker /*$s3*/)
{ // line 1, offset 0x800131fc
    long angleRelCamera; // $s2
    struct Camera *camera; // $s4
   // { // line 28, offset 0x800132d8
        SVECTOR v; // stack offset -80
        VECTOR dv; // stack offset -72
        MATRIX rotate_mat; // stack offset -56
    //} // line 38, offset 0x8001335c
} // line 39, offset 0x8001335c
/*
 * Offset 0x8001337C
 * C:\kain2\game\DEBUG.C (line 1278)
 * Stack frame base $sp, size 0
 */
void /*$ra*/ DEBUG_ProcessSecondController(struct GameTracker *gameTracker /*$a0*/)
{
}
/*
 * Offset 0x80013384
 * C:\kain2\game\DEBUG.C (line 1368)
 * Stack frame base $sp, size 64
 * Saved registers at offset -4: s0 s1 s2 ra
 */
void /*$ra*/ DEBUG_DisplayStatus(struct GameTracker *gameTracker /*$s2*/)
{ // line 1, offset 0x80013384
    { // line 15, offset 0x800133e0
        short i; // $s0
    } // line 21, offset 0x80013428
    { // line 24, offset 0x8001343c
        short i; // $s1
        struct AadSynthVoice *voice; // $s0
        unsigned char spuVoiceStatus[24]; // stack offset -48
    } // line 139, offset 0x80013910
    { // line 249, offset 0x80013a74
        int deg; // $a0
    } // line 259, offset 0x80013af8
    { // line 265, offset 0x80013b08
        long numberInQueue; // stack offset -24
    } // line 272, offset 0x80013b28
} // line 283, offset 0x80013b28
/*
 * Offset 0x80013B40
 * C:\kain2\game\DEBUG.C (line 2352)
 * Stack frame base $sp, size 0
 */
void /*$ra*/ DEBUG_DrawLine(long r /*$a0*/, long g /*$a1*/, long b /*$a2*/, short x0 /*$a3*/, int y0 /*stack 16*/, int z0 /*stack 20*/, int x1 /*stack 24*/, int y1 /*stack 28*/, int z1 /*stack 32*/)
{
}
/*
 * Offset 0x80013B48
 * C:\kain2\game\DEBUG.C (line 2596)
 * Stack frame base $sp, size 0
 */
void /*$ra*/ DEBUG_DrawShrinkCels(unsigned long **polyAddr /*$a0*/)
{
}
/*
 * Offset 0x80013B50
 * C:\kain2\game\DEBUG.C (line 2772)
 * Stack frame base $sp, size 0
 */
void /*$ra*/ DEBUG_ExitGame()
{
}
/*
 * Offset 0x80013B6C
 * C:\kain2\game\DEBUG.C (line 2780)
 * Stack frame base $sp, size 24
 * Saved registers at offset -8: ra
 */
void /*$ra*/ DEBUG_ReloadCurrentLevel()
{
}

void /*$ra*/ DEBUG_LevelSelectNew()
{ // line 1, offset 0x80013bb0
    char *name; // $a0
    short number; // $a1
    char *p; // $s0
    char saveChar; // $s1
} // line 28, offset 0x80013c5c

void DEBUG_MusicSelect()
{
    char *name;
    char *p;
	char saveChar;
}

void DEBUG_PrintSramStatus()
{
    struct AadNewSramBlockDesc *sramDescTbl; // $s4
    struct AadNewSramBlockDesc *sramDesc; // $s0
    unsigned short largestFree; // $s1
    unsigned long numWaves; // $s2
    unsigned long totalFree; // $s3
}

void DEBUG_SetViewVram()
{
}

void DEBUG_EndViewVram(struct GameTracker* gameTracker)
{
}

void DEBUG_ViewVram(struct GameTracker* gameTracker)
{
    long* controlCommand;
    static int xPos;
    static int yPos;
}

void DEBUG_CaptureScreen(struct GameTracker* gameTracker)
{
}

void DEBUG_FONT_Flush()
{
}