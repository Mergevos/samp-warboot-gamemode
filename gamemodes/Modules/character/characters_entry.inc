static 
    character_Country[MAX_PLAYERS],
    character_Age[MAX_PLAYERS],
    character_Skin[MAX_PLAYERS],
    character_Gender[MAX_PLAYERS],
	character_DOB[MAX_PLAYER_NAME][32],
    character_User_Name[MAX_PLAYERS][MAX_PLAYER_NAME];
 

/*
  * <summary> Sets character's country</summary>
  * <param name="playerid"> playerid to set</param>
  * <param name="name"> name to set</param>
  */

stock Character_SetUserName(playerid, const name[MAX_PLAYER_NAME])
{
    strcopy(character_User_Name[playerid], name);
}

/*
  * <summary> Sets character's country</summary>
  * <param name="playerid"> playerid to set</param>
  * <param name="skinid"> country to set</param>
  */

stock Character_SetCountry(playerid, const country)
{
    character_Country[playerid] = country;
}

/*
  * <summary> Sets character's gender</summary>
  * <param name="playerid"> playerid to set</param>
  * <param name="gender"> gender to set</param>
  */

stock Character_SetGender(playerid, const gender)
{
    character_Gender[playerid] = gender;
}



/*
  * <summary> Sets character's skin</summary>
  * <param name="playerid"> playerid to set</param>
  * <param name="skinid"> skinid to set</param>
  */

stock Character_SetSkin(playerid, const skinid)
{
    character_Skin[playerid] = skinid;
    SetPlayerSkin(playerid, skinid);
}

/*
  * <summary> Sets character's age</summary>
  * <param name="playerid"> playerid to set</param>
  * <param name="playerid"> age to set</param>
  */

stock Character_SetAge(playerid, const skinid)
{
    character_Age[playerid] = skinid;
}

/*
  * <summary> Sets character's age</summary>
  * <param name="playerid"> playerid to set</param>
  * <param name="dob"> date to set</param>
  */

stock Character_SetDOB(playerid, const dob[])
{
    strcopy(character_DOB[playerid], dob);
}

 /*
  * <summary> Returns character's user name</summary>
  * <param name="playerid"> playerid to return</param>
  */

stock Character_ReturnUserName(playerid)
{
    return character_User_Name[playerid];
}

 /*
  * <summary> Returns character's country</summary>
  * <param name="playerid"> playerid to return</param>
  */

stock Character_ReturnCountry(playerid)
{
    return character_Country[playerid];
}

/*
  * <summary> Returns character's age</summary>
  * <param name="playerid"> playerid to return</param>
  */

stock Character_ReturnAge(playerid)
{
    return character_Age[playerid];
}

/*
 * <summary> Returns character's skin</summary>
 * <param name="playerid"> playerid to return</param>
 */

stock Character_ReturnSkin(playerid)
{
    return character_Skin[playerid];
}

/*
 * <summary> Returns character's gender</summary>
 * <param name="playerid"> playerid to return</param>
 */

stock Character_ReturnGender(playerid)
{
	return character_Gender[playerid];
}

/*
 * <summary> Returns character's date of birth</summary>
 * <param name="playerid"> playerid to return</param>
 */

stock Character_ReturnDOB(playerid)
{
	return character_DOB[playerid];
}

