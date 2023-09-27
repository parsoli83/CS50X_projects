/*

*** search algorithms ***

linear search:
searching linearly

binary search:
find the middle and navigate

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{

    int number;
    scanf("%d", &number);
    int list[31] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
    printf("search: %d\n",search(number,list,31));
}

int search (int number,int list[],int length)
{
    int start = 0;
    int end = length - 1;
    while (true)
    {
        printf("start: %d, end: %d\n", start, end);
        int mid = middle(start,end);
        int mid_value = list[mid];
        if (mid_value==number)
        {
            return mid;
        } 
        else if (mid_value<number)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }

        //exit
        if (end==start)
        {
            if (list[start]==number)
            {
                return start;
            }
            return -1;
        }

    };
    return -1;
    
}

int middle(int start,int end)
{
    int d=end-start;
    return start + (int)((float)d/2);
}

*** running time ***

Big O (worst case)
linear search --> O(n)
binary search --> O(log 2 n)

omega (best case)
linear search --> omega(1)
binary search --> omega(1)


*** typedef struct ***

to define a costume type

typedef struct
{
    string brand;
    string type;
    int age;
}
car;

//example

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    typedef struct
    {
        string brand;
        string type;
        int age;
    }
    car;
    car s500;
    s500.brand = "benz";
    s500.type = "sedan";
    s500.age = "12";

    printf("%i\n", strcmp(s500.brand,"benz"));
}


*** sorting algorithms ***

*** selection sort ***

//check from the first to last and find the smallest
// swap index[0] with the smallest
// repeat from index[1]
// then index[2]
// then ... till index[length]


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    int list[30] = {0,11,2,4,3,25,6,7,8,19,10,1,12,13,14,29,15,16,17,18,9,20,21,22,23,24,5,26,27,28};

    for (int i=0; i<30; i++)
    {
        int smallest = 100;
        int smallest_index = 0;
        for (int j=i; j<30; j++)
        {
            if (list[j] < smallest){
                smallest = list[j];
                smallest_index = j;
            }
        }
        list[smallest_index] = list[i];
        list[i] = smallest;
    }
    for (int i=0; i<30; i++)
    {
        printf("%d\n", list[i]);
    }
    
}


*** bubble sort ***

// again and again iterate over the list
// fix minor placemens until everything is in place


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    int list[30] = {0,11,2,4,3,25,6,7,8,19,10,1,12,13,14,29,15,16,17,18,9,20,21,22,23,24,5,26,27,28};
    int length = 30;
    int n=100;
    do
    {
        n=0;
        for (int i=0; i<length-1; i++)
        {
            if (list[i]>list[i+1])
            {
                n++;
                int ii = list[i];
                list[i] = list[i+1];
                list[i+1] = ii;
            }
        }
    } while (n!=0);
    for (int i=0; i<30; i++)
    {
        printf("%d\n", list[i]);
    }
    
}


*** recursion ***

//the lovely functional programming paradigm


int main()
{
    pyramid(100);

}

int pyramid(int h)
{
    if ( h > 0)
    {
        block(h);
        printf("\n");
        pyramid(h-1);
    }

}
int block(int w)
{
    if (w > 0)
    {
        printf("#");
        block(w-1);
    }
}


//or


int main()
{
    pyramid(10);
}

int pyramid(int h)
{
    if ( h != 0)
    {
        pyramid(h-1);

        for (int i=0;i<h;i++)
        {
            printf("#");
        }
        printf("\n");
    }
}


*** merge sort ***









*/










#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    pyramid(50);

}

int pyramid(int h)
{
    if ( h != 0)
    {
        pyramid(h-1);
        for (int i=0;i<h;i++)
        {
            printf("#");
        }
        printf("\n");
    }
}