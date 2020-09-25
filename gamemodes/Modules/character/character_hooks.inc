#include <YSI_Coding\y_hooks>

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Character_ReturnTextdraw(4)) { // china 
        Character_SetCountry(playerid, 1);
        Character_HideTextdraws(playerid);
        CancelSelectTextDraw(playerid);
        Character_SelectNameDialog(playerid, 1);
    }
    else if(clickedid == Character_ReturnTextdraw(9)) {
        Character_SetCountry(playerid, 2);
        Character_HideTextdraws(playerid);
        CancelSelectTextDraw(playerid);
        Character_SelectNameDialog(playerid, 2);
    }
    else if(clickedid == Character_ReturnTextdraw(11)) {
        Character_SetCountry(playerid, 3);
        Character_HideTextdraws(playerid);
        CancelSelectTextDraw(playerid);
        Character_SelectNameDialog(playerid, 3);
    }
    return 1;
}