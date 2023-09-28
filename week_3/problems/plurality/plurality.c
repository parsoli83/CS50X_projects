#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner();

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    for (int i = 0; i < argc -1 ; i++)
    {
        candidate test= candidates[i];
    }
    int voter_count;// = get_int("Number of voters: ");
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name[128]; //= get_string("Vote: ");
        printf("Vote: ");
        scanf("%s", name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    for (int i = 0; i < argc -1 ; i++)
    {
        candidate test= candidates[i];
    }
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO

    for (int i = 0; i < candidate_count ; i++)
    {
        candidate test= candidates[i];
        if (strcmp(test.name, name)==0)
        {

            test.votes +=1;
            candidates[i] = test;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner()
{
    // TODO

    int winners[candidate_count];
    for (int j = 0; j < candidate_count; j++)
    {
        winners[j] = 1;
    }
    int high = 0;
    for (int i = 0; i < candidate_count ; i++)
    {
        if (candidates[i].votes == high)
        {
            winners[i] = 0;
        }
        else if (candidates[i].votes > high)
        {
            //winners cleaner
            for (int j = 0; j < candidate_count; j++)
            {
                winners[j] = 1;
            }
            winners[i] = 0;
            high = candidates[i].votes;
            
        }
        else
        {
            winners[i] = 1;
        }
    }
    
    for (int i =0 ; i < candidate_count ;i++)
    {
        if (winners[i]==0)
        {
            printf("%s\n",candidates[i].name);
        }
    }
    return;
}
