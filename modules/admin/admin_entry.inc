#define ACMD:[%0]%1(%2,%3) CMD:%1(%2,%3) if (Admin_Level[%2] < %0) return Message_SendError(playerid, -1, "You're not an admin.") else

static 
    admin_Level[MAX_PLAYERS],
    admin_Code[MAX_PLAYERS];

const 
    MAX_ADMINS = 64;

//----------------------------------------
static 
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
 * <summary>Return admin code</summary>
 * <param name="playerid"> playerid to whose code is being returned</param>
 */

stock Admin_ReturnCode(playerid)
{
    return admin_Code[playerid];
}

/*
 * <summary>Adds an admin into the list of online admins(iter)</summary>
 * <param name="playerid"> playerid to who is being added</param>
 */

stock Admin_IterAdd(playerid)
{
    Iter_Add(OnlineAdmins, playerid);
}

/*
 * <summary>Return admin iter</summary>
 */

stock Iterator: Admin_ReturnIter()
{
    return OnlineAdmins;
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
