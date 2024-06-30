#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Width: ");
    }
    while (!(height >= 1 && height <= 8));

    for (int row = 1; row <= height; row++)
    {
        for (int k = 1; k <= height - row; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= row; j++)
        {
            printf("#");
        }
        printf(" ");
        printf(" ");

        for (int j = 1; j <= row; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
