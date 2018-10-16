#include "PLAYER.H"

#include "G2TYPES.H"

void PLAYER_TurnHead(struct _Instance* instance, short* rotx, short* rotz, struct GameTracker* gameTracker)
{
}

long PLAYER_OkToLookAround(struct _Instance* instance)
{
	return 0;
}

void PLAYER_SetLookAround(struct _Instance* instance)
{
}

void PLAYER_ReSetLookAround(struct _Instance* instance)
{
}

long PLAYER_HandleLaunchSignal(struct _Instance* instance, struct Signal* signal)
{
	return 0;
}

int PLAYER_ChangeCostume(struct _Instance* instance, struct GameTracker* gameTracker, char* newModelName)
{
	return 0;
}