static 
    account_ID[MAX_PLAYERS],
    account_Name[MAX_PLAYERS][MAX_PLAYER_NAME],
    account_Email[MAX_PLAYERS][40],
    account_Password[MAX_PLAYERS][61],
    account_Password_Attempts[MAX_PLAYERS] = 0,
    account_Player_Choosen_Country[MAX_PLAYERS];

/*                 */
/*       APi       */
/*                 */

/* --
 * <summary> Return account's sql id</summary>
 * <param name="playerid"> playerid to return ID</param>
 */

stock Account_ReturnID(playerid)
{
    return account_ID[playerid];
}

 /*
  * <summary> Return account's login attempts</summary>
  * <param name="playerid"> playerid to return</param>
  */

stock Account_ReturnLoginAttempts(playerid)
{
    return account_Password_Attempts[playerid];
}

/*
  * <summary> Return account's choosen country</summary>
  * <param name="playerid"> playerid to return</param>
  */

stock Account_ReturnCountry(playerid)
{
    return account_Player_Choosen_Country[playerid];
}


/*
 * <summary> Return account's email</summary>
 * <param name="playerid"> playerid to return email</param>
 */


stock Account_ReturnEmail(playerid)
{
    return account_Email[playerid];
}

/*
 * <summary> Return account's password</summary>
 * <param name="playerid"> playerid to return password</param>
 */


stock Account_ReturnPassword(playerid)
{
    return account_Password[playerid];
}

/*
 * <summary> Return account's name</summary>
 * <param name="playerid"> playerid to return name</param>
 */


stock Account_ReturnName(playerid)
{
    return account_Name[playerid];
}

 /*
  * <summary> Seta account's sqlid</summary>
  * <param name="playerid"> playerid to Sett ID</param>
  * <param name="name"> id to set</param>
  */

stock Account_SetID(playerid, const id)
{
    account_ID[playerid] = id;
}

/*
  * <summary> Sets account's login attempts</summary>
  * <param name="playerid"> playerid to set</param>
  * <param name="amount"> amount to set</param>
  */

stock Account_SetLoginAttempts(playerid, amount)
{
    account_Password_Attempts[playerid] = amount;
}


 /*
  * <summary> Seta account's password</summary>
  * <param name="playerid"> playerid to Sett password</param>
  * <param name="pass"> password to set</param>
  */


stock Account_SetPassword(playerid, const pass[61])
{
    strcopy(account_Password[playerid], pass);
}


/*
  * <summary> Seta account's name</summary>
  * <param name="playerid"> playerid to Sett name</param>
  * <param name="name"> Name to set</param>
  */

stock Account_SetName(playerid, const name[MAX_PLAYER_NAME+1])
{
    strcopy(account_Name[playerid], name);
}

 /*
  * <summary> Seta account's email</summary>
  * <param name="playerid"> playerid to Sett email</param>
  * <param name="email"> Email to set</param>
  */

stock Account_SetEmail(playerid, const email[])
{
    strcopy(account_Email[playerid], email);
}


 /*
  * <summary> Resets player info</summary>
  * <param name="playerid"> playerid to reset info</param>
  */


stock Account_ResetInfo(playerid)
{
    account_ID[playerid] = -1, // start sqlid = 0
    account_Name[playerid][0] = EOS,
    account_Email[playerid][0] = EOS,
    account_Password[playerid][0] = EOS;
}

/*
  * <summary> Sets account's choosen country</summary>
  * <param name="playerid"> playerid to set</param>
  */

stock Account_SetCountry(playerid, value)
{
    account_Player_Choosen_Country[playerid] = value;
}
