#include <YSI_Coding\y_hooks>
static auth_RaceCheck[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    auth_RaceCheck[playerid] ++;   
    account_CheckIfExists(playerid, auth_RaceCheck[playerid]);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{

    auth_RaceCheck[playerid]++;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

 /*
  * <summary> Checks if player's acc exists</summary>
  * <param name="playerid"> playerid to reset info</param>
  * <param name="race_check"> race_check to check/param>
  */


static stock account_CheckIfExists(playerid, const race_check)
{
    if(race_check != auth_RaceCheck[playerid]) {
        return Kick(playerid);
    }
    mysql_tquery_s(
        Database_ReturnHandle(), 
            str_format("SELECT * \
            FROM `accounts` \
            WHERE `account_name` = '%e'", Misc_ReturnName(playerid)),
            "OnPlayerAccountChecked", "i", playerid
    );
    return 0;
}

