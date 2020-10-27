CMD:makeadmin(playerid, params[])
{
    /*if(!Admin_IsOnDuty(playerid)) {
        return SendClientMessage(playerid, -1, "Niste admin na duznosti");
    }*/
    new id, level;
    if(sscanf(params, "ud", id, level)) {
        return Message_SendUsage(playerid, "/makeadmin [ID][Level]");
    }
    if(!IsPlayerConnected(id)) {
        return Message_SendError(playerid, "Specified player isn't connected.");
    }
    if(!(1 <= level <= 6)) {
        return Message_SendError(playerid, "Wrong admin level");
    }
    if(Admin_ReturnLevel(id) != 0) {
        return Message_SendError(playerid, "Vec je admin");
    }
    Admin_MakePlayer(playerid, id, level, random(99999));

    return COMMAND_OK;

}

ACMD:[1]aduty(playerid, params[]) {
    static
        string[64];
    
    if(sscanf(params, "d", params[0])) {
        return Message_SendUsage(playerid, "/aduty [Code]");
    }

    if(!(params[0] == Admin_ReturnCode(playerid))) {
        return Message_SendError(playerid, "Entered code is invalid.");
    }

    Admin_SetDuty(playerid, Admin_IsOnDuty(playerid) ? false : true);

    format(string, sizeof(string), ""GOLD" // INFO // {ffffff} You are now %s", Admin_IsOnDuty(playerid) ? "on duty." : "off duty.");
    SendClientMessage(playerid, -1, string);
    return COMMAND_OK;
}