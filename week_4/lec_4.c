/*

//I tried to keep it short

*** hexadecimal  ***

0123456789ABCDEF

13 -> D
15 -> F
16 -> 10
255 -> FF

hexadecimal digits are 4-bits

theres a human convention for hexadecimals
to be represented with a 0x

0xD
0x1F
0x4

*** pointers ***

& wil tell the address from the value
* will give the value from the address

%p  print pointers

int n=50;
printf("%p",&n);

0x7fffda893644

int n=50;
int *pointer_n=&n;
// you can store pointers with * after the type
printf("%p",pointer_n);


*** string ***

string s= "HI!";
char *s = "HI!"; #pointer to H

strings store the pointer of first char
and go till they see \0

char *string = "hello";
printf("%s\n",string);

>hello

char *string = "hello";
printf("%p\n",string);

>0x5642fddef004

char *string = "hello";
printf("%c\n",*string);

>h

*** pointer arithmetics ***

#include <stdio.h>
#include <string.h>

int main()
{
    char *string = "GAY";
    printf("%c\n",*(string));
    printf("%c\n",*(string+1));
    printf("%c\n",*(string+2));
}

>G
>A
>Y

*** malloc and free functions ***

malloc -> memory allocation
free -> free the memory

stdlib.h --> memory management and etc library

-->to copy strings strcpy(target,source)


+++ nice trick
instead of:

int length = strlen(string);
for (int i=0; i<length; i++)
{
    ...
}

do:

for (int i=0, int length=strlen(string); i<length; i++)
{
    ...
}

*** valgrind ***

a tool for memory safety in c :)

*** garbage value ***

when you allocate memory to something but
dont initiallize any value
and it has random value


*** solving the issue of scope ***

int main()
{
    int a = 1;
    int b = 2;
    swap(a,b);

}

void swap(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//this is buggy code
//because the variable dont literally get passed
// to swap and indeed are copies

//to solve it pass the literal addresses instead of values

int main()
{
    int a = 1;
    int b = 2;
    swap(&a,&b);

}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

heap overflow = program using to much memory 
stack overflow = functions using too much memory
buffer overflow = some chunk of data program uses overflow

*/
