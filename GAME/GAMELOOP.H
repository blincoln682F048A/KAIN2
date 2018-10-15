#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "G2TYPES.H"

extern void GAMELOOP_AllocStaticMemory();
extern void GAMELOOP_SystemInit(struct GameTracker* gameTracker);
extern void GAMELOOP_ResetGameStates();

#endif