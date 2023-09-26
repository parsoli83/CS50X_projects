//#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int card = get_input();
    printf("%d\n",digit(card,16));

}



int evaluator(int card) 
{
    switch (length(card))
    {
        // fail 0
        case 15:
            return amex(card); //3
        case 16:
            //if (digit(card,16))
            mastercard(card);//4
        case 13:
            visa(card);//5
    }
    
}

long get_input(void)
{
    long card;
    scanf("%ld", &card);
    return card;

}

int digit(int num,int d)
{
    return num/10^(d-1)%10^(d+1);
}

int length(int num)
{
    int d=0;
    int n=1;
    while (n<num)
    {
        d++;
        n=n*10;
    }
    return d;

}