#include < a_samp >

//database
#include < a_mysql >
// --
// Void/String/color
// --
#include < YSI_Core\y_core\y_globaltags >
#include < YSI_Server\y_colors >
#include < YSI_Coding\y_va >
#include < sscanf2 >

//pawnplus
#define PP_SYNTAX_AWAIT
#include < PawnPlus >
#include < pp-mysql >
#include < advanced_kicks >
#include < async-dialogs >
#include < eSelection >
// regex
#include < Pawn.Regex >
//hash
#define BCRYPT_COST 12
#include < bcrypt >
//env
#include < env >
// flag models
#include < world-flags >
//Modules
//Modules/database
#include < database >
//modules/misc
#include < misc >
//Modules/account
#include < accounts >
//Modules/character
#include < characters >

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

