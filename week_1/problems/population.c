#include <stdio.h>

int main()
{
    int start_pop=get_start_pop();
    int end_pop=get_end_pop(start_pop);
    years(start_pop, end_pop);


}

int get_start_pop(void)
{
    int number;
    do
    {
        printf("Start size: ");
        scanf("%d", &number);
    }
    while (number<9);
    return number;
}

int get_end_pop(start_pop)
{
    int number;
    do
    {
        printf("End size: ");
        scanf("%d", &number);
    }
    while (number<start_pop);
    return number;
}


int years(int start,int e)
{
    int s = start;
    int y = 0;
    while (e>s)
    {
        s = s + s/3 - s/4;
        y++;
    }
    
    printf("Years: ");
    printf("%d\n",y);
}

