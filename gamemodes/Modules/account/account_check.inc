stock Account_CheckIfExists(playerid)
{
    mysql_tquery_s(
        Database_ReturnHandle(), 
            str_format("SELECT * \
            FROM `accounts` \
            WHERE `account_name` = '%e'", Misc_ReturnName(playerid)),
            "OnAccountChecked", "i", playerid
    );
    return Y_HOOKS_BREAK_RETURN_1;
}

