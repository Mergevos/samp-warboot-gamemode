#include < YSI_Coding\y_hooks >

hook OnPlayerText(playerid, text[])
{
    if(!(GetTickCount() - Cooldown_GetPlayerTick(playerid, CHAT) > Cooldown_GetPlayerTime(playerid, CHAT))) {
        Message_SendError(playerid, "You're cooldowned, please, try again");
        printf("cooldown time %d\ncooldown tick %d\ndiff %d", 
            Cooldown_GetPlayerTime(playerid, CHAT), 
            Cooldown_GetPlayerTick(playerid, CHAT),
            Cooldown_GetPlayerTick(playerid, CHAT) - GetTickCount());
        return Y_HOOKS_CONTINUE_RETURN_0; 
    }
    Message_SendRadius(playerid, 15, -1, ""ORANGE"[%d] "BLUE"%s{ffffff}: %s", playerid, Misc_ReturnName(playerid), text);
    Cooldown_SetPlayerTick(playerid, CHAT, GetTickCount());
    return Y_HOOKS_CONTINUE_RETURN_0;
}
