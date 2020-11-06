/* 
 * <summary> Called when vehicle load</summary>
 */ 

forward OnVehicleLoad();

/*
 * <summary> Handles vehicles loading</summary>
 */

stock void: LoadVehicles()
{
    mysql_tquery(Database_ReturnHandle(),
        "SELECT * FROM \
        `vehicle_entry` \
        LEFT JOIN `vehicle_info` \
        ON `vehicle_entry`.`ID` = `vehicle_info`.`ID`\
            LEFT JOIN `vehicle_params`\
            ON `vehicle_entry`.`ID` = `vehicle_params`.`ID`", "OnVehicleLoad", "");
}

//-----------------------------

public void:OnVehicleLoad() 
{
    new
        Float: load_Pos[4],
        load_Model,
        load_Sqlid,
        load_colors[2],
        load_dimensions[2],
        load_type,
        load_params[7];

    if(cache_num_rows()) {  
        for (new i, j = cache_num_rows(); i != j; i++) {
            new id = Iter_Alloc(Vehicles);
            cache_get_value_name_float(i, "X", load_Pos[0]);
            cache_get_value_name_float(i, "Y", load_Pos[1]);
            cache_get_value_name_float(i, "Z", load_Pos[2]);
            cache_get_value_name_float(i, "A", load_Pos[3]);
            cache_get_value_name_int(i, "Model", load_Model);
            
            cache_get_value_name_int(i, "ID", load_Sqlid);
            cache_get_value_name_int(i, "Color1", load_colors[0]);
            cache_get_value_name_int(i, "Color2", load_colors[1]);
            cache_get_value_name_int(i, "Interior", load_dimensions[0]);
            cache_get_value_name_int(i, "VW", load_dimensions[1]);
            cache_get_value_name_int(i, "Type", load_type);
            cache_get_value_name_int(i, "Engine", load_params[0]);
            cache_get_value_name_int(i, "Lights", load_params[1]);
            cache_get_value_name_int(i, "Alarm", load_params[2]);
            cache_get_value_name_int(i, "Doors", load_params[3]);
            cache_get_value_name_int(i, "Bonnet", load_params[4]);
            cache_get_value_name_int(i, "Boot", load_params[5]);
            cache_get_value_name_int(i, "Objective", load_params[6]);

            Vehicle_SetModel(id, load_Model);
            Vehicle_SetPosition(id, load_Pos[0], load_Pos[1], load_Pos[2], load_Pos[3]);
            Vehicle_SetColor(id, load_colors[0], load_colors[1]);
            
            id = CreateVehicle(Vehicle_GetModel(id), Vehicle_GetPosition(id, 0), Vehicle_GetPosition(id, 1), Vehicle_GetPosition(id, 2), Vehicle_GetPosition(id, 3), Vehicle_GetColor(id, 0), Vehicle_GetColor(id, 1), -1);
            Vehicle_SetInterior(id, load_dimensions[0]);
            Vehicle_SetVirtualWorld(id, load_dimensions[1]);
            Vehicle_SetParamsEx(id, 0, load_params[0]);
            Vehicle_SetParamsEx(id, 1, load_params[1]);
            Vehicle_SetParamsEx(id, 2, load_params[2]);
            Vehicle_SetParamsEx(id, 3, load_params[3]);
            Vehicle_SetParamsEx(id, 4, load_params[4]);
            Vehicle_SetParamsEx(id, 5, load_params[5]);
        }      
    }
}