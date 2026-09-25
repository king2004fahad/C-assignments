Credit Card Validator

This is a small C++ program that checks if a credit card number is valid. It uses the Luhn algorithm, which is the same method banks use to catch typos in card numbers.

What it does

You type in a card number, and the program tells you if it's valid or not. It checks two things:

The number of digits is between 13 and 16 (most real cards fall in this range).
The number starts with a digit (or digits) that match a known card type:
4 for Visa
5 for MasterCard
37 for American Express
6 for Discover

If both of those pass, it runs the Luhn check to make sure the number itself isn't just made up.

How the Luhn check works

Starting from the rightmost digit and moving left:

Double every second digit (the 2nd, 4th, 6th... from the right).
If doubling a digit makes it two digits (like 8 x 2 = 16), add those two digits together (1 + 6 = 7).
Add up all the digits you didn't double.
Add that to the sum from step 2.
If the total is divisible by 10, the number passes.

This is basically why the algorithm works in real life — it's designed to catch simple mistakes like a mistyped or transposed digit, not to prove a card is real or active.

How the code is organized
isValid() – runs all the checks and gives the final yes/no answer.
getSize() – counts how many digits are in a number.
prefixMatched() / getPrefix() – used to check what the card number starts with (e.g. does it start with "37"?).
sumOfDoubleEvenPlace() – handles the doubling part of the Luhn check.
sumOfOddPlace() – adds up the digits that don't get doubled.
getDigit() – helper that collapses a two-digit number into a single digit by adding its digits.
How it works (short version)
getSize() counts digits by dividing by 10 until nothing's left.
getPrefix() grabs the first k digits by stripping digits off the end (dividing by 10 repeatedly) until only k digits remain — that's how prefixMatched() checks things like "does this start with 37?".
sumOfOddPlace() adds up every other digit starting from the rightmost one, using n % 10 to grab a digit and n /= 100 to skip two at a time.
sumOfDoubleEvenPlace() does the same skip-by-100 pattern, but shifts right by one digit first (number / 10) so it lands on the other set of digits, then doubles each one and folds it down to a single digit with getDigit() if it goes over 9 (e.g. 8 → 16 → 1+6 → 7).
isValid() adds both sums together — if the total divides evenly by 10, the card number passes the Luhn check.
How to run it

Compile it with any C++ compiler, for example:

g++ credit_card.cpp -o credit_card
./credit_card

Then just type in a card number when it asks:

Enter a credit card number as a long integer: 4388576018402626
4388576018402626 is valid
Notes
Enter the number as one long string of digits, no spaces or dashes.
This is just a validity check based on math and prefix rules — it doesn't check if the card actually exists or is active.
Very long numbers might cause issues since it's stored as long long, so stick to real-world card lengths
