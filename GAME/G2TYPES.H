#ifndef G2TYPES_H
#define G2TYPES_H

#include <SYS\TYPES.H>
#include <LIBGTE.H>
#include <LIBGPU.H>
#include <LIBCD.H>
#include <LIBSPU.H>

typedef unsigned short PadData;

typedef struct
{
	unsigned short buttons;
	char xOffset;
	char yOffset;
} MouseData;

typedef struct
{
	unsigned short digitalButtons;
	char centralTwist;
	char buttonI;
	char buttonII;
	char topLeft;
} NegconData;

typedef struct
{
	unsigned char transStatus;
	unsigned char dataFormat;

	union
	{
		PadData    pad;
		NegconData negcon;
	}
	data;
} TapCtrllerData;

typedef struct
{
	TapCtrllerData ctrllers[4];
} MultiTapData;

typedef struct
{
	unsigned char transStatus;
	unsigned char dataFormat;

	union
	{
		PadData      pad;
		MouseData    mouse;
		NegconData   negcon;
		MultiTapData tap;
	}
	data;
} ControllerPacket;

enum _G2Bool_Enum 
{
	G2FALSE = 0,
};

struct _G2AppDataVM_Type
{
	int argc;
	int* argv;
};

struct NodeType
{
	struct NodeType* prev;
	struct NodeType* next;
};

struct fake97
{
	void* intro;
	long model;
};

struct AadInitAttr
{
	unsigned short updateMode;
	unsigned short numSlots;
	void(*nonBlockLoadProc)();
	void(*nonBlockBufferedLoadProc)();
	void *(*memoryMallocProc)();
	void(*memoryFreeProc)();
	unsigned char memMallocType;
	unsigned char unused1;
	unsigned short unused2;
};

struct Signal
{
	long id; // size=0, offset=0
	struct fake97 data; // size=24, offset=4
};

struct RedirectList
{
	long numPointers;
	long* data;
};

struct MATRIX {
	short m[3][3]; // size=18, offset=0
	long t[3]; // size=12, offset=20
};

struct _FX_MATRIX
{
	struct NodeType node;
	long flags;
	struct MATRIX lwTransform;
};

struct _Position {
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _FX_PRIM {
	struct NodeType node; // size=8, offset=0
	struct TextureMT3 *texture; // size=16, offset=8
	long flags; // size=0, offset=12
	long timeToLive; // size=0, offset=16
	void *process; // size=0, offset=20
	struct _FX_MATRIX *matrix; // size=44, offset=24
	long color; // size=0, offset=28
	long startColor; // size=0, offset=32
	long endColor; // size=0, offset=36
	short colorFadeValue; // size=0, offset=40
	short colorFadeStep; // size=0, offset=42
	struct _Position position; // size=6, offset=44
	short fadeStep; // size=0, offset=50
	short fadeValue[4]; // size=8, offset=52
	struct _Position v0; // size=6, offset=60
	short work0; // size=0, offset=66
	struct _Position v1; // size=6, offset=68
	short work1; // size=0, offset=74
	struct _Position v2; // size=6, offset=76
	short work2; // size=0, offset=82
	struct _Position v3; // size=6, offset=84
	short work3; // size=0, offset=90
	///union .206fake duo; // size=20, offset=92
	///struct .207fake ani; // size=12, offset=112
};

struct _FXTracker
{
	struct _FX_MATRIX matrixPool[32];
	struct NodeType usedMatrixList;
	struct NodeType freeMatrixList;
	struct _FX_PRIM primPool[256];
	struct NodeType usedPrimList;
	struct NodeType usedPrimListSprite;
	struct NodeType freePrimList;
};

struct _PolytopeList
{
	long numPolytopes;
	void* polytope[1024];
};

struct DebugMenuLine
{
	long type;
	long lower;
	long upper;
	char* text;
	long* var_address;
	long bit_mask;
};

struct _Rotation
{
	short x;
	short y;
	short z;
	short pad;
};

struct _PlaneConstants
{
	short a;
	short b;
	short c;
	short flags;
	long d;
};

struct _Normal
{
	short x;
	short y;
	short z;
	short pad;
};

struct _G2SVector3_Type
{
	short x;
	short y;
	short z;
};
struct _G2LVector3_Type
{
	long x;
	long y;
	long z;
};

struct _G2Matrix_Type
{
	short rotScale[3][3];
	short scaleFlag;
	struct _G2LVector3_Type trans;
};

struct _G2Quat_Type
{
	short x;
	short y;
	short z;
	short w;
};
struct _G2AnimQuatInfo_Type
{
	struct _G2Quat_Type srcQuat;
	struct _G2Quat_Type destQuat;
	struct _G2SVector3_Type srcScale;
	struct _G2SVector3_Type destScale;
	struct _G2SVector3_Type srcTrans;
	struct _G2SVector3_Type destTrans;
};

struct _G2AnimAlphaTable_Type
{
	unsigned short size;
	long data[0];
};

struct _G2AnimInterpStateBlock_Type
{
	struct _G2AnimInterpStateBlock_Type* next;
	struct _G2AnimQuatInfo_Type quatInfo[4];
};

struct _G2AnimInterpInfo_Type
{
	short duration;
	short targetTime;
	struct _G2AnimAlphaTable_Type* alphaTable;
	struct _G2AnimInterpStateBlock_Type* stateBlockList;
};

struct _G2AnimFxHeader_Type
{
	unsigned char sizeAndSection;
	char type;
	unsigned short keyframeID;
};

struct _G2AnimKeylist_Type
{
	unsigned char sectionCount;
	unsigned char s0TailTime;
	unsigned char s1TailTime;
	unsigned char s2TailTime;
	unsigned short keyCount;
	short timePerKey;
	unsigned short pad00;
	short pad01;
	unsigned short pad10;
	short pad11;
	struct _G2AnimFxHeader_Type* fxList;
	unsigned short *sectionData[0];
};

struct _G2AnimChanStatus_Type
{
	short keyData;
	short index;
};

struct _G2AnimChanStatusBlock_Type
{
	struct _G2AnimChanStatusBlock_Type* next;
	struct _G2AnimChanStatus_Type chunks[8];
};

struct _G2AnimSection_Type 
{
	unsigned char flags;
	unsigned char sectionID;
	unsigned char firstSeg;
	unsigned char segCount;
	short elapsedTime;
	short storedTime;
	short loopStartTime;
	short loopEndTime;
	short* swAlarmTable;
	long speedAdjustment;
	unsigned short keylistID;
	unsigned long alarmFlags;
	long(*callback)();
	void *callbackData;
	struct _G2AnimKeylist_Type* keylist;
	struct _G2AnimChanStatusBlock_Type* chanStatusBlockList;
	struct _G2AnimInterpInfo_Type* interpInfo;
};

struct _G2Anim_Type
{
	unsigned char sectionCount;
	unsigned char masterSection;
	unsigned short controllerList;
	unsigned short disabledControllerList;
	unsigned short pad;
	struct _G2SVector3_Type rootTrans;
	struct _Model* modelData;
	struct _G2Matrix_Type* segMatrices;
	unsigned long disabledBits[3];
	struct _G2AnimSection_Type section[3];
};

struct _ColorType
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char code;
};

struct gSoundData
{
	unsigned long gMasterVol;
	unsigned long gMusicVol;
	unsigned long gSfxVol;
	unsigned long gVoiceVol;
	char gSfxOn;
	char gMusicOn;
	char gVoiceOn;
	char soundsLoaded;
};

struct EventAliasCommandStruct
{
	struct _Instance* hostInstance;
	short newanim;
	short newframe;
	short interpframes;
};

struct SoundInstance
{
	unsigned char channel;
	unsigned char state;
	unsigned char delay;
};

struct _SVector
{
	short x;
	short y;
	short z;
	short pad;
};

struct _Instance
{
	struct NodeType node;
	struct _Instance* next;
	struct _Instance* prev;
	long instanceID;
	long flags;
	long flags2;
	struct Object* object;
	struct Intro* intro;
	void* data;
	void* introData;
	struct _Instance* parent;
	long introNum;
	long birthStreamUnitID;
	long currentStreamUnitID;
	long introUniqueID;
	struct MATRIX* matrix;
	struct MATRIX* oldMatrix;
	struct SoundInstance soundInstanceTbl[4];
	unsigned long maxCheckDistance;
	unsigned long checkMask;
	struct _Position position;
	unsigned char lightGroup;
	struct _Position oldPos;
	unsigned char spectralLightGroup;
	short currentTextureAnimFrame;
	struct _Position initialPos;
	struct _Rotation rotation;
	struct _Rotation oldRotation;
	struct _SVector scale;
	long attachedID;
	long attachedSegment;
	MATRIX relativeMatrix;
	struct _TFace* tface;
	struct _TFace* oldTFace;
	void* tfaceLevel;
	void* collideInfo;
	long bspTree;
	struct _Normal oldWNormal;
	struct _Normal wNormal;
	struct _SVector offset;
	void* dsignal;
	void* shadow0;
	void* shadow1;
	void* extraLight;
	struct _Position extraLightDir;
	short extraLightScale;
	struct _HModel* hModelList;
	short fadeValue;
	short lightMatrix;
	void(*processFunc)();
	void(*collideFunc)();
	void(*additionalCollideFunc)();
	void *additionalDrawFunc;
	unsigned long(*queryFunc)();
	void(*messageFunc)();
	struct _Position shadowPosition;
	short currentModel;
	struct _TFace* waterFace;
	struct _TFace* oldWaterFace;
	struct _Terrain* waterFaceTerrain;
	struct _PlaneConstants halvePlane;
	struct _SVector splitPoint;
	struct _Instance* LinkParent;
	struct _Instance* LinkChild;
	struct _Instance* LinkSibling;
	long ParentLinkNode;
	void* InstanceState;
	char introName[16];
	void* extraData;
	short constrictAngle;
	long xVel;
	long yVel;
	long zVel;
	long xAccl;
	long yAccl;
	long zAccl;
	long maxXVel;
	long maxYVel;
	long maxZVel;
	long currentMainState;
	long currentSubState;
	long work0;
	long work1;
	long work2;
	long work3;
	long work4;
	long work5;
	long work6;
	long work7;
	long work8;
	long work9;
	struct _G2Anim_Type anim;
	enum _G2Bool_Enum(*rebuildCallback)();
	short eventVariables[5];
	short splineFlags;
	short targetFrame;
	short clipBeg;
	short clipEnd;
	struct EventAliasCommandStruct aliasCommand;
	long light_color;
	struct CVECTOR* perVertexColor;
};

struct _InstanceList
{
	long numInstances;
	struct _Instance* first;
	struct _InstancePool* pool;
	struct NodeType group[32];
};

struct _InstancePool
{
	long nextInstanceID;
	long numFreeInstances;
	struct _Instance instance[60];
	struct _Instance* first_free;
};

struct Intro
{
	char name[16];
	long intronum;
	long UniqueID;
	struct _Rotation rotation;
	struct _Position position;
	short maxRad;
	long maxRadSq;
	long flags;
	void *data;
	struct _Instance *instance;
	struct MultiSpline *multiSpline;
	void *dsignal;
	short specturalLightGroup;
	short meshColor;
	struct _Position spectralPosition;
	short spad;
};

struct LightInstance
{
	struct _Instance* lightInstance;
	long r;
	long g;
	long b;
	short radius;
	unsigned char segment;
	unsigned char flags;
};

struct Object
{
	long oflags;
	short id;
	short snfFileID;
	short numModels;
	short numAnims;
	struct _Model** modelList;
	struct _G2AnimKeylist_Type** animList;
	short introDist;
	short vvIntroDist;
	short removeDist;
	short vvRemoveDist;
	void* data;
	char* script;
	char* name; 
	unsigned char* soundData;
	long oflags2;
	short sectionA;
	short sectionB;
	short sectionC;
	short numberOfEffects;
	struct ObjectEffect* effectList;
	unsigned long* relocList;
	void* relocModule;
};

struct PointLight
{
	struct NodeType node;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char flags;
	struct _Position position;
	short radius;
	long radiusSquared;
};

struct SpotLight
{
	struct NodeType node;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char flags;
	struct _Position centroid;
	short radius;
	long radiusSquared;
	struct _Position position;
	struct _Position direction;
	short cosFalloffAngle;
	short attenuationScale;

};

struct _PVertex
{
	short x;
	short y;
	long otz;
};

struct CVECTOR {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char cd;
};

struct _VertexPool
{
	struct _PVertex vertex[525];
	struct CVECTOR color[525];
};

struct LightInfo
{
	long numPointLights;
	struct PointLight pointLightPool[32];
	struct NodeType usedPointLightList;
	struct NodeType freePointLightList;
	struct NodeType activePointLightList;
	long numSpotLights;
	struct SpotLight spotLightPool[8];
	struct NodeType usedSpotLightList;
	struct NodeType freeSpotLightList;
	struct NodeType activeSpotLightList;
	long numSavedColors;
};

struct GameTracker
{
	long drawBackFaces;
	struct Level* level;
	struct Camera* camera;
	struct _Instance* playerInstance;
	long dispPage;
	short MorphTime;
	short MorphType;
	struct LightInstance lightInstances[1];
	long drawPage;
	struct _InstanceList* instanceList;
	struct _InstancePool* instancePool;
	struct _VertexPool* vertexPool;
	struct _PrimPool* primPool;
	struct _ObjectTracker* GlobalObjects;
	long controlCommand[2][5];
	long controlData[2][5];
	long overrideData[2][5];
	long debugFlags;
	long debugFlags2;
	CVECTOR wipeColor;
	short wipeTime;
	short maxWipeTime;
	short wipeType;
	short numGSignals;
	void* gSignal[16];
	struct LightInfo* lightInfo;
	void* reqDisp;
	long* drawTimerReturn;
	long usecsStartDraw;
	void* disp;
	unsigned long displayFrameCount;
	unsigned long frameCount;
	unsigned long vblFrames;
	unsigned long vblCount;
	long numMatrices;
	long gameFlags;
	long streamFlags;
	void* drawNonAnimatedSegmentFunc;
	void* drawAnimatedModelFunc;
	void* drawDisplayPolytopeListFunc;
	void* drawBgFunc;
	struct Level* mainDrawUnit;
	char baseAreaName[16];
	short levelDone;
	short levelChange;
	short hideBG;
	short gameMode;
	void* mirror;
	long currentHotSpot;
	long StreamUnitID;
	long SwitchToNewStreamUnit;
	char S_baseAreaName[16];
	short toSignal;
	short fromSignal;
	char LastSignal;
	short StreamNormalA;
	short StreamNormalB;
	short StreamNormalC;
	long StreamNormalD;
	struct _ColorType animObjLine;
	struct _ColorType animObjShade;
	long introFXTime;
	long maxIntroFXTime;
	struct gSoundData sound;
	short controllerMode;
	short cheatMode;
	char curDynamicSoundName[16];
	char currentLvl;
	char lastLvl;
	struct Object* introFX;
	struct Intro* introFXIntro;
	unsigned long** drawOT;
	unsigned long** dispOT;
	long introWaitTime;
	long mirrorZPush;
	long defVVRemoveDist;
	long defRemoveDist;
	struct _Position forcedStartPosition;
	short hudCollDisplay;
	long primMemUsed;
	char demoMode;
	char setDemoMode;
	char demoIndex;
	char demoEnabled;
	long cheatTimerCount;
	long playerCheatFlags;
	long savedPlayerCameraMode;
	long debugDrawFlags;
	void* planningPool;
	void* enemyPlanPool;
	short block_collide_override;
	short timeOfDay;
	long decoupleGame;
	long multGameTime;
	short spectral_fadeValue;
	short material_fadeValue;
	unsigned long drawTime;
	unsigned long currentTime;
	unsigned long currentMaterialTime;
	unsigned long currentSpectralTime;
	unsigned long lastLoopTime;
	unsigned long timeMult;
	unsigned long globalTimeMult;
	unsigned long spectralTimeMult;
	unsigned long materialTimeMult;
	unsigned long currentTicks;
	unsigned long totalTime;
	unsigned long idleTime;
	long visibleInstances;
	short frameRateLock;
	short frameRate24fps;
};

struct XAFileInfo {
	int startPos; // size=0, offset=0
};

struct CdCommand {
	unsigned short flags; // size=0, offset=0
	unsigned char unused; // size=0, offset=2
	unsigned char cdCommand; // size=0, offset=3
	unsigned char cdCmdParam[4]; // size=4, offset=4
};
struct VoiceCommand {
	unsigned char voiceCmd; // size=0, offset=0
	unsigned char nextVoiceStatus; // size=0, offset=1
	unsigned short voiceCmdParam; // size=0, offset=2
};

struct XAVoiceTracker {
	CdlLOC currentPos; // size=4, offset=0
	int currentSector; // size=0, offset=4
	int endSector; // size=0, offset=8
	void(*prevCallback)(); // size=0, offset=12
	unsigned char cdResult[8]; // size=8, offset=16
	struct CdCommand cdCmdQueue[8]; // size=64, offset=24
	unsigned short requestQueue[4]; // size=8, offset=88
	struct VoiceCommand voiceCmdQueue[16]; // size=64, offset=96
	unsigned char cdCmdIn; // size=0, offset=160
	unsigned char cdCmdOut; // size=0, offset=161
	unsigned char cdCmdsQueued; // size=0, offset=162
	unsigned char reqIn; // size=0, offset=163
	unsigned char reqOut; // size=0, offset=164
	unsigned char reqsQueued; // size=0, offset=165
	unsigned char voiceCmdIn; // size=0, offset=166
	unsigned char voiceCmdOut; // size=0, offset=167
	unsigned char voiceCmdsQueued; // size=0, offset=168
	unsigned char unused1; // size=0, offset=169
	unsigned char voiceStatus; // size=0, offset=170
	unsigned char cdStatus; // size=0, offset=171
	short fileNum; // size=0, offset=172
	short unused2; // size=0, offset=174
	struct XAFileInfo xaFileInfo[13]; // size=52, offset=176
};

struct MainTracker
{
	long mainState;
	long previousState;
	long movieNum;
	long done;
};

struct FileAccessInfo
{
	CdlLOC loc;
	unsigned long* dest;
	unsigned long* finalDest;
	long fileOffset;
	long blocks;
	long status;
	long checksum;
	long checksumType;
	long compressedLen;
	long bufferBlocks;
	long totalBlocks;
	long curBufferOffset;
	unsigned long* buffer1;
	unsigned long* buffer2;
	short bufferFlags;
	short currentBuffer;
	unsigned long* bufferRead;
	long numberOfBlocksRead;
	void* retFunc;
	void* retData;
	void* retData2;
	struct NonBlockLoadEntry* loadEntry;
};

struct BigFileFileInfo
{
	long fileHash;
	long fileLen;
	long compressedLen;
	long filePos;
	long checkSumFull;
	long checkSumBlocks;
};

struct BigFile
{
	long numFiles;
	long bigfileBaseOffset;
	struct BigFileFileInfo* contents;
};

struct LoadStatus
{
	struct FileAccessInfo loadQueue[4];
	struct FileAccessInfo* currentQueueFile;
	long currentQueueFileIndex;
	long currentQueueReqIndex;
	long waitingForSeek;
	long* waitingForData;
	long* waitingSector;
	long remSectors;
	long currentSector;
	long cdWaitTime;
	unsigned char* compSrcAddr;
	unsigned char* compDstAddr;
	long compControlbits;
	long compControl;
	long compEndBytes;
	long decompressLen;
	long checksum;
	long* checkAddr;
	struct BigFile bigFile;
};

struct NonBlockLoadEntry
{
	long filePos;
	long* loadAddr;
	long* finalDest;
	long* finalDest2;
	long compressedLength;
	long checksum;
	long checksumType;
	long compressed;
	long mallocedSize;
	long memType;
	long posInFile;
	long bufferSize;
	long fileSize;
	void* retFunc;
	void* retData;
	void* retData2;
};

struct _ObjectTracker
{
	char name[16];
	struct Object* object;
	short objectStatus;
	short numInUse;
	void* vramBlock;
	char numObjectsUsing;
	char objectsUsing[7];
};

struct AadTempoCounter {
	unsigned long currentTick; // size=0, offset=0
	unsigned long currentError; // size=0, offset=4
	unsigned long tickTimeFixed; // size=0, offset=8
	unsigned long errorPerUpdate; // size=0, offset=12
	unsigned short ticksPerUpdate; // size=0, offset=16
	unsigned short ppqn; // size=0, offset=18
	unsigned long quarterNoteTime; // size=0, offset=20
};
struct AadSeqEvent {
	unsigned long deltaTime; // size=0, offset=0
	unsigned char statusByte; // size=0, offset=4
	unsigned char dataByte[7]; // size=7, offset=5
};
struct _AadSequenceSlot {
	struct AadTempoCounter tempo; // size=24, offset=0
	struct AadSeqEvent eventQueue[16]; // size=192, offset=24
	unsigned char eventIn; // size=0, offset=216
	unsigned char eventOut; // size=0, offset=217
	unsigned short eventsInQueue; // size=0, offset=218
	unsigned long lastEventExecutedTime; // size=0, offset=220
	unsigned char *sequencePosition; // size=0, offset=224
	struct _AadSequenceSlot *selectedSlotPtr; // size=372, offset=228
	unsigned char selectedSlotNum; // size=0, offset=232
	unsigned char selectedChannel; // size=0, offset=233
	unsigned short sequenceNumberAssigned; // size=0, offset=234
	unsigned char thisSlotNumber; // size=0, offset=236
	unsigned char unused; // size=0, offset=237
	unsigned short status; // size=0, offset=238
	unsigned short flags; // size=0, offset=240
	unsigned short channelMute; // size=0, offset=242
	unsigned short enableSustainUpdate; // size=0, offset=244
	unsigned char slotVolume; // size=0, offset=246
	unsigned char slotPan; // size=0, offset=247
	unsigned char runningStatus; // size=0, offset=248
	unsigned char slotID; // size=0, offset=249
	unsigned char *masterVolPtr; // size=0, offset=252
	unsigned char selectedDynamicBank; // size=0, offset=256
	unsigned char sequenceAssignedDynamicBank; // size=0, offset=257
	unsigned char currentDynamicBank[16]; // size=16, offset=258
	unsigned short pitchWheel[16]; // size=32, offset=274
	unsigned char currentProgram[16]; // size=16, offset=306
	unsigned char baseProgram[16]; // size=16, offset=322
	unsigned char volume[16]; // size=16, offset=338
	unsigned char panPosition[16]; // size=16, offset=354
};
struct AadSfxCommand {
	unsigned char statusByte; // size=0, offset=0
	unsigned char dataByte[3]; // size=3, offset=1
	unsigned long ulongParam; // size=0, offset=4
	short shortParam; // size=0, offset=8
	unsigned short unused; // size=0, offset=10
};
struct AadSfxSlot {
	struct AadSfxCommand commandQueue[32]; // size=384, offset=0
	unsigned char commandIn; // size=0, offset=384
	unsigned char commandOut; // size=0, offset=385
	unsigned short commandsInQueue; // size=0, offset=386
	unsigned short handleCounter; // size=0, offset=388
	unsigned char sfxVolume; // size=0, offset=390
	unsigned char sfxPan; // size=0, offset=391
};
struct AadSoundBankHdr {
	unsigned long bankID; // size=0, offset=0
	unsigned long headerSize; // size=0, offset=4
	unsigned short bankVersion; // size=0, offset=8
	unsigned char numBanks; // size=0, offset=10
	unsigned char numPrograms; // size=0, offset=11
	unsigned short numTones; // size=0, offset=12
	unsigned short numWaves; // size=0, offset=14
	unsigned char numSequences; // size=0, offset=16
	unsigned char numPitchMaps; // size=0, offset=17
	unsigned short numLabels; // size=0, offset=18
	unsigned char reverbMode; // size=0, offset=20
	unsigned char unused1; // size=0, offset=21
	short reverbDepth; // size=0, offset=22
	unsigned short objectID; // size=0, offset=24
	unsigned short unused2; // size=0, offset=26
	unsigned long unused3; // size=0, offset=28
	unsigned long unused4; // size=0, offset=32
	unsigned long unused5; // size=0, offset=36
	unsigned long unused6; // size=0, offset=40
	unsigned long unused7; // size=0, offset=44
	unsigned long unused8; // size=0, offset=48
	unsigned long unused9; // size=0, offset=52
	unsigned long unused10; // size=0, offset=56
	unsigned long unused11; // size=0, offset=60
	unsigned long unused12; // size=0, offset=64
	unsigned long unused13; // size=0, offset=68
	unsigned long unused14; // size=0, offset=72
	unsigned long unused15; // size=0, offset=76
	unsigned char baseProgramTbl[16]; // size=16, offset=80
	unsigned short baseToneTbl[16]; // size=32, offset=96
};
struct AadProgramAtr {
	unsigned short numTones; // size=0, offset=0
	unsigned short firstTone; // size=0, offset=2
	unsigned char volume; // size=0, offset=4
	unsigned char panPosition; // size=0, offset=5
	unsigned short unused; // size=0, offset=6
};
struct AadToneAtr {
	unsigned char priority; // size=0, offset=0
	unsigned char parentProgram; // size=0, offset=1
	unsigned char volume; // size=0, offset=2
	unsigned char panPosition; // size=0, offset=3
	unsigned char centerNote; // size=0, offset=4
	char centerFine; // size=0, offset=5
	unsigned char minNote; // size=0, offset=6
	unsigned char maxNote; // size=0, offset=7
	unsigned char mode; // size=0, offset=8
	unsigned char pitchBendMax; // size=0, offset=9
	unsigned short adsr1; // size=0, offset=10
	unsigned short adsr2; // size=0, offset=12
	short waveIndex; // size=0, offset=14
};
struct _AadDynSfxFileHdr {
	unsigned long snfID; // size=0, offset=0
	unsigned short snfVersion; // size=0, offset=4
	unsigned short uniqueID; // size=0, offset=6
	unsigned short referenceCount; // size=0, offset=8
	unsigned short numSfxInFile; // size=0, offset=10
	struct _AadDynSfxFileHdr *prevDynSfxFile; // size=20, offset=12
	struct _AadDynSfxFileHdr *nextDynSfxFile; // size=20, offset=16
};
struct AadDynSfxAttr {
	unsigned short sfxID; // size=0, offset=0
	unsigned short waveID; // size=0, offset=2
	struct AadToneAtr toneAttr; // size=16, offset=4
	unsigned long waveSize; // size=0, offset=20
};
struct AadSynthVoice {
	unsigned long voiceMask; // size=0, offset=0
	unsigned long handle; // size=0, offset=4
	unsigned char voiceID; // size=0, offset=8
	unsigned char priority; // size=0, offset=9
	unsigned char note; // size=0, offset=10
	unsigned char program; // size=0, offset=11
	unsigned char baseProg; // size=0, offset=12
	unsigned char volume; // size=0, offset=13
	unsigned char updateVol; // size=0, offset=14
	unsigned char pan; // size=0, offset=15
	unsigned char voiceNum; // size=0, offset=16
	unsigned char unused; // size=0, offset=17
	unsigned short flags; // size=0, offset=18
	struct AadToneAtr *toneAtr; // size=16, offset=20
	struct AadProgramAtr *progAtr; // size=8, offset=24
};
struct AadDynamicLoadRequest {
	unsigned long type; // size=0, offset=0
	unsigned long userData; // size=0, offset=4
	char fileName[40]; // size=40, offset=8
	//union .135fake u; // size=4, offset=48
};
struct AadDynamicBankLoadInfo {
	char *sndFileName; // size=0, offset=0
	char *smpFileName; // size=0, offset=4
	unsigned short dynamicBankIndex; // size=0, offset=8
	unsigned short loadOption; // size=0, offset=10
	void(*userCallbackProc)(); // size=0, offset=12
	unsigned long sramDataSize; // size=0, offset=16
	unsigned long nextSramAddr; // size=0, offset=20
	unsigned long flags; // size=0, offset=24
};
struct AadDynamicSfxLoadInfo {
	char snfFileName[40]; // size=40, offset=0
	char smfFileName[40]; // size=40, offset=40
	unsigned long userData; // size=0, offset=80
	void(*userCallbackProc)(); // size=0, offset=84
	unsigned short flags; // size=0, offset=88
	unsigned short smfLoadingState; // size=0, offset=90
	unsigned long bytesToLoad; // size=0, offset=92
	unsigned short numSfxToLoad; // size=0, offset=96
	unsigned short error; // size=0, offset=98
	unsigned long waveTransferAddr; // size=0, offset=100
	unsigned long totalSramUsed; // size=0, offset=104
	struct _AadDynSfxFileHdr *snfFile; // size=20, offset=108
	struct AadDynSfxAttr attr; // size=24, offset=112
};
struct AadNewSramBlockDesc {
	unsigned short waveID; // size=0, offset=0
	unsigned short address; // size=0, offset=2
	unsigned short size; // size=0, offset=4
	unsigned char prevIndex; // size=0, offset=6
	unsigned char nextIndex; // size=0, offset=7
};
struct AadLoadedSfxToneAttr {
	unsigned short referenceCount; // size=0, offset=0
	unsigned short waveID; // size=0, offset=2
	struct AadToneAtr toneAttr; // size=16, offset=4
};
struct AadLoadedSfxWaveAttr {
	unsigned short referenceCount; // size=0, offset=0
	unsigned char unused; // size=0, offset=2
	unsigned char sramHandle; // size=0, offset=3
};
struct AadMasterVolFader {
	short volumeStep; // size=0, offset=0
	short targetVolume; // size=0, offset=2
	void(*fadeCompleteCallback)(); // size=0, offset=4
};
struct AadVolFader {
	short volumeStep; // size=0, offset=0
	short targetVolume; // size=0, offset=2
	void(*fadeCompleteCallback)(); // size=0, offset=4
};

struct AadNewSequenceHdr {
	unsigned long sequenceID; // size=0, offset=0
	unsigned long quarterNoteTime; // size=0, offset=4
	unsigned short ppqn; // size=0, offset=8
	unsigned short version; // size=0, offset=10
};
struct AadMemoryStruct {
	unsigned long updateCounter; // size=0, offset=0
	unsigned char numSlots; // size=0, offset=4
	unsigned char updateMode; // size=0, offset=5
	short masterVolume; // size=0, offset=6
	struct AadMasterVolFader masterVolFader; // size=8, offset=8
	unsigned char sfxMasterVol; // size=0, offset=16
	unsigned char musicMasterVol; // size=0, offset=17
	unsigned short flags; // size=0, offset=18
	struct AadVolFader musicMasterVolFader; // size=8, offset=20
	struct _AadSequenceSlot *sequenceSlots[8]; // size=32, offset=28
	struct AadSfxSlot sfxSlot; // size=392, offset=60
	struct AadSynthVoice synthVoice[24]; // size=672, offset=452
	char voiceStatus[24]; // size=24, offset=1124
	unsigned short voicePitchSave[24]; // size=48, offset=1148
	unsigned long voiceKeyOffRequest; // size=0, offset=1196
	unsigned long voiceKeyOnRequest; // size=0, offset=1200
	unsigned long voiceReverbRequest; // size=0, offset=1204
	struct AadSoundBankHdr *dynamicSoundBankHdr[2]; // size=8, offset=1208
	struct AadProgramAtr *dynamicProgramAtr[2]; // size=8, offset=1216
	struct AadToneAtr *dynamicToneAtr[2]; // size=8, offset=1224
	unsigned long *dynamicWaveAddr[2]; // size=8, offset=1232
	unsigned char **dynamicSequenceAddressTbl[2]; // size=8, offset=1240
	unsigned long *dynamicSequenceLabelOffsetTbl[2]; // size=8, offset=1248
	unsigned char dynamicBankStatus[2]; // size=2, offset=1256
	unsigned char *dynamicSoundBankData[2]; // size=8, offset=1260
	unsigned long dynamicSoundBankSramData[2]; // size=8, offset=1268
	unsigned long dynamicSoundBankSramDataSize[2]; // size=8, offset=1276
	unsigned char dynamicSoundBankLoadOption[2]; // size=2, offset=1284
	struct AadDynamicLoadRequest loadRequestQueue[8]; // size=416, offset=1288
	struct AadDynamicBankLoadInfo dynamicBankLoadInfo; // size=28, offset=1704
	unsigned char *loadBufferAddress; // size=0, offset=1732
	unsigned long loadBufferSize; // size=0, offset=1736
	void(*nonBlockLoadProc)(); // size=0, offset=1740
	void(*nonBlockBufferedLoadProc)(); // size=0, offset=1744
	void *(*memoryMallocProc)(); // size=0, offset=1748
	void(*memoryFreeProc)(); // size=0, offset=1752
	unsigned char memMallocType; // size=0, offset=1756
	unsigned char nextLoadReqIn; // size=0, offset=1757
	unsigned char nextLoadReqOut; // size=0, offset=1758
	unsigned char numLoadReqsQueued; // size=0, offset=1759
	unsigned long fixedSoundBankSramStart; // size=0, offset=1760
	unsigned long fixedSoundBankSramSize; // size=0, offset=1764
	unsigned long nextSramFreeFromBot; // size=0, offset=1768
	unsigned long lastSramUsedFromTop; // size=0, offset=1772
	struct AadDynamicSfxLoadInfo dynamicSfxLoadInfo; // size=136, offset=1776
	struct _AadDynSfxFileHdr *firstDynSfxFile; // size=20, offset=1912
	unsigned char sfxToneMasterList[512]; // size=512, offset=1916
	unsigned char sfxWaveMasterList[512]; // size=512, offset=2428
	struct AadLoadedSfxToneAttr sfxToneAttrTbl[128]; // size=2560, offset=2940
	struct AadLoadedSfxWaveAttr sfxWaveAttrTbl[128]; // size=512, offset=5500
	unsigned short nextToneIndex; // size=0, offset=6012
	unsigned short nextWaveIndex; // size=0, offset=6014
	struct AadNewSramBlockDesc sramDescriptorTbl[128]; // size=1024, offset=6016
	unsigned short nextSramDescIndex; // size=0, offset=7040
	unsigned char firstSramBlockDescIndex; // size=0, offset=7042
	unsigned char unused; // size=0, offset=7043
	void(*controller11Callback)(); // size=0, offset=7044
	void(*endSequenceCallback)(); // size=0, offset=7048
	long controller11CallbackData; // size=0, offset=7052
	long endSequenceCallbackData; // size=0, offset=7056
	unsigned char userVariables[128]; // size=128, offset=7060
};
struct AadTempo {
	unsigned long quarterNoteTime; // size=0, offset=0
	unsigned short ppqn; // size=0, offset=4
};
struct AadSlotAttributes {
	unsigned short sequenceNumberAssigned; // size=0, offset=0
	unsigned short sequenceAssignedDynamicBank; // size=0, offset=2
	unsigned short playingStatus; // size=0, offset=4
	unsigned short channelMute; // size=0, offset=6
	unsigned char slotVolume; // size=0, offset=8
	unsigned char slotPan; // size=0, offset=9
	unsigned short eventsInQueue; // size=0, offset=10
};

struct __EngagedInstance {
	struct _Instance *instance; // size=672, offset=0
	unsigned long distance; // size=0, offset=4
};

struct __FitPoint {
	short x; // size=0, offset=0
	short y; // size=0, offset=2
};

struct __GlyphHudSaveData {
	short MANNA_Count; // size=0, offset=0
	short HUD_Count; // size=0, offset=2
};

struct __SensoryData {
	int Flags; // size=0, offset=0
	struct _SVector ForwardNormal; // size=8, offset=4
	struct _SVector AboveNormal; // size=8, offset=12
	struct _SVector BelowNormal; // size=8, offset=20
	struct _SVector BelowPoint; // size=8, offset=28
	struct _SVector Delta; // size=8, offset=36
	struct _Instance *HitMonster; // size=672, offset=44
	struct _Instance *CurrentAutoFace; // size=672, offset=48
	struct _Instance *LastAutoFace; // size=672, offset=52
	struct __EngagedInstance *EngagedList; // size=8, offset=56
	unsigned long EngagedMask; // size=0, offset=60
	struct _Position lookAtPoint; // size=6, offset=64
};

struct _Vector {
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct __Force {
	int Type; // size=0, offset=0
	struct _Vector LinearForce; // size=12, offset=4
	short Friction; // size=0, offset=16
};

struct _G2AnimChanStatusBlockPool_Type {
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimChanStatusBlock_Type *blockPool; // size=36, offset=12
};

struct _G2AnimControllerPool_Type {
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimController_Type *blockPool; // size=36, offset=12
};

struct _G2AnimInterpStateBlockPool_Type {
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimInterpStateBlock_Type *blockPool; // size=164, offset=12
};

struct __Event {
	int ID; // size=0, offset=0
	int Data; // size=0, offset=4
};

struct __MessageQueue {
	int Head; // size=0, offset=0
	int Tail; // size=0, offset=4
	struct __Event Queue[16]; // size=128, offset=8
};

struct __State {
	void(*Process)(); // size=0, offset=0
	struct __MessageQueue Event; // size=136, offset=4
	struct __MessageQueue Defer; // size=136, offset=140
	int Data1; // size=0, offset=276
	int Data2; // size=0, offset=280
};

struct __CharacterState {
	struct _Instance *CharacterInstance; // size=672, offset=0
	int TotalSections; // size=0, offset=4
	struct __State SectionList[3]; // size=852, offset=8
};

struct __Player {
	struct __CharacterState State; // size=860, offset=0
	int Mode; // size=0, offset=860
	int RotationSegment; // size=0, offset=864
	struct _SVector iVelocity; // size=8, offset=868
	int Magnitude; // size=0, offset=876
	int input; // size=0, offset=880
	int lastInput; // size=0, offset=884
	int ZDirection; // size=0, offset=888
	short Bearing; // size=0, offset=892
	short LastBearing; // size=0, offset=894
	int steeringMode; // size=0, offset=896
	short steeringVelocity; // size=0, offset=900
	short steeringAcceleration; // size=0, offset=902
	int steeringLockRotation; // size=0, offset=904
	int movementMinRate; // size=0, offset=908
	short movementMinAnalog; // size=0, offset=912
	short movementMaxAnalog; // size=0, offset=914
	struct __SensoryData Senses; // size=72, offset=916
	struct _Instance *attachedPlatform; // size=672, offset=988
	short HealthScale; // size=0, offset=992
	short HealthBalls; // size=0, offset=994
	int HitPoints; // size=0, offset=996
	int DamageFrequency; // size=0, offset=1000
	int Abilities; // size=0, offset=1004
	struct _Instance *GlyphSystem; // size=672, offset=1008
	int GlyphManaBalls; // size=0, offset=1012
	struct __FitPoint *constrictData; // size=4, offset=1016
	short constrictIndex; // size=0, offset=1020
	short constrictWaitIndex; // size=0, offset=1022
	struct _SVector constrictCenter; // size=8, offset=1024
	short constrictFlag; // size=0, offset=1032
	short constrictGoodCircle; // size=0, offset=1034
	unsigned long constrictXTotal; // size=0, offset=1036
	unsigned long constrictYTotal; // size=0, offset=1040
	struct _Instance *soulReaver; // size=672, offset=1044
	unsigned long currentSoulReaver; // size=0, offset=1048
	int CurrentPlane; // size=0, offset=1052
	int slipSlope; // size=0, offset=1056
	unsigned long idleCount; // size=0, offset=1060
	struct _Instance *idleInstance; // size=672, offset=1064
	struct __AttackItem *attack; // size=36, offset=1068
	int attackFlags; // size=0, offset=1072
	struct _Instance *attackCurrentHit; // size=672, offset=1076
	struct _Instance *attackLastHit; // size=672, offset=1080
	struct _FXGlowEffect *glowEffect; // size=44, offset=1084
	struct _Instance *attackedBy; // size=672, offset=1088
	struct __ThrowItem *throwData; // size=32, offset=1092
	int throwMode; // size=0, offset=1096
	struct _Position throwTarget; // size=6, offset=1100
	struct _Instance *throwInstance; // size=672, offset=1108
	short throwXRot; // size=0, offset=1112
	short throwZRot; // size=0, offset=1114
	void(*returnState)(); // size=0, offset=1116
	unsigned long passedMask; // size=0, offset=1120
	struct _G2SVector3_Type extraRot; // size=6, offset=1124
	int effectsFlags; // size=0, offset=1132
	short effectsFadeSource; // size=0, offset=1136
	short effectsFadeDest; // size=0, offset=1138
	int effectsFadeStep; // size=0, offset=1140
	int effectsFadeSteps; // size=0, offset=1144
	short autoFaceZone; // size=0, offset=1148
	short autoFaceAngle; // size=0, offset=1150
	int autoFaceLastRootAngle; // size=0, offset=1152
	int autoFaceRootAngle; // size=0, offset=1156
	int autoFaceTrueAngle; // size=0, offset=1160
	int autoFaceAnim; // size=0, offset=1164
	int autoFaceLastAnim; // size=0, offset=1168
	int nothingCounter; // size=0, offset=1172
	int timeAccumulator; // size=0, offset=1176
	struct _Instance *possessed; // size=672, offset=1180
	int possessedCheckMask; // size=0, offset=1184
	struct _Position puppetMoveToPoint; // size=6, offset=1188
	int soundModifier; // size=0, offset=1196
	short alarmTable; // size=0, offset=1200
	short terminator; // size=0, offset=1202
	short swimSpeedAdjustment; // size=0, offset=1204
	short swimTargetSpeed; // size=0, offset=1206
};

struct _MonsterFunctionTable {
	void(*initFunc)(); // size=0, offset=0
	void(*cleanUpFunc)(); // size=0, offset=4
	void(*damageEffectFunc)(); // size=0, offset=8
	unsigned long(*queryFunc)(); // size=0, offset=12
	void(*messageFunc)(); // size=0, offset=16
	struct _MonsterStateChoice *stateFuncs; // size=12, offset=20
	char *versionID; // size=0, offset=24
	char *localVersionID; // size=0, offset=28
};

struct _MonsterState {
	void(*entryFunction)(); // size=0, offset=0
	void(*stateFunction)(); // size=0, offset=4
};

struct burntTuneType {
	int burntDist; // size=0, offset=0
	int fadeDelta; // size=0, offset=4
};

struct _SavedCinematic {
	struct _Position position; // size=6, offset=0
	struct _Position focusPoint; // size=6, offset=6
	struct _Position base; // size=6, offset=12
	struct _Position targetPos; // size=6, offset=18
	struct _Position targetFocusPoint; // size=6, offset=24
	struct _Position targetBase; // size=6, offset=30
	struct _Rotation baseRot; // size=8, offset=36
	struct _Rotation focusRotation; // size=8, offset=44
	struct _Rotation targetFocusRotation; // size=8, offset=52
	short focusDistance; // size=0, offset=60
	short targetFocusDistance; // size=0, offset=62
	struct _SVector focusPointVel; // size=8, offset=64
	struct _SVector focusPointAccl; // size=8, offset=72
	struct _SVector baseVel; // size=8, offset=80
	struct _SVector baseAccl; // size=8, offset=88
	long maxVel; // size=0, offset=96
	struct MultiSpline *posSpline; // size=0, offset=100
	struct MultiSpline *targetSpline; // size=0, offset=104
	struct Level *level; // size=0, offset=108
};

struct _Sphere {
	struct _Position position; // size=6, offset=0
	unsigned short radius; // size=0, offset=6
	unsigned long radiusSquared; // size=0, offset=8
};

struct DVECTOR {
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
};

struct EventTimer {
	long flags : 1; // offset=0.0
	long time : 31; // offset=0.1
	struct Event *event; // size=28, offset=4
	struct ScriptPCode *actionScript; // size=8, offset=8
	short *scriptPos; // size=0, offset=12
	struct Level *level; // size=372, offset=16
	long nextEventIndex; // size=0, offset=20
};

struct LoadQueueEntry {
	long fileId; // size=0, offset=0
	short status; // size=0, offset=4
	short relocateBinary; // size=0, offset=6
	void *retFunc; // size=0, offset=8
	void *retData; // size=0, offset=12
	void *retData2; // size=0, offset=16
	void **retPointer; // size=0, offset=20
	struct NonBlockLoadEntry loadEntry; // size=64, offset=24
};

struct MissileGraphics {
	unsigned char object; // size=0, offset=0
	unsigned char model; // size=0, offset=1
};

struct NewMemTracker {
	struct MemHeader *rootNode; // size=8, offset=0
	unsigned long totalMemory; // size=0, offset=4
	unsigned long currentMemoryUsed; // size=0, offset=8
	char *lastMemoryAddress; // size=0, offset=12
	long doingGarbageCollection; // size=0, offset=16
};

struct PoolManagementData {
	char state; // size=0, offset=0
	unsigned char numNodesInPool; // size=0, offset=1
	struct _Position playerPosAtLastPlanMkrUpdate; // size=6, offset=2
	struct PlanningNode *expansionNode1; // size=28, offset=8
	struct PlanningNode *expansionNode2; // size=28, offset=12
	unsigned short *distanceMatrix[32]; // size=4, offset=16
	unsigned short pairType; // size=0, offset=20
	struct _Position peakPos; // size=6, offset=22
	unsigned char currentNode; // size=0, offset=28
	unsigned char currentBit; // size=0, offset=29
};

struct RadarInfo {
	short angle; // size=0, offset=0
	short x; // size=0, offset=2
	short y; // size=0, offset=4
};

struct SavedInfoTracker {
	char *InfoStart; // size=0, offset=0
	char *InfoEnd; // size=0, offset=4
	char *EndOfMemory; // size=0, offset=8
};

struct SVECTOR {
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
	short vz; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct WaterLevelProcess {
	long flags; // size=0, offset=0
	struct BSPTree *bspTree; // size=36, offset=4
	struct _StreamUnit *streamUnit; // size=0, offset=8
	short oldWaterZ; // size=0, offset=12
	short oldGlobalOffset; // size=0, offset=14
	short zValueFrom; // size=0, offset=16
	short zValueTo; // size=0, offset=18
	short maxSteps; // size=0, offset=20
	short curStep; // size=0, offset=22
};

struct Camera {
	struct _Position position; // size=6, offset=0
	short pad1; // size=0, offset=6
	struct MATRIX vvNormalWorVecMat[2]; // size=64, offset=8
	long vvPlaneConsts[6]; // size=24, offset=72
	struct MATRIX *wcTransform; // size=32, offset=96
	struct MATRIX *wcTransform2; // size=32, offset=100
	struct MATRIX *cwTransform2; // size=32, offset=104
	struct _Normal viewVolumeNormal[5]; // size=40, offset=108
	long projDistance; // size=0, offset=148
	long projWidth; // size=0, offset=152
	long projHeight; // size=0, offset=156
	struct _SVector screenScale; // size=8, offset=160
	short shake; // size=0, offset=168
	short shakeScale; // size=0, offset=170
	long nearPlane; // size=0, offset=172
	long farPlane; // size=0, offset=176
	long flags; // size=0, offset=180
	long lock; // size=0, offset=184
	short mode; // size=0, offset=188
	short state; // size=0, offset=190
	short posState; // size=0, offset=192
	short rotState; // size=0, offset=194
	short tiltState; // size=0, offset=196
	short distanceState; // size=0, offset=198
	struct _Rotation rotation; // size=8, offset=200
	short lagZ; // size=0, offset=208
	short tilt; // size=0, offset=210
	struct _Position focusPoint; // size=6, offset=212
	short focusDistance; // size=0, offset=218
	struct _Instance *focusInstance; // size=672, offset=220
	struct _Position oldFocusInstancePos; // size=6, offset=224
	struct _Position newFocusInstancePos; // size=6, offset=230
	struct _Rotation oldFocusInstanceRot; // size=8, offset=236
	struct _Rotation newFocusInstanceRot; // size=8, offset=244
	struct _SVector focusInstanceVelVec; // size=8, offset=252
	struct _Position focusLeadPivot; // size=6, offset=260
	struct _Position focusOffset; // size=6, offset=266
	struct _Rotation focusRotation; // size=8, offset=272
	short tiltVel; // size=0, offset=280
	short tiltAccl; // size=0, offset=282
	struct _SVector positionVel; // size=8, offset=284
	struct _SVector positionAccl; // size=8, offset=292
	struct _SVector focusPointVel; // size=8, offset=300
	struct _SVector focusPointAccl; // size=8, offset=308
	short focusDistanceVel; // size=0, offset=316
	short focusDistanceAccl; // size=0, offset=318
	struct _SVector focusRotVel; // size=8, offset=320
	struct _SVector focusRotAccl; // size=8, offset=328
	struct _SVector maxFocusVel; // size=8, offset=336
	struct _SVector rotationVel; // size=8, offset=344
	struct _SVector rotationAccl; // size=8, offset=352
	short maxVel; // size=0, offset=360
	short maxRot; // size=0, offset=362
	struct _Position targetPos; // size=6, offset=364
	short targetTilt; // size=0, offset=370
	struct _Rotation targetRotation; // size=8, offset=372
	short targetFocusDistance; // size=0, offset=380
	struct _Position targetFocusPoint; // size=6, offset=382
	short collisionTargetFocusDistance; // size=0, offset=388
	struct _Rotation targetFocusRotation; // size=8, offset=390
	short tfaceTilt; // size=0, offset=398
	struct _Rotation collisionTargetFocusRotation; // size=8, offset=400
	short smooth; // size=0, offset=408
	struct _CameraKey *cameraKey; // size=24, offset=412
	struct _Sphere focusSphere; // size=12, offset=416
	struct _Sphere smallBaseSphere; // size=12, offset=428
	struct _Sphere posSphere; // size=12, offset=440
	short lookTimer; // size=0, offset=452
	short lookSavedMode; // size=0, offset=454
	short presetIndex; // size=0, offset=456
	short presetFocusDistance[3]; // size=6, offset=458
	long minFocusDistance; // size=0, offset=464
	long maxFocusDistance; // size=0, offset=468
	long minTilt; // size=0, offset=472
	long maxTilt; // size=0, offset=476
	long pad[3]; // size=12, offset=480
	long minXYDist; // size=0, offset=492
	long maxXYDist; // size=0, offset=496
	long oppositeError; // size=0, offset=500
	long tempsplinePointAhead; // size=0, offset=504
	long noTeleport; // size=0, offset=508
	long focusDistanceList[3][3]; // size=36, offset=512
	long tiltList[3][3]; // size=36, offset=548
	long cineControl; // size=0, offset=584
	short stack; // size=0, offset=588
	short targetStack; // size=0, offset=590
	long savedMode[3]; // size=12, offset=592
	long savedTargetFocusDistance[3]; // size=12, offset=604
	struct _Rotation savedFocusRotation; // size=8, offset=616
	short savedFocusDistance; // size=0, offset=624
	short signalFocusDistance; // size=0, offset=626
	struct _SavedCinematic savedCinematic[3]; // size=336, offset=628
	struct _Rotation savedfocusRotation; // size=8, offset=964
	struct _Position signalPos; // size=6, offset=972
	short pad11; // size=0, offset=978
	struct _Rotation signalRot; // size=8, offset=980
	struct _Position debugPos; // size=6, offset=988
	short pad4; // size=0, offset=994
	struct _Rotation debugRot; // size=8, offset=996
	struct _Position nondebugPos; // size=6, offset=1004
	short forced_movement; // size=0, offset=1010
	short last_forced_movement; // size=0, offset=1012
	short rotDirection; // size=0, offset=1014
	unsigned long lastModTime; // size=0, offset=1016
	struct _Rotation lookRot; // size=8, offset=1020
	struct MultiSpline *Spline00; // size=0, offset=1028
	struct MultiSpline *Spline01; // size=0, offset=1032
	///@FIXME union? struct .107fake data; // size=96, offset=1036
	long cuckooTimer; // size=0, offset=1132
	short teleportZRot; // size=0, offset=1136
	short extraZRot; // size=0, offset=1138
	short extraXRot; // size=0, offset=1140
	short leftTimer; // size=0, offset=1142
	short rightTimer; // size=0, offset=1144
	short collideRotControl; // size=0, offset=1146
	short collision_lastPush; // size=0, offset=1148
	short collision_timer; // size=0, offset=1150
	long halfwidth_per_z; // size=0, offset=1152
	long halfheight_per_z; // size=0, offset=1156
	unsigned long instance_mode; // size=0, offset=1160
	long instance_xyvel; // size=0, offset=1164
	long instance_prev_xyvel; // size=0, offset=1168
	struct _Position real_focuspoint; // size=6, offset=1172
	short always_rotate_flag; // size=0, offset=1178
	short follow_flag; // size=0, offset=1180
	short actual_x_rot; // size=0, offset=1182
	short actual_vel_x; // size=0, offset=1184
	short actual_acc_x; // size=0, offset=1186
	short x_rot_change; // size=0, offset=1188
	short focuspoint_fallz; // size=0, offset=1190
	short lead_angle; // size=0, offset=1192
	short lead_vel; // size=0, offset=1194
	short lead_accl; // size=0, offset=1196
	short lead_timer; // size=0, offset=1198
};


struct _BlockVramEntry {
	struct _BlockVramEntry *next; // size=28, offset=0
	unsigned char type; // size=0, offset=4
	unsigned char flags; // size=0, offset=5
	short time; // size=0, offset=6
	long ID; // size=0, offset=8
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short w; // size=0, offset=16
	short h; // size=0, offset=18
	long area; // size=0, offset=20
	///@FIXME union union .244fake udata; // size=4, offset=24
};

extern char *BufferLoadPtr1; // offset 0x800BFEEC
extern char *BufferLoadPtr2; // offset 0x800BFEF0
extern char *missionText[1]; // offset 0x800B5BE0
extern char *primBase; // offset 0x800C188C
extern char *selectMenuText[5]; // offset 0x800B5BE4
extern char *voiceFileList[13]; // offset 0x800C0434
extern char GlobalLevelVramName[80]; // offset 0x800C2450
extern char HashExtensions[7][4]; // offset 0x800BF0DC
extern char mainOptionsInit; // offset 0x800BF10C
extern char monVersion[12]; // offset 0x800C0414
extern char soundBuffer[8676]; // offset 0x800C57F0
extern char strFadeBoxDim[8]; // offset 0x800BE4AC
extern int _ramsize; // offset 0x800BF104
extern int _stacksize; // offset 0x800BF108
extern int AutoFaceAngle; // offset 0x800C55E0
extern int ControlFlag; // offset 0x800C55E4
extern int currentIdleCount; // offset 0x800C035C
extern int currentIdleListCount; // offset 0x800C0358
extern int devstation; // offset 0x800C1B40
extern int fontDistance; // offset 0x800BEFF0
extern int InStreamUnit; // offset 0x800C1784
extern int LoopCounter; // offset 0x800C0328
extern int nosound; // offset 0x800BF114
extern int pcverify; // offset 0x800BF110
extern int SAVE_OTZ; // offset 0x800C2920
extern long *controlsScreen; // offset 0x800C1AF4
extern long *mainMenuScreen; // offset 0x800C1F6C
extern long camera_modeToIndex[15]; // offset 0x800BE87C
extern long cameraMode; // offset 0x800BEFFC
extern long campoint_hh; // offset 0x800C0CB0
extern long campoint_hw; // offset 0x800C0CAC
extern long cheatCodeLastCommand; // offset 0x800BE4B8
extern long cheatCodeStage; // offset 0x800BE4B4
extern long cheatCombo[6]; // offset 0x800BE4BC
extern long collide_acceptAttr; // offset 0x800BEF74
extern long collide_ignoreAttr; // offset 0x800BEF70
extern long collide_t0; // offset 0x800C0F00
extern long collide_t1; // offset 0x800C0F04
extern long CurrentWarpNumber; // offset 0x800BFC34
extern long debug_cameraMode; // offset 0x800BD610
extern long debugFogBlu; // offset 0x800BD630
extern long debugFogFar; // offset 0x800BD61C
extern long debugFogGrn; // offset 0x800BD62C
extern long debugFogNear; // offset 0x800BD620
extern long debugFogRed; // offset 0x800BD628
extern long debugGameTime; // offset 0x800BD624
extern long debugVoiceIndex; // offset 0x800BD614
extern long DoMainMenu; // offset 0x800BF118
extern long draw_belowSplit; // offset 0x800BEFA0
extern long dyna_clddyna[8]; // offset 0x800BEF10
extern long dyna_cldstat[8]; // offset 0x800BEF50
extern long eventListNumInstances[20]; // offset 0x800C2A7C
extern long FOG_Color; // offset 0x800C24A0
extern long FRAC_BITS; // offset 0x800BF690
extern long FX_ColorArray[6]; // offset 0x800BF6DC
extern long gDummyCommand[2][2]; // offset 0x800C1934
extern long gTimerEnabled; // offset 0x800BF47C
extern long mainMenuMode; // offset 0x800BF11C
extern long menuPauseSel; // offset 0x800BD60C
extern long modelDQP; // offset 0x800C0F20
extern long MORPH_A_Component; // offset 0x800C24C8
extern long MORPH_B_Component; // offset 0x800C24CC
extern long numOfBlocksUsed; // offset 0x800C4628
extern long playerCameraMode; // offset 0x800BF000
extern long RazielCommands[10]; // offset 0x800C00E8
extern long SaveArraySize[6]; // offset 0x800C03FC
extern long signal_gexCurrentMainState; // offset 0x800BE8F4
extern long signal_logicValue[36]; // offset 0x800BE8F8
extern long SignalEndGame; // offset 0x800BE9A0
extern long stat_clddyna[8]; // offset 0x800BEF30
extern long VRAM_NeedToUpdateMorph; // offset 0x800C013C
extern long WaterInUse; // offset 0x800BFF0C
extern short aadStepsPerSemitone[85]; // offset 0x800BFB88
extern short AXIS_LENGTH; // offset 0x800BE7BC
extern short debugOrgFogFar; // offset 0x800C06D4
extern short debugOrgFogNear; // offset 0x800C06C0
extern short fontScale; // offset 0x800BEFEA
extern short fontScaleFrac; // offset 0x800BEFEC
extern short forceDrawInFront; // offset 0x800BEF9C
extern short identityMatrix[3][3]; // offset 0x800BF418
extern short M_TrackClutUpdate; // offset 0x800C4624
extern short mainMenuFadeInTime; // offset 0x800BF120
extern short mainMenuTimeOut; // offset 0x800C1C80
extern short playerMissionSelection; // offset 0x800BF0F8
extern short RENDER_currentStreamUnitID; // offset 0x800C1880
extern short signal_tagTimer; // offset 0x800BE988
extern short signal_tagTimerIndex; // offset 0x800BE98A
extern struct __Idle **currentIdleList; // offset 0x800C0354
extern struct _BlockVramEntry *FONT_vramBlock; // offset 0x800C1124
extern struct _BlockVramEntry *openVramBlocks; // offset 0x800C464C
extern struct _BlockVramEntry *usedVramBlocks; // offset 0x800C4648
extern struct _BlockVramEntry TerrainVramBlock; // offset 0x800C462C
extern struct _BlockVramEntry vramBlockList[75]; // offset 0x800C3DF0
extern struct _ButtonTexture BexitLine[2]; // offset 0x800C1AF8
extern struct _ButtonTexture BmenuLines[3][2]; // offset 0x800C1BFC
extern struct _ButtonTexture PauseButtons[4][2]; // offset 0x800C1EEC
extern struct _FXBlastringEffect *fx_blastring; // offset 0x800C0178
extern struct _FXTracker *fxTracker; // offset 0x800C1888
extern struct _FXTracker *gFXT; // offset 0x800C1780
extern struct _GlobalSaveTracker GlobalSave; // offset 0x800C039C
extern struct _Instance *collide_boxInstance; // offset 0x800BEF78
extern struct _Instance *eventListArray[20][10]; // offset 0x800C2ACC
extern struct _Mirror GlobalMirror; // offset 0x800C0CB4
extern struct _MonsterFunctionTable HUMAN_FunctionTable; // offset 0x800C0184
extern struct _MonsterFunctionTable HUNTER_FunctionTable; // offset 0x800C01A4
extern struct _MonsterFunctionTable SKINNER_FunctionTable; // offset 0x800C0270
extern struct _MonsterFunctionTable SLUAGH_FunctionTable; // offset 0x800C0290
extern struct _MonsterFunctionTable SOUL_FunctionTable; // offset 0x800C02B8
extern struct _MonsterFunctionTable VWRAITH_FunctionTable; // offset 0x800C02D8
extern struct _MonsterFunctionTable WORSHIP_FunctionTable; // offset 0x800C02F8
extern struct _MonsterStateChoice HUMAN_StateChoiceTable[6]; // offset 0x800B65A8
extern struct _MonsterStateChoice HUNTER_StateChoiceTable[6]; // offset 0x800B65F0
extern struct _MonsterStateChoice SKINNER_StateChoiceTable[4]; // offset 0x800B67A0
extern struct _MonsterStateChoice SLUAGH_StateChoiceTable[4]; // offset 0x800B67D0
extern struct _MonsterStateChoice SOUL_StateChoiceTable[7]; // offset 0x800B6800
extern struct _MonsterStateChoice VWRAITH_StateChoiceTable[6]; // offset 0x800B6860
extern struct _MonsterStateChoice WORSHIP_StateChoiceTable[5]; // offset 0x800B68A8
extern struct _Normal gNormalList[244]; // offset 0x800B5E04
extern struct _SVector *collide_normal0; // offset 0x800C0F14
extern struct _SVector *collide_normal1; // offset 0x800C0F18
extern struct _SVector *collide_point0; // offset 0x800C0EF8
extern struct _SVector *collide_point1; // offset 0x800C0EFC
extern struct _SVector collide_localPoint; // offset 0x800C0F08
extern struct _Terrain *light_terrain; // offset 0x800C194C
extern struct _TFace *MORPH_SavedFace; // offset 0x800C291C
extern struct _TVertex C_tvertex0; // offset 0x800C24A4
extern struct _TVertex C_tvertex1; // offset 0x800C24B0
extern struct _TVertex C_tvertex2; // offset 0x800C24BC
extern struct _Vector MORPH_BasePoint; // offset 0x800C24D0
extern struct AadMemoryStruct *aadMem; // offset 0x800BF774
extern struct BLK_FILL AuxClearRect[10]; // offset 0x800C17E0
extern struct BLK_FILL clearRect; // offset 0x800C1C60
extern struct Camera *cameraOne; // offset 0x800BE868
extern struct Camera *sbsp_camera; // offset 0x800C1F70
extern struct Camera *theCamera; // offset 0x800BE86C
extern struct ControllerPacket gpbuffer1; // offset 0x800C18A4
extern struct ControllerPacket gpbuffer2; // offset 0x800C18EC
extern struct ControllerPacket readGPBuffer1; // offset 0x800C18C8
extern struct ControllerPacket readGPBuffer2; // offset 0x800C1910
extern struct DebugMenuLine *currentMenu; // offset 0x800BE4A8
extern struct DebugMenuLine *remotesMenu; // offset 0x800C06C4
extern struct DebugMenuLine AlukaMenu[10]; // offset 0x800B49A0
extern struct DebugMenuLine AnteRoomsMenu[11]; // offset 0x800B5510
extern struct DebugMenuLine AshVillageMenu[7]; // offset 0x800B4A90
extern struct DebugMenuLine BossAreasMenu[12]; // offset 0x800B5618
extern struct DebugMenuLine cameraMenu[7]; // offset 0x800B48F8
extern struct DebugMenuLine CityMenu[6]; // offset 0x800B51F8
extern struct DebugMenuLine CliffMenu[3]; // offset 0x800B5288
extern struct DebugMenuLine debugForgedAbilitiesMenu[12]; // offset 0x800B4598
extern struct DebugMenuLine debugGlyphAbilitiesMenu[12]; // offset 0x800B46B8
extern struct DebugMenuLine debugImbueSoulReaverMenu[12]; // offset 0x800B47D8
extern struct DebugMenuLine debugRazielMenu[7]; // offset 0x800B43A0
extern struct DebugMenuLine debugSoundMenu[14]; // offset 0x800B4250
extern struct DebugMenuLine debugSpecialAbilitiesMenu[14]; // offset 0x800B4448
extern struct DebugMenuLine eventMenu[7]; // offset 0x800B3F50
extern struct DebugMenuLine fogMenu[8]; // offset 0x800B3FF8
extern struct DebugMenuLine goodiesMenu[17]; // offset 0x800B40B8
extern struct DebugMenuLine HubAMenu[5]; // offset 0x800B5378
extern struct DebugMenuLine HubBMenu[3]; // offset 0x800B53F0
extern struct DebugMenuLine LairMenu[5]; // offset 0x800B5078
extern struct DebugMenuLine level2SelectMenu[12]; // offset 0x800B5738
extern struct DebugMenuLine levelSelectMenu[16]; // offset 0x800B5858
extern struct DebugMenuLine MorlockMenu[4]; // offset 0x800B5318
extern struct DebugMenuLine musicSelectMenu[11]; // offset 0x800B59D8
extern struct DebugMenuLine OracleMenu[5]; // offset 0x800B4B38
extern struct DebugMenuLine PillarsMenu[7]; // offset 0x800B4BB0
extern struct DebugMenuLine PushMenu[11]; // offset 0x800B50F0
extern struct DebugMenuLine RetreatMenu[4]; // offset 0x800B54B0
extern struct DebugMenuLine SilencedCathedralMenu[8]; // offset 0x800B4C58
extern struct DebugMenuLine SkinnerMenu[7]; // offset 0x800B4D18
extern struct DebugMenuLine standardMenu[12]; // offset 0x800B3DA0
extern struct DebugMenuLine statsMenu[6]; // offset 0x800B3EC0
extern struct DebugMenuLine StoneMenu[5]; // offset 0x800B4DC0
extern struct DebugMenuLine SunLightMenu[7]; // offset 0x800B4E38
extern struct DebugMenuLine TombMenu[6]; // offset 0x800B4EE0
extern struct DebugMenuLine TrainingMenu[5]; // offset 0x800B5438
extern struct DebugMenuLine UnderCityMenu[7]; // offset 0x800B4F70
extern struct DebugMenuLine UnderMenu[3]; // offset 0x800B52D0
extern struct DebugMenuLine WaterMenu[4]; // offset 0x800B5018
extern DISPENV disp[2]; // offset 0x800C1B18
extern DRAWENV draw[2]; // offset 0x800C1B44
extern struct FontPos fontPos[45]; // offset 0x800B5AE0
extern struct FontTracker fontTracker; // offset 0x800C112C
extern struct GameTracker gameTrackerX; // offset 0x800C1C84
extern struct LightInfo *light_lightInfo; // offset 0x800C1950
extern struct LightInfo *sbsp_lightInfo; // offset 0x800C1F74
extern struct LoadStatus loadStatus; // offset 0x800C1954
extern struct MATRIX *collide_lwTransform; // offset 0x800C0F10
extern struct MATRIX *wcTransform; // offset 0x800BE870
extern struct Object *fontsObject; // offset 0x800BF004
extern struct ObjectAccess objectAccess[26]; // offset 0x800B5BF8
extern struct ObjectFunc objectFunc[8]; // offset 0x800B5CC8
extern struct POLY_F3 flashRect; // offset 0x800C17CC
extern struct POLY_F3 flashRect2; // offset 0x800C17B8
extern struct POLY_F4 coverRect; // offset 0x800C1788
extern struct POLY_F4 screenWipeClear; // offset 0x800C17A0
extern struct PoolManagementData *poolManagementData; // offset 0x800C4F08
extern struct PrintSignal signal_printList[5]; // offset 0x800C0CBC
extern struct RECT PortalRect; // offset 0x800C243C
extern struct Screen_XY C_TXY[3]; // offset 0x800C2444
extern struct ScriptPCode *currentActionScript; // offset 0x800C2A78
extern struct SignalInfo signalInfoList[111]; // offset 0x800BE9A4
extern struct SoundEffectChannel soundEffectChannelTbl[32]; // offset 0x800C1FB8
extern struct STracker StreamTracker; // offset 0x800C24DC
extern struct SVECTOR *face_v0; // offset 0x800BEFA4
extern struct SVECTOR *face_v01; // offset 0x800BEFB0
extern struct SVECTOR *face_v1; // offset 0x800BEFA8
extern struct SVECTOR *face_v12; // offset 0x800BEFB4
extern struct SVECTOR *face_v2; // offset 0x800BEFAC
extern struct SVECTOR *face_v20; // offset 0x800BEFB8
extern struct TILE clearRect2; // offset 0x800C1C70
extern struct TimedSignal timedSignalList[16]; // offset 0x800C0CF8
extern struct UVTYPE *face_uv0; // offset 0x800BEFBC
extern struct UVTYPE *face_uv01; // offset 0x800BEFC8
extern struct UVTYPE *face_uv1; // offset 0x800BEFC0
extern struct UVTYPE *face_uv12; // offset 0x800BEFCC
extern struct UVTYPE *face_uv2; // offset 0x800BEFC4
extern struct UVTYPE *face_uv20; // offset 0x800BEFD0
extern struct WarpRoom WarpRoomArray[3]; // offset 0x800BFC38
extern struct XAVoiceListEntry voiceList[196]; // offset 0x800C0538
extern struct XAVoiceTracker voiceTracker; // offset 0x800C570C
extern struct ZSignal signal_zSignalList[16]; // offset 0x800C0E38
//extern union .218fake GlowColor[3]; // offset 0x800B6854
extern unsigned char *draw_stack; // offset 0x800C0F1C
extern unsigned char controllerType[2]; // offset 0x800C189C
extern unsigned char debugOrgFogBlu; // offset 0x800C06D0
extern unsigned char debugOrgFogGrn; // offset 0x800C06CC
extern unsigned char debugOrgFogRed; // offset 0x800C06C8
extern unsigned char dualshock_align[6]; // offset 0x800B5B98
extern unsigned char dualshock_motors[2]; // offset 0x800B5B94
extern unsigned long **ot[2]; // offset 0x800C1778
extern unsigned long __timerEvent; // offset 0x800C1C5C
extern unsigned long aadGp; // offset 0x800B65A4
extern unsigned long aadStepsPerCent[85]; // offset 0x800BFA34
extern unsigned long CurrentBirthID; // offset 0x800BF0A8
extern unsigned long debugRazielFlags1; // offset 0x800C06D8
extern unsigned long debugRazielFlags2; // offset 0x800C06DC
extern unsigned long debugTimeMult; // offset 0x800BD618
extern unsigned long StackSave; // offset 0x800C1884
extern unsigned short aadPitchTable[85]; // offset 0x800BF988
extern unsigned short lastData[2]; // offset 0x800BF088
extern unsigned short psxData[2]; // offset 0x800C18A0
extern unsigned short SpecialFogClut; // offset 0x800C1128
extern void *light_light; // offset 0x800C1948
static char aadDateString[9]; // offset 0x800BF788
static char aadNameString[7]; // offset 0x800BF778
static char aadVersionString[5]; // offset 0x800BF780
static char circBuf[4096]; // offset 0x800C2DF0
static char fp_str[512]; // offset 0x800C0F24
static char midiDataByteCount[8]; // offset 0x800BF7C4
static int _indexTable[16]; // offset 0x800B68E4
static int _stepSizeTable[64]; // offset 0x800B6924
static int AlgoControlFlag; // offset 0x800C0334
static int BlockCount; // offset 0x800C0360
static int Down; // offset 0x800C0118
static int fx_radius_old; // offset 0x800C4694
static int gNumMonsters; // offset 0x800C01C4
static int LastBlock; // offset 0x800C0364
static int LastRC; // offset 0x800C55DC
static int Pending; // offset 0x800C0110
static int PhysicsMode; // offset 0x800C554C
static int roll_inc; // offset 0x800BE8CC
static int s_zval; // offset 0x800C2438
static int Up; // offset 0x800C0114
static int WaterStatus; // offset 0x800C032C
static int ZoneDelta; // offset 0x800C0338
//static long *PadData; // offset 0x800C54E0
static long ACE_amount; // offset 0x800C0C9C
static long current_roll_amount; // offset 0x800BE8C8
static long CurrentEventLine; // offset 0x800BFF04
static long debugMenuChoice; // offset 0x800BD608
static long dualshock0_time; // offset 0x800C1894
static long dualshock1_time; // offset 0x800C1898
static long EndQueuePos; // offset 0x800BFEF8
static long EventCurrentEventIndex; // offset 0x800BFF08
static long MoveCodeStreamExtra; // offset 0x800BFF00
static long numActiveEventTimers; // offset 0x800C2A74
static long numbufferedIntros; // offset 0x800C03F8
static long numColumns; // offset 0x800C55F0
static long numRows; // offset 0x800C55EC
static long roll_target; // offset 0x800BE8C4
static long Spiral_Current; // offset 0x800BF6F8
static long Spiral_Max; // offset 0x800BF6FC
static long StartQueuePos; // offset 0x800BFEF4
static long timerArray[10]; // offset 0x800C4EDC
static long timerIndex; // offset 0x800C4F04
static long UW_time; // offset 0x800C55F4
static long vmClock; // offset 0x800BF714
static long vmRealClock; // offset 0x800BF710
static short *EventAbortedPosition; // offset 0x800C2928
static short align_flag; // offset 0x800BF05C
static short Camera_lookDist; // offset 0x800C0CAA
static short Camera_lookHeight; // offset 0x800C0CA8
static short camera_still; // offset 0x800BE8C2
static short CameraLookStickyFlag; // offset 0x800BE8E0
static short CenterFlag; // offset 0x800BE8DE
static short combat_cam_angle; // offset 0x800BE8BA
static short combat_cam_distance; // offset 0x800BE8B8
static short combat_cam_weight; // offset 0x800BE8BC
static short dualshock_onflag; // offset 0x800BF05E
static short EventAbortLine; // offset 0x800BFEFC
static short EventJustRecievedTimer; // offset 0x800BFEFE
static short FX_ConstrictStage; // offset 0x800BF69C
static short FX_Frames; // offset 0x800C2100
static short fx_going; // offset 0x800C0174
static short FX_TimeCount; // offset 0x800C2102
static short glyph_cost; // offset 0x800C468C
static short glyph_time; // offset 0x800C4688
static short glyph_trigger; // offset 0x800C468A
static short hitline_rot; // offset 0x800C0C98
static short HUD_Captured; // offset 0x800C017C
static short HUD_Pos_vel; // offset 0x800C469E
static short HUD_Position; // offset 0x800C469C
static short HUD_Rot_vel; // offset 0x800C469A
static short HUD_Rotation; // offset 0x800C4698
static short HUD_State; // offset 0x800C46A0
static short HUD_Wait; // offset 0x800C46A2
static short MANNA_Pos_vel; // offset 0x800C4686
static short MANNA_Position; // offset 0x800C4684
static short panic_count; // offset 0x800BE8E4
static short rain_amount; // offset 0x800BF6A6
static short shorten_count; // offset 0x800BE8BE
static short shorten_flag; // offset 0x800BE8C0
static short snow_amount; // offset 0x800BF6A4
static short Spiral_Degrees; // offset 0x800BF6F6
static short Spiral_Number; // offset 0x800BF6F4
static short wind_deg; // offset 0x800BF6D0
static short wind_speed; // offset 0x800BF6D2
static short windx; // offset 0x800BF6CC
static short windy; // offset 0x800BF6CE
//static struct .187fake functionChoiceTable[8]; // offset 0x800B6668
static struct __EngagedInstance EngagedList[15]; // offset 0x800C555C
static struct __FitPoint constrictData[32]; // offset 0x800C543C
//static struct __Force *ExternalForces; // offset 0x800C4F0C
static struct __Force ExternalForces[4]; // offset 0x800C54FC
static struct __GlyphHudSaveData HudSave; // offset 0x800C4690
static struct __Player Raziel; // offset 0x800C4F4C
static struct _FX_PRIM *FX_LastUsedPrim; // offset 0x800C20FC
static struct _FXGeneralEffect *FX_GeneralEffectTracker; // offset 0x800BF694
static struct _FXGlowEffect *Spiral_Glow1; // offset 0x800BF700
static struct _FXGlowEffect *Spiral_Glow2; // offset 0x800BF704
static struct _FXRibbon *FX_ConstrictRibbon; // offset 0x800BF698
static struct _G2AnimAlphaTable_Type *G2AlphaTables[7]; // offset 0x800C011C
static struct _G2AnimChanStatusBlockPool_Type _chanStatusBlockPool; // offset 0x800C4704
static struct _G2AnimControllerPool_Type _controllerPool; // offset 0x800C4E94
static struct _G2AnimInterpInfo_Type razInterpInfo[3]; // offset 0x800C540C
static struct _G2AnimInterpStateBlockPool_Type _interpStateBlockPool; // offset 0x800C4EA4
//static struct _G2AnimSegValue_Type _segValues[80]; // offset 0x800C4714
static struct _G2AppDataVM_Type _appDataVM; // offset 0x800C4EB4
static struct _G2SVector3_Type *ExtraRot; // offset 0x800C54EC
static struct _G2SVector3_Type ExtraRotData; // offset 0x800C54E4
static struct _Instance *FX_ConstrictInstance; // offset 0x800BF6A0
static struct _Instance *FX_reaver_instance; // offset 0x800BF6A8
static struct _InstanceList *instanceList; // offset 0x800C175C
static struct _InstancePool *instancePool; // offset 0x800C1760
static struct _MonsterFunctionTable DefaultFunctionTable; // offset 0x800C0250
static struct _MonsterState DefaultStateTable[31]; // offset 0x800B66A8
static struct _MonsterVars *monsterSenseArray[20]; // offset 0x800C46B4
static struct _Normal Norm; // offset 0x800C55D4
static struct _ObjectTracker *GlobalObjects; // offset 0x800C1774
static struct _PolytopeList *polytopeList; // offset 0x800C1758
static struct _Position *FX_ConstrictPositionPtr; // offset 0x800C20F8
static struct _Position FX_ConstrictPosition; // offset 0x800C20F0
static struct _PrimPool *primPool[2]; // offset 0x800C1750
static struct _Rotation splinecam_helprot; // offset 0x800C0CA0
static struct _SavedIntro *bufferSavedIntroArray[64]; // offset 0x800C5608
static struct _SVector camera_plane; // offset 0x800C0C80
static struct _SVector camera_shakeOffset[16]; // offset 0x800C0C00
static struct _SVector HUD_Cap_Pos; // offset 0x800C46A4
static struct _SVector HUD_Cap_Vel; // offset 0x800C46AC
static struct _SVector left_point; // offset 0x800C0C88
static struct _SVector right_point; // offset 0x800C0C90
static struct _SVector signal_gexOldPosX; // offset 0x800BE8EC
static struct _VertexPool *vertexPool; // offset 0x800C1764
static struct AadProgramAtr aadDummySfxProgram; // offset 0x800BF980
static struct burntTuneType burntTest; // offset 0x800C0238
static struct Camera cameraOneX; // offset 0x800C06F0
static struct DVECTOR Spiral_Array[65]; // offset 0x800C2110
static struct DVECTOR Spiral_OffsetM[64]; // offset 0x800C2320
static struct DVECTOR Spiral_OffsetP[64]; // offset 0x800C2220
static struct Event *currentEventInstance; // offset 0x800C2924
static struct EventTimer eventTimerArray[8]; // offset 0x800C29B4
static struct GameTracker *gameTracker; // offset 0x800C54DC
static struct Level *CurrentPuzzleLevel; // offset 0x800C29AC
static struct LightInfo *gLightInfo; // offset 0x800C1768
static struct LoadQueueEntry LoadQueue[64]; // offset 0x800C79D4
static struct MATRIX *cwTransform2; // offset 0x800BE878
static struct MATRIX *pTempMat; // offset 0x800C4680
static struct MATRIX *wcTransform2; // offset 0x800BE874
static struct MATRIX cwTransformX2; // offset 0x800C0BE0
static struct MATRIX TempMat; // offset 0x800C4660
static struct MATRIX TempMat; // offset 0x800C4F1C
static struct MATRIX TempMat; // offset 0x800C54BC
static struct MATRIX wcTransformX; // offset 0x800C0BA0
static struct MATRIX wcTransformX2; // offset 0x800C0BC0
static struct MissileGraphics MISSILE_objectTable[4]; // offset 0x800B6638
static struct NewMemTracker newMemTracker; // offset 0x800C2420
static struct Object *PathObject; // offset 0x800C2DEC
static struct PoolManagementData poolManagementDataStorage; // offset 0x800C4EBC
static struct RadarInfo radarDir[16]; // offset 0x800C01C8
static struct RazielData *PlayerData; // offset 0x800C5404
static struct SavedInfoTracker savedInfoTracker; // offset 0x800C55F8
static struct SVECTOR New; // offset 0x800C4658
static struct SVECTOR Old; // offset 0x800C4650
static struct UW_ScreenXY *ScreenMorphArray; // offset 0x800C0374
static struct WaterLevelProcess WaterLevelArray[5]; // offset 0x800C2934
static unsigned char PickupList[4]; // offset 0x800C0330
static unsigned char radarDirIndex[16]; // offset 0x800C0228
static unsigned long __hblankEvent; // offset 0x800C2434
static unsigned long aadReverbModeSize[10]; // offset 0x800BF79C
static unsigned long aadUpdateRate[4]; // offset 0x800BF764
static unsigned short *__demoBuffer; // offset 0x800BF058
static unsigned short *__demoBufferStart; // offset 0x800BF054
static unsigned short __currentData; // offset 0x800BF050
static unsigned short __dataCount; // offset 0x800BF052
static unsigned short aadHblanksPerUpdate[4]; // offset 0x800BF75C
static void *circWhere; // offset 0x800C0138
static void *enemyPlanPool; // offset 0x800C176C
static void *planningPool; // offset 0x800C1770

#endif