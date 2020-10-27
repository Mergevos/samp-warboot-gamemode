// --
// <summary> Create vehicle with data saving</params>
// --
stock void:Vehicle_CreateVehicle(vehicleid, model, type, Float: x, Float: y, Float: z, Float: a, color1, color2, virtualworld, interior)
{

    Vehicle_Position[vehicleid][0] = x;
    Vehicle_Position[vehicleid][1] = y;
    Vehicle_Position[vehicleid][2] = z;
    Vehicle_Position[vehicleid][3] = a;
    Vehicle_Model[vehicleid] = model;
    Vehicle_Type[vehicleid] = type;
    Vehicle_Colors[vehicleid][0] = color1;
    Vehicle_Colors[vehicleid][1] = color2;
    Vehicle_Interior[vehicleid] = interior;
    Vehicle_VirtualWorld[vehicleid] = virtualworld;
    Vehicle_Doors[vehicleid][0] = 0;
    Vehicle_Doors[vehicleid][1] = 0;
    Vehicle_Doors[vehicleid][2] = 0;
    Vehicle_Doors[vehicleid][3] = 0;
    Vehicle_Price[vehicleid] = 0;
    Vehicle_Windows[vehicleid][0] = 1;
    Vehicle_Windows[vehicleid][1] = 1;
    Vehicle_Windows[vehicleid][2] = 1;
    Vehicle_Windows[vehicleid][3] = 1;
    Vehicle_Params[vehicleid][0] = 0;
    Vehicle_Params[vehicleid][1] = 0;
    Vehicle_Params[vehicleid][2] = 0;
    Vehicle_Params[vehicleid][3] = 0;
    Vehicle_Params[vehicleid][4] = 0;
    Vehicle_Params[vehicleid][5] = 0;
    Vehicle_Params[vehicleid][6] = 0;

    CreateVehicle(model, x, y, z, a, color1, color2, -1, 0);
    LinkVehicleToInterior(vehicleid, interior);
    SetVehicleVirtualWorld(vehicleid, virtualworld);

    new String: Query = str_format("INSERT INTO `vehicle_entry` (`X`, `Y`, `Z`, `A`) VALUES (%f, %f, %f, %f)", x, y, z, a);
    mysql_tquery_s(Database_ReturnHandle(), Query, "OnCreateVeh", "i", vehicleid);

}

forward OnCreateVeh(vehicleid);
public OnCreateVeh(vehicleid) {
    Vehicle_SQLID[vehicleid] = cache_insert_id();
    new String: Query = str_format(
        "INSERT INTO `vehicle_info` \
        (`ID`, `Model`, `Color1`, `Color2`, `Interior`, `VW`) \
        VALUES (%d, %d, %d, %d, %d, %d); \
        INSERT INTO `vehicle_params` \
        (`ID`, `Type`, `Engine`, `Lights`, `Alarm`, `Doors`, `Bonnet`, `Boot`, `Objective`) \
        VALUES (%d, %d, %d, %d, %d, %d, %d, %d, %d);",
        Vehicle_SQLID[vehicleid], model, color1, color2, interior, virtualworld,
        Vehicle_SQLID[vehicleid], Vehicle_Type[vehicleid], Vehicle_Params[vehicleid][0], Vehicle_Params[vehicleid][1],
        Vehicle_Params[vehicleid][2], Vehicle_Params[vehicleid][3], Vehicle_Params[vehicleid][4], Vehicle_Params[vehicleid][5], Vehicle_Params[vehicleid][6]
    );
    mysql_tquery_s(Database_ReturnHandle(), Query);
}
// --
// <summary> Set vehicle engine state</summary>
// --

stock void:SetVehicleEngineState(vehicleid, bool:stat) 
{
    GetVehicleParamsEx(vehicleid, Vehicle_Params[vehicleid][0], Vehicle_Params[vehicleid][1], Vehicle_Params[vehicleid][2], Vehicle_Params[vehicleid][3], Vehicle_Params[vehicleid][4], Vehicle_Params[vehicleid][5], Vehicle_Params[vehicleid][6]);
    Vehicle_Params[vehicleid][0] = stat ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
    static query[100];
    if(Iter_Contains(Vehicles, vehicleid)) {
        
        mysql_format(Database_ReturnHandle(), query, sizeof(query), "UPDATE `vehicle_params` SET `Engine` = %d WHERE `ID` = %d", Vehicle_Params[vehicleid][0], Vehicle_SQLID[vehicleid]);
        mysql_tquery(Database_ReturnHandle(), query);
    }
    SetVehicleParamsEx(vehicleid, stat ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF,Vehicle_Params[vehicleid][1], Vehicle_Params[vehicleid][2], Vehicle_Params[vehicleid][3], Vehicle_Params[vehicleid][4], Vehicle_Params[vehicleid][5], Vehicle_Params[vehicleid][6]);
}

// --
// <summary> Returns engine state</summary>
// --

stock bool:Vehicle_ReturnEngineState(vehicleid)
{
    GetVehicleParamsEx(vehicleid, Vehicle_Params[vehicleid][0], Vehicle_Params[vehicleid][1], Vehicle_Params[vehicleid][2], Vehicle_Params[vehicleid][3], Vehicle_Params[vehicleid][4], Vehicle_Params[vehicleid][5], Vehicle_Params[vehicleid][6]);
    if(Vehicle_Params[vehicleid][0] == VEHICLE_PARAMS_ON) {
        return true;
    }
    else {
        return false;
    }
}

// --
// <summary> Set vehicle lights state</summary>
// --

stock void:SetVehicleLightsState(vehicleid, bool:stat) 
{
    GetVehicleParamsEx(vehicleid, Vehicle_Params[vehicleid][0], Vehicle_Params[vehicleid][1], Vehicle_Params[vehicleid][2], Vehicle_Params[vehicleid][3], Vehicle_Params[vehicleid][4], Vehicle_Params[vehicleid][5], Vehicle_Params[vehicleid][6]);
    Vehicle_Params[vehicleid][1] = stat ? 1 : 0;
    static query[100];
    if(Iter_Contains(Vehicles, vehicleid)) {
        mysql_format(Database_ReturnHandle(), query, sizeof(query), "UPDATE `vehicle_params` SET `Lights` = %d WHERE `ID` = %d", Vehicle_Params[vehicleid][1], Vehicle_SQLID[vehicleid]);
        mysql_tquery(Database_ReturnHandle(), query);
    }
    SetVehicleParamsEx(vehicleid, Vehicle_Params[vehicleid][0], stat ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF, Vehicle_Params[vehicleid][2], Vehicle_Params[vehicleid][3], Vehicle_Params[vehicleid][4], Vehicle_Params[vehicleid][5], Vehicle_Params[vehicleid][6]);
}

// --
// <summary> Returns lights state</summary>
// --

stock bool:Vehicle_ReturnLightsState(vehicleid)
{
    GetVehicleParamsEx(vehicleid, Vehicle_Params[vehicleid][0], Vehicle_Params[vehicleid][1], Vehicle_Params[vehicleid][2], Vehicle_Params[vehicleid][3], Vehicle_Params[vehicleid][4], Vehicle_Params[vehicleid][5], Vehicle_Params[vehicleid][6]);
    if(Vehicle_Params[vehicleid][1] == VEHICLE_PARAMS_ON) {
        return true;
    }
    else {
        return false;
    }
}

// --
// <summary> Returns windows states</summary>
// --

stock bool:Vehicle_ReturnWindowState(vehicleid, window)
{
    GetVehicleParamsCarWindows(vehicleid, Vehicle_Windows[vehicleid][0], Vehicle_Windows[vehicleid][1], Vehicle_Windows[vehicleid][2], Vehicle_Windows[vehicleid][3]);
    if(Vehicle_Windows[vehicleid][window] == VEHICLE_PARAMS_ON) {
        return false;
    }
    else {
        return true;
    }
}

// --
// <summary> Sets a window's state</summary>
// --

stock SetVehicleWindowState(vehicleid, window, bool:stat)
{
    Vehicle_Windows[vehicleid][window] = stat ? 0 : 1;
    SetVehicleParamsCarWindows(vehicleid, Vehicle_Windows[vehicleid][0], Vehicle_Windows[vehicleid][1], Vehicle_Windows[vehicleid][2], Vehicle_Windows[vehicleid][3]);
}