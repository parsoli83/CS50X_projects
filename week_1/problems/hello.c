#include <stdio.h>

int main(void)
{
    char name[256];
    printf("What's your name? ");
    gets(name);
    printf("hello, %s\n", name);

}