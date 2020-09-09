stock Account_RegisterHandler(playerid)
{
    task_yield(1);
    TogglePlayerSpectating(playerid, true);
    new 
        account_RegisterHandler[e_DIALOG_RESPONSE_INFO];

    task_await_arr(ShowPlayerAsyncDialogStr(playerid, DIALOG_STYLE_PASSWORD, 
        str_new(""INDIANRED"L{ffffff}ogin"), 
        str_format(""LIGHTGREEN"> {ffffff}Welcome on server "INDIANRED"%s {ffffff}\n\
        "LIGHTGREEN"> {ffffff} Your account doesn't exists in our database. Please input your desired password\n\
        "LIGHTGREEN"> {ffffff} Take into account that you can't input more than 24 characters or less than 6", Misc_ReturnName(playerid)), 
    str_new(""GREEN"Register"), str_new(""RED"Exit")), account_RegisterHandler);
    
    if(account_RegisterHandler[E_DIALOG_RESPONSE_Response]) {
        if(strlen(account_RegisterHandler[E_DIALOG_RESPONSE_InputText]) < 6 || strlen(account_RegisterHandler[E_DIALOG_RESPONSE_InputText]) > 24) {
            Account_RegisterHandler(playerid);
        }
        bcrypt_hash(account_RegisterHandler[E_DIALOG_RESPONSE_InputText], BCRYPT_COST, "OnPasswordHashed", "d", playerid);
    }
    else {
        KickEx(playerid, ""INDIANRED"[WARBOOT] {ffffff}You've been kicked because you didn't want to login", false);
    }
}

stock Account_EmailDialogHandler(playerid)
{
    task_yield(1);
    new
        account_EmailDialogResponse[e_DIALOG_RESPONSE_INFO];

    task_await_arr(ShowPlayerAsyncDialogStr(playerid, DIALOG_STYLE_INPUT, 
        str_new(""INDIANRED"E{ffffff}mail"), 
        str_format(""LIGHTGREEN"> "INDIANRED"%s,\n\
        "LIGHTGREEN"> {ffffff} Your account doesn't have an email. Please input your desired one\n\
        "LIGHTGREEN"> {ffffff} Take into account that you can't request password back for your account if you don't have the email", Misc_ReturnName(playerid)), 
    str_new(""GREEN"Input"), str_new(""RED"Exit")), account_EmailDialogResponse);
    
    if(account_EmailDialogResponse[E_DIALOG_RESPONSE_Response]) {
        if (!(6 <= strlen(account_EmailDialogResponse[E_DIALOG_RESPONSE_InputText]) <= 40)) {
            Account_EmailDialogHandler(playerid);
        }
        Account_SetEmail(playerid, account_EmailDialogResponse[E_DIALOG_RESPONSE_InputText]);
        registerPlayer(playerid);
    }
    else {
        KickEx(playerid, ""INDIANRED"[WARBOOT] {ffffff}You've been kicked because you didn't want to login", false);
    }
}

static stock registerPlayer(playerid)
{
    mysql_tquery_s(Database_ReturnHandle(),
        str_format(
            "INSERT INTO `accounts` \
            (`account_name`, `account_password`, `account_email`) \
            VALUES \
            ('%e', '%s', '%e')", Misc_ReturnName(playerid), Account_ReturnPassword(playerid), Account_ReturnEmail(playerid)),
            "OnPlayerRegister", "i", playerid
    );
}