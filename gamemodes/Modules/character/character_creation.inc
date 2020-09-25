static const
    male_Skins[] = {21, 22, 24, 25, 26, 28, 29, 33, 34, 44, 62, 67, 78, 79, 132, 133, 134, 135, 229, 230, 231, 232},
    female_Skins[] = {11, 12, 13, 39, 40, 41, 55, 56, 64, 69, 89, 90, 91, 93, 129, 130, 131, 157, 169, 192, 195, 226};

stock Character_SelectNameDialog(playerid, const nationid)
{
    task_yield(1);
    new 
        National_Dialog_Response[e_DIALOG_RESPONSE_INFO],
        String: Nation,
        String: Nation_names;

    if(nationid == 1) {
        Nation = str_new("People's republic of China"),
        Nation_names = str_new("Wei, Baozhai");
    } else if(nationid == 2) {
        Nation = str_new("the United States of America");
        Nation_names = str_new("James, Angel");
    } else if(nationid == 3) {
        Nation = str_new("Russia");
        Nation_names = str_new("Dmitriy, Eva");
    }

    task_await_arr(ShowPlayerAsyncDialogStr(playerid, DIALOG_STYLE_INPUT, 
        str_new(""INDIANRED"C{ffffff}haracter"INDIANRED" N{ffffff}ame"), 
        str_format(""LIGHTGREEN">"INDIANRED"%s,\n\
        "LIGHTGREEN"> {ffffff} We please you to input your desired name, which will be, used as name of your character.\n\
        "LIGHTGREEN"> {ffffff} Take into account that you've selected %S as your nation, thus, names like %S, and equal last names too, are welcome.\n\
        "LIGHTGREEN"> {ffffff} In order to continue, names have to be in Name_LastName format. You will have to select the gender, thus, the name must match gender.", 
        Misc_ReturnName(playerid), Nation, Nation_names), 
    str_new(""GREEN"Continue"), str_new(""RED"Exit")), National_Dialog_Response);

    if(National_Dialog_Response[E_DIALOG_RESPONSE_Response]) {
        if(!Misc_CheckRoleplayName(National_Dialog_Response[E_DIALOG_RESPONSE_InputText])) {
           return Character_SelectNameDialog(playerid, nationid);
        }
        SetPVarString(playerid, "Char_Name", National_Dialog_Response[E_DIALOG_RESPONSE_InputText]); 
        va_SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff} You've choosen your name as %s", National_Dialog_Response[E_DIALOG_RESPONSE_InputText]);
        Character_SelectGender(playerid);
        
    } else {
        Character_ShowTextdraws(playerid);
        SelectTextDraw(playerid, -1);
    }
    return 0;
}

stock void: Character_SelectGender(playerid)
{
    task_yield(1);
    new 
        National_Gender_Response[e_DIALOG_RESPONSE_INFO];

    task_await_arr(ShowPlayerAsyncDialogStr(playerid, DIALOG_STYLE_MSGBOX, 
        str_new(""INDIANRED"C{ffffff}haracter"INDIANRED" G{ffffff}ender"), 
        str_format(""LIGHTGREEN">"INDIANRED"%s,\n\
        "LIGHTGREEN"> {ffffff} We please you to select your desired gender, which will be, used as gender of your character.",
        Misc_ReturnName(playerid)), 
    str_new(""GREY"Male"), str_new(""PINK"Female")), National_Gender_Response);

    if(National_Gender_Response[E_DIALOG_RESPONSE_Response]) {
        Character_SetGender(playerid, 1);
        SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff} You've choosen your gender as male");
        Character_SelectDateOfBirth(playerid);
    } else {
        Character_SetGender(playerid, 2); 
        SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff} You've choosen your gender as female");
        Character_SelectDateOfBirth(playerid);
    }
}

stock Character_SelectDateOfBirth(playerid)
{
    task_yield(1);
    new 
        National_Date_Response[e_DIALOG_RESPONSE_INFO], 
        Day, 
        Month, 
        Year,
        Dob_String[32];

    static const
	    arr_Months_Days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    task_await_arr(ShowPlayerAsyncDialogStr(playerid, DIALOG_STYLE_INPUT, 
        str_new(""INDIANRED"C{ffffff}haracter"INDIANRED" D{ffffff}oB"), 
        str_format(""LIGHTGREEN">"INDIANRED"%s,\n\
        "LIGHTGREEN"> {ffffff} We please you to input date of birth for your character.\n\
        "LIGHTGREEN"> {ffffff} Take into account that we only accept dd/mm/yyyy format",
        Misc_ReturnName(playerid)), 
    str_new(""GREEN"Continue"), str_new(""RED"Exit")), National_Date_Response);

    if(National_Date_Response[E_DIALOG_RESPONSE_Response]) {
        if (sscanf(National_Date_Response[E_DIALOG_RESPONSE_InputText], "p</>ddd", Day, Month, Year)) {
            SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff}Your didn't use the correct syntax");
            return Character_SelectDateOfBirth(playerid);
        } else if (!(1930 < Year < 2020)) {
            SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff}Your didn't input the correct year");
            return Character_SelectDateOfBirth(playerid);
            
        } else if (!(1 < Month < 12)) {
            SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff}Your didn't input the correct month");
            return Character_SelectDateOfBirth(playerid);
            
        } else if (!(1 < Day < arr_Months_Days[Month - 1])) {
            SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff}Your didn't input the correct day");
            return Character_SelectDateOfBirth(playerid);
            
        }
        va_SendClientMessage(playerid, -1, ""INDIANRED"[WARBOOT] {ffffff}Your date of birth is %d/%d/%d", Day, Month, Year);
        format(Dob_String, sizeof(Dob_String), "%d/%d/%d", Day, Month, Year);
        Character_SetDOB(playerid, Dob_String);
        Character_SelectSkin(playerid);
    } else { 
        Character_SelectGender(playerid);
    }
    return 0;
}

stock void: Character_SelectSkin(playerid)
{
    task_yield(1);
    new List: Skins = list_new(), 
        Response[E_MODEL_SELECTION_INFO];

    if(Character_ReturnGender(playerid) == 1) {
        for(new i; i < sizeof(male_Skins); i++) {
            AddModelMenuItem(Skins, male_Skins[i]);
        }
    } else {
        for(new i; i < sizeof(female_Skins); i++) {
            AddModelMenuItem(Skins, female_Skins[i]);
        }
    }

    task_await_arr(
        ShowAsyncModelSelectionMenu(playerid, "Character Skins", Skins), Response);

    if(Response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT) {
        static return_String[MAX_PLAYER_NAME];
        GetPVarString(playerid, "Char_Name", return_String, MAX_PLAYER_NAME);
        Character_SetSkin(playerid, Response[E_MODEL_SELECTION_MODELID]);
        mysql_aquery_s(Database_ReturnHandle(), 
            str_format("INSERT INTO `characters`\
            (`character_name`, `character_username`, `character_country`, `character_gender`, `character_age`, `character_skin`, `character_birthdate`) \
            VALUES \
            ('%e', '%e', %d, %d, %d, %d, '%e')", 
            return_String, 
            Misc_ReturnName(playerid), 
            Character_ReturnCountry(playerid),
            Character_ReturnGender(playerid),
            Character_ReturnAge(playerid),
            Character_ReturnSkin(playerid),
            Character_ReturnDOB(playerid)));
        TogglePlayerSpectating(playerid, false);
        SetSpawnInfo(playerid, NO_TEAM, Character_ReturnSkin(playerid), 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
        SpawnPlayer(playerid);
    } else {
        Character_SelectDateOfBirth(playerid);
    }
}