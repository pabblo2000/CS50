#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string string_to_upper(string text);
bool is_valid_key(string text);
string substitute(string text, string key);

// Test: NQXPOMAFTRHLZGECYJIUWSKDVB


int main (int argc, string argv[])
{
    // Check there is only one argument
    if (argc != 2)
    {
        printf("Enter just one KEY as an argument\n");
        return 1;
    }
    string key = string_to_upper(argv[1]);
    //printf("The key introduced is: %s\n", key);
    
    // Check the key length (26characters) & Check for non-alphabetic characters & Check for repeated characters (case-insensitive)
    //printf("%i\n", is_valid_key(key));
    if (is_valid_key(key))
    {
        // Ask the user of a text
        string text = get_string("plaintext: ");

        // Makes the cypher and prints it
        text = substitute(text, key);

        printf("ciphertext: %s\n", text);

        return 0;
    }
    else
    {
        return 1;
    }
}



string string_to_upper(string text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            text[i] = toupper(text[i]);
        }
    }
    return text;
}



bool is_valid_key(string text)
{
    // Checks if there are 26 letters, if all of them are alphabetic and if there are not duplicate values
    unsigned int n_letters = 0;
    bool alphabet[26] = {false};
    int index = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if(!isalpha(text[i]))
        {
            printf("There is a non alphabetical value in the key\n");
            return false;
        }
        index = toupper(text[i]) - 'A';
        if (alphabet[index] == false)
        {
            alphabet[index] = true;
        }
        else
        {
            printf("The key contains a duplicate letter\n");
            return false;
        }
        n_letters++;
    }
    if (n_letters == 26)
    {
        return true;
    }
    else
    {
        printf("The key doesn't have 26 letters\n");
        return false;
    }
}



string substitute(string text, string key)
{
    // Substitutes the letters for the ones on the key
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                text[i] = tolower(key[text[i] - 'a']);
            }
            else
            {
                text[i] = key[text[i] - 'A'];
            }
        }
    }
    return text;
}





