import csv
import sys


def main():

    if len(sys.argv)!= 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    


    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as db:
        dbase = csv.DictReader(db)
        patterns = dbase.fieldnames[1:]
        n_patterns = len(patterns)
        # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2], 'r') as seq:
            sequence = seq.read()
            n_seq = len(sequence)
            
            # TODO: Find longest match of each STR in DNA sequence
            occurances = []
            for i in range(n_patterns):
                occurances.append(0)
            
            for i in range(n_patterns):
                pattern = patterns[i]
                length = len(pattern)
                j = 0
                current_run = 0
                while j < n_seq:
                    found = False
                    try:
                        if sequence[j:j+length] == pattern:
                            j+=length
                            found = True
                            current_run +=1
                        else:
                            if current_run > occurances[i]:
                                occurances[i] = current_run
                                current_run = 0
                    except:
                        if current_run > occurances[i]:
                                occurances[i] = current_run
                                current_run = 0
                    if not found:
                        j+=1



            
                    


            # TODO: Check database for matching profiles
            found = False
            print(occurances)
            for case in dbase:
                suspect = True
                print(case)
                print()
                for i in range(n_patterns):
                    if case[patterns[i]] != str(occurances[i]):
                        suspect = False
                if suspect:
                    print(suspect["name"])
                    found = True
            if not found:
                print("not found")

            return


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
