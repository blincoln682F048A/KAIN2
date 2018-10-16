#include "SUPPORT.H"

#include <STDIO.H>

int printf(char* fmt /*stack 0*/)
{
	int len; // $s0
	char string[256]; // stack offset -264
}
  /*
  * Offset 0x8006E124
  * C:\kain2\game\PSX\SUPPORT.C (line 78)
  * Stack frame base $sp, size 24
  * Saved registers at offset -8: ra
  */
int /*$ra*/ sprintf(char *string /*$a0*/, char *fmt /*stack 4*/)
{ // line 1, offset 0x8006e124
} // line 1, offset 0x8006e124
  /*
  * Offset 0x8006E154
  * C:\kain2\game\PSX\SUPPORT.C (line 109)
  * Stack frame base $sp, size 72
  * Saved registers at offset -4: s0 s1 s2 s3 s4 s5 s6 s7 fp ra
  */
int /*$ra*/ vsprintf(char *str /*$s7*/, char *fmtstr /*$a1*/, void *argptr /*$s5*/)
{ // line 1, offset 0x8006e154
	int scopy; // $s4
	char *fmt; // $s3
	{ // line 11, offset 0x8006e1bc
		int fsize; // $s0
		int pad; // $s6
		int left_just; // $fp
		int ts_len; // $s2
		char *temp_str; // $s1
		char buf[16]; // stack offset -56
	} // line 111, offset 0x8006e378
} // line 113, offset 0x8006e388
  /*
  * Offset 0x8006E3C4
  * C:\kain2\game\PSX\SUPPORT.C (line 230)
  * Stack frame base $sp, size 32
  */
char * /*$ra*/ my_itoa(unsigned long value /*$v1*/, char *str /*$a1*/, int radix /*$a2*/)
{ // line 1, offset 0x8006e3c4
	char *p; // $a0
	char *q; // $a3
	char digits[31]; // stack offset -32
} // line 41, offset 0x8006e48c
  /*
  * Offset 0x8006E494
  * C:\kain2\game\PSX\SUPPORT.C (line 294)
  * Stack frame base $sp, size 0
  */
int /*$ra*/ atoi(char *str /*$a1*/)
{ // line 1, offset 0x8006e494
	int val; // $a2
	int neg; // $a3
} // line 21, offset 0x8006e4f4

int mytolower(int c)
{
	if ((c - 0x41) < 0x1A)
	{
		c += 0x20;
	}

	return c;
}

int strcmpi(char* s1, char* s2)
{
	int c1;
	int c2;

	//loc_8006E53C:
	do
	{
		c1 = mytolower(*s1++);
		c2 = mytolower(*s2++);

		if (c1 != c2)
		{
			return c1 - c2;
		}
	} while (c1 != 0);

	return 0;
}