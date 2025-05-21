// Array Excercise
// Create an array of size 5 where each element is two times the previous and the first element is two times the previous element.
// Print the array, integer by integer.

#import <stdio.h>
#import <cs50.h>

int main(void){

    // Declare an array
    int const size = 5;
    int numbers[5];
    numbers[0] = 1;

    // Populate an array
    // numbers[0] = 1;
    // numbers[1] = numbers[0]*2;
    // numbers[2] = numbers[1]*2;
    // numbers[3] = numbers[2]*2;
    // numbers[4] = numbers[3]*2;

    // int numbers[5] = {1, 2, 4, 8, 16};

    for (int i = 1; i < size; i++){
        numbers[i] = numbers[i-1] * 2;
    }

    // Print out the values one by one
    for (int i = 0 ; i < size; i++){
        printf("%i\n", numbers[i]);
    }

}
