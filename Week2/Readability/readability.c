#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // input
    string input = get_string("Text: ");
    int n = strlen(input);
    int lettercount = 0;
    int wordcount = 1;
    int sentcount = 0;

    // count the number of letters, words, and sentences in the text
    for (int i = 0; i < n; i++)
    {
        if (isalpha(input[i]))
        {
            lettercount++;
        }
    }

    // count the word by finding charecter before whitespace
    for (int i = 0; i < n; i++)
    {
        if (isspace(input[i]) && isgraph(input[i + 1]))
        {
            wordcount++;
        }
    }

    // count sentences by finding ., !, ? after letter
    for (int i = 0; i < n; i++)
    {
        if (isalpha(input[i]) && input[i + 1] == '.')
        {
            sentcount++;
        }
        else if (isalpha(input[i]) && input[i + 1] == '!')
        {
            sentcount++;
        }
        else if (isalpha(input[i]) && input[i + 1] == '?')
        {
            sentcount++;
        }
    }

    // calculating
    float l = (float) lettercount / wordcount * 100;
    float s = (float) sentcount / wordcount * 100;
    float grade = 0.0588 * l - 0.296 * s - 15.8;
    printf("%i %i %i\n", lettercount, wordcount, sentcount);

    // printing
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else
    {
        printf("Grade 16+\n");
    }
}
