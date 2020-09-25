// --
// <summary>Used to check if the particular nickname is valid, by Firstname_Lastname standards</summary>
    // <param name="username"> Nickname to check</param>
// --

stock Misc_CheckRoleplayName(const nickname[])
{
    new Regex:r = Regex_New("[A-Z][a-z]+_[A-Z][a-z]+");

    new check = Regex_Check(nickname, r);

    Regex_Delete(r);

    return check;
}