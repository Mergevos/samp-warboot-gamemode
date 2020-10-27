YCMD:shout(playerid, params[], help)
{
    new 
        Text[144];
    if(help) {
        return Message_SendHelp(playerid, "Send a shout message.");
    }
    
    if(sscanf(params, "s[144]", Text)) {
       Message_SendUsage(playerid, "/w(hisper) [ID][text]");
       return COMMAND_DENIED;
    }
    if(strlen(Text) > 144) {
        Message_SendError(playerid, "The message can't be longer than 144. Please input a new one.");
        return COMMAND_DENIED;
    }
    
    ApplyAnimation( playerid, "ON_LOOKERS", "null",4.0,0,0,0,0,0, 0);
    ApplyAnimation( playerid, "ON_LOOKERS", "panic_shout",4.0,0,0,0,0,1500,1 );
    Message_SendRadius(playerid, 45, -1, ""BLUE"[%d]{ffffff} %s shouts: %s", playerid, Misc_ReturnName(playerid), Text);
    return COMMAND_OK;
}

YCMD:s(playerid, params[], help) = shout;