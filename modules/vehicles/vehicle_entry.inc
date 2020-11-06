#undef MAX_VEHICLES 
#define MAX_VEHICLES 300
new 
    Iterator: Vehicles<MAX_VEHICLES>;

static
    vehicle_SQLID[MAX_VEHICLES],
    vehicle_Type[MAX_VEHICLES],
    vehicle_Price[MAX_VEHICLES],
    vehicle_Model[MAX_VEHICLES],
    vehicle_Interior[MAX_VEHICLES],
    vehicle_Colors[MAX_VEHICLES][2],
    vehicle_Params[MAX_VEHICLES][7],
    Float: vehicle_Position[MAX_VEHICLES][5],
    vehicle_VirtualWorld[MAX_VEHICLES],
    vehicle_Windows[MAX_VEHICLES][4],
    vehicle_Doors[MAX_VEHICLES][4];

/*
 * <summary> Creates a vehicle</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="model">model of vehicle</param>
 * <param name="type">type of vehicle</param>
 * <param name="x">x coordinate of vehicle</param>
 * <param name="y">y coordinate of vehicle</param>
 * <param name="z">z coordinate of vehicle</param>
 * <param name="a"> rotation of vehicle</param>
 * <param name="color1">color1 of vehicle</param>
 * <param name="color2">color2 of vehicle</param>
 * <param name="virtualworld">virtual world of vehicle</param>
 * <param name="interior">interior of vehicle</param>
 */

stock void:Vehicle_CreateVehicle(vehicleid, model, type, Float: x, Float: y, Float: z, Float: a, color1, color2, virtualworld, interior)
{

    vehicle_Position[vehicleid][0] = x;
    vehicle_Position[vehicleid][1] = y;
    vehicle_Position[vehicleid][2] = z;
    vehicle_Position[vehicleid][3] = a;
    vehicle_Model[vehicleid] = model;
    vehicle_Type[vehicleid] = type;
    vehicle_Colors[vehicleid][0] = color1;
    vehicle_Colors[vehicleid][1] = color2;
    vehicle_Interior[vehicleid] = interior;
    vehicle_VirtualWorld[vehicleid] = virtualworld;
    vehicle_Doors[vehicleid][0] = 0;
    vehicle_Doors[vehicleid][1] = 0;
    vehicle_Doors[vehicleid][2] = 0;
    vehicle_Doors[vehicleid][3] = 0;
    vehicle_Price[vehicleid] = 0;
    vehicle_Windows[vehicleid][0] = 1;
    vehicle_Windows[vehicleid][1] = 1;
    vehicle_Windows[vehicleid][2] = 1;
    vehicle_Windows[vehicleid][3] = 1;
    vehicle_Params[vehicleid][0] = 0;
    vehicle_Params[vehicleid][1] = 0;
    vehicle_Params[vehicleid][2] = 0;
    vehicle_Params[vehicleid][3] = 0;
    vehicle_Params[vehicleid][4] = 0;
    vehicle_Params[vehicleid][5] = 0;
    vehicle_Params[vehicleid][6] = 0;

    CreateVehicle(model, x, y, z, a, color1, color2, -1, 0);
    LinkVehicleToInterior(vehicleid, interior);
    SetVehicleVirtualWorld(vehicleid, virtualworld);

    new String: Query = str_format("INSERT INTO `vehicle_entry` (`X`, `Y`, `Z`, `A`) VALUES (%f, %f, %f, %f)", x, y, z, a);
    mysql_tquery_s(Database_ReturnHandle(), Query, "OnCreateVeh", "iiiiii", vehicleid, model, color1, color2, interior, virtualworld);

}


/*
 * <summary> Set vehicle sqlid</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="sqlid">sqlid</param>
 */

stock void:Vehicle_SetSQLID(vehicleid, sqlid) 
{
    vehicle_SQLID[vehicleid] = sqlid;
}

/*
 * <summary> Gets vehicle sqlid</summary>
 * <param name="vehicleid">Vehicleid</param>
 */

stock Vehicle_GetSQLID(vehicleid) 
{
    return vehicle_SQLID[vehicleid];
}

/*
 * <summary> Set vehicle type</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="type">Type to set</param>
 */

stock void:Vehicle_SetType(vehicleid, type) 
{
    vehicle_Type[vehicleid] = type;
}


/*
 * <summary> Get vehicle type</summary>
 * <param name="vehicleid">Vehicleid</param>
 */

stock Vehicle_GetType(vehicleid) 
{
    return vehicle_Type[vehicleid];
}

/*
 * <summary> Set vehicle price</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="price"> Price to set</param>
 */

stock void:Vehicle_SetPrice(vehicleid, price) 
{
    vehicle_Type[vehicleid] = price;
}

/*
 * <summary> Set vehicle colors</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="model">Model to set</param>
 */

stock void:Vehicle_SetModel(vehicleid, model) 
{
    vehicle_Model[vehicleid] = model;
}

/*
 * <summary> Gets vehicle model/summary>
 * <param name="vehicleid">Vehicleid</param>
 */

stock Vehicle_GetModel(vehicleid)
{
    return vehicle_Model[vehicleid];
}

/*
 * <summary> Set vehicle interior</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="interior">Interior id to set</param>
 */

stock void:Vehicle_SetInterior(vehicleid, interior) 
{
    vehicle_Interior[vehicleid] = interior;
    LinkVehicleToInterior(vehicleid, interior);
}

/*
 * <summary> Set vehicle colors</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="color1">Color 1 to set</param>
 * <param name="color2">Color 2 to set</param>
 */

stock void:Vehicle_SetColor(vehicleid, color1, color2) 
{
    vehicle_Colors[vehicleid][0] = color1;
    vehicle_Colors[vehicleid][1] = color2;
    ChangeVehicleColor(vehicleid, vehicle_Colors[vehicleid][0], vehicle_Colors[vehicleid][1]);
}

/*
 * <summary> Set vehicle virtual world</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="vw">Virtual world to set</param>
 */

stock void:Vehicle_SetVirtualWorld(vehicleid, vw) {
    vehicle_VirtualWorld[vehicleid] = vw;
}

/*
 * <summary> Get vehicle color by index</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="pos">Index of color being returned</param>
 */

stock Vehicle_GetColor(vehicleid, colorind) 
{
    return vehicle_Colors[vehicleid][colorind];
}

/*
 * <summary> Set vehicle engine state</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="pos">Index of position being returned</param>
 */

stock void:Vehicle_SetParamsEx(vehicleid, paramsind, val)
{
    vehicle_Params[vehicleid][paramsind] = val;
    SetVehicleParamsEx(vehicleid, vehicle_Params[vehicleid][0], vehicle_Params[vehicleid][1], vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
}

/*
 * <summary> Get vehicle params by index</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="paramsind">Index of params being returned</param>
 */

stock Vehicle_GetParamsEx(vehicleid, paramsind)
{
    GetVehicleParamsEx(vehicleid, vehicle_Params[vehicleid][0], vehicle_Params[vehicleid][1], vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
    return vehicle_Params[vehicleid][paramsind];
}

/*
 * <summary> Set vehicle position</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="x">X coordinate to set</param>
 * <param name="y">Y coordinate to set</param>
 * <param name="z">Z coordinate to set</param>
 * <param name="a">Facing angle to set</param>
 */

stock Float:Vehicle_SetPosition(vehicleid, Float: x, Float: y, Float: z, Float: a)
{
    vehicle_Position[vehicleid][0] = x;
    vehicle_Position[vehicleid][1] = y;
    vehicle_Position[vehicleid][2] = z;
    vehicle_Position[vehicleid][3] = a;
    SetVehiclePos(vehicleid, x, y, z);
    SetVehicleZAngle(vehicleid, a);
}

/*
 * <summary> Set vehicle engine state</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="pos">Index of position being returned</param>
 */


stock Float:Vehicle_GetPosition(vehicleid, pos)
{
    GetVehiclePos(vehicleid, vehicle_Position[vehicleid][0], vehicle_Position[vehicleid][1], vehicle_Position[vehicleid][2]);
    GetVehicleZAngle(vehicleid, vehicle_Position[vehicleid][3]);
    return vehicle_Position[vehicleid][pos];
}
/*
 * <summary> Set vehicle engine state</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="stat">State of engine</param>
 */

stock void:Vehicle_SetEngineState(vehicleid, bool:stat) 
{
    GetVehicleParamsEx(vehicleid, vehicle_Params[vehicleid][0], vehicle_Params[vehicleid][1], vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
    vehicle_Params[vehicleid][0] = stat ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF;
    if(Iter_Contains(Vehicles, vehicleid)) { 
        mysql_tquery_s(Database_ReturnHandle(), str_format("UPDATE `vehicle_params` SET `Engine` = %d WHERE `ID` = %d", vehicle_Params[vehicleid][0], vehicle_SQLID[vehicleid]));
    }
    SetVehicleParamsEx(vehicleid, stat ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF,vehicle_Params[vehicleid][1], vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
}

/*
 * <summary> Returns engine state</summary>
 */

stock bool:Vehicle_ReturnEngineState(vehicleid)
{
    GetVehicleParamsEx(vehicleid, vehicle_Params[vehicleid][0], vehicle_Params[vehicleid][1], vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
    return vehicle_Params[vehicleid][0] == VEHICLE_PARAMS_ON ? true : false;
}

/*
 * <summary> Set vehicle lights state</summary>
 */

stock void:Vehicle_SetLightsState(vehicleid, bool:stat) 
{
    GetVehicleParamsEx(vehicleid, vehicle_Params[vehicleid][0], vehicle_Params[vehicleid][1], vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
    vehicle_Params[vehicleid][1] = stat ? 1 : 0;
    if(Iter_Contains(Vehicles, vehicleid)) {
        mysql_tquery_s(Database_ReturnHandle(), str_format("UPDATE `vehicle_params` SET `Lights` = %d WHERE `ID` = %d", vehicle_Params[vehicleid][1], vehicle_SQLID[vehicleid]));
    }
    SetVehicleParamsEx(vehicleid, vehicle_Params[vehicleid][0], stat ? VEHICLE_PARAMS_ON : VEHICLE_PARAMS_OFF, vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
}

/*
 * <summary> Returns lights state</summary>
 */

stock bool:Vehicle_ReturnLightsState(vehicleid)
{
    GetVehicleParamsEx(vehicleid, vehicle_Params[vehicleid][0], vehicle_Params[vehicleid][1], vehicle_Params[vehicleid][2], vehicle_Params[vehicleid][3], vehicle_Params[vehicleid][4], vehicle_Params[vehicleid][5], vehicle_Params[vehicleid][6]);
    return vehicle_Params[vehicleid][1] == VEHICLE_PARAMS_ON ? true : false;
}

/*
 * <summary> Returns windows states</summary>
 */

stock bool:Vehicle_ReturnWindowState(vehicleid, window)
{
    GetVehicleParamsCarWindows(vehicleid, vehicle_Windows[vehicleid][0], vehicle_Windows[vehicleid][1], vehicle_Windows[vehicleid][2], vehicle_Windows[vehicleid][3]);
    return vehicle_Windows[vehicleid][window] == VEHICLE_PARAMS_ON ? true : false;
}

/*
 * <summary> Sets a window's state</summary>
 */

stock void:Vehicle_SetWindowState(vehicleid, window, bool:stat)
{
    vehicle_Windows[vehicleid][window] = stat ? 0 : 1;
    SetVehicleParamsCarWindows(vehicleid, vehicle_Windows[vehicleid][0], vehicle_Windows[vehicleid][1], vehicle_Windows[vehicleid][2], vehicle_Windows[vehicleid][3]);
}