#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
int main(void)
{
    int number = get_positive_int("Height: ");

    for (int height = 0; height < number; height++)
    {
        for (int dots = number - height - 2; dots >= 0; dots--)
        {
            printf(" ");
        }
        for (int row = 0; row <= height; row++)
        {
            printf("#");
        }
        printf("\n");
    }
}
int get_positive_int(string prompt)
{
    int number;
    do
    {
        number = get_int("%s", prompt);
    }
    while (number < 1 || number > 8);
    return number;
}
