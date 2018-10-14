#include "GAMEPAD.H"

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

