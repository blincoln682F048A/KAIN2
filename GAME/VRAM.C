#include "VRAM.H"

#include "G2TYPES.H"

void VRAM_PrintVramBlock(struct _BlockVramEntry* vblock /*$a0*/)
{
}

void VRAM_PrintInfo()
{
    struct _BlockVramEntry* vblock; // $v0
}

void VRAM_InitVramBlockCache()
{
    int i; // $v1
}

int VRAM_ConcatanateMemory(struct _BlockVramEntry* curBlock /*$s1*/)
{
    struct _BlockVramEntry* nextBlock; // $s0
}

void VRAM_GarbageCollect()
{
}

int VRAM_InsertFreeBlock(struct _BlockVramEntry* block /*$a0*/)
{
    struct _BlockVramEntry *next; // $v1
    struct _BlockVramEntry *prev; // $a1
}

void VRAM_DeleteFreeBlock(struct _BlockVramEntry* block /*$a0*/)
{
    struct _BlockVramEntry *next; // $v1
    struct _BlockVramEntry *prev; // $a1
}

void VRAM_InsertUsedBlock(struct _BlockVramEntry* block /*$a0*/)
{
}

void VRAM_DeleteUsedBlock(struct _BlockVramEntry* block /*$a0*/)
{
    struct _BlockVramEntry *next; // $v1
    struct _BlockVramEntry *prev; // $a1
}

struct _BlockVramEntry* VRAM_GetOpenBlock()
{
    int i; // $a0
}

int VRAM_InsertFreeVram(short x /*stack -48*/, short y /*stack -46*/, short w /*$s7*/, short h /*$fp*/, int flags /*stack 16*/)
{
    struct _BlockVramEntry* useBlock; // $a0
}

struct _BlockVramEntry* VRAM_CheckVramSlot(short *x /*$s6*/, short *y /*stack 4*/, short w /*$s1*/, short h /*$s3*/, int type /*stack 16*/, int startY /*stack 20*/)
{
    struct _BlockVramEntry *vblock; // $s2
    short hldx; // $s4
    short hldy; // $s7
    short hldw; // $s5
    short hldh; // stack offset -48
    long fits; // $t2
    long offset; // $s0
}

void VRAM_ClearVramBlock(struct _BlockVramEntry *block /*$s0*/)
{
}

void AdjustVramCoordsObject(int oldx /*$s3*/, int oldy /*$s1*/, int newx /*$a2*/, int newy /*$t7*/, struct Object *object /*stack 16*/)
{
    struct TextureMT3 *texture; // $t1
    int oldclutxoffset; // $v0
    int oldclutyoffset; // $a0
    int newclut; // $a0
    int d; // $t4
    int oldtpagexoffset; // $v1
    int oldtpageyoffset; // $v0
    int newtpage; // $a3
    struct _Model *model; // $t3
    short diffy; // $s5
    short diffx; // $s6
}

struct _BlockVramEntry* VRAM_InsertionSort(struct _BlockVramEntry *rootNode /*$a0*/, struct _BlockVramEntry *newBlock /*$a1*/)
{
    struct _BlockVramEntry *next; // $v1
    struct _BlockVramEntry *prev; // $a2
}

void VRAM_RearrangeVramsLayer(long whichLayer /*$s6*/)
{
    struct _BlockVramEntry *vblock; // $s0
    struct _BlockVramEntry *sortedBlocks; // $s2
    struct _BlockVramEntry *curBlock; // $s1
    struct _BlockVramEntry *savedVramBlocksPTR[32]; // stack offset -1072
    struct _BlockVramEntry savedVramBlocks[32]; // stack offset -944
    struct RECT vramLoc; // stack offset -48
    long numBlocks; // $s3
    long d; // $s4
    short x; // stack offset -40
    short y; // stack offset -38
    short dispYPos; // $s5
}

void VRAM_TransferBufferToVram(void *dataPtr /*$s3*/, long dataSize /*$s2*/, short status /*$s5*/, void *data1 /*$a3*/, void *data2 /*stack 16*/)
{
    struct VramBuffer *vramControl; // $s1
    struct RECT rect; // stack offset -40
    { // line 27, offset 0x8006ddd8
    } // line 57, offset 0x8006de94
    { // line 62, offset 0x8006de9c
    } // line 83, offset 0x8006df4c
}

long VRAM_GetObjectVramSpace(long* addr /*$a0*/, struct _ObjectTracker* objectTracker /*$s2*/)
{
    struct RECT rect; // stack offset -24
    long *picdim; // $a0
    long x; // $v0
    long y; // $v1
    long w; // $a2
    long h; // $a3
    long result; // $s1
    struct _BlockVramEntry* lastVramBlockUsed; // $s0
}

long VRAM_GetLevelVramSpace(long* addr /*$a0*/, struct _StreamUnit* streamUnit /*$a1*/)
{
	struct RECT rect; // stack offset -8
	long *picdim; // $a2
	long x; // $v0
	long y; // $v1
	long w; // $t0
	long h; // $a3
}

void  VRAM_InitMorphPalettes()
{
}

void VRAM_UpdateMorphPalettes()
{
}

void MORPH_ChangeAreaPalettes(long time /*$a0*/)
{
}