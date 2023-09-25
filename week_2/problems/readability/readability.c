#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

int count_sentences(string text);
int count_words(string text);
int coleman_liau(string text);

int main(void) 
{
    string text = get_string("Text: "); 
    int score = (int) coleman_liau(text);

}


int coleman_liau(string text)
{
    int length =strlen(text);
    int words = count_words(text);
    int sentances = count_sentences(text);
    int letters = count_letters(text);
    float av_l= (float) letters / (float) words *100;
    float av_s= (float) sentances / (float) words * 100;
    float index = 0.0588 * av_l - 0.296 * av_s - 15.8;
    int rounded = (int) round(index);
    //printf("%i\n%i\n%i\n%i\n",words,sentances,letters,rounded);
    if (index < 1)
    {
        printf("Before Grade 1\n");

    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %d\n", rounded);

    }
    return rounded;
}

int count_letters(string word)      
{
    int num_letter = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            //printf("space");
            num_letter++;
        }
    }
    return num_letter;
}
int count_words(string text)
{
    int length =strlen(text);
    int n = 1;
    for (int i=0;i<length;i++)
    {
        if (isspace(text[i]))
        {
            n++;
        }
    }
    return n;
}



int count_sentences(string text)
{
    int length =strlen(text);
    int n = 0;
    for (int i=0;i<length;i++)
    {
        if (text[i]=='.' || text[i]=='!' || text[i]=='?')
        {
            n++;
        }
    }
    return n;
}