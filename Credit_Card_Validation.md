# Credit Card Validation Program

## Introduction

This is a C++ program that checks if a credit card number is valid. It uses the **Luhn algorithm** to do this.

The program asks the user to enter a credit card number. It then checks the number of digits, checks the first digits of the card, and performs the Luhn calculation.

I split the program into different functions so that each function does one specific job.

## Main Function

The program starts from the `main()` function.

```cpp
int main() {
    long long cardNumber;

    cout << "Enter a credit card number as an integer: ";
    cin >> cardNumber;

    if (isValid(cardNumber))
        cout << cardNumber << " is valid" << endl;
    else
        cout << cardNumber << " is invalid" << endl;

    return 0;
}
```

First, I declared `cardNumber` as a `long long`. I used `long long` because a credit card number can have up to 16 digits, which can be too large for a normal `int`.

The user enters the card number using `cin`.

I then pass the number to:

```cpp
isValid(cardNumber)
```

This function returns either `true` or `false`.

If it returns `true`, the program says that the card is valid. Otherwise, it says that the card is invalid.

## `isValid()` Function

```cpp
bool isValid(long long number) {
    int size = getSize(number);

    if (size < 13 || size > 16)
        return false;

    if (!prefixMatched(number, 4) && !prefixMatched(number, 5) &&
        !prefixMatched(number, 37) && !prefixMatched(number, 6))
        return false;

    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);

    return total % 10 == 0;
}
```

This is the main function that decides if the card number is valid.

First, I find the number of digits by calling:

```cpp
getSize(number)
```

The program accepts numbers with 13 to 16 digits. If the number is outside this range, the function returns `false`.

The next part checks the prefix:

```cpp
if (!prefixMatched(number, 4) && !prefixMatched(number, 5) &&
    !prefixMatched(number, 37) && !prefixMatched(number, 6))
```

The `!` means **not**. So, if the number does not start with 4, 5, 37, or 6, it is treated as invalid.

If the number passes these checks, the program does the Luhn calculation.

```cpp
int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
```

These two functions calculate the two parts of the sum.

Finally:

```cpp
return total % 10 == 0;
```

checks if the total is divisible by 10. If the remainder is zero, `isValid()` returns `true`.

## `getSize()` Function

```cpp
int getSize(long long d) {
    int count = 0;

    while (d > 0) {
        d /= 10;
        count++;
    }

    return count;
}
```

This function finds the number of digits in the card number.

The `while` loop keeps running as long as the number is greater than zero.

Every time I use:

```cpp
d /= 10;
```

the last digit is removed.

For example, if the number is:

```text
12345
```

it becomes:

```text
1234
123
12
1
0
```

The loop runs five times, so `count` becomes 5.

## `prefixMatched()` Function

```cpp
bool prefixMatched(long long number, int d) {
    int size = getSize(static_cast<long long>(d));

    return getPrefix(number, size) == d;
}
```

This function checks if the card number starts with a certain prefix.

The variable `d` is the prefix I want to check.

For example, if I call:

```cpp
prefixMatched(number, 37)
```

the function first finds that `37` has two digits.

It then calls:

```cpp
getPrefix(number, 2)
```

to get the first two digits of the card number.

The two values are compared using `==`.

If they are the same, the function returns `true`. If they are different, it returns `false`.

## `getPrefix()` Function

```cpp
long long getPrefix(long long number, int k) {
    int size = getSize(number);

    if (size <= k)
        return number;

    for (int i = 0; i < size - k; i++)
        number /= 10;

    return number;
}
```

This function gets the first few digits of a number.

First, I find the total number of digits using `getSize()`.

If the number of digits is less than or equal to `k`, the function returns the number as it is.

Otherwise, the `for` loop removes digits from the end.

For example:

```text
number = 123456
k = 2
```

I need to remove four digits from the right:

```text
123456 → 12345 → 1234 → 123 → 12
```

The result is `12`, which is the prefix I wanted.

## `sumOfDoubleEvenPlace()` Function

```cpp
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        number /= 10;
        sum += getDigit(static_cast<int>(number % 10) * 2);
        number /= 10;
    }

    return sum;
}
```

This function handles the digits that are doubled in the Luhn algorithm.

First:

```cpp
number /= 10;
```

removes the last digit and moves to the next digit.

Then:

```cpp
number % 10
```

gets the digit I need.

I multiply that digit by 2:

```cpp
number % 10 * 2
```

and pass the result to `getDigit()`.

After that, I divide the number by 10 again to move to the next pair of digits.

This continues until all the required digits have been handled.

## `getDigit()` Function

```cpp
int getDigit(int number) {
    return number / 10 + number % 10;
}
```

This function is used when a doubled digit becomes a two-digit number.

For example, if the digit is 8:

```text
8 × 2 = 16
```

The digits of 16 are added:

```text
1 + 6 = 7
```

The function does this using:

```cpp
number / 10
```

to get the first digit, and:

```cpp
number % 10
```

to get the second digit.

So:

```cpp
getDigit(16)
```

gives:

```text
1 + 6 = 7
```

If the number is already a single digit, the division gives zero, so the original digit is still returned.

## `sumOfOddPlace()` Function

```cpp
int sumOfOddPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        sum += static_cast<int>(number % 10);
        number /= 100;
    }

    return sum;
}
```

This function adds the digits that are not doubled.

First:

```cpp
number % 10
```

gets the last digit and adds it to `sum`.

Then:

```cpp
number /= 100;
```

removes two digits.

This allows the function to skip the digit handled by `sumOfDoubleEvenPlace()` and move to the next required digit.

The loop continues until there are no more digits.

## How the Functions Work Together

The functions are connected through `isValid()`.

First, the program uses `getSize()` to check the length of the number. It then uses `prefixMatched()` and `getPrefix()` to check the beginning of the number.

After that, `sumOfDoubleEvenPlace()` and `sumOfOddPlace()` calculate the two parts of the Luhn sum. `getDigit()` is used by `sumOfDoubleEvenPlace()` when a doubled digit becomes a two-digit number.

The final total is checked using:

```cpp
total % 10 == 0
```

This gives the final `true` or `false` result.
