/*
 * <summary>Used to send a message info</summary>
 */

stock Message_SendInfo(playerid, const str[144])
{
    return va_SendClientMessage(playerid, -1, ""GOLD" // INFO // {ffffff} %s", str);
}

/*
 * <summary>Used to send a message usage</summary>
 */

stock Message_SendUsage(playerid, const str[144])
{
    return va_SendClientMessage(playerid, -1, ""LIGHTGREEN" // USAGE // {ffffff} %s", str);
}

/*
 * <summary>Used to send a message error</summary>
 */

stock Message_SendError(playerid, const str[144])
{
    return va_SendClientMessage(playerid, -1, ""PURPLE" // ERROR // {ffffff} %s", str);
}

/*
 * <summary>Used to send a message help</summary>
 */

stock Message_SendHelp(playerid, const str[144])
{
    return va_SendClientMessage(playerid, -1, ""BLUE" // HELP // {ffffff} %s", str);
}