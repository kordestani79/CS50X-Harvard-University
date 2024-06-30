#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    int count = 0;
    long temp = number;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    int digits[count];
    temp = number;
    for (int i = 0; i < count; i++)
    {
        digits[i] = temp % 10;
        temp /= 10;
    }
    int sum = 0;
    for (int i = 1; i < count; i += 2)
    {
        int digit = digits[i] * 2;
        sum += digit / 10 + digit % 10;
    }
    for (int i = 0; i < count; i += 2)
    {
        sum += digits[i];
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    if (count == 15 && digits[count - 1] == 3 && (digits[count - 2] == 4 || digits[count - 2] == 7))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && digits[count - 1] == 5 &&
             (digits[count - 2] == 1 || digits[count - 2] == 2 || digits[count - 2] == 3 ||
              digits[count - 2] == 4 || digits[count - 2] == 5))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && digits[count - 1] == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
