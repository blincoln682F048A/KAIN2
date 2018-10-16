#ifndef VRAM_H
#define VRAM_H

#include "G2TYPES.H"

extern void VRAM_PrintVramBlock(struct _BlockVramEntry* vblock);
extern void VRAM_PrintInfo();
extern void VRAM_InitVramBlockCache();
extern int VRAM_ConcatanateMemory(struct _BlockVramEntry* curBlock);
extern void VRAM_GarbageCollect();
extern int VRAM_InsertFreeBlock(struct _BlockVramEntry* block);
extern void VRAM_DeleteFreeBlock(struct _BlockVramEntry* block);
extern void VRAM_InsertUsedBlock(struct _BlockVramEntry* block);
extern void VRAM_DeleteUsedBlock(struct _BlockVramEntry* block);
extern struct _BlockVramEntry* VRAM_GetOpenBlock();
extern int VRAM_InsertFreeVram(short x, short y, short w, short h, int flags);
extern struct _BlockVramEntry* VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY);
extern void VRAM_ClearVramBlock(struct _BlockVramEntry *block);
extern void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, struct Object *object);
extern struct _BlockVramEntry* VRAM_InsertionSort(struct _BlockVramEntry *rootNode, struct _BlockVramEntry *newBlock);
extern void VRAM_RearrangeVramsLayer(long whichLayer);
extern void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2);
extern long VRAM_GetObjectVramSpace(long* addr, struct _ObjectTracker* objectTracker);
extern long VRAM_GetLevelVramSpace(long* addr, struct _StreamUnit* streamUnit);
extern void  VRAM_InitMorphPalettes();
extern void VRAM_UpdateMorphPalettes();
extern void MORPH_ChangeAreaPalettes(long time);

#endif