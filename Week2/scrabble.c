#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char lower_char(char letter);
int str_value(string word);

int main(void)
{
    string StrPlayer1 = get_string("Player 1: ");
    string StrPlayer2 = get_string("Player 2: ");
    int ValuePlayer1 = str_value(StrPlayer1);
    int ValuePlayer2 = str_value(StrPlayer2);
    if (ValuePlayer1 == ValuePlayer2)
    {
        printf("Tie!\n");
    }
    else if (ValuePlayer1>ValuePlayer2)
    {
        printf("Player 1 wins!\n");
    }
    else if (ValuePlayer1<ValuePlayer2)
    {
        printf("Player 2 wins!\n");
    }
}

char lower_char(char letter)
{
    if (isupper(letter))
    {
        return letter + 32;
    }
    else
    {
        return letter;
    }
}


int str_value(string word)
{
    int len = strlen(word);
    int value = 0;
    for (int i = 0; i < len; i++)
    {
        int lval;
        char letter = word[i];
        letter = lower_char(letter);
        if (letter == 'a' || letter == 'e' || letter =='i' || letter == 'l' || letter == 'n' || letter == 'o' || letter == 'r' || letter == 's' || letter == 't' || letter == 'u')
        {
            lval = 1;
        }
        else if (letter == 'd' || letter == 'g')
        {
            lval = 2;
        }
        else if (letter == 'b' || letter == 'c' || letter == 'm' || letter == 'p')
        {
            lval = 3;
        }
        else if (letter == 'f' || letter == 'h' || letter == 'v' || letter == 'w' || letter == 'y')
        {
            lval = 4;
        }
        else if (letter == 'k')
        {
            lval = 5;
        }
        else if (letter == 'j' || letter == 'x')
        {
            lval = 8;
        }
        else if (letter == 'q' || letter == 'z')
        {
            lval = 10;
        }
        else
        {
            lval = 0;
        }
        value = value + lval;
        // printf("%c - %ipuntos\n", letter, lval);
    }
    // printf("\n");
    return value;
}


