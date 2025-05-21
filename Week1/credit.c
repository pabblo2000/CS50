// Luhn’s Algorithm
// So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
// Add the sum to the sum of the digits that weren’t multiplied by 2.
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

// AMEX --> 15 digits, starts with 34 or 37
// MasterCard --> 16 digits and starts with 51, 52, 53, 54, or 55
// VISA --> 13 or 16 digits starts with 4
// INVALID

// Example: 4003600000000014  --> Valid

#include <stdio.h>
#include <cs50.h>

int luhn_sum(long card);
bool luhn(long card);
int card_length(long card);
int starts_with(long card, int n);
void card_type(long card);


int main(void)
{
    long card = get_long("Number: ");
    // printf("Card Length: %i\n", card_length(card));
    // printf("First number %i\n", starts_with(card, 1));
    // printf("First two numbers %i\n", starts_with(card, 2));
    // printf("Luhn suma: %i\n", luhn_sum(card));
    // printf("Es valida: %i\n\n", luhn(card));
    card_type(card);
}



int luhn_sum(long card)
{
    long number = card;
    int sum = 0;
    int alter = 0;
    while(number > 0)
    {
        int n = 0;
        number /= 10;
        // printf("We're in: %li\n",number);
        if(alter % 2 == 0)
        {
            n = (number % 10) * 2;
            while(n > 0)
            {
                // printf("The number is: %i\n", n);
                sum += n % 10;
                // printf("Sum is now equal to: %i\n", sum);
                n /= 10;
            }
            // printf("----------------------\n");
        }
        // else
        // {
        //     // printf("----------------------\n");
        //     // printf("We skip it\n");
        // }
        // printf("Sum is now equal to: %i\n",sum);
        // printf("----------------------\n");
        alter += 1;

    }

    // printf("Total Sum is equal to: %i\n", sum);
    return sum;
}



bool luhn(long card)
{
    long number = card;
    int sum = 0;
    int alter = 0;
    while(number > 0)
    {
        // printf("Number is now worth %li\n", number);
        if(alter % 2 == 0)
        {

            sum += number % 10;
            // printf("Sum is now worth %i\n", sum);
        }
        alter += 1;
        number /= 10;
    }
    sum += luhn_sum(card);
    // printf("Total sum is: %i", sum);
    if(sum == 20)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int card_length(long card)
{
    long card_number = card;
    int digits = 0;
    while(card_number > 0)
    {
        digits++;
        card_number /= 10;
    }
    // printf("The card: %li has %i digits\n", card, digits);
    return digits;
}

int starts_with(long card, int n)
{
    int length = card_length(card);
    long long divide_by = 1;
    for (int i = 0; i < length - n; i++)
    {
        divide_by *= 10;
    }
    int starts = card / divide_by;
    // printf("Starts with %i\n", starts);
    // printf("Divided by %lld\n", divide_by);
    return starts;
}

void card_type(long card)
{
    if((starts_with(card, 2) ==  34 || starts_with(card, 2) == 37) && card_length(card) == 15 && luhn(card))
    {
        printf("AMEX\n");
    }
    else if(starts_with(card, 2) >= 51 && starts_with(card, 2) <= 55 && card_length(card) == 16 && luhn(card))
    {
        printf("MasterCard\n");
    }
    else if(starts_with(card, 1) ==  4 && (card_length(card) == 13 || card_length(card) == 16) && luhn(card))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
