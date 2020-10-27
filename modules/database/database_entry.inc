static 
    MySQL: handle_Sql;

stock MySQL: Database_ReturnHandle()
{
    return handle_Sql;
}

/*
 * <summary>Handles the mysql connection which's triggered in OnGameModeInit</summary>
 */

stock Database_Connect()
{
    new 
        MySQLOpt:Options = mysql_init_options(), 
        TempConnectStr[3][32];

	mysql_set_option(Options, AUTO_RECONNECT, true);
	mysql_set_option(Options, MULTI_STATEMENTS, true);
    
	if(Env_Has("MYSQL_HOST")) {
		Env_Get("MYSQL_HOST", TempConnectStr[0]);
		print("MYSQL_HOST initialized");
	}
	if(Env_Has("MYSQL_USERNAME")) {
		Env_Get("MYSQL_USERNAME", TempConnectStr[1]);
		print("MYSQL_USER initialized");
	}
	if(Env_Has("MYSQL_DATABASE")) {
		Env_Get("MYSQL_DATABASE", TempConnectStr[2]);
		print("MYSQL_DATABASE initialized");
	}
	handle_Sql = mysql_connect(TempConnectStr[0], TempConnectStr[1], "", TempConnectStr[2], Options);
	if(handle_Sql == MYSQL_INVALID_HANDLE || mysql_errno(handle_Sql) != 0) {
		return print("[MySQL] Connection failed");
	}
	printf("{MYSQL] Connection established\nUser: %s\n\
		Host: %s\n\
		Database: %s",
	TempConnectStr[0], TempConnectStr[1], TempConnectStr[2]);
	return 0;
}