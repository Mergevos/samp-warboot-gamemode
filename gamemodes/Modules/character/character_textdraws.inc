//Global TextDraws: 
#include <YSI_Coding\y_hooks>

static
    Text: character_Country_Selection[18],
    PlayerText: characterSelectTD[MAX_PLAYERS][10];

hook OnGameModeInit()
{
    character_InitTextdraws();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    character_DestroyTextDraws();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    character_InitPlayerTextDraws(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}
/*
  * <summary> Destroy character's tds</summary>
  */

static stock character_DestroyTextDraws()
{
    for (new i; i < sizeof(character_Country_Selection); i++) {
        TextDrawDestroy(character_Country_Selection[i]);
    }
}

/*
  * <summary> Creates character's tds</summary>
  */

static stock character_InitTextdraws()
{
    character_Country_Selection[0] = TextDrawCreate(316.701629, 126.996238, "box");
    TextDrawLetterSize(character_Country_Selection[0], 0.000000, 24.383598);
    TextDrawTextSize(character_Country_Selection[0], 0.000000, 130.000000);
    TextDrawAlignment(character_Country_Selection[0], 2);
    TextDrawColor(character_Country_Selection[0], -1);
    TextDrawUseBox(character_Country_Selection[0], 1);
    TextDrawBoxColor(character_Country_Selection[0], 150);
    TextDrawSetShadow(character_Country_Selection[0], 0);
    TextDrawSetOutline(character_Country_Selection[0], 0);
    TextDrawBackgroundColor(character_Country_Selection[0], 255);
    TextDrawFont(character_Country_Selection[0], 1);
    TextDrawSetProportional(character_Country_Selection[0], 1);
    TextDrawSetShadow(character_Country_Selection[0], 0);

    character_Country_Selection[1] = TextDrawCreate(175.092987, 126.996238, "box");
    TextDrawLetterSize(character_Country_Selection[1], 0.000000, 24.383598);
    TextDrawTextSize(character_Country_Selection[1], 0.000000, 130.000000);
    TextDrawAlignment(character_Country_Selection[1], 2);
    TextDrawColor(character_Country_Selection[1], -1);
    TextDrawUseBox(character_Country_Selection[1], 1);
    TextDrawBoxColor(character_Country_Selection[1], 150);
    TextDrawSetShadow(character_Country_Selection[1], 0);
    TextDrawSetOutline(character_Country_Selection[1], 0);
    TextDrawBackgroundColor(character_Country_Selection[1], 255);
    TextDrawFont(character_Country_Selection[1], 1);
    TextDrawSetProportional(character_Country_Selection[1], 1);
    TextDrawSetShadow(character_Country_Selection[1], 0);

    character_Country_Selection[2] = TextDrawCreate(458.110260, 126.996238, "box");
    TextDrawLetterSize(character_Country_Selection[2], 0.000000, 24.383598);
    TextDrawTextSize(character_Country_Selection[2], 0.000000, 130.000000);
    TextDrawAlignment(character_Country_Selection[2], 2);
    TextDrawColor(character_Country_Selection[2], -1);
    TextDrawUseBox(character_Country_Selection[2], 1);
    TextDrawBoxColor(character_Country_Selection[2], 150);
    TextDrawSetShadow(character_Country_Selection[2], 0);
    TextDrawSetOutline(character_Country_Selection[2], 0);
    TextDrawBackgroundColor(character_Country_Selection[2], 255);
    TextDrawFont(character_Country_Selection[2], 1);
    TextDrawSetProportional(character_Country_Selection[2], 1);
    TextDrawSetShadow(character_Country_Selection[2], 0);

    character_Country_Selection[3] = TextDrawCreate(139.173278, 336.149902, "ld_pool:ball");
    TextDrawLetterSize(character_Country_Selection[3], 0.000000, 0.000000);
    TextDrawTextSize(character_Country_Selection[3], 71.000000, 24.000000);
    TextDrawAlignment(character_Country_Selection[3], 1);
    TextDrawColor(character_Country_Selection[3], 4063487);
    TextDrawSetShadow(character_Country_Selection[3], 0);
    TextDrawSetOutline(character_Country_Selection[3], 0);
    TextDrawBackgroundColor(character_Country_Selection[3], 255);
    TextDrawFont(character_Country_Selection[3], 4);
    TextDrawSetProportional(character_Country_Selection[3], 0);
    TextDrawSetShadow(character_Country_Selection[3], 0);

    character_Country_Selection[4] = TextDrawCreate(175.167114, 341.500000, "Enter");
    TextDrawLetterSize(character_Country_Selection[4], 0.356999, 1.309998);
    TextDrawTextSize(character_Country_Selection[4], 10.000000, 33.000000);
    TextDrawAlignment(character_Country_Selection[4], 2);
    TextDrawColor(character_Country_Selection[4], -2139094785);
    TextDrawUseBox(character_Country_Selection[4], 1);
    TextDrawBoxColor(character_Country_Selection[4], 0xFFFFFF00);
    TextDrawSetShadow(character_Country_Selection[4], 0);
    TextDrawSetOutline(character_Country_Selection[4], 1);
    TextDrawBackgroundColor(character_Country_Selection[4], 255);
    TextDrawFont(character_Country_Selection[4], 3);
    TextDrawSetProportional(character_Country_Selection[4], 1);
    TextDrawSetShadow(character_Country_Selection[4], 0);
    TextDrawSetSelectable(character_Country_Selection[4], true);

    character_Country_Selection[5] = TextDrawCreate(114.773086, 172.499954, "-_People_s_Republic_of_China_is_a~n~country_located_in_East_Asia._It_s_a_~n~socialist_republic._The_country_with~n~the_biggest_number_of_citizen._~n~~n~__________-_Informations_-~n~~n~-_Main_ethnic_group:_Han_Chinese~n~-_Main_language:_Standard_Mandarin~n~-_Main_script:_Simplified_chinese~n~-_Capital_city:_Beijing~n~~n~__-_In_Game_holds_San_Fierro_-");
    TextDrawLetterSize(character_Country_Selection[5], 0.193850, 1.086665);
    TextDrawAlignment(character_Country_Selection[5], 1);
    TextDrawColor(character_Country_Selection[5], -1);
    TextDrawSetShadow(character_Country_Selection[5], 0);
    TextDrawSetOutline(character_Country_Selection[5], 1);
    TextDrawBackgroundColor(character_Country_Selection[5], 255);
    TextDrawFont(character_Country_Selection[5], 1);
    TextDrawSetProportional(character_Country_Selection[5], 1);
    TextDrawSetShadow(character_Country_Selection[5], 0);

    Flag_Create(E_FLAG_PRC, E_FLAG_MEDIUM, 173.395706, 106.749809);

    character_Country_Selection[6] = TextDrawCreate(172.401184, 143.916671, "-_Current_Leader_-");
    TextDrawLetterSize(character_Country_Selection[6], 0.249001, 1.100000);
    TextDrawAlignment(character_Country_Selection[6], 2);
    TextDrawColor(character_Country_Selection[6], -1);
    TextDrawSetShadow(character_Country_Selection[6], 0);
    TextDrawSetOutline(character_Country_Selection[6], 1);
    TextDrawBackgroundColor(character_Country_Selection[6], 255);
    TextDrawFont(character_Country_Selection[6], 1);
    TextDrawSetProportional(character_Country_Selection[6], 1);
    TextDrawSetShadow(character_Country_Selection[6], 0);

    character_Country_Selection[7] = TextDrawCreate(172.401184, 154.217300, "Xing_Jang_Mi");
    TextDrawLetterSize(character_Country_Selection[7], 0.214001, 0.940000);
    TextDrawAlignment(character_Country_Selection[7], 2);
    TextDrawColor(character_Country_Selection[7], -16776961);
    TextDrawSetShadow(character_Country_Selection[7], 0);
    TextDrawSetOutline(character_Country_Selection[7], 1);
    TextDrawBackgroundColor(character_Country_Selection[7], 255);
    TextDrawFont(character_Country_Selection[7], 1);
    TextDrawSetProportional(character_Country_Selection[7], 1);
    TextDrawSetShadow(character_Country_Selection[7], 0);

    character_Country_Selection[8] = TextDrawCreate(281.581970, 336.549926, "ld_pool:ball");
    TextDrawLetterSize(character_Country_Selection[8], 0.000000, 0.000000);
    TextDrawTextSize(character_Country_Selection[8], 71.000000, 24.000000);
    TextDrawAlignment(character_Country_Selection[8], 1);
    TextDrawColor(character_Country_Selection[8], 4063487);
    TextDrawSetShadow(character_Country_Selection[8], 0);
    TextDrawSetOutline(character_Country_Selection[8], 0);
    TextDrawBackgroundColor(character_Country_Selection[8], 255);
    TextDrawFont(character_Country_Selection[8], 4);
    TextDrawSetProportional(character_Country_Selection[8], 0);
    TextDrawSetShadow(character_Country_Selection[8], 0);

    character_Country_Selection[9] = TextDrawCreate(318.575866, 341.800018, "Enter");
    TextDrawLetterSize(character_Country_Selection[9], 0.356999, 1.309998);
    TextDrawTextSize(character_Country_Selection[9], 10.000000, 33.000000);
    TextDrawAlignment(character_Country_Selection[9], 2);
    TextDrawColor(character_Country_Selection[9], -2139094785);
    TextDrawUseBox(character_Country_Selection[9], 1);
    TextDrawBoxColor(character_Country_Selection[9], 0xFFFFFF00);
    TextDrawSetShadow(character_Country_Selection[9], 0);
    TextDrawSetOutline(character_Country_Selection[9], 1);
    TextDrawBackgroundColor(character_Country_Selection[9], 255);
    TextDrawFont(character_Country_Selection[9], 3);
    TextDrawSetProportional(character_Country_Selection[9], 1);
    TextDrawSetShadow(character_Country_Selection[9], 0);
    TextDrawSetSelectable(character_Country_Selection[9], true);


    character_Country_Selection[10] = TextDrawCreate(422.090545, 336.549926, "ld_pool:ball");
    TextDrawLetterSize(character_Country_Selection[10], 0.000000, 0.000000);
    TextDrawTextSize(character_Country_Selection[10], 71.000000, 24.000000);
    TextDrawAlignment(character_Country_Selection[10], 1);
    TextDrawColor(character_Country_Selection[10], 4063487);
    TextDrawSetShadow(character_Country_Selection[10], 0);
    TextDrawSetOutline(character_Country_Selection[10], 0);
    TextDrawBackgroundColor(character_Country_Selection[10], 255);
    TextDrawFont(character_Country_Selection[10], 4);
    TextDrawSetProportional(character_Country_Selection[10], 0);
    TextDrawSetShadow(character_Country_Selection[10], 0);

    character_Country_Selection[11] = TextDrawCreate(457.784362, 341.600006, "Enter");
    TextDrawLetterSize(character_Country_Selection[11], 0.356999, 1.309998);
    TextDrawTextSize(character_Country_Selection[11], 10.000000, 32.000000);
    TextDrawAlignment(character_Country_Selection[11], 2);
    TextDrawColor(character_Country_Selection[11], -2139094785);
    TextDrawUseBox(character_Country_Selection[11], 1);
    TextDrawBoxColor(character_Country_Selection[11], 0xFFFFFF00);
    TextDrawSetShadow(character_Country_Selection[11], 0);
    TextDrawSetOutline(character_Country_Selection[11], 1);
    TextDrawBackgroundColor(character_Country_Selection[11], 255);
    TextDrawFont(character_Country_Selection[11], 3);
    TextDrawSetProportional(character_Country_Selection[11], 1);
    TextDrawSetShadow(character_Country_Selection[11], 0);
    TextDrawSetSelectable(character_Country_Selection[11], true);

    character_Country_Selection[12] = TextDrawCreate(256.580718, 172.499954, "-_The_United_States_of_America_is~n~a_country_located_in_North_America.~n~It_consists_of_50_states,_thus_there_~n~are_50_stars_on_the_USA_flag._There~n~are_more_than_300_million_people_~n~living_in_the_USA.~n~~n~__________-_Informations_-~n~~n~-_Main_ethnic_group:_73%_white~n~-_Main_language:_American_English~n~-_Main_script:_Latin~n~-_Capital_city:_Washington_DC~n~~n~__-_In_Game_holds_Los_Santos_-");
    TextDrawLetterSize(character_Country_Selection[12], 0.193850, 1.086665);
    TextDrawAlignment(character_Country_Selection[12], 1);
    TextDrawColor(character_Country_Selection[12], -1);
    TextDrawSetShadow(character_Country_Selection[12], 0);
    TextDrawSetOutline(character_Country_Selection[12], 1);
    TextDrawBackgroundColor(character_Country_Selection[12], 255);
    TextDrawFont(character_Country_Selection[12], 1);
    TextDrawSetProportional(character_Country_Selection[12], 1);
    TextDrawSetShadow(character_Country_Selection[12], 0);

    character_Country_Selection[13] = TextDrawCreate(398.089355, 172.499954, "-_Russian_federation_is_a_transcont-~n~intal_country_located_in_Eastern~n~Europe_and_Northern_Asia._The~n~largest_country_in_the_world_and_it~n~borders_16_sovereign_countries._~n~There_are_85_Russian_Subjects._~n~~n~_________-_Informations_-~n~~n~-_Main_ethnic_group:_Russians~n~-_Main_language:_Russian~n~-_Main_script:_Cyrillic~n~-_Capital_city:_Moscow~n~~n~__-_In_Game_holds_Las_Venturas_-");
    TextDrawLetterSize(character_Country_Selection[13], 0.193850, 1.086665);
    TextDrawAlignment(character_Country_Selection[13], 1);
    TextDrawColor(character_Country_Selection[13], -1);
    TextDrawSetShadow(character_Country_Selection[13], 0);
    TextDrawSetOutline(character_Country_Selection[13], 1);
    TextDrawBackgroundColor(character_Country_Selection[13], 255);
    TextDrawFont(character_Country_Selection[13], 1);
    TextDrawSetProportional(character_Country_Selection[13], 1);
    TextDrawSetShadow(character_Country_Selection[13], 0);

    character_Country_Selection[14] = TextDrawCreate(314.709869, 143.916671, "-_Current_Leader_-");
    TextDrawLetterSize(character_Country_Selection[14], 0.249001, 1.100000);
    TextDrawAlignment(character_Country_Selection[14], 2);
    TextDrawColor(character_Country_Selection[14], -1);
    TextDrawSetShadow(character_Country_Selection[14], 0);
    TextDrawSetOutline(character_Country_Selection[14], 1);
    TextDrawBackgroundColor(character_Country_Selection[14], 255);
    TextDrawFont(character_Country_Selection[14], 1);
    TextDrawSetProportional(character_Country_Selection[14], 1);
    TextDrawSetShadow(character_Country_Selection[14], 0);

    character_Country_Selection[15] = TextDrawCreate(313.304290, 153.684082, "Donald_Duck");
    TextDrawLetterSize(character_Country_Selection[15], 0.214001, 0.940000);
    TextDrawAlignment(character_Country_Selection[15], 2);
    TextDrawColor(character_Country_Selection[15], -1056899073);
    TextDrawSetShadow(character_Country_Selection[15], 0);
    TextDrawSetOutline(character_Country_Selection[15], 1);
    TextDrawBackgroundColor(character_Country_Selection[15], 255);
    TextDrawFont(character_Country_Selection[15], 1);
    TextDrawSetProportional(character_Country_Selection[15], 1);
    TextDrawSetShadow(character_Country_Selection[15], 0);

    Flag_Create(E_FLAG_USA, E_FLAG_MEDIUM, 315.104339, 106.749809);

    character_Country_Selection[16] = TextDrawCreate(457.018554, 143.616653, "-_Current_Leader_-");
    TextDrawLetterSize(character_Country_Selection[16], 0.249001, 1.100000);
    TextDrawAlignment(character_Country_Selection[16], 2);
    TextDrawColor(character_Country_Selection[16], -1);
    TextDrawSetShadow(character_Country_Selection[16], 0);
    TextDrawSetOutline(character_Country_Selection[16], 1);
    TextDrawBackgroundColor(character_Country_Selection[16], 255);
    TextDrawFont(character_Country_Selection[16], 1);
    TextDrawSetProportional(character_Country_Selection[16], 1);
    TextDrawSetShadow(character_Country_Selection[16], 0);

    character_Country_Selection[17] = TextDrawCreate(455.412963, 153.684082, "Vlad_The_Big_Dick");
    TextDrawLetterSize(character_Country_Selection[17], 0.214001, 0.940000);
    TextDrawAlignment(character_Country_Selection[17], 2);
    TextDrawColor(character_Country_Selection[17], 5373951);
    TextDrawSetShadow(character_Country_Selection[17], 0);
    TextDrawSetOutline(character_Country_Selection[17], 1);
    TextDrawBackgroundColor(character_Country_Selection[17], 255);
    TextDrawFont(character_Country_Selection[17], 1);
    TextDrawSetProportional(character_Country_Selection[17], 1);
    TextDrawSetShadow(character_Country_Selection[17], 0);

    Flag_Create(E_FLAG_RUSSIAN, E_FLAG_MEDIUM, 457.013000, 106.749809);

}

static stock character_InitPlayerTextDraws(playerid)
{
    characterSelectTD[playerid][0] = CreatePlayerTextDraw(playerid, 243.694046, 157.649993, "box");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][0], 0.000000, 9.670591);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][0], 399.399902, 0.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, characterSelectTD[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, characterSelectTD[playerid][0], 555819519);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][0], 1);

    characterSelectTD[playerid][1] = CreatePlayerTextDraw(playerid, 246.705932, 177.166641, "box");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][1], 0.000000, 1.529404);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][1], 396.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, characterSelectTD[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, characterSelectTD[playerid][1], 808464639);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][1], 1);

    characterSelectTD[playerid][2] = CreatePlayerTextDraw(playerid, 247.094268, 200.549850, "box");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][2], 0.000000, 1.529404);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][2], 395.800109, 0.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, characterSelectTD[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, characterSelectTD[playerid][2], 808464639);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][2], 1);

    characterSelectTD[playerid][3] = CreatePlayerTextDraw(playerid, 247.094268, 224.051284, "box");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][3], 0.000000, 1.529404);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][3], 395.800109, 0.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, characterSelectTD[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, characterSelectTD[playerid][3], 808464639);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][3], 1);

    characterSelectTD[playerid][4] = CreatePlayerTextDraw(playerid, 249.970565, 160.049972, "BeverlyProjectAlpha");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][4], 0.199999, 0.935000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][4], 1);

    characterSelectTD[playerid][5] = CreatePlayerTextDraw(playerid, 317.664672, 179.099960, "CHARACTER_1");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][5], 0.199999, 0.935000);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][5], 10.000000, 65.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][5], 2);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][5], 1347440895);
    PlayerTextDrawUseBox(playerid, characterSelectTD[playerid][5], 0xFFFFFF00);
    PlayerTextDrawBoxColor(playerid, characterSelectTD[playerid][5], 1347440895);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, characterSelectTD[playerid][5], true);

    characterSelectTD[playerid][6] = CreatePlayerTextDraw(playerid, 317.664672, 202.599914, "CHARACTER_2");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][6], 0.199999, 0.935000);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][6], 10.000000, 65.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][6], 2);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][6], 1347440895);
    PlayerTextDrawUseBox(playerid, characterSelectTD[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, characterSelectTD[playerid][6], 0xFFFFFF00);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, characterSelectTD[playerid][6], true);

    characterSelectTD[playerid][7] = CreatePlayerTextDraw(playerid, 317.664672, 226.649810, "CHARACTER_3");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][7], 0.199999, 0.935000);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][7], 10.000000, 65.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][7], 2);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][7], 1347440895);
    PlayerTextDrawUseBox(playerid, characterSelectTD[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, characterSelectTD[playerid][7], 0xFFFFFF00);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, characterSelectTD[playerid][7], true);

    characterSelectTD[playerid][8] = CreatePlayerTextDraw(playerid, 246.235366, 157.333328, "l");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][8], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][8], 336860415);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][8], 1);
    

    characterSelectTD[playerid][9] = CreatePlayerTextDraw(playerid, 397.794006, 155.983322, "x");
    PlayerTextDrawLetterSize(playerid, characterSelectTD[playerid][9], 0.199999, 0.935000);
    PlayerTextDrawTextSize(playerid, characterSelectTD[playerid][9], 10.000000, 7.000000);
    PlayerTextDrawAlignment(playerid, characterSelectTD[playerid][9], 2);
    PlayerTextDrawColor(playerid, characterSelectTD[playerid][9], 1347440895);
    PlayerTextDrawSetShadow(playerid, characterSelectTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, characterSelectTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, characterSelectTD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, characterSelectTD[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, characterSelectTD[playerid][9], true);

}

/*
 * <summary> Returns character's textdraw</summary>
 * <param name="playerid"> id to return</param>
 */

stock Text:Character_ReturnTextdraw(id)
{
    return character_Country_Selection[id];
}

/*
 * <summary> Returns character's player textdraw</summary>
 * <param name="playerid"> playerid to return</param>
 * <param name="playerid"> id to return</param>
 */

stock Text:Character_ReturnPlayerTextdraw(playerid, id)
{
    return characterSelectTD[playerid][id];
}


/*
 * <summary> Shows character's textdraws</summary>
 */

stock Character_ShowTextdraws(playerid)
{
    for(new i; i < sizeof(character_Country_Selection); i++) {
        TextDrawShowForPlayer(playerid, character_Country_Selection[i]);
    }
    Flag_ShowForPlayer(playerid, E_FLAG_RUSSIAN, E_FLAG_MEDIUM);
    Flag_ShowForPlayer(playerid, E_FLAG_PRC, E_FLAG_MEDIUM);
    Flag_ShowForPlayer(playerid, E_FLAG_USA, E_FLAG_MEDIUM);
}

/*
 * <summary> Shows character's player textdraws</summary>
 */

stock Character_ShowPlayerTextdraws(playerid)
{
    for(new i; i < 10; i++) {
        PlayerTextDrawShow(playerid, characterSelectTD[playerid][i]);
    }
}

/*
 * <summary> Shows character's player textdraws</summary>
 */

stock Character_HidelayerTextdraws(playerid)
{
    for(new i; i < 10; i++) {
        PlayerTextDrawHide(playerid, characterSelectTD[playerid][i]);
    }
}


/*
 * <summary> Hide character's textdraws</summary>
 */

stock Character_HideTextdraws(playerid)
{
    for(new i; i < sizeof(character_Country_Selection); i++) {
        TextDrawHideForPlayer(playerid, character_Country_Selection[i]);
    }
    Flag_HideForPlayer(playerid, E_FLAG_RUSSIAN, E_FLAG_MEDIUM);
    Flag_HideForPlayer(playerid, E_FLAG_PRC, E_FLAG_MEDIUM);
    Flag_HideForPlayer(playerid, E_FLAG_USA, E_FLAG_MEDIUM);
}

