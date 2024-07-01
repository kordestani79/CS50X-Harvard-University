#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
char substitute_char(char c, string key);

int main(int argc, string argv[])
{
    // Check if the program was run with a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!is_valid_key(key))
    {
        return 1;
    }

    // Get plaintext input from user
    string plaintext = get_string("plaintext: ");

    // Print ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute_char(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    // Check if the key has 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    bool seen[26] = {false};

    // Check if the key contains only alphabets and no repeated characters
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            printf("Key must not contain repeated characters.\n");
            return false;
        }
        seen[index] = true;
    }

    return true;
}

char substitute_char(char c, string key)
{
    if (isalpha(c))
    {
        bool is_lower = islower(c);
        int index = toupper(c) - 'A';
        char substituted_char = is_lower ? tolower(key[index]) : toupper(key[index]);
        return substituted_char;
    }
    return c;
}
