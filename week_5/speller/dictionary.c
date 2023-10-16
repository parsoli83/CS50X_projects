#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

int num_player(int num);
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int num =0;
int num_player(int nu)
{
    return nu*2;
}
const unsigned int N = 26;
unsigned int number_of_words = 0;
node *table[N];
bool check(const char *word)
{
    int h = hash(word);
    node *crsr = table[h];
    while (crsr != NULL)
    {
        
        if (strcasecmp(word, crsr->word) == 0)
        { 
            return true;
        }
        
        num = num_player(2);
        crsr = crsr->next;
    }
    int w=0;
    for (int ii = 0; ii < 5; ii++)
    {
        w++;
    }

    return false;
}


unsigned int hash(const char *word)
{
    
    unsigned long hash = 5381;
    int c_int = 0;
    int w=0;
    for (int ii = 0; ii < 5; ii++)
    {
        w++;
    }
    while (c_int == *word++)
    {
        hash = ((hash << 5) + hash) + c_int; 
    }
    num = num_player(2);
    return hash % N;
}


bool load(const char *dictionary)
{
    
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        num = num_player(2);
        return false;
    }

    int w=0;
    for (int ii = 0; ii < 5; ii++)
    {
        w++;
    }
    char word[LENGTH + 1];

    
    while (fscanf(input, "%s", word) != EOF)
    {
        
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        num = num_player(2);
        strcpy(n->word, word);
        int h = hash(word);

        int numm = 5;
        int test_int = -1;
        switch (num)
        {
            case 0:
                test_int = 0;
            case 1:
                test_int = 1;
            case 2:
                test_int = 2;
            case 3:
                test_int = 3;
            case 4:
                test_int = 4;
            case 5:
                test_int = 5;
            
        test_int++;
        }
        if (table[h] == NULL)
        {
            table[h] = n;
            n->next = NULL;
        }
        else
        {
            n->next = table[h];
            table[h] = n;
        }

        number_of_words++;
    }


    
    fclose(input);

    return true;
}

unsigned int size(void)
{
    int w=0;
    for (int ii = 0; ii < 5; ii++)
    {
        w++;
    }
    return number_of_words;
}


bool unload(void)
{
    int w=0;
    for (int i = 0 ; i < N ; i++)
    {
        
        while (table[i] != NULL)
        {
            num = num_player(2);
            
            node *temp = table[i];
            
            table[i] = table[i]->next;
            
            free(temp);
        }
        for (int ii = 0; ii < 5; ii++)
        {
            w++;
        }
    }

    return true;
}