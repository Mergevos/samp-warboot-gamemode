#include            < YSI_Coding\y_hooks >

hook OnGameModeInit()
{
    Database_Connect();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

