#include "GAMEPAD.H"

#include "G2TYPES.H"

#include <LIBAPI.H>
#include <LIBETC.H>
#include <LIBPAD.H>
#include <STDLIB.H>
#include <STDIO.H>
#include <STRING.H>

void GAMEPAD_Commands(long* command[5] /*$t4*/, long *data[5] /*$t3*/, long pad /*$a2*/)
{
	long analogX; // $t2
	long analogY; // $t1
	unsigned long padData; // $a3
	static short lastPad[2]; // offset 0x0
}

void GAMEPAD_HandleDualShock()
{
	int decrement_amount; // $s3
	{ // line 8, offset 0x80032674
		int timeout; // $s0
	} // line 15, offset 0x800326b0
}

void GAMEPAD_Shock(int motor0_speed /*$a0*/, int motor0_time /*$a1*/, int motor1_speed /*$a2*/, int motor1_time /*$a3*/)
{
}

void  GAMEPAD_Init()
{
	int dualShock; // $s0
	int padState; // $v0

	dualShock = 0;

	ResetRCnt((unsigned long)&readGPBuffer1);///@FIXME check
	PadStartCom();

	dualshock0_time = 0;
	dualshock1_time = 0;
	align_flag = 0;
	dualshock_onflag = 0;

	//loc_800327B4
	do
	{
		VSync(0);
		padState = PadGetState(0);

		if (padState == 4)
		{
			dualShock = 1;
		}
		//loc_800327D0
	} while (padState == 1 || padState == 4 || padState == 5);

	if (dualShock != 0)
	{
		PadSetMainMode(0, 1, 3);
	}

	
	//loc_800327FC
	memset(&gDummyCommand[0][0], 0, sizeof(gDummyCommand));
	memset(&readGPBuffer1, 0, 0x22);
	memset(&readGPBuffer2, 0, 0x22);
	gpbuffer1.data = 0xFFFF;
	gpbuffer1.transStatus = 0;
	gpbuffer2.data = 0xFFFF;
	gpbuffer2.transStatus = 0;

	return;
}

void GAMEPAD_FillOutDemoNames(char* baseAreaName /*$s0*/, char* demoName /*$s1*/)
{
	char text[16]; // stack offset -32
	char *number; // $v0
}

void GAMEPAD_LoadDemo()
{
	char demoFileName[80]; // stack offset -88
}

void PSXPAD_TranslateData(long* data /*$a0*/, unsigned short padData /*$a1*/, unsigned short lastData /*$a2*/)
{
	static unsigned short transTable[32]; // offset 0xc
	unsigned short *from; // $t0
	{ // line 28, offset 0x80032954
		unsigned short padButton; // $a3
		unsigned short logicalButton; // $v1
	} // line 44, offset 0x800329b8
}

void /*$ra*/ GAMEPAD_GetData(long* data[5] /*$s0*/)
{ // line 1, offset 0x80032a1c
	long analogue_x; // $a0
	long analogue_y; // $v1
} // line 263, offset 0x80032e5c

unsigned short GAMEPAD_RemapAnalogueButtons(unsigned short in /*$a0*/)
{
}

void GAMEPAD_Process(struct GameTracker* gameTracker /*$s1*/)
{
}

