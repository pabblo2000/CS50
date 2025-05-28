#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau(string text);
void grade_coleman_liau(string text);


// Program assumptions
// 1. will contain at least one word;
// 2. will not start or end with a space; and
// 3. will not have multiple spaces in a row.

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Input your Text: ");

    // // Count the number of letters, words, and sentences in the text
    // printf("There are %i letters in the text.\n", count_letters(text));
    // printf("There are %i words in the text.\n", count_words(text));
    // printf("There are %i sentences in the text.\n", count_sentences(text));

    // // Compute the Coleman-Lieau index
    // printf("The Coleman-Lieau index is: %i.\n", coleman_liau(text));

    // Print the grade level
    grade_coleman_liau(text);
}


int count_letters(string text)
{
    // Returns the number of letters in text
    unsigned int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // Returns the words in a text (using spaces + 1)
    unsigned int words = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string text)
{
    // Returns the number of sentences of a text (number of ['.', '!', '?'])
    unsigned int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int coleman_liau(string text)
{
    // Returns the Coleman-Liau index, computed using index = 0.0588 * L - 0.296 * S - 15.8
    float w = count_words(text);

    float l = count_letters(text) / w * 100;
    float s = count_sentences(text) / w * 100;

    return round(0.0588 * l - 0.296 * s - 15.8);
}

void grade_coleman_liau(string text)
{
    // Prints the resulting index number, capped on 1 and 16.
    int grade = coleman_liau(text);
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
