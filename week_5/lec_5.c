/*

*** data structures ***

--> abstract data types <---

--> queue

FIFO
first in, first out.

there are two operations:

enqueue = add to the end
dequeue = remove from the first

--> stack

LIFO
last in, last out

push = put on the end
pop = pop off the end

*** realloc ***

reallocates the chunk of memory to a new address with a new size

int list[3];
realloc(list , 4*sizeof(int));


*** arrays ***

you know them
.
*
->

--> struct:

you can make custom data types

.   

*


*** linked lists ***

//this is how you define a datatype that has a pointer to itself
//here its how you make linked list building blocks

typedef struct node
{
    int value;
    struct node * next;
}node;

// when you wanna go to an address and get something done

(*pointer_to_node).value = 1;

or 

pointer_to_node->value = 1;

//how i tried to do it :)
//#########################################

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *previous;
    int *next;
    int value;
}
block;

int main()
{
    int numbers[10] =
    {
        100,101,102,103,104,105,106,107,108,109
    };
    block zero;
    zero.previous = NULL;
    zero.next = NULL;
    zero.value = 0;
    for ( int i =1 ; i<5 ; i++)
    {
        
    }
    printf("%p", pointer_to_last(zero));
}

block * pointer_to_last(block zero)
{
    block * current = &zero;
    int * next = zero.next;
    do
    {
        current = next;
        block current_block = *current;
        next = current_block.next;
    } while (next != NULL);

    return current;
}
//#########################################


how it is actually done :)
//#########################################

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *before;
}
node;


int main()
{
    int hund[10]=
    {
        100,101,102,103,104,105,106,107,108,109
    };
    node *list = NULL;
    for (int i=0 ; i<10 ; i++)
    {
        node * n = malloc(sizeof(node));
        n -> value = hund[i];
        n -> before = list;
        list = n;
    }
    //printf("%d", get_node(list,3));
    node *target = list;
    while (target ->before != NULL)
    {
        printf("%i\n", target -> value);
        target = target -> before;

    }
}

*** binary search trees ***
1234567

        4
    2       6
1      3 5      7

you implement this with linked lists :)


*** hashing ***

taking an input and outputing a simpler demonstration

*** hash tables ***



*** tries ***

big array pointing to big array pointing to big array ...


*/
