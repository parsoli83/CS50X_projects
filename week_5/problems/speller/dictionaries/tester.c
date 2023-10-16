#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool load(char *dictionary);
unsigned int hash(const char *word);
unsigned int size(void);

int is_loaded  = 0;
typedef struct node
{
    char value[45];
    struct node *before;
}
node;

int main()
{
    char *small= "small";
    bool idiot = load(small);
    
}

unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    char char0 = tolower(word[0]); 
    char char1 = tolower(word[1]);

    return (char0 - 'a')*26 + char1 - 'a';
}
bool load(char *dictionary)
{
    node *hash_array[26*26];
    for (int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            hash_array[i][j] = NULL;
        }
    }
    FILE *dict = fopen(dictionary,"r");
    if (dict == NULL)
    {
        printf("Couldn't open");
    }
    else
    {
        while (true)
        {
            char c[45];
            while (fgets(c,45,dict))
            {
                is_loaded++;
                node * n = malloc(sizeof(node));
                for (int i = 0; i < 45; i++)
                {
                    n -> value[i] = c[i];
                }
                n -> before = hash_array[hash(c)];
                hash_array[hash(c)] = n;
            }
            return true;
        }
    }
    return false;
}

int isvowel(char ch)
{
    switch (ch)
    {
        case 'a':
            return 0;
        case 'e':
            return 1;
        case 'i':
            return 2;
        case 'o':
            return 3;
        case 'u':
            return 4;
        default:
            return -1;
    }
}

unsigned int size(void)
{
    if (is_loaded==0)
    {

    }
    return 0;
}