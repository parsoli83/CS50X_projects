#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char *word[45];
    scanf("%s", word);
    printf("hash: %i\n",hash(word));

}


int hash(char *word)
{
    // TODO: Improve this hash function
    char char0 = tolower(word[0]); 
    char char1 = tolower(word[1]);

    return (char0 - 'a')*26 + char1 - 'a';
    




    
    //return toupper(word[0]) - 'A';
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