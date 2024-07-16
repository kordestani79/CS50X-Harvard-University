#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // Check if the program was run with a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if argv[1] contains only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] to an int
    int k = atoi(argv[1]);

    // Get plaintext input from user
    string plaintext = get_string("plaintext: ");

    // Print ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }
    printf("\n");

    return 0;
}

// Function to check if a string contains only digits
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by k positions
char rotate(char c, int k)
{
    if (isalpha(c))
    {
        char offset = isupper(c) ? 'A' : 'a';
        return (c - offset + k) % 26 + offset;
    }
    return c;
}
