/*
 * <summary>Makeas a player admin</summary>
 * <param name="playerid"> playerid to who is being promoted to admin</param>
 * <param name="adminid"> admin who set the admin</param>
 * <param name="level"> Level of the admin</param>
 * <param name="code"> code of the admin</param>
 */

stock Admin_MakePlayer(adminid, playerid, level, code)
{
    Admin_SetLevel(playerid, level);
    Admin_SetCode(playerid, code);
    Iter_Add(OnlineAdmins, playerid);

    va_SendClientMessage(adminid, -1, ""INDIANRED"* You've given admin level %d to %s [%d]", level, Misc_ReturnName(playerid), adminid);
    
    mysql_tquery_s(Database_ReturnHandle(),
        str_format("INSERT INTO `admins`\
            (`account_id`, `admin_name`, `admin_level`, `admin_code`) \
            VALUES \
            (%d, '%s', %d, %d)", Account_ReturnID(playerid), Account_ReturnName(playerid), Admin_ReturnLevel(playerid), Admin_ReturnCode(playerid))
    );
    va_SendClientMessage(playerid, -1, ""BLUE"* {ffffff}You've been promoted to admin level %d by admin.", level);
    va_SendClientMessage(playerid, -1, ""BLUE"* {ffffff}Your admin code is %d, use it carefully, along with /aduty", Admin_ReturnCode(playerid));
    SendClientMessage(playerid, -1, ""BLUE"* {ffffff}Do not give your admin code to anyone.");
}