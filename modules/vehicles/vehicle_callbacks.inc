
/* 
 * <summary>This is called after the vehicle is created</summary>
 * <param name="vehicleid">Vehicleid</param>
 * <param name="model">Model of the vehicle</param>
 * <param name="color1">Color1 of the vehicle</param>
 * <param name="color2">Color2 of the vehicle</param>
 * <param name="Interior">Interior of the vehicle</param>
 * <param name="virtualworld">Virtualworld of the vehicle</param>
 */

forward OnCreateVeh(vehicleid, model, color1, color2, interior, virtualworld);

//-----------------------------------------------

public void:OnCreateVeh(vehicleid, model, color1, color2, interior, virtualworld) {

    Vehicle_SetSQLID(vehicleid, cache_insert_id());
    new String: Query = str_format(
        "INSERT INTO `vehicle_info` \
        (`ID`, `Model`, `Color1`, `Color2`, `Interior`, `VW`) \
        VALUES (%d, %d, %d, %d, %d, %d); \
        INSERT INTO `vehicle_params` \
        (`ID`, `Type`, `Engine`, `Lights`, `Alarm`, `Doors`, `Bonnet`, `Boot`, `Objective`) \
        VALUES (%d, %d, %d, %d, %d, %d, %d, %d, %d);",
        Vehicle_GetSQLID(vehicleid), model, color1, color2, interior, virtualworld,
        Vehicle_GetSQLID(vehicleid), Vehicle_GetType(vehicleid), Vehicle_GetParamsEx(vehicleid, 0), Vehicle_GetParamsEx(vehicleid, 1),
        Vehicle_GetParamsEx(vehicleid, 2), Vehicle_GetParamsEx(vehicleid, 3), Vehicle_GetParamsEx(vehicleid, 4), Vehicle_GetParamsEx(vehicleid, 5), Vehicle_GetParamsEx(vehicleid, 6)
    );
    mysql_tquery_s(Database_ReturnHandle(), Query);
}
