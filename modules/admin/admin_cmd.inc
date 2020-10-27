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
