#include            < YSI_Coding\y_hooks >

hook OnGameModeExit()
{
    closeSql();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

// --
// <summary>Closes mysql connection in OnGameModeExit</summary>
// --

static stock closeSql()
{
    mysql_close(Database_ReturnHandle());
}
