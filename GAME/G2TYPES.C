#include "G2TYPES.H"

char *BufferLoadPtr1; // offset 0x800BFEEC
char *BufferLoadPtr2; // offset 0x800BFEF0
char *missionText[1]; // offset 0x800B5BE0
char *primBase; // offset 0x800C188C
char *selectMenuText[5]; // offset 0x800B5BE4
char *voiceFileList[13]; // offset 0x800C0434
char GlobalLevelVramName[80]; // offset 0x800C2450
char HashExtensions[7][4]; // offset 0x800BF0DC
char mainOptionsInit; // offset 0x800BF10C
char monVersion[12]; // offset 0x800C0414
char soundBuffer[8676]; // offset 0x800C57F0
char strFadeBoxDim[8]; // offset 0x800BE4AC
int _ramsize; // offset 0x800BF104
int _stacksize; // offset 0x800BF108
int AutoFaceAngle; // offset 0x800C55E0
int ControlFlag; // offset 0x800C55E4
int currentIdleCount; // offset 0x800C035C
int currentIdleListCount; // offset 0x800C0358
int devstation; // offset 0x800C1B40
int fontDistance; // offset 0x800BEFF0
int InStreamUnit; // offset 0x800C1784
int LoopCounter; // offset 0x800C0328
int nosound; // offset 0x800BF114
int pcverify; // offset 0x800BF110
int SAVE_OTZ; // offset 0x800C2920
long *controlsScreen; // offset 0x800C1AF4
long *mainMenuScreen; // offset 0x800C1F6C
long camera_modeToIndex[15]; // offset 0x800BE87C
long cameraMode; // offset 0x800BEFFC
long campoint_hh; // offset 0x800C0CB0
long campoint_hw; // offset 0x800C0CAC
long cheatCodeLastCommand; // offset 0x800BE4B8
long cheatCodeStage; // offset 0x800BE4B4
long cheatCombo[6]; // offset 0x800BE4BC
long collide_acceptAttr; // offset 0x800BEF74
long collide_ignoreAttr; // offset 0x800BEF70
long collide_t0; // offset 0x800C0F00
long collide_t1; // offset 0x800C0F04
long CurrentWarpNumber; // offset 0x800BFC34
long debug_cameraMode; // offset 0x800BD610
long debugFogBlu; // offset 0x800BD630
long debugFogFar; // offset 0x800BD61C
long debugFogGrn; // offset 0x800BD62C
long debugFogNear; // offset 0x800BD620
long debugFogRed; // offset 0x800BD628
long debugGameTime; // offset 0x800BD624
long debugVoiceIndex; // offset 0x800BD614
long DoMainMenu; // offset 0x800BF118
long draw_belowSplit; // offset 0x800BEFA0
long dyna_clddyna[8]; // offset 0x800BEF10
long dyna_cldstat[8]; // offset 0x800BEF50
long eventListNumInstances[20]; // offset 0x800C2A7C
long FOG_Color; // offset 0x800C24A0
long FRAC_BITS; // offset 0x800BF690
long FX_ColorArray[6]; // offset 0x800BF6DC
long gDummyCommand[2][2]; // offset 0x800C1934
long gTimerEnabled; // offset 0x800BF47C
long mainMenuMode; // offset 0x800BF11C
long menuPauseSel; // offset 0x800BD60C
long modelDQP; // offset 0x800C0F20
long MORPH_A_Component; // offset 0x800C24C8
long MORPH_B_Component; // offset 0x800C24CC
long numOfBlocksUsed; // offset 0x800C4628
long playerCameraMode; // offset 0x800BF000
long RazielCommands[10]; // offset 0x800C00E8
long SaveArraySize[6]; // offset 0x800C03FC
long signal_gexCurrentMainState; // offset 0x800BE8F4
long signal_logicValue[36]; // offset 0x800BE8F8
long SignalEndGame; // offset 0x800BE9A0
long stat_clddyna[8]; // offset 0x800BEF30
long VRAM_NeedToUpdateMorph; // offset 0x800C013C
long WaterInUse; // offset 0x800BFF0C
short aadStepsPerSemitone[85]; // offset 0x800BFB88
short AXIS_LENGTH; // offset 0x800BE7BC
short debugOrgFogFar; // offset 0x800C06D4
short debugOrgFogNear; // offset 0x800C06C0
short fontScale; // offset 0x800BEFEA
short fontScaleFrac; // offset 0x800BEFEC
short forceDrawInFront; // offset 0x800BEF9C
short identityMatrix[3][3]; // offset 0x800BF418
short M_TrackClutUpdate; // offset 0x800C4624
short mainMenuFadeInTime; // offset 0x800BF120
short mainMenuTimeOut; // offset 0x800C1C80
short playerMissionSelection; // offset 0x800BF0F8
short RENDER_currentStreamUnitID; // offset 0x800C1880
short signal_tagTimer; // offset 0x800BE988
short signal_tagTimerIndex; // offset 0x800BE98A
struct __Idle **currentIdleList; // offset 0x800C0354
struct _BlockVramEntry *FONT_vramBlock; // offset 0x800C1124
struct _BlockVramEntry *openVramBlocks; // offset 0x800C464C
struct _BlockVramEntry *usedVramBlocks; // offset 0x800C4648
struct _BlockVramEntry TerrainVramBlock; // offset 0x800C462C
struct _BlockVramEntry vramBlockList[75]; // offset 0x800C3DF0
struct _ButtonTexture BexitLine[2]; // offset 0x800C1AF8
struct _ButtonTexture BmenuLines[3][2]; // offset 0x800C1BFC
struct _ButtonTexture PauseButtons[4][2]; // offset 0x800C1EEC
struct _FXBlastringEffect *fx_blastring; // offset 0x800C0178
struct _FXTracker *fxTracker; // offset 0x800C1888
struct _FXTracker *gFXT; // offset 0x800C1780
struct _GlobalSaveTracker GlobalSave; // offset 0x800C039C
struct _Instance *collide_boxInstance; // offset 0x800BEF78
struct _Instance *eventListArray[20][10]; // offset 0x800C2ACC
struct _Mirror GlobalMirror; // offset 0x800C0CB4
struct _MonsterFunctionTable HUMAN_FunctionTable; // offset 0x800C0184
struct _MonsterFunctionTable HUNTER_FunctionTable; // offset 0x800C01A4
struct _MonsterFunctionTable SKINNER_FunctionTable; // offset 0x800C0270
struct _MonsterFunctionTable SLUAGH_FunctionTable; // offset 0x800C0290
struct _MonsterFunctionTable SOUL_FunctionTable; // offset 0x800C02B8
struct _MonsterFunctionTable VWRAITH_FunctionTable; // offset 0x800C02D8
struct _MonsterFunctionTable WORSHIP_FunctionTable; // offset 0x800C02F8
struct _MonsterStateChoice HUMAN_StateChoiceTable[6]; // offset 0x800B65A8
struct _MonsterStateChoice HUNTER_StateChoiceTable[6]; // offset 0x800B65F0
struct _MonsterStateChoice SKINNER_StateChoiceTable[4]; // offset 0x800B67A0
struct _MonsterStateChoice SLUAGH_StateChoiceTable[4]; // offset 0x800B67D0
struct _MonsterStateChoice SOUL_StateChoiceTable[7]; // offset 0x800B6800
struct _MonsterStateChoice VWRAITH_StateChoiceTable[6]; // offset 0x800B6860
struct _MonsterStateChoice WORSHIP_StateChoiceTable[5]; // offset 0x800B68A8
struct _Normal gNormalList[244]; // offset 0x800B5E04
struct _SVector *collide_normal0; // offset 0x800C0F14
struct _SVector *collide_normal1; // offset 0x800C0F18
struct _SVector *collide_point0; // offset 0x800C0EF8
struct _SVector *collide_point1; // offset 0x800C0EFC
struct _SVector collide_localPoint; // offset 0x800C0F08
struct _Terrain *light_terrain; // offset 0x800C194C
struct _TFace *MORPH_SavedFace; // offset 0x800C291C
struct _TVertex C_tvertex0; // offset 0x800C24A4
struct _TVertex C_tvertex1; // offset 0x800C24B0
struct _TVertex C_tvertex2; // offset 0x800C24BC
struct _Vector MORPH_BasePoint; // offset 0x800C24D0
struct AadMemoryStruct *aadMem; // offset 0x800BF774
struct BLK_FILL AuxClearRect[10]; // offset 0x800C17E0
struct BLK_FILL clearRect; // offset 0x800C1C60
struct Camera *cameraOne; // offset 0x800BE868
struct Camera *sbsp_camera; // offset 0x800C1F70
struct Camera *theCamera; // offset 0x800BE86C
ControllerPacket gpbuffer1; // offset 0x800C18A4
ControllerPacket gpbuffer2; // offset 0x800C18EC
ControllerPacket readGPBuffer1; // offset 0x800C18C8
ControllerPacket readGPBuffer2; // offset 0x800C1910
struct DebugMenuLine *currentMenu; // offset 0x800BE4A8
struct DebugMenuLine *remotesMenu; // offset 0x800C06C4
struct DebugMenuLine AlukaMenu[10]; // offset 0x800B49A0
struct DebugMenuLine AnteRoomsMenu[11]; // offset 0x800B5510
struct DebugMenuLine AshVillageMenu[7]; // offset 0x800B4A90
struct DebugMenuLine BossAreasMenu[12]; // offset 0x800B5618
struct DebugMenuLine cameraMenu[7]; // offset 0x800B48F8
struct DebugMenuLine CityMenu[6]; // offset 0x800B51F8
struct DebugMenuLine CliffMenu[3]; // offset 0x800B5288
struct DebugMenuLine debugForgedAbilitiesMenu[12]; // offset 0x800B4598
struct DebugMenuLine debugGlyphAbilitiesMenu[12]; // offset 0x800B46B8
struct DebugMenuLine debugImbueSoulReaverMenu[12]; // offset 0x800B47D8
struct DebugMenuLine debugRazielMenu[7]; // offset 0x800B43A0
struct DebugMenuLine debugSoundMenu[14]; // offset 0x800B4250
struct DebugMenuLine debugSpecialAbilitiesMenu[14]; // offset 0x800B4448
struct DebugMenuLine eventMenu[7]; // offset 0x800B3F50
struct DebugMenuLine fogMenu[8]; // offset 0x800B3FF8
struct DebugMenuLine goodiesMenu[17]; // offset 0x800B40B8
struct DebugMenuLine HubAMenu[5]; // offset 0x800B5378
struct DebugMenuLine HubBMenu[3]; // offset 0x800B53F0
struct DebugMenuLine LairMenu[5]; // offset 0x800B5078
struct DebugMenuLine level2SelectMenu[12]; // offset 0x800B5738
struct DebugMenuLine levelSelectMenu[16]; // offset 0x800B5858
struct DebugMenuLine MorlockMenu[4]; // offset 0x800B5318
struct DebugMenuLine musicSelectMenu[11]; // offset 0x800B59D8
struct DebugMenuLine OracleMenu[5]; // offset 0x800B4B38
struct DebugMenuLine PillarsMenu[7]; // offset 0x800B4BB0
struct DebugMenuLine PushMenu[11]; // offset 0x800B50F0
struct DebugMenuLine RetreatMenu[4]; // offset 0x800B54B0
struct DebugMenuLine SilencedCathedralMenu[8]; // offset 0x800B4C58
struct DebugMenuLine SkinnerMenu[7]; // offset 0x800B4D18
struct DebugMenuLine standardMenu[12]; // offset 0x800B3DA0
struct DebugMenuLine statsMenu[6]; // offset 0x800B3EC0
struct DebugMenuLine StoneMenu[5]; // offset 0x800B4DC0
struct DebugMenuLine SunLightMenu[7]; // offset 0x800B4E38
struct DebugMenuLine TombMenu[6]; // offset 0x800B4EE0
struct DebugMenuLine TrainingMenu[5]; // offset 0x800B5438
struct DebugMenuLine UnderCityMenu[7]; // offset 0x800B4F70
struct DebugMenuLine UnderMenu[3]; // offset 0x800B52D0
struct DebugMenuLine WaterMenu[4]; // offset 0x800B5018
DISPENV disp[2]; // offset 0x800C1B18
DRAWENV draw[2]; // offset 0x800C1B44
struct FontPos fontPos[45]; // offset 0x800B5AE0
struct FontTracker fontTracker; // offset 0x800C112C
struct GameTracker gameTrackerX; // offset 0x800C1C84
struct LightInfo *light_lightInfo; // offset 0x800C1950
struct LightInfo *sbsp_lightInfo; // offset 0x800C1F74
struct LoadStatus loadStatus; // offset 0x800C1954
struct MATRIX *collide_lwTransform; // offset 0x800C0F10
struct MATRIX *wcTransform; // offset 0x800BE870
struct Object *fontsObject; // offset 0x800BF004
struct ObjectAccess objectAccess[26]; // offset 0x800B5BF8
struct ObjectFunc objectFunc[8]; // offset 0x800B5CC8
POLY_F3 flashRect; // offset 0x800C17CC
POLY_F3 flashRect2; // offset 0x800C17B8
POLY_F4 coverRect; // offset 0x800C1788
POLY_F4 screenWipeClear; // offset 0x800C17A0
struct PoolManagementData *poolManagementData; // offset 0x800C4F08
struct PrintSignal signal_printList[5]; // offset 0x800C0CBC
RECT PortalRect; // offset 0x800C243C
struct Screen_XY C_TXY[3]; // offset 0x800C2444
struct ScriptPCode *currentActionScript; // offset 0x800C2A78
struct SignalInfo signalInfoList[111]; // offset 0x800BE9A4
struct SoundEffectChannel soundEffectChannelTbl[32]; // offset 0x800C1FB8
struct STracker StreamTracker; // offset 0x800C24DC
struct SVECTOR *face_v0; // offset 0x800BEFA4
struct SVECTOR *face_v01; // offset 0x800BEFB0
struct SVECTOR *face_v1; // offset 0x800BEFA8
struct SVECTOR *face_v12; // offset 0x800BEFB4
struct SVECTOR *face_v2; // offset 0x800BEFAC
struct SVECTOR *face_v20; // offset 0x800BEFB8
struct TILE clearRect2; // offset 0x800C1C70
struct TimedSignal timedSignalList[16]; // offset 0x800C0CF8
struct UVTYPE *face_uv0; // offset 0x800BEFBC
struct UVTYPE *face_uv01; // offset 0x800BEFC8
struct UVTYPE *face_uv1; // offset 0x800BEFC0
struct UVTYPE *face_uv12; // offset 0x800BEFCC
struct UVTYPE *face_uv2; // offset 0x800BEFC4
struct UVTYPE *face_uv20; // offset 0x800BEFD0
struct WarpRoom WarpRoomArray[3]; // offset 0x800BFC38
struct XAVoiceListEntry voiceList[196]; // offset 0x800C0538
struct XAVoiceTracker voiceTracker; // offset 0x800C570C
struct ZSignal signal_zSignalList[16]; // offset 0x800C0E38
//union .218fake GlowColor[3]; // offset 0x800B6854
unsigned char *draw_stack; // offset 0x800C0F1C
unsigned char controllerType[2]; // offset 0x800C189C
unsigned char debugOrgFogBlu; // offset 0x800C06D0
unsigned char debugOrgFogGrn; // offset 0x800C06CC
unsigned char debugOrgFogRed; // offset 0x800C06C8
unsigned char dualshock_align[6]; // offset 0x800B5B98
unsigned char dualshock_motors[2]; // offset 0x800B5B94
unsigned long **ot[2]; // offset 0x800C1778
unsigned long __timerEvent; // offset 0x800C1C5C
unsigned long aadGp; // offset 0x800B65A4
unsigned long aadStepsPerCent[85]; // offset 0x800BFA34
unsigned long CurrentBirthID; // offset 0x800BF0A8
unsigned long debugRazielFlags1; // offset 0x800C06D8
unsigned long debugRazielFlags2; // offset 0x800C06DC
unsigned long debugTimeMult; // offset 0x800BD618
unsigned long StackSave; // offset 0x800C1884
unsigned short aadPitchTable[85]; // offset 0x800BF988
unsigned short lastData[2]; // offset 0x800BF088
unsigned short psxData[2]; // offset 0x800C18A0
unsigned short SpecialFogClut; // offset 0x800C1128
void *light_light; // offset 0x800C1948