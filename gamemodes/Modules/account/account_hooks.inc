#include <YSI_Coding\y_hooks> // evo ti

static auth_RaceCheck[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    auth_RaceCheck[playerid] ++;
    Account_CheckIfExists(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    auth_RaceCheck[playerid] ++;
    Account_ResetInfo(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

