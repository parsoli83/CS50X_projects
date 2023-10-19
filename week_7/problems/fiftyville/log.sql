-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM passengers;

-- interviews with the word bakery
SELECT * FROM interviews WHERE transcript LIKE '%bakery%';
--161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
--162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
--192|Kiana|2021|5|17|I saw Richard take a bite out of his pastry at the bakery before his pastry was stolen from him.

/*
SQLite version 3.37.2 2022-01-06 13:25:41
Enter ".help" for usage hints.
sqlite> SELECT * FROM crime_scene_reports WHERE description LIKE '%duck%';
295|2021|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
sqlite> SELECT * FROM interviews WHERE transcript LIKE '%bakery%';
161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
192|Kiana|2021|5|17|I saw Richard take a bite out of his pastry at the bakery before his pastry was stolen from him.
sqlite> SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE activity = 'exit' AND hour = 10 AND minute >= 5 AND minute<=25);
Vanessa
Karen
Barry
Christine
Alexander
Noah
Iman
Sofia
Luca
Diana
Kathleen
Kelsey
Bruce
Alice
sqlite> SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type='withdraw' AND day = 28));
Kenny
Iman
Benista
Taylor
Brooke
Luca
Diana
Bruce
sqlite> SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type='withdraw' AND day = 28)) INTERSECT SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE activity = 'exit' AND hour = 10 AND minute >= 5 AND minute<=25);
Bruce
Diana
Iman
Luca
sqlite> SELECT caller FROM phone_calls WHERE day = 28 AND duration<60 INTERSECT SELECT phone_number FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type='withdraw' AND day = 28)) INTERSECT SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE activity = 'exit' AND hour = 10 AND minute >= 5 AND minute<=25);
(367) 555-5533
(770) 555-1861
sqlite> SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE caller IN ('(367) 555-5533','(770) 555-1861') AND day = 28 AND duration<60);
Diana
Bruce
sqlite> SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE caller IN ('(367) 555-5533','(770) 555-1861') AND day = 28 AND duration<60);
Philip
Robin
sqlite> SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29;
18|8|6|2021|7|29|16|0
23|8|11|2021|7|29|12|15
36|8|4|2021|7|29|8|20
43|8|1|2021|7|29|9|30
53|8|9|2021|7|29|15|20
sqlite> SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
Kenny
Sofia
Taylor
Luca
Kelsey
Edward
Bruce
Doris
sqlite> SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE caller IN ('(367) 555-5533','(770) 555-1861') AND day = 28 AND duration<60) INTERSECT SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
Bruce

*/

-- people who left bakery at ten minute interval of rubbery
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE activity = 'exit' AND hour = 10 AND minute >= 5 AND minute<=25);

--atm at laggete street users
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type='withdraw' AND day = 28));

--people who did both
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type='withdraw' AND day = 28)) INTERSECT SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE activity = 'exit' AND hour = 10 AND minute >= 5 AND minute<=25);

-- phone numbers that are sus
SELECT caller FROM phone_calls WHERE day = 28 AND duration<60 INTERSECT SELECT phone_number FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type='withdraw' AND day = 28)) INTERSECT SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE activity = 'exit' AND hour = 10 AND minute >= 5 AND minute<=25);

--callers
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE caller IN ('(367) 555-5533','(770) 555-1861') AND day = 28 AND duration<60);

--receivers
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE caller IN ('(367) 555-5533','(770) 555-1861') AND day = 28 AND duration<60);

--first flight of the next day
SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29;

--passengers
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);

--the thief
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE caller IN ('(367) 555-5533','(770) 555-1861') AND day = 28 AND duration<60) INTERSECT SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);

-- and the assistant is Robin since bruce called him
-- destination airport is in nyc