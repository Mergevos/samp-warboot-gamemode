/*
 * <summary> Called after the account  get checked</summary>
 * <param name="playerid"> Player ID of the player whose account was checked</param>
 */
forward OnPlayerAccountChecked(playerid);

/*
 * <summary> Called after the password  get hashed</summary>
 * <param name="playerid"> Player ID of the player whose password was hashed</param>
 */

forward OnPasswordHashed(playerid);

/*
 * <summary> Called after the password  get checked</summary>
 * <param name="playerid"> Player ID of the player whose password was checked</param>
 */

forward OnPasswordChecked(playerid);

//------------------------------------------
public OnPlayerAccountChecked(playerid)
{
    if(cache_num_rows()) {
        new 
            id,
            password[61],
            email[40],
            bool:nullval,
            admin_level,
            admin_code;

        cache_get_value_name_int(0, "account_id", id);
        cache_get_value_name(0, "account_password", password);
        cache_get_value_name(0, "account_email", email);
        
        Account_SetID(playerid, id);
        Account_SetPassword(playerid, password);
        Account_SetEmail(playerid, email);
        

        cache_is_value_name_null(0, "admin_level", nullval);
        if(!nullval) {
            cache_get_value_name_int(0, "admin_level", admin_level);
            Admin_SetLevel(playerid, admin_level);
            cache_get_value_name_int(0, "admin_code", admin_code);
            Admin_SetCode(playerid, admin_code);
        }

        Account_LoginDialog(playerid);
        
        TogglePlayerSpectating(playerid, true);
        return 0;
    }
    Account_RegisterHandler(playerid);

    return 1;
}

public void:OnPasswordHashed(playerid)
{
    new hash[61];
    bcrypt_get_hash(hash);
    Account_SetPassword(playerid, hash);
    Account_EmailDialogHandler(playerid);
}

public void:OnPasswordChecked(playerid)
{
    new
        bool:match = bcrypt_is_equal();

    if(match) {
        CallLocalFunction("OnPlayerLogin", "i", playerid);
        strdel(Account_ReturnPassword(playerid), 0, 61);
    } 
    else {
        Account_SetLoginAttempts(playerid, Account_ReturnLoginAttempts(playerid) + 1);
        if(Account_ReturnLoginAttempts(playerid) == 3) {
            Account_SetLoginAttempts(playerid, 0);
            KickEx(playerid, ""INDIANRED"// WARBOOT // {ffffff}You've been kicked because of too many password attempts");
        }
        Account_LoginDialog(playerid);
        
    }
}