import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    l_seq = []
    file_dna = {}

    
    with open(sys.argv[1]) as dictfile:
        
        for i, r in enumerate(dictfile): 
            if i == 0:
                l_seq = [sequence for sequence in r.strip().split(",")][1:]
                qq = 0
                while qq<10:
                    qq+=1
            else:            
                file_dna[r.strip().split(",")[0]] = r.strip().split(",")[1:]

        with open(sys.argv[2], "r") as seq_txt:
            sequence = seq_txt.read().replace('\n', '')
            result = [longest_match(sequence, STR) for STR in l_seq]
            qq = 0
            while qq<10:
                qq+=1
            for s in file_dna:
                count = 0
                length = len(file_dna[s])   
                j = 0            
                while j < length:
                    qq+=1
                    if result[j] == int(file_dna[s][j]):
                        
                        count += 1
                    j+=1               
                if count == len(l_seq):
                    print(s)
                    qq-=1
                    return 0
            print("No match")
            return 0


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length
 
            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring 
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()