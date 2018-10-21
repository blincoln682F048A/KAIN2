#include "MEMPACK.H"

void /*$ra*/ MEMPACK_Init()
{
#if 0
		//lui     $v0, 0x801F
		lw      $v1, -0x666C($gp)
		la      $v0, unk_801FF000
		subu    $v0, $v1
		sw      $v0, -0x31E0($gp)
		li      $v0, 0xBADE
		sw      $v1, -0x31E4($gp)
		sh      $v0, 0($v1)
		lw      $v0, -0x31E4($gp)
		nop
		sb      $zero, 2($v0)
		lw      $v0, -0x31E4($gp)
		nop
		sb      $zero, 3($v0)
		lw      $v1, -0x31E4($gp)
		lw      $v0, -0x31E0($gp)
		nop
		sw      $v0, 4($v1)
		lw      $v0, -0x31E4($gp)
		lw      $v1, -0x31E0($gp)
		sw      $zero, -0x31DC($gp)
		sw      $zero, -0x31D4($gp)
		addu    $v0, $v1
		sw      $v0, -0x31D8($gp)
		jr      $ra
#endif
}
/*
* Offset 0x800501A8
* C:\kain2\game\MEMPACK.C (line 236)
* Stack frame base $sp, size 0
*/
struct MemHeader * /*$ra*/ MEMPACK_GetSmallestBlockTopBottom(long allocSize /*$a0*/)
{ // line 2, offset 0x800501a8
	struct MemHeader *address; // $v1
	struct MemHeader *bestAddress; // $a1
} // line 34, offset 0x80050208
  /*
  * Offset 0x80050210
  * C:\kain2\game\MEMPACK.C (line 276)
  * Stack frame base $sp, size 0
  */
struct MemHeader * /*$ra*/ MEMPACK_GetSmallestBlockBottomTop(long allocSize /*$a0*/)
{ // line 2, offset 0x80050210
	struct MemHeader *address; // $v1
	struct MemHeader *bestAddress; // $a1
} // line 29, offset 0x80050274
  /*
  * Offset 0x8005027C
  * C:\kain2\game\MEMPACK.C (line 308)
  * Stack frame base $sp, size 0
  */
long  MEMPACK_RelocatableType(long memType)
{
	return (memType - 1 < 0 ? 1 : 0);
}
/*
* Offset 0x80050288
* C:\kain2\game\MEMPACK.C (line 326)
* Stack frame base $sp, size 40
* Saved registers at offset -8: s0 s1 s2 s3 ra
*/
char * /*$ra*/ MEMPACK_Malloc(unsigned long allocSize /*$s1*/, unsigned char memType /*$s3*/)
{ // line 1, offset 0x80050288
	struct MemHeader *bestAddress; // $s0
	long relocatableMemory; // $s2
	{ // line 78, offset 0x80050374
		struct MemHeader *address; // $a1
		{ // line 101, offset 0x800503a8
			long topOffset; // $a0
		} // line 103, offset 0x800503a8
	} // line 103, offset 0x800503a8
} // line 135, offset 0x80050418
  /*
  * Offset 0x80050434
  * C:\kain2\game\MEMPACK.C (line 465)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ MEMORY_MergeAddresses(struct MemHeader *firstAddress /*$a0*/, struct MemHeader *secondAddress /*$a1*/)
{
}
/*
* Offset 0x8005047C
* C:\kain2\game\MEMPACK.C (line 484)
* Stack frame base $sp, size 24
* Saved registers at offset -8: ra
*/
void /*$ra*/ MEMPACK_Return(char *address /*$a0*/, long takeBackSize /*$a1*/)
{ // line 1, offset 0x8005047c
	struct MemHeader *memAddress; // $a0
	struct MemHeader *nextAddress; // $a1
} // line 28, offset 0x800504f0
  /*
  * Offset 0x80050500
  * C:\kain2\game\MEMPACK.C (line 543)
  * Stack frame base $sp, size 24
  * Saved registers at offset -4: s0 ra
  */
void /*$ra*/ MEMPACK_Free(char *address /*$a0*/)
{ // line 1, offset 0x80050500
	struct MemHeader *memAddress; // $s0
	struct MemHeader *secondAddress; // $v1
} // line 45, offset 0x800505a4
  /*
  * Offset 0x800505B4
  * C:\kain2\game\MEMPACK.C (line 590)
  * Stack frame base $sp, size 32
  * Saved registers at offset -4: s0 s1 s2 ra
  */
void /*$ra*/ MEMPACK_FreeByType(unsigned char memType /*$a0*/)
{ // line 1, offset 0x800505b4
	struct MemHeader *address; // $a0
	int freed; // $s0
} // line 22, offset 0x80050634

unsigned long MEMPACK_Size(char* address)
{
	return ((unsigned long*)address)[-1] - 8;
}

unsigned long MEMPACK_ReportFreeMemory()
{
	return newMemTracker.totalMemory - newMemTracker.currentMemoryUsed;
}
/*
* Offset 0x80050668
* C:\kain2\game\MEMPACK.C (line 708)
* Stack frame base $sp, size 0
*/
void /*$ra*/ MEMPACK_ReportMemory()
{ // line 2, offset 0x80050668
	struct MemHeader *address; // $v1
	long i; // $a1
	long firstTime; // $a0
} // line 72, offset 0x800506fc
  /*
  * Offset 0x80050704
  * C:\kain2\game\MEMPACK.C (line 782)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ MEMPACK_SetMemoryBeingStreamed(char *address /*$a0*/)
{ // line 2, offset 0x80050704
} // line 7, offset 0x80050704
  /*
  * Offset 0x80050710
  * C:\kain2\game\MEMPACK.C (line 792)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ MEMPACK_SetMemoryDoneStreamed(char *address /*$a0*/)
{ // line 2, offset 0x80050710
} // line 7, offset 0x80050710
  /*
  * Offset 0x8005071C
  * C:\kain2\game\MEMPACK.C (line 807)
  * Stack frame base $sp, size 0
  */
long /*$ra*/ MEMPACK_MemoryValidFunc(char *address /*$a0*/)
{ // line 2, offset 0x8005071c
} // line 27, offset 0x80050748
  /*
  * Offset 0x80050750
  * C:\kain2\game\MEMPACK.C (line 836)
  * Stack frame base $sp, size 40
  * Saved registers at offset -8: s0 s1 s2 s3 ra
  */
char * /*$ra*/ MEMPACK_GarbageCollectMalloc(unsigned long *allocSize /*$s1*/, unsigned char memType /*$s2*/, unsigned long *freeSize /*$s3*/)
{ // line 1, offset 0x80050750
	struct MemHeader *bestAddress; // $s0
} // line 71, offset 0x8005087c
  /*
  * Offset 0x80050898
  * C:\kain2\game\MEMPACK.C (line 909)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize /*$a0*/, struct MemHeader *bestAddress /*$a1*/, long memType /*$a2*/, unsigned long freeSize /*$a3*/)
{ // line 2, offset 0x80050898
	{ // line 4, offset 0x800508a0
		struct MemHeader *address; // $v0
	} // line 12, offset 0x800508b4
} // line 14, offset 0x800508b4
  /*
  * Offset 0x800508BC
  * C:\kain2\game\MEMPACK.C (line 928)
  * Stack frame base $sp, size 24
  * Saved registers at offset -4: s0 ra
  */
void /*$ra*/ MEMPACK_GarbageCollectFree(struct MemHeader *memAddress /*$s0*/)
{ // line 1, offset 0x800508bc
	struct MemHeader *secondAddress; // $v1
} // line 37, offset 0x80050960
  /*
  * Offset 0x80050970
  * C:\kain2\game\MEMPACK.C (line 986)
  * Stack frame base $sp, size 56
  * Saved registers at offset -4: s0 s1 s2 s3 s4 s5 s6 ra
  */
void /*$ra*/ MEMPACK_DoGarbageCollection()
{ // line 1, offset 0x80050970
	struct MemHeader *relocateAddress; // $s0
	long foundOpening; // $s2
	long done; // $s5
	long addressSize; // $s4
	long addressMemType; // $s3
	long holdSize; // stack offset -40
	long freeSize; // stack offset -36
	char *oldAddress; // $s0
	char *newAddress; // $s1
} // line 111, offset 0x80050adc
  /*
  * Offset 0x80050B08
  * C:\kain2\game\MEMPACK.C (line 1111)
  * Stack frame base $sp, size 40
  * Saved registers at offset -8: s0 s1 s2 s3 ra
  */
void /*$ra*/ MEMPACK_RelocateAreaType(struct MemHeader *newAddress /*$a0*/, long offset /*$s1*/, struct Level *oldLevel /*$s3*/)
{ // line 1, offset 0x80050b08
	struct Level *level; // $s0
	struct _MultiSignal *msignal; // $a0
	long sizeOfLevel; // $s2
	long i; // $a2
	long d; // $a3
	{ // line 55, offset 0x80050da0
		struct _Terrain *terrain; // $t0
		{ // line 75, offset 0x80050ef8
			struct _BSPNode *snode; // $a2
			struct _SBSPLeaf *sleaf; // $a3
			{ // line 135, offset 0x80051144
				struct DrMoveAniTexDestInfo **dest; // $v0
			} // line 145, offset 0x80051198
		} // line 171, offset 0x800512dc
		{ // line 179, offset 0x80051318
			struct _VMObject *vmo; // $a1
		} // line 190, offset 0x800513f0
		{ // line 177, offset 0x80051408
			struct _BSPNode *node; // $a2
			struct _BSPLeaf *leaf; // $a1
		} // line 216, offset 0x80051570
	} // line 218, offset 0x80051570
} // line 227, offset 0x800515a4
  /*
  * Offset 0x80051620
  * C:\kain2\game\MEMPACK.C (line 1365)
  * Stack frame base $sp, size 0
  */
void /*$ra*/ MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist /*$a0*/, int offset /*$a1*/, char *start /*$a2*/, char *end /*$a3*/)
{ // line 1, offset 0x80051620
	{ // line 4, offset 0x8005163c
		int j; // $a2
		struct _G2AnimKeylist_Type *keylist; // $a3
	} // line 20, offset 0x800516b8
} // line 21, offset 0x800516b8
  /*
  * Offset 0x800516C0
  * C:\kain2\game\MEMPACK.C (line 1388)
  * Stack frame base $sp, size 40
  * Saved registers at offset -4: s0 s1 s2 s3 s4 ra
  */
void /*$ra*/ MEMPACK_RelocateObjectType(struct MemHeader *newAddress /*$a0*/, long offset /*$s1*/, struct Object *oldObject /*$s3*/)
{ // line 1, offset 0x800516c0
	struct _Instance *instance; // $a1
	struct Object *object; // $s0
	int i; // $s2
	int j; // $a2
	int d; // $a1
	int sizeOfObject; // $s4
	{ // line 62, offset 0x80051b5c
		struct AniTexInfo *aniTexInfo; // $a0
	} // line 71, offset 0x80051bbc
} // line 146, offset 0x80051eac