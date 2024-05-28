// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

string replace(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <word>\n", argv[0]);
        return (1);
    }
    else
    {
        string result = replace(argv[1]);
        printf("%s\n", result);
        free(result);
        return (0);
    }
}

string replace(string input)
{
    int i = 0;
    string result = malloc(sizeof(input));
    if (!result)
    {
        printf("Memory allocation went wrong...\n");
        return (NULL);
    }
    while (input[i])
    {
        switch (input[i])
        {
            case 'a':
                result[i] = '6';
                i++;
                break;
            case 'e':
                result[i] = '3';
                i++;
                break;
            case 'i':
                result[i] = '1';
                i++;
                break;
            case 'o':
                result[i] = '0';
                i++;
                break;
            default:
                result[i] = input[i];
                i++;
                break;
        }
    }
    return (result);
}
