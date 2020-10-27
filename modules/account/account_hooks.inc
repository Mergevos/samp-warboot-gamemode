#include <YSI_Coding\y_hooks> // evo ti

hook OnPlayerDisconnect(playerid, reason)
{
    Account_ResetInfo(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

