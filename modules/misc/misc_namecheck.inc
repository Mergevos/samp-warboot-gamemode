/* <summary> Used to check if inputed email is valid</summary>
 * <param name="email">email which we are checking</param>
 */
stock Misc_IsRPNick(const nickname[])
{
    new Regex:r = Regex_New("[A-Z][a-z]+_[A-Z][a-z]+");

    new check = Regex_Check(nickname, r);

    Regex_Delete(r);

    return check;
}