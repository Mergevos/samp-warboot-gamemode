static 
    account_ID[MAX_PLAYERS],
    account_Name[MAX_PLAYERS][MAX_PLAYER_NAME],
    account_Email[MAX_PLAYERS][40],
    account_Password[MAX_PLAYERS][61];

/*                 */
/*       APi       */
/*                 */

// --
// <summary> Return account's sql id</summary>
    // <param name="playerid"> playerid to return ID</param>
// --

stock Account_ReturnID(playerid)
{
    return account_ID[playerid];
}

// --
// <summary> Return account's email</summary>
    // <param name="playerid"> playerid to return email</param>
// --


stock Account_ReturnEmail(playerid)
{
    return account_Email[playerid];
}

// --
// <summary> Return account's password</summary>
    // <param name="playerid"> playerid to return password</param>
// --


stock Account_ReturnPassword(playerid)
{
    return account_Password[playerid];
}

// --
// <summary> Return account's name</summary>
    // <param name="playerid"> playerid to return name</param>
// --


stock Account_ReturnName(playerid)
{
    return account_Name[playerid];
}

 /*
  * <summary> Seta account's name</summary>
  * <param name="playerid"> playerid to Sett ID</param>
  * <param name="name"> Name to set</param>
  */

stock Account_SetName(playerid, const name[MAX_PLAYER_NAME])
{
    strcopy(account_Name[playerid], name);
}

 /*
  * <summary> Seta account's name</summary>
  * <param name="playerid"> playerid to reset info</param>
  */


stock Account_ResetInfo(playerid)
{
    account_ID[playerid] = -1, // start sqlid = 0
    account_Name[playerid][0] = EOS,
    account_Email[playerid][0] = EOS,
    account_Password[playerid][0] = EOS;
}

