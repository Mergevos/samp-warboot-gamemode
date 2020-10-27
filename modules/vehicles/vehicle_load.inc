// --
// <summary> Handles vehicles loading</summary>
// --

stock LoadVehicles()
{
    mysql_tquery(Database_ReturnHandle(),
        "SELECT * FROM \
        `vehicle_entry` \
        LEFT JOIN `vehicle_info` \
        ON `vehicle_entry`.`ID` = `vehicle_info`.`ID`\
            LEFT JOIN `vehicle_params`\
            ON `vehicle_entry`.`ID` = `vehicle_params`.`ID`", "OnVehicleLoad", "");
}

forward OnVehicleLoad();
public OnVehicleLoad() 
{
    if(cache_num_rows()) {  
        for (new i, j = cache_num_rows(); i != j; i++) {
            new id = Iter_Alloc(Vehicles);
            cache_get_value_name_float(i, "X", Vehicle_Position[id][0]);
            cache_get_value_name_float(i, "Y", Vehicle_Position[id][1]);
            cache_get_value_name_float(i, "Z", Vehicle_Position[id][2]);
            cache_get_value_name_float(i, "A", Vehicle_Position[id][3]);
            cache_get_value_name_int(i, "Model", Vehicle_Model[id]);
            
            cache_get_value_name_int(i, "ID", Vehicle_SQLID[id]);
            printf("i: %d j: %d model %d and sqlid %d and id %d", i, j, Vehicle_Model[id], Vehicle_SQLID[id], id);
            cache_get_value_name_int(i, "Color1", Vehicle_Colors[id][0]);
            cache_get_value_name_int(i, "Color2", Vehicle_Colors[id][1]);
            cache_get_value_name_int(i, "Interior", Vehicle_Interior[id]);
            cache_get_value_name_int(i, "VW", Vehicle_VirtualWorld[id]);
            cache_get_value_name_int(i, "Type", Vehicle_Type[id]);
            cache_get_value_name_int(i, "Engine", Vehicle_Params[id][0]);
            cache_get_value_name_int(i, "Lights", Vehicle_Params[id][1]);
            cache_get_value_name_int(i, "Alarm", Vehicle_Params[id][2]);
            cache_get_value_name_int(i, "Doors", Vehicle_Params[id][3]);
            cache_get_value_name_int(i, "Bonnet", Vehicle_Params[id][4]);
            cache_get_value_name_int(i, "Boot", Vehicle_Params[id][5]);
            cache_get_value_name_int(i, "Objective", Vehicle_Params[id][6]);
            id = CreateVehicle(Vehicle_Model[id], Vehicle_Position[id][0], Vehicle_Position[id][1], Vehicle_Position[id][2], Vehicle_Position[id][3], Vehicle_Colors[id][0], Vehicle_Colors[id][1], -1);
            LinkVehicleToInterior(id, Vehicle_Interior[id]);
            SetVehicleVirtualWorld(id, Vehicle_VirtualWorld[id]);
            SetVehicleParamsEx(id, Vehicle_Params[id][0], Vehicle_Params[id][1], Vehicle_Params[id][2], Vehicle_Params[id][3], Vehicle_Params[id][4], Vehicle_Params[id][5], Vehicle_Params[id][6]);
        }      
    }
}