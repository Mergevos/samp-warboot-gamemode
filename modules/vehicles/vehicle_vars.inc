#undef MAX_VEHICLES 
#define MAX_VEHICLES 300
new 
    Iterator: Vehicles<MAX_VEHICLES>,
    //Vehicle_Handle[MAX_VEHICLES],
    Vehicle_SQLID[MAX_VEHICLES],
    Vehicle_Type[MAX_VEHICLES],
    Vehicle_Price[MAX_VEHICLES],
    Vehicle_Model[MAX_VEHICLES],
    Vehicle_Interior[MAX_VEHICLES],
    Vehicle_Colors[MAX_VEHICLES][2],
    Vehicle_Params[MAX_VEHICLES][7],
    Float: Vehicle_Position[MAX_VEHICLES][5],
    Vehicle_VirtualWorld[MAX_VEHICLES],
    Vehicle_Windows[MAX_VEHICLES][4],
    Vehicle_Doors[MAX_VEHICLES][4];

