forward OnPlayerAccountChecked(playerid);
public OnPlayerAccountChecked(playerid)
{
    if(cache_num_rows()) {
        return 0;
    }
    
    return 1;
}