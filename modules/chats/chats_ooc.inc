YCMD:b(playerid, params[], help)
{
    new 
        Text[144];
    if(help) {
        return Message_SendHelp(playerid, "Send an OOC message.");
    }
    if(sscanf(params, "s[144]", Text)) {
       Message_SendUsage(playerid, "/b [text]");
       return COMMAND_DENIED;
    }
    if(strlen(Text) > 144) {
        Message_SendError(playerid, "The message can't be longer than 144. Please input a new one.");
        return COMMAND_DENIED;
    }

    Message_SendRadius(playerid, 15.0, 0xFFFFFFFF, "(( [%d]%s: %s ))", playerid, Misc_ReturnName(playerid), Text);
    return COMMAND_OK;
}