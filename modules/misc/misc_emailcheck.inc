/* <summary> Used to check if inputed email is valid</summary>
 * <param name="email">email which we are checking</param>
 */

stock Misc_IsValidEmail(const email[])
{
    new Regex:r = Regex_New("^[_a-z0-9-]+(.[a-z0-9-]+)@[a-z0-9-]+(.[a-z0-9-]+)*(.[a-z]{2,4})$");
    new check = Regex_Check(email, r);
    Regex_Delete(r);
    return check;
}