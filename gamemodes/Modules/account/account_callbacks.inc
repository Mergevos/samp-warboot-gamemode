
forward OnPlayerAccountChecked(playerid);
public OnPlayerAccountChecked(playerid)
{
    if(cache_num_rows()) {
        static 
            password[61],
            email[40];
        cache_get_value_name(0, "account_password", password);
        cache_get_value_name(0, "account_email", email);

        Account_SetPassword(playerid, password);
        Account_SetEmail(playerid, email);
        Account_LoginDialog(playerid);
        TogglePlayerSpectating(playerid, true);
        return 0;
    }
    Account_RegisterHandler(playerid);

    return 1;
}

forward OnPasswordHashed(playerid);
public void:OnPasswordHashed(playerid)
{
    new hash[61];
    bcrypt_get_hash(hash);
    Account_SetPassword(playerid, hash);
    Account_EmailDialogHandler(playerid);
}

forward OnPasswordChecked(playerid);
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
            KickEx(playerid, ""INDIANRED"[WARBOOT] {ffffff}You've been kicked because of too many password attempts");
        }
        Account_LoginDialog(playerid);
        
    }
}