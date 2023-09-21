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

adding techniques:

var+=2;
var++;  +1
var-=2;
var--;  -1

*** loops ***

int i = 10;
while (i>0)
{
    ...
    i--;
}

for (int i=0; i<10; i++)
{
    ...
}

to use boolians:
#include <stdbool.h>

while (true)
{
    ...
}


0 means false
1 or any other num is true
while (1)
{
    ...
}


*** const ***

basically saying something should be constant :)

const int number = 5

you cant change number


*** do while ***

not repeating yourself

do
{
    ...
}
while (true);

to comment in c:
// comment

*** function ***

int get_input(void)
{
    int number;
    do
    {
        scanf("%d",&number);
        printf("%d\n",number);
    }
    while (number<0);
    return number;
}

void print_*(int num)
{
    for (num;num>=0;num--){
        printf("*");
    }
    printf("\n");
}

*/
