#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string text = get_string("Message: ");

    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
            print_bulb(1 & (text[i] >> j));
        printf("\n");
    }
    return (0);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
