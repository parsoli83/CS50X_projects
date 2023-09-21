//#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{

    char car[32];
    scanf("%s", car);
    int length = strlen(car);
    long card= (long) car;
    check(car);
    /*
    switch (length)
    {
        // fail 0
        case 15:
            //return amex(card); //3
            amex(car);

        case 16:
            //if (digit(card,16))
            //mastercard(card);//4
            if (car[0]=='4'){
                visa(car);
            }
            else
            {
                master(car);
            }
        case 13:
            visa(car);
        default:
            printf("INVALID");

    }
    */
    

}

int check(car)
{
    int length = strlen(car);
    int s_1 = 0;
    for (int i=length-1;i>0;i--)
    {
        int f = i;
        if ((length-i)%2==0)
        {
            int ch = (int) car[f] * 2;
            if (ch>9)
            {
                s_1+=(int) ch/10 + (int) ch%10;
            }
            else
            {
                s_1+= ch;
            }
        }
    }
    printf ("%d",s_1);
}


int evaluator(int card) 
{
    switch (length(card))
    {
        // fail 0
        case 15:
            //return amex(card); //3
        case 16:
            //if (digit(card,16))
            //mastercard(card);//4
        case 13:
            //visa(card);//5
    }
    
}


int digit(long num,int d)
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