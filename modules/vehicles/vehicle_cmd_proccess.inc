/*ACMD:[6]createveh(playerid, params[])
{
    static Float: pos[4];
    if(!Admin_IsOnDuty(playerid)) {
        return SendClientMessage(playerid, -1, "Niste admin na duznosti");
    }
    if(sscanf(params, "dddd", params[0], params[1], params[2], params[3])) {
        SendClientMessage(playerid, -1, "/createveh model color1 color2 type");
        SendClientMessage(playerid, -1, "Model [400 - 612], Color1/2 [0-255], type [1-4]");
        SendClientMessage(playerid, -1, "1: School Driving car");
        return COMMAND_DENIED;
    }
    
    if(!(400 <= params[0] <= 612)) {
        return SendClientMessage(playerid, -1, "Model ne moze ispod 400 niti iznad 612");
    }
    if(!(0 <= params[1] <= 255)) {
        return SendClientMessage(playerid, -1, "Boja ne moze ispod 0 niti iznad 255");
    }
    if(!(0 <= params[2] <= 255)) {
        return SendClientMessage(playerid, -1, "Boja ne moze ispod 0 niti iznad 255");
    }
    if(!(1 <= params[3] < 5)) {
        return SendClientMessage(playerid, -1, "Tip ne moze ispod 0 niti iznad 4");
    }

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(playerid, pos[3]);
    SetPlayerPos(playerid, pos[0], pos[1] + 3, pos[2]);
    
    Vehicle_CreateVehicle(Iter_Alloc(Vehicles), params[0], params[3], pos[0], pos[1], pos[2], pos[3], params[1], params[2], GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    return COMMAND_OK;
}

ACMD:[6]rac(playerid, params[])
{
    if(!Admin_IsOnDuty(playerid)) {
        return SendClientMessage(playerid, -1, "Niste admin na duznosti");
    }
    foreach(new i : Vehicles) {
        if(!IsVehicl)
        SetVehicleToRespawn(i);
    }
    return COMMAND_OK;
}*/

/*ACMD:[6]rtc(playerid, params[])
{
    if(!Admin_IsOnDuty(playerid)) {
        return SendClientMessage(playerid, -1, "Niste admin na duznosti");
    }
    if(!IsPlayerInAnyVehicle(playerid)) {
        return SendClientMessage(playerid, -1, "You're not in a vehicle");
    }
    if(!Iter_Contains(Vehicles, GetPlayerVehicleID(playerid))) {
        return SendClientMessage(playerid, -1, "Cannot be respawned");
    }
    SetVehicleToRespawn(GetPlayerVehicleID(playerid));
    return COMMAND_OK;
}
*/
YCMD:engine(playerid, params[], help) 
{
    if(help) {
        return SendClientMessage(playerid, -1, "Turns the engine either on or off depending on its state");
    }
    if(GetPlayerVehicleSeat(playerid) == -1) {
        return SendClientMessage(playerid, -1, "You're not in a vehicle");
    }
    else if(GetPlayerVehicleSeat(playerid) > 0) {
        return SendClientMessage(playerid, -1, "You're not the driver");
    }
    if(Vehicle_ReturnEngineState(GetPlayerVehicleID(playerid))) {
        SetVehicleEngineState(GetPlayerVehicleID(playerid), false);
        SendClientMessage(playerid, -1, "You've just turned off the vehicle's engine");
    }
    else if(!Vehicle_ReturnEngineState(GetPlayerVehicleID(playerid))) {
        SetVehicleEngineState(GetPlayerVehicleID(playerid), true);
        SendClientMessage(playerid, -1, "You've just turned on the vehicle's engine");
    }
    return COMMAND_OK;
}

YCMD:lights(playerid, params[], help) 
{
    if(help) {
        return SendClientMessage(playerid, -1, "Turns the lights either on or off depending on its state");
    }
    if(GetPlayerVehicleSeat(playerid) == -1) {
        return SendClientMessage(playerid, -1, "You're not in a vehicle");
    }
    else if(GetPlayerVehicleSeat(playerid) > 0) {
        return SendClientMessage(playerid, -1, "You're not the driver");
    }
    if(Vehicle_ReturnLightsState(GetPlayerVehicleID(playerid))) {
        SetVehicleLightsState(GetPlayerVehicleID(playerid), false);
        SendClientMessage(playerid, -1, "You've just turned off the vehicle's lights");
    }
    else if(!Vehicle_ReturnLightsState(GetPlayerVehicleID(playerid))) {
        SetVehicleLightsState(GetPlayerVehicleID(playerid), true);
        SendClientMessage(playerid, -1, "You've just turned on the vehicle's lights");
    }
    return COMMAND_OK;
}

YCMD:windows(playerid, params[], help)
{
    if(help) {
        return SendClientMessage(playerid, -1, "Open a window");
    }
    if(GetPlayerVehicleSeat(playerid) == -1) {
        return SendClientMessage(playerid, -1, "You're not in a vehicle");
    }
    if(!Vehicle_ReturnWindowState(GetPlayerVehicleID(playerid), GetPlayerVehicleSeat(playerid))) {
        SetVehicleWindowState(GetPlayerVehicleID(playerid), GetPlayerVehicleSeat(playerid), true);
        SendClientMessage(playerid, -1, "You've just open the vehicle's lights");
    }
    else {
        SetVehicleWindowState(GetPlayerVehicleID(playerid), GetPlayerVehicleSeat(playerid), false);
        SendClientMessage(playerid, -1, "You've just close the vehicle's lights");
    }
    return COMMAND_OK;
}