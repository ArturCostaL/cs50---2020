// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

int dic_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int word_size = strlen(word);
    if (word_size > LENGTH + 1)
    {
        return false;
    }
    for (node *n = table[hash(word)]; n != NULL; n = n->next)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int letter2 = 1;
    int letter1 = toupper(word[0]) - 64;
    if (toupper(word[1]) > 64  && toupper(word[1]) < 91)
    {
        letter2 = toupper(word[1]) - 64;
    }
    return letter1 * letter2;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for (int i = 0; i < 676; i++)
    {
        table[i] = NULL;
    }

    char *word = malloc((LENGTH + 1) * sizeof(char));

    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        return false;
    }

    while (fgets(word, LENGTH + 2, dict) != NULL)
    {
        int word_size = strlen(word);
        if (word_size > LENGTH + 1)
        {
            continue;
        }

        node *new_node = malloc(sizeof(node));
        if ((int)word[word_size - 1] == 10)
        {
            word[word_size - 1] = '\0';
        }

        if (table[hash(word)] == NULL)
        {
            strcpy(new_node->word, word);
            new_node->next = NULL;
            table[hash(word)] = new_node;
        }
        else
        {
            strcpy(new_node->word, word);
            new_node->next = table[hash(word)];
            table[hash(word)] = new_node;
        }
        dic_size++;
    }
    free(word);
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dic_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 676; i++)
    {
        node *n = table[i];

        while (n != NULL)
        {
            node *tmp = n->next;
            free(n);
            n = tmp;
        }

        if (i == 675)
        {
            return true;
        }
    }
    return false;

}
