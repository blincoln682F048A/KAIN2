#ifndef STRMLOAD_H
#define STRMLOAD_H

extern int STREAM_IsCdBusy(long* numberInQueue);
extern int STREAM_PollLoadQueue();
extern long STREAM_QueueNonblockingLoads(char* fileName, unsigned char memType, void* retFunc, void* retData, void* retData2, void* *retPointer, long relocateBinary, long forceSize);
extern void LOAD_NonBlockingBinaryLoad(char* fileName, void* retFunc, void* retData, void* retData2, void* *retPointer, int memType);
extern void LOAD_NonBlockingFileLoad(char* fileName, void* retFunc, void* retData, void* retData2, void* *retPointer, int memType);
extern void LOAD_NonBlockingPartOfFileLoad(char* fileName, long forceSize, void* retFunc, void* retData, void* retData2, void* *retPointer, int memType);
extern void STREAM_CleanUpNonblockingBufferedLoad();
extern long LOAD_NonBlockingBufferedLoad(char* fileName, void* retFunc, void* retData1, void* retData2);

#endif