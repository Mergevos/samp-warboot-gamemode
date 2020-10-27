// by IllidanS4
/*
 * <summary> Used to check if roleplay name is valid.</summary>
 * <param name="playerid"> playerid whose name is to be checked</param>
 */ 
forward [MAX_PLAYER_NAME + 1]Misc_ReturnName(playerid);
stock Misc_ReturnName(playerid)
{
    #assert MAX_PLAYER_NAME + 1 == 25
    #emit PUSH.C 25
    #emit PUSH.S 16
    #emit PUSH.S playerid
    #emit PUSH.C 12
    #emit SYSREQ.C GetPlayerName
    #emit STACK 16
    #emit RETN
}