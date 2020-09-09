#include < a_samp >

//database
#include < a_mysql >
// --
// Void/String/color
// --
#include < YSI_Core\y_core\y_globaltags >
#include < YSI_Server\y_colors >

//pawnplus
#define PP_SYNTAX_AWAIT
#include < PawnPlus >
#include < pp-mysql >
#include < advanced_kicks >
#include < async-dialogs >
//hash
#define BCRYPT_COST 12
#include < bcrypt >
//env
#include < env >
//Modules
//Modules/database
#include < database >
//modules/misc
#include < misc >
//Modules/account
#include < accounts >




main()
{
    return;
}

public OnGameModeInit()
{
    pp_use_funcidx(true);
    return 1;
}

public OnGameModeExit()
{
    return 1;
}

