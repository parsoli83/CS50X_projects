/*
*** about compilers ***

to work with clang:

$ clang file.c && ls
file.c a.out
// a.out is the executable output

// to make it with the same name
$ clang -0 file file.c

>>> gcc:

$ gcc file.c && ls
file.c a.out

& gcc -c file.c

*** comiling ***

pre proccessing
// getting the libraries

compiling
// c to assembly

assembling
// assembly into 01

linking
// linking libraries with your code to make a final form

*** debug ***
// you can test stuff with printf
// I guess either unit test or debugger

*** data types ***

bool    1 byte
int    4 byte
long    8 byte
float   4 byte
double  8 byte
char    1 byte
string  ? byte

*** array ***

int array_int[n];
// an array of ints in the size n

array_int[i]=12;
// you can modify values

// to pass an array as an argument:
int average_taker (int scores[])
{
    ...
}

// you cant take length of an array
// therefore always store the length in a variable
int len_array = 10;
int array[10];

*** string ***

// strings are stored like arrays
// but to specify their boundaries

string("yo!")
in memory =>    'y','o','!','0'
//at the end we have an extra 0(all zero bits/NULL) to state that it ends here

//defining:

string s = "HI!";
//this works fine

//more string functionality here:
<string.h>

//more datatype functions here:
<ctype.h>


//uppercase(string):


#include <stdio.h>
#include <string.h>

char uppercase (char before[]);

int main(void)
{
    printf(uppercase("hello world!"));
}


char uppercase (char before[])
{
    int length = strlen(before);
    char after[length];
    printf("%i\n", length);
    for (int i=0;i<=length;i++)
    {
        if (before[i] >= 'a' && before[i] <= 'z')
        {
            after[i]= (char) before[i]-32;
        }
        else
        {
            after[i]= (char) before[i];
        }
        printf("%s\n", after);
    }
    printf("%s\n", after);
    return after;
}

*** ctype.h ***

you can do pretty mmuch a lot
like toupper
like islower

instead of:
for (int i=0;i<=strlen(thing);i++)
{
    ...
}

do:
for (int i=0; n=strlen(thing); i<=n;i++)
{
    ...
}


*** CL arguments ***

instead of:
int main(void)
{
    ...
}

you can get command-line arguments with:
int main(int argc, char *argv)

#####################
string = char *
#####################


*** exit status *** 
echo $?
// return exit status









*/









#include <stdio.h>
#include <string.h>



int main(int argc, char * argv[])
{
    printf("hello %s", argv[1]);
}
