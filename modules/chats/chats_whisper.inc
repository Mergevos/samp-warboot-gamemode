YCMD:whisper(playerid, params[], help)
{
    new 
        id,
        Text[144],
        Float: Pos[3];
    if(help) {
        return Message_SendHelp(playerid, "Send a whisper message.");
    }
    
    if(sscanf(params, "us[144]", id, Text)) {
       Message_SendUsage(playerid, "/w(hisper) [ID][text]");
       return COMMAND_DENIED;
    }
    if(!IsPlayerConnected(id)) {
        return Message_SendError(playerid, "Player is not connected.");
    }
    if(strlen(Text) > 144) {
        Message_SendError(playerid, "The message can't be longer than 144. Please input a new one.");
        return COMMAND_DENIED;
    }
    GetPlayerPos(id, Pos[0], Pos[1], Pos[2]);
    if(!IsPlayerInRangeOfPoint(playerid, 2, Pos[0], Pos[1], Pos[2])) {
        return Message_SendError(playerid, "You're not close to the another player.");
    }
    va_SendClientMessage(id, -1, ""RED"[%d]"YELLOW"%s: {ffffff}%s", playerid, Misc_ReturnName(playerid), Text);
    va_SendClientMessage(playerid, -1, ""RED"[WHISPER]{ffffff} to"YELLOW" [%d]%s: {ffffff}%s", id, Misc_ReturnName(id), Text);
    return COMMAND_OK;
}

YCMD:w(playerid, params[], help) = whisper;