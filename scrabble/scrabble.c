#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

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

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
    return (0);
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int acc = 0;
    int i = 0;
    while (word[i])
    {
        if (is_uppercase(word[i]))
            acc += POINTS[(word[i++] - 'A')];
        else if (is_lowercase(word[i]))
            acc += POINTS[(word[i++] - 'a')];
        else
            i++;
    }
    return (acc);
}
