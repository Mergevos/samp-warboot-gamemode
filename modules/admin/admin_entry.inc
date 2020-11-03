#define ACMD:[%0]%1(%2,%3) CMD:%1(%2,%3) if (Admin_ReturnLevel(%2) < %0) return Message_SendError(%2, "You're not an admin."); else

static 
    admin_Level[MAX_PLAYERS],
    admin_Code[MAX_PLAYERS];

static
    bool: admin_Duty[MAX_PLAYERS] = false;

const 
    MAX_ADMINS = 64;

//----------------------------------------
new 
    Iterator: OnlineAdmins<MAX_ADMINS>;

//----------------------------------------
/*
 * <summary>Return admin level</summary>
 * <param name="playerid"> playerid to whose level is being returned</param>
 */

stock Admin_ReturnLevel(playerid)
{
    return admin_Level[playerid];
}

/*
* <summary>Return an admin's duty</summary>
* <param name="playerid"> playerid to whose duty status is being returned</param>
*/
stock Admin_IsOnDuty(playerid) {
    return admin_Duty[playerid];
}

/*
 * <summary>Return admin code</summary>
 * <param name="playerid"> playerid to whose code is being returned</param>
 */

stock Admin_ReturnCode(playerid)
{
    return admin_Code[playerid];
}


/*
 * <summary>Sets admin level</summary>
 * <param name="playerid"> playerid to whose level is being set</param>
 * <param name="level"> level to set</param>
 */

stock Admin_SetLevel(playerid, level)
{
    admin_Level[playerid] = level;
}

/*
 * <summary>Sets admin code</summary>
 * <param name="playerid"> playerid to whose code is being set</param>
 * <param name="code"> code to set</param>
 */

stock Admin_SetCode(playerid, code)
{
    admin_Code[playerid] = code;
}

/*
 * <summary>Sets admin duty</summary>
 * <param name="playerid"> playerid to whose duty is being set</param>
 * <param name="duty"> duty to set</param>
 */
stock Admin_SetDuty(playerid, bool: duty) {
    admin_Duty[playerid] = duty;
}