#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            preferences[i][j] = 0;
            locked[i][j] = false;
        }
    }
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    printf("Number of voters: ");
    int voter_count;
    scanf("%d", &voter_count);
    
    // = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name[128];
            printf("Rank %i: ", j + 1);
            scanf("%s",name);
            
            
            //= get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count ; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank]=i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int index = 0;
    for (int n1 = 0; n1 < candidate_count - 1; n1++)
    {
        for (int n2 = 0; n2 < candidate_count; n2++)
        {
            for (int n3 = 0; n3 < candidate_count; n3++)
            {
                for (int n4 = 0; n4 < candidate_count; n4++)
                {
                    if (ranks[n1] == n2 && ranks[n3] == n4 && n1 < n3)
                    {
                        index++;
                        preferences[n2][n4]++;
                    }
                }
            }
        }
    }
    return;
    /*
    int done[candidate_count][candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            done[i][j] = 0;
        }
    }

    for (int i = 0; i < candidate_count ; i++)
    {
        // ranks[i] is the index and i the preference
        int index = ranks[i];
        for (int j = 0; j < candidate_count; j++)
        {
            if (done[index][j]==0)
            {
                done[index][j] = 1;
                done[j][index] = 1;
                preferences[index][j] += 1;
                preferences[j][index] -= 1;
            }
        }
    }

    for (int i = 0; i < candidate_count ; i++)
    {
        // ranks[i] is the index and i the preference
        
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j]<0)
            {
                
                preferences[i][j] = 0;
            }
            printf("%d to%d by %d\n", i, j, preferences[i][j]);
        }
    }
    // TODO
    return;
    */
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int w = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count ++;
                w++;

            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int sorted_border = 0;
    do
    {
        int most_value = 0;
        int most_index = 0;
        pair most;
        most.winner = 0;
        most.loser = 0;
        for (int i = sorted_border; i < pair_count ; i++)
        {
            pair current = pairs[i];
            int current_value = preferences[current.winner][current.loser];

            if (current_value > most_value)
            {
                most_index = i;
                most = current;
                most_value = current_value;
            }
        }
        pairs[most_index] = pairs[sorted_border];
        pairs[sorted_border] = most;

        /* code */
        sorted_border ++;
    } while (sorted_border < pair_count);
    
    return;
}

bool check_circle(int start, pair current)
{
    if (current.loser == start)
    {
        return true;
    }

    for (int i = 0; i < candidate_count ; i++)
    {
        if (locked[current.loser][i] == 1)
        {
            pair new_current;
            new_current.winner = current.loser;
            new_current.loser = i;
            if (check_circle(start, new_current))
            {
                //printf("Circle %d: %d to %d\n",new_current.winner, new_current.loser, start);
                //printf("w: %d l:%d\n", current.winner, current.loser);
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
// pair pairs[pair_count] is sorted in descending order
// pair_count counts the number of pairs
// check_circle checks if adding this pair makes a circle

void lock_pairs()
{
    for (int i = 0; i < pair_count ; i++)
    {
        pair current = pairs[i];
        if (!check_circle(current.winner,current))
        {

            locked[current.winner][current.loser] = true;
            //printf("lock_pairs: %d to %d\n", current.winner, current.loser);
        }
    }
    
}

// Print the winner of the election
void print_winner(void)
{
    bool winner_candidates [candidate_count];
    for (int i = 0; i < candidate_count ; i++)
    {
        winner_candidates[i] = 1;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == 1)
            {
                winner_candidates[j] = 0;
            }
        }
    }
    int buggy_circle = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (winner_candidates[i] == 1)
        {
            buggy_circle = 0;
            printf("%s\n", candidates[i]);
        }
    }

    if (buggy_circle==1)
    {
        printf("%d\n",buggy_circle);
    }

    return;
}