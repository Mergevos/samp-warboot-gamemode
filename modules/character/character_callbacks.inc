/*
 * <summary>Called when a player registers</summary>
 * <param name="playerid"> playerid who  registered</param>
 */

forward OnPlayerRegister(playerid);

/*
 * <summary>Called when a player logins</summary>
 * <param name="playerid"> playerid who login</param>
 */
 
forward OnPlayerLogin(playerid);

/*
 * <summary>Called when a player character got checked</summary>
 * <param name="playerid"> playerid whose character got checked</param>
 */
 
forward OnPlayerCharacterChecked(playerid);

//----------------------------------------------------------------
public void: OnPlayerRegister(playerid)
{
    Account_SetID(playerid, cache_insert_id());
    Character_ShowTextdraws(playerid);
    SelectTextDraw(playerid, -1);
}

public void: OnPlayerLogin(playerid)
{
    mysql_tquery_s(
        Database_ReturnHandle(), 
            str_format("SELECT * \
            FROM `characters` \
            WHERE `character_username` = '%e'", Misc_ReturnName(playerid)),
            "OnPlayerCharacterChecked", "i", playerid
    );
    
}

public OnPlayerCharacterChecked(playerid)
{
    if(cache_num_rows()) {
        static 
            load_Name[MAX_PLAYER_NAME],
            load_Age,
            load_Skin,
            load_Country;

        cache_get_value_name_int(0, "character_age", load_Age);
        cache_get_value_name_int(0, "character_skin", load_Skin);
        cache_get_value_name_int(0, "character_country", load_Country);
        cache_get_value_name(0, "character_name", load_Name, MAX_PLAYER_NAME);

        Character_SetAge(playerid, load_Age);
        Character_SetSkin(playerid, load_Skin);
        Character_SetCountry(playerid, load_Country);
        Account_SetName(playerid, Misc_ReturnName(playerid));
        SetPlayerName(playerid, load_Name);

        TogglePlayerSpectating(playerid, false);
        SetSpawnInfo(playerid, NO_TEAM, Character_ReturnSkin(playerid), 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
        SpawnPlayer(playerid);
     
        return 0;
    }
    Character_ShowTextdraws(playerid);
    SelectTextDraw(playerid, -1);
    return 1;
}
