/*
  * <summary> Handles login dialog</summary>
  * <param name="playerid"> playerid to handle dialogid</param>
  */

stock void:Account_LoginDialog(playerid)
{
    task_yield(1);
    static 
        account_LoginDialogHandle[e_DIALOG_RESPONSE_INFO];
    TogglePlayerSpectating(playerid, true);

    task_await_arr(ShowPlayerAsyncDialogStr(playerid, DIALOG_STYLE_PASSWORD, 
        str_new(""INDIANRED"L{ffffff}ogin"), 
        str_format(""LIGHTGREEN"> {ffffff} Welcome, "INDIANRED"%s,\n\
        "LIGHTGREEN"> {ffffff} Your account exists in our database. In order to continue, please input your password\n\
        "LIGHTGREEN"> {ffffff} After 3 times of inputting uncorrect password, you're going to be kicked.", Misc_ReturnName(playerid)), 
    str_new(""GREEN"Continue"), str_new(""RED"Exit")), account_LoginDialogHandle);

    if(account_LoginDialogHandle[E_DIALOG_RESPONSE_Response]) {
        bcrypt_check(account_LoginDialogHandle[E_DIALOG_RESPONSE_InputText], Account_ReturnPassword(playerid), "OnPasswordChecked", "d", playerid);
    }
    else {
        KickEx(playerid, ""INDIANRED"// WARBOOT // {ffffff}You've been kicked because you didn't want to login", false);
    }
}