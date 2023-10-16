import csv

with open('2018m.csv', 'r') as file:
    reader = csv.DictReader(file)
    for i in reader:
        print(i)
        
