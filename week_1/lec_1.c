/*

*** c ***

a lovely language

to compile c code:
$ make file_name    #keepin mind no .c

to run the code:
$./file_name

>>> getting input:

specifiers:

    %d: reads an integer value
    %f: reads a floating-point value
    %c: reads a single character
    %s: reads a string of characters
    %lf: reads a double-precision floating-point value

first declare variable:
int number;
or
char stringy[30];    just a example

for integer:
scanf("%d",number);

for string:
scanf("%s",stirngy);

>>> output:

for string:
printf("string is %s",stringy);

for int:
printf("int is %d",number);

# %% means literally %

printf("%%");
>>> %

*** Data types ***

bool
char
double
float
int
string

*** Conditionals ***

&& and
|| or
! not

eg:
if (!(num==1) && fnum==0){printf("yeah\n");}

>>> if
if (statement){
    ...
}

>>> else
if (statement){
    ...
}else{
    ...
}

eg:

if (x>y){
    ...
}
else if (x<y)
{
    ...
}
else
{
    ...
}

code example:

#include <stdio.h>

int main() {
    int num_1,num_2;
    scanf("%d %d",&num_1,&num_2);
    if (num_1>num_2){
        printf("num_1 is bigger than num_2\n");
    }else if (num_1<num_2){
        printf("num_2 is bigger than num_1\n");
    }else{
        printf("num_1 is equal to num_2\n");
    }
    return 0;
}

>>> stupid thingy with c

to represent string:
"string"

to represent char:
'c'











*/

#include <stdio.h>

int main() {
    int num_1,num_2;
    scanf("%d %d",&num_1,&num_2);
    if (num_1>num_2){
        printf("num_1 is bigger than num_2\n");
    }else if (num_1<num_2){
        printf("num_2 is bigger than num_1\n");
    }else{
        printf("num_1 is equal to num_2\n");
    }
    return 0;
}