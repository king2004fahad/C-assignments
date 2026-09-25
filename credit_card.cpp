#include <iostream>
#include <vector>
using namespace std;

int getSize(long long number)
{
    int count = 0;
    while (number > 0)
    {
        count++;
        number = number / 10;
    }
    return count;
}

int getDigit(long long number)
{
    if (number < 10)
    {
        return number;
    }
    else
    {
        int remainder = number % 10;
        int dividend = number / 10;
        return remainder + dividend;
    }
}

int sumofOddPlace(long long number)
{
    int sum = 0;
    while (number > 0)
    {
        int remainder = number % 10;
        sum = sum + remainder;
        number = number / 100;
    }
    return sum;
}

int sum_Of_Even_Place(long long number)
{
    number = number / 10;
    int product;
    int sum = 0;
    while (number > 0)
    {
        int remainder = number % 10;
        product = remainder * 2;
        number = number / 100;
        sum = sum + getDigit(product);
    }
    return sum;
}

long long getPrefix(long long number, int k)
{

    while (getSize(number) > k)
    {
        number = number / 10;
    }
    return number;
}

bool match_prefix(long long number, int d) // checking if a number starts with d
{
    if (getPrefix(number, getSize(d)) == d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValid(long long number)
{
    int count = getSize(number);
    bool valid_prefix = match_prefix(number, 4) ||
                        match_prefix(number, 5) || match_prefix(number, 37) || match_prefix(number, 6);
    int sum = sum_Of_Even_Place(number) + sumofOddPlace(number);
    if ((count >= 13 && count <= 16) && valid_prefix && (sum % 10 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    long long number;
    cout << "Enter a credit card number: ";
    cin >> number;
    if (isValid(number))
    {
        cout << "Credit Card number is Valid";
    }
    else
    {
        cout << "Credit Card number is Invalid";
    }
    return 0;
}
