CMD:makeadmin(playerid, params[])
{
    /*if(!Admin_IsOnDuty(playerid)) {
        return SendClientMessage(playerid, -1, "Niste admin na duznosti");
    }*/
    new id, level;
    if(sscanf(params, "ud", id, level)) {
        return Message_SendUsage(playerid, "/makeadmin [ID] [Level]");
    }
    if(!IsPlayerConnected(id)) {
        return Message_SendError(playerid, "Specified player isn't connected.");
    }
    if(!(1 <= level <= 6)) {
        return Message_SendError(playerid, "Wrong admin level");
    }
    if(Admin_ReturnLevel(id) != 0) {
        return Message_SendError(playerid, "He's already an admin.");
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

// ACMD:[1]achat(playerid, params[]) {
//     static
//         text[64];

//     if(sscanf(params, "s[64]", text)) {
//         return Message_SendUsage(playerid, "/a [Text]");
//     }

//     foreach(new i : OnlineAdmins) {
//         va_SendClientMessage(i, X11_LIGHTGREEN, "[A] Admin (%d) %s: %s", Admin_ReturnLevel(playerid), Misc_ReturnName(playerid), text);
//     }

//     return COMMAND_OK;
// }

ACMD:[1]cc(playerid, params[]) {
    for(new l = 0; l < 25; l++) SendClientMessageToAll(-1, " ");

    SendClientMessageToAll(X11_INDIANRED, "// WARBOOT //");
    va_SendClientMessageToAll(X11_INDIANRED, "Admin "WHITE"%s "LIGHTGREEN"has cleared the chat.", Misc_ReturnName(playerid));
    return COMMAND_OK;
}

ACMD:[1]kick(playerid, params[]) {
    static
        targetid,
        string[128],
        reason[24];

    if(sscanf(params, "us[24]", targetid, reason)) {
        return Message_SendUsage(playerid, "/kick [ID] [Reason]");
    }

    if(!(Admin_ReturnLevel(targetid) < Admin_ReturnLevel(playerid))) {
        return Message_SendError(playerid, "You cannot kick an admin whose admin level is bigger than or equal to yours.");
    }

    format(string, sizeof(string), ""INDIANRED"// WARBOOT // {ffffff}You've been kicked by an admin %s, reason: %s", Misc_ReturnName(playerid), reason);
    KickEx(targetid, string, false);

    va_SendClientMessageToAll(X11_INDIANRED, "// WARBOOT // {ffffff}Player %s has been kicked from this server, reason: %s", Misc_ReturnName(targetid), reason);
    return COMMAND_OK;
}