#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Define the node structure for the trie
typedef struct node
{
    bool isWord;                  // To mark the end of a word
    struct node* children[27];    // Array for 26 letters + apostrophe
}
node;

int count = 0; // To keep track of the number of words loaded

// Root of the trie data structure used in the "load" function
struct node *root = NULL;

// Returns true if word is in dictionary else false.
bool check(const char* word)
{
    int k = strlen(word);
    node *checkSample = root;
    int i;
    for (i = 0; i < k; i++)
    {
        int charValue = 0;

        // Convert character to index
        if (isalpha(word[i]))
        {
            charValue = tolower(word[i]) - 'a';
        }
        else
        {
            charValue = 26; // Apostrophe case
        }

        // If the corresponding child node doesn't exist, return false
        if (checkSample->children[charValue] == NULL)
        {
            return false;
        }

        // Move to the next node
        checkSample = checkSample->children[charValue];
    }
    return checkSample->isWord; // Check if the node marks the end of a word
}

// Loads dictionary into memory.  Returns true if successful else false.
bool load(const char* dictionary)
{
    // Open the dictionary file
    FILE *dict = fopen(dictionary, "r");
    root = calloc(1, sizeof(node));

    // Check if the file stream has been opened correctly
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(dict, "%s\n", word) != EOF)
    {
        node *guide = root;
        int len = strlen(word);
        int i;
        for (i = 0; i < len; i++)
        {
            int numValue = 0;
            // Convert character to index
            if (isalpha(word[i]))
            {
                numValue = word[i] - 'a';
            }
            else
            {
                numValue = 26; // Apostrophe case
            }

            // If the corresponding child node doesn't exist, create it
            if (guide->children[numValue] == NULL)
            {
                guide->children[numValue] = calloc(1, sizeof(node));
            }
            // Move to the next node
            guide = guide->children[numValue];
        }
        guide->isWord = true; // Mark the end of a word
        count++; // Increment word count
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded.
unsigned int size(void)
{
    return count;
}

// Recursively frees the trie nodes
void free_trie(node *rootPtr)
{
    if (rootPtr != NULL)
    {
        int i;
        for (i = 0; i < 27; i++)
        {
            free_trie(rootPtr->children[i]);
        }
    }

    free(rootPtr);
    rootPtr = NULL;
    return;
}

// Unloads dictionary from memory.  Returns true if successful else false.
bool unload(void)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        free_trie(root->children[i]);
    }

    free(root);
    root = NULL;

    if (root == NULL)
    {
        return true;
    }

    return false;
}
