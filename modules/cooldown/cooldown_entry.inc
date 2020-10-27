#include <YSI_Coding\y_hooks>

const CHAT = 0,
    CMD = 1;

static 
    player_Tick[MAX_PLAYERS][2],
    player_Time[MAX_PLAYERS][2];

//---------------------------
hook OnPlayerConnect(playerid)
{
    player_Time[playerid][CHAT] = 2000;
    player_Time[playerid][CMD] = 2000;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    player_Time[playerid][CHAT] = 0;
    player_Time[playerid][CMD] = 0;
    return Y_HOOKS_CONTINUE_RETURN_1;
}
//--------------------------------------------------------

/*
 * <summary> Set player's cooldown ticks</summary>
 * <param name="playerid"> playerid to set</param>
 * <param name="type"> type of cooldown</param>
 * <param name="tick"> Tick to set</param>
 */

stock Cooldown_SetPlayerTick(playerid, type, tick)
{
    player_Tick[playerid][type] = tick;
}

/*
 * <summary> Returns player's cooldown ticks</summary>
 * <param name="playerid"> playerid whose ticks are returned</param>
 * <param name="type"> type of cooldown</param>
 */

stock Cooldown_GetPlayerTick(playerid, type)
{
    return player_Tick[playerid][type];
}

/*
 * <summary> Returns player's cooldown time</summary>
 * <param name="playerid"> playerid whose time are returned</param>
 * <param name="type"> type of cooldown</param>
 */

stock Cooldown_GetPlayerTime(playerid, type)
{
    return player_Time[playerid][type];
}

/*
 * <summary> Sets player's cooldown time</summary>
 * <param name="playerid"> playerid whose time are returned</param>
 * <param name="type"> type of cooldown</param>
 */

stock Cooldown_SetPlayerTime(playerid, type, time)
{
    return player_Time[playerid][type] = time;
}