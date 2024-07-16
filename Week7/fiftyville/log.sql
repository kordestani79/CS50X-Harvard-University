-- Keep a log of any SQL queries you execute as you solve the mystery.

-- DATA:
-- - Date and time of theft: 2020-07-28 10:15
-- - Exited from courthouse parking lot within 10 minutes of the crime.
-- - Withdrew money from ATM on Fifer street that day.
-- - Made a phone call as they were leaving the court house, duration
--   was less than 1 minute.
-- - Said they were taking first flight out of Fiftyville on 2020-07-29.
-- - Thief asked person on other end of call to purchase the ticket.

-- OUTPUT:
-- 295|Theft of the CS50 duck took place at 10:15am at the Chamberlin Street
-- courthouse. Interviews were conducted today with three witnesses who were present
-- at the time — each of their interview transcripts mentions the courthouse.

-- Checking crime scene reports for the date and location of the crime
SELECT id, description FROM crime_scene_reports
WHERE year = 2020
AND month = 7
AND day = 28
AND street = "Chamberlin Street";

-- OUTPUT:
-- 161|Ruth|Sometime within ten minutes of the theft, I saw the thief get into a car
-- in the courthouse parking lot and drive away. If you have security footage from the
-- courthouse parking lot, you might want to look for cars that left the parking lot
-- in that time frame.
--
-- 162|Eugene|I don't know the thief's name, but it was someone I recognized. Earlier
-- this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer
-- Street and saw the thief there withdrawing some money.
--
-- 163|Raymond|As the thief was leaving the courthouse, they called someone who talked
-- to them for less than a minute. In the call, I heard the thief say that they were
-- planning to take the earliest flight out of Fiftyville tomorrow. The thief then
-- asked the person on the other end of the phone to purchase the flight ticket.

-- Finding interviews that mention the courthouse
SELECT id, name, transcript FROM interviews
WHERE year = 2020
AND month = 7
AND day = 28
AND transcript LIKE("%courthouse%");

-- Investigate Ruth's statement by checking the security footage from the courthouse
-- parking lot.
SELECT license_plate FROM courthouse_security_logs
WHERE year = 2020
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = "exit";

-- Check ATM transactions on Fifer street the day of the crime.
SELECT id, account_number, amount FROM atm_transactions
WHERE year = 2020
AND month = 7
AND day = 28
AND atm_location = "Fifer Street"
AND transaction_type = "withdraw";

-- Find phone calls made for less than a minute on the day of the crime.
SELECT caller, receiver FROM phone_calls
WHERE year = 2020
AND month = 7
AND day = 28
AND duration < 60;

-- Combining information to identify the thief
SELECT DISTINCT(name) FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE phone_number IN (SELECT caller FROM phone_calls
                       WHERE year = 2020
                       AND month = 7
                       AND day = 28
                       AND duration < 60)
AND license_plate IN (SELECT license_plate FROM courthouse_security_logs
                      WHERE year = 2020
                      AND month = 7
                      AND day = 28
                      AND hour = 10
                      AND minute BETWEEN 15 AND 25
                      AND activity = "exit")
AND atm_transactions.account_number IN (SELECT account_number FROM atm_transactions
                                        WHERE year = 2020
                                        AND month = 7
                                        AND day = 28
                                        AND atm_location = "Fifer Street"
                                        AND transaction_type = "withdraw");

-- Get passengers on the first flight the following day from Fiftyville airport.
SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights
                    WHERE year = 2020
                    AND month = 7
                    AND day = 29
                    AND origin_airport_id IN (SELECT id FROM airports
                                              WHERE city = "Fiftyville")
                    ORDER BY hour, minute
                    LIMIT 1);

-- Combining all information to identify the thief
SELECT DISTINCT(name) FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE phone_number IN (SELECT caller FROM phone_calls
                       WHERE year = 2020
                       AND month = 7
                       AND day = 28
                       AND duration < 60)
AND license_plate IN (SELECT license_plate FROM courthouse_security_logs
                      WHERE year = 2020
                      AND month = 7
                      AND day = 28
                      AND hour = 10
                      AND minute BETWEEN 15 AND 25
                      AND activity = "exit")
AND atm_transactions.account_number IN (SELECT account_number FROM atm_transactions
                                        WHERE year = 2020
                                        AND month = 7
                                        AND day = 28
                                        AND atm_location = "Fifer Street"
                                        AND transaction_type = "withdraw")
AND passport_number IN (SELECT passport_number FROM passengers
                        WHERE flight_id IN (SELECT id FROM flights
                                            WHERE year = 2020
                                            AND month = 7
                                            AND day = 29
                                            AND origin_airport_id IN (SELECT id FROM airports
                                                                      WHERE city = "Fiftyville")
                                            ORDER BY hour, minute
                                            LIMIT 1));

-- Identify the destination city the thief escaped to
SELECT city FROM airports WHERE id IN (SELECT destination_airport_id FROM flights
                                       WHERE year = 2020
                                       AND month = 7
                                       AND day = 29
                                       AND origin_airport_id IN (SELECT id FROM airports
                                                                 WHERE city = "Fiftyville")
                                       ORDER BY hour, minute
                                       LIMIT 1);

-- Identify the accomplice who helped the thief escape
SELECT name FROM people
WHERE phone_number IN (SELECT receiver FROM phone_calls
                       WHERE year = 2020
                       AND month = 7
                       AND day = 28
                       AND duration < 60
                       AND caller IN (SELECT phone_number FROM people
                                      WHERE name = "Ernest"));
