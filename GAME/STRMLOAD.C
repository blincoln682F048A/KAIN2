#include "STRMLOAD.H"

#include "G2TYPES.H"

int /*$ra*/ STREAM_IsCdBusy(long *numberInQueue /*$a0*/)
{ // line 2, offset 0x8005e904
    long isTheCDBusy; // $a2
} // line 25, offset 0x8005e93c
/*
 * Offset 0x8005E944
 * C:\kain2\game\STRMLOAD.C (line 174)
 * Stack frame base $sp, size 24
 * Saved registers at offset -4: s0 ra
 */
int /*$ra*/ STREAM_PollLoadQueue()
{ // line 1, offset 0x8005e944
    long isTheCDBusy; // $v0
    struct LoadQueueEntry *queueEntry; // $s0
} // line 207, offset 0x8005ebe4
/*
 * Offset 0x8005EBF4
 * C:\kain2\game\STRMLOAD.C (line 386)
 * Stack frame base $sp, size 40
 * Saved registers at offset -8: s0 s1 s2 s3 ra
 */
long /*$ra*/ STREAM_QueueNonblockingLoads(char *fileName /*$a0*/, unsigned char memType /*$a1*/, void *retFunc /*$s2*/, void *retData /*$s3*/, void *retData2 /*stack 16*/, void **retPointer /*stack 20*/, long relocateBinary /*stack 24*/, long forceSize /*stack 28*/)
{ // line 1, offset 0x8005ebf4
    struct LoadQueueEntry *currentEntry; // $s0
} // line 42, offset 0x8005eccc
/*
 * Offset 0x8005ECE8
 * C:\kain2\game\STRMLOAD.C (line 441)
 * Stack frame base $sp, size 40
 * Saved registers at offset -8: ra
 */
void /*$ra*/ LOAD_NonBlockingBinaryLoad(char *fileName /*$a0*/, void *retFunc /*$t0*/, void *retData /*$t1*/, void *retData2 /*$a3*/, void **retPointer /*stack 16*/, int memType /*stack 20*/)
{
}
/*
 * Offset 0x8005ED30
 * C:\kain2\game\STRMLOAD.C (line 448)
 * Stack frame base $sp, size 40
 * Saved registers at offset -8: ra
 */
void /*$ra*/ LOAD_NonBlockingFileLoad(char *fileName /*$a0*/, void *retFunc /*$v1*/, void *retData /*$t0*/, void *retData2 /*$a3*/, void **retPointer /*stack 16*/, int memType /*stack 20*/)
{
}
/*
 * Offset 0x8005ED74
 * C:\kain2\game\STRMLOAD.C (line 455)
 * Stack frame base $sp, size 40
 * Saved registers at offset -8: ra
 */
void /*$ra*/ LOAD_NonBlockingPartOfFileLoad(char *fileName /*$a0*/, long forceSize /*$a1*/, void *retFunc /*$a2*/, void *retData /*$a3*/, void *retData2 /*stack 16*/, void **retPointer /*stack 20*/, int memType /*stack 24*/)
{
}
/*
 * Offset 0x8005EDB0
 * C:\kain2\game\STRMLOAD.C (line 461)
 * Stack frame base $sp, size 24
 * Saved registers at offset -8: ra
 */
void /*$ra*/ STREAM_CleanUpNonblockingBufferedLoad()
{
}
/*
 * Offset 0x8005EDF8
 * C:\kain2\game\STRMLOAD.C (line 477)
 * Stack frame base $sp, size 40
 * Saved registers at offset -8: s0 s1 s2 s3 ra
 */
long /*$ra*/ LOAD_NonBlockingBufferedLoad(char *fileName /*$a0*/, void *retFunc /*$s1*/, void *retData1 /*$s2*/, void *retData2 /*$s3*/)
{ // line 1, offset 0x8005edf8
    struct LoadQueueEntry *currentEntry; // $s0
} // line 43, offset 0x8005eec4