"""

*** SQL ***
structured querry language

a language for storing data

*** sorted ***

l = [0,1,2,3,4,5,6,7,8,9]
for item in sorted(l):
# this will work

# but you can give it a key for sorting

l = [0,1,2,3,4,5,6,7,8,9]
def distance_from_2(num):
    output = num-2
    if output<0:
        return output*-1
    return output

for i in sorted(l , key=distance_from_2):    # a key is given !!
    print(i)


*** relational database ***
using sqlite3

C   create    -> CREATE INSERT
R   read    -> SELECT
U   update    -> UPDATE
D   delete    -> DELETE DROP

parsoli@pop-os:~/CS50X_projects/week_7$ sqlite3 large.db
SQLite version 3.37.2 2022-01-06 13:25:41
Enter ".help" for usage hints.
sqlite> .mode csv   #mode is csv

sqlite> .import large.csv large     # import large.csv

sqlite> .schema     # the structure of large

CREATE TABLE IF NOT EXISTS "large"(
  "name" TEXT,
  "AGATC" TEXT,
  "TTTTTTCT" TEXT,
  "AATG" TEXT,
  "TCTAG" TEXT,
  "GATA" TEXT,
  "TATC" TEXT,
  "GAAA" TEXT,
  "TCTG" TEXT
);

sqlite> SELECT * FROM large;    #show everything

Albus,15,49,38,5,14,44,14,12
Cedric,31,21,41,28,30,9,36,44
Draco,9,13,8,26,15,25,41,39
Fred,37,40,10,6,5,10,28,8
Ginny,37,47,10,23,5,48,28,23
Hagrid,25,38,45,49,39,18,42,30
Harry,46,49,48,29,15,5,28,40
Hermione,43,31,18,25,26,47,31,36
James,46,41,38,29,15,5,48,22
Kingsley,7,11,18,33,39,31,23,14
Lavender,22,33,43,12,26,18,47,41
Lily,42,47,48,18,35,46,48,50
Lucius,9,13,33,26,45,11,36,39
Luna,18,23,35,13,11,19,14,24
Minerva,17,49,18,7,6,18,17,30
Neville,14,44,28,27,19,7,25,20
Petunia,29,29,40,31,45,20,40,35
Remus,6,18,5,42,39,28,44,22
Ron,37,47,13,25,17,6,13,35
Severus,29,27,32,41,6,27,8,34
Sirius,31,11,28,26,35,19,33,6
Vernon,26,45,34,50,44,30,32,28
Zacharias,29,50,18,23,38,24,22,9

sqlite> SELECT name FROM large;

Albus
Cedric
Draco
Fred
Ginny
Hagrid
Harry
Hermione
James
Kingsley
Lavender
Lily
Lucius
Luna
Minerva
Neville
Petunia
Remus
Ron
Severus
Sirius
Vernon
Zacharias

sqlite> SELECT COUNT(*) from large;     #number of rows of data (people in this case)
23

sqlite> SELECT DISTINCT("name") FROM large;
# shows only the distinct types without repetition

sqlite> SELECT COUNT(*) FROM Large WHERE AGATC > 25;
17
sqlite> SELECT COUNT(*) FROM Large;
23

sqlite> INSERT INTO large(TCTG) VALUES ('persian');
# insert new values
 



*** sqlite functions ***

AVG
COUNT
DISTINCT
LOWER
MAX
MIN
UPPER
...
WHERE
LIKE
ORDER BY
LIMIT
GROUP BY
...
JOIN 


*** python and sql ***
from cs50 import SQL
db = SQL("sqlite:///large.db")
limit = 35
rows = db.execute(f"SELECT COUNT(name) AS n FROM large WHERE AGATC > {limit}")
print(rows[0]["n"])


for this:
f"SELECT COUNT(name) AS n FROM large WHERE AGATC > {limit}"

you can do this too:
("SELECT COUNT(name) AS n FROM large WHERE AGATC > ?",limit)

>>> 11

"""
from cs50 import SQL
db = SQL("sqlite:///large.db")
limit = 35
rows = db.execute(f"SELECT COUNT(name) AS n FROM large WHERE AGATC > {limit}")
print(rows[0]["n"])