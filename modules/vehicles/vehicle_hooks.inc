#include < YSI_Coding\y_hooks >

hook OnGameModeInit()
{
    Iter_Init(Vehicles);
    Iter_Add(Vehicles, 0);
    ManualVehicleEngineAndLights();

    LoadVehicles();   
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    Iter_Clear(Vehicles);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    va_SendClientMessage(playerid, -1, "DEBUG: Vozilo ID: %d, SQLID: %d", vehicleid, Vehicle_SQLID[vehicleid]);
    return Y_HOOKS_CONTINUE_RETURN_1;
}