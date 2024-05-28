#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string caesar(string str, int key);
bool only_digits(string str);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (!only_digits(argv[1]))
        {
            printf("Usage: %s key\n", argv[0]);
            return (1);
        }
        else
        {
            int key = atoi(argv[1]);
            string str = get_string("plaintext: ");
            string new = caesar(str, key);
            printf("ciphertext: %s\n", new);
            free(new);
            return (0);
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return (1);
    }
}

bool only_digits(string str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

string caesar(string str, int key)
{
    string coded = malloc(strlen(str) + 1);
    int i = 0;
    while (str[i])
    {
        coded[i] = rotate(str[i], key % 26);
        i++;
    }
    coded[i] = '\0';
    return (coded);
}

char rotate(char c, int n)
{
    string alphabet_hi = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabet_lo = "abcdefghijklmnopqrstuvwxyz";

    int index = 0;

    if (!isalpha(c))
        return (c);
    else
    {
        if (isupper(c))
        {
            if (c + n > 'Z')
                index = (c + n) % 90 - 1;
            else
                index = (c + n) % 90 - 65;
            return alphabet_hi[index];
        }
        else
        {
            if (c + n > 'z')
                index = (c + n) % 122 - 1;
            else
                index = (c + n) % 122 - 97;
            return alphabet_lo[index];
        }
    }
}
