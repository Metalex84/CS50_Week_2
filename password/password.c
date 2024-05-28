// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>

bool valid(string password);

bool is_uppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (true);
    return (false);
}

bool is_lowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (true);
    return (false);
}

bool is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool is_symbol(char c)
{
    if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
        return (true);
    return (false);
}

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool status[4] = {false, false, false, false};
    int i = 0;
    while (password[i])
    {
        if (is_uppercase(password[i]))
            status[0] = true;
        if (is_lowercase(password[i]))
            status[1] = true;
        if (is_digit(password[i]))
            status[2] = true;
        if (is_symbol(password[i]))
            status[3] = true;
        i++;
    }
    if (status[0] && status[1] && status[2] && status[3])
        return (true);
    else
        return (false);
}
