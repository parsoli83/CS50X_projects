text = input("Text: ")
num_letters = 0
num_sent = 0
for letter in text:
    if letter.isalpha():
        num_letters +=1
    else:
        if letter == "." or letter =="!" or letter == "?":
            num_sent+=1

L = num_letters/len(text.split())*100
S = num_sent/len(text.split())*100
score = round(0.0588 * L - 0.296 * S - 15.8)
pre_text = ""
if score <1:
    print("Before Grade 1")
elif score > 16:
    print("Grade 16+")
else:
    print(f"Grade {score}")