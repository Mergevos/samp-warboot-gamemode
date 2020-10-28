#include < a_samp >
#undef MAX_PLAYERS
#define MAX_PLAYERS 50
#include < fixes >
//database
#include < a_mysql >
// --
// Void/String/color
// --
#include < YSI_Core\y_core\y_globaltags >
#include < YSI_Server\y_colors >
#include < YSI_Coding\y_va >
//#include < YSI_Coding\y_inline >
#include < sscanf2 >

//cmd//
#include < YSI_Visual\y_commands >
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
#define BCRYPT_COST 6
#include < bcrypt >
//env
#include < env >
// flag models
#include < world-flags >
//Modules
// Modules/ 

#include <cmd_proc>
//Modules/database
#include < database >
//modules/misc
#include < misc >
//Modules/account
#include < accounts >
#include < admin >
//Modules/character
#include < characters >

// Modules/chats/
#include <cooldown>
#include < chats >

//Modules/vehicles
#include <vehicles>


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

