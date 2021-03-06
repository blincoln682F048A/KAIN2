#ifndef SUPPORT_H
#define SUPPORT_H

extern int printf(char* fmt);
extern int sprintf(char* string, char* fmt);
extern int vsprintf(char* str, char* fmtstr, void* argptr);
extern char* my_itoa(unsigned long value, char* str, int radix);
extern int atoi(char* str);
extern int mytolower(int c);
extern int strcmpi(char* s1, char* s2);

#endif