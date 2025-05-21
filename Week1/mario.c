#include <cs50.h>
#include <stdio.h>

//   # s = h-row; c = row | row = 1
//  ## s = h-row; c = row | row = 2
// ### s = h-row; c = row | row = 3

int main(void)
{
    int height = -1;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    for (int row = 1; row <= height; row++)
    {
        // spaces left
        for (int s = 0; height - row > s; s++)
        {
            printf(" ");
        }
        // letters left
        for (int c = 0; c < row; c++)
        {
            printf("#");
        }
        // middle
        printf("  ");
        // letters right
        for (int c = 0; c < row; c++)
        {
            printf("#");
        }
        // //spaces right
        // for(int s = 0; height - row > s; s++)
        // {
        //     printf(" ");
        // }
        printf("\n");
    }
}

