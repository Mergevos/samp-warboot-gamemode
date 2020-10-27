#include <YSI_Coding\y_hooks>
public OnPlayerCommandText(playerid, cmdtext[])
{
    return 1;
}

public e_COMMAND_ERRORS: OnPlayerCommandPerformed(playerid, cmdtext[], e_COMMAND_ERRORS: success)
{	

    return COMMAND_OK;
}

public e_COMMAND_ERRORS: OnPlayerCommandReceived(playerid, cmdtext[], e_COMMAND_ERRORS: success)
{	

    return COMMAND_OK;
}