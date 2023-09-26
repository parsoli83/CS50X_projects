// program named mainreturn.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// defining main with arguments
int main(int argc, char* argv[])
{
    char* guess = get_string("Input a 5-letter word: ");
    if (atoi(argv[1]) == 5 || atoi(argv[1]) == 6 || atoi(argv[1]) == 7 || atoi(argv[1]) == 8)
    {
        printf("good program\n");
    }
    /*
    if (argc != 2){
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }
    char *thingy = "5";
    printf("%d\n",strlen(thingy));
    printf("%d\n",strlen(argv[1]));
    if (strcmp(argv[1][0],thingy[0]) || atoi(argv[1]) == 6 || argv[1] == '7' || argv[1] == '8')
    {
        printf("Wordsize");
    }
    */
    
}