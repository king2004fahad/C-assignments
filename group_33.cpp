#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// --------------------------------------------------
// 1. BETWEEN
// Checks whether each value is between lower and upper
// --------------------------------------------------
vector<bool> between(const vector<double>& data,
                     double lower,
                     double upper)
{
    vector<bool> result;

    for (double value : data)
    {
        result.push_back(value >= lower && value <= upper);
    }

    return result;
}


// --------------------------------------------------
// 2. WITHIN
// Checks whether each value is within a tolerance
// of a given center value
// --------------------------------------------------
vector<bool> within(const vector<double>& data,
                    double center,
                    double tolerance)
{
    vector<bool> result;

    for (double value : data)
    {
        result.push_back(abs(value - center) <= tolerance);
    }

    return result;
}


// --------------------------------------------------
// 3. APPROXIMATELY_EQUAL
// Checks whether two numbers are approximately equal
// --------------------------------------------------
bool approximately_equal(double a,
                         double b,
                         double tolerance = 0.000001)
{
    return abs(a - b) <= tolerance;
}


// --------------------------------------------------
// 4. CLAMP
// Keeps a single value within a minimum and maximum
// --------------------------------------------------
double clamp(double value,
             double minimum,
             double maximum)
{
    if (value < minimum)
    {
        return minimum;
    }

    if (value > maximum)
    {
        return maximum;
    }

    return value;
}


// --------------------------------------------------
// 5. CLIP
// Applies the clamp operation to every value
// --------------------------------------------------
vector<double> clip(const vector<double>& data,
                    double minimum,
                    double maximum)
{
    vector<double> result;

    for (double value : data)
    {
        result.push_back(clamp(value, minimum, maximum));
    }

    return result;
}


// --------------------------------------------------
// MAIN PROGRAM
// --------------------------------------------------
int main()
{
    vector<double> data = {5, 10, 15, 20, 25};

    cout << "GROUP 33 - COMPARISONS" << endl;
    cout << "========================" << endl;


    // --------------------------------------------------
    // BETWEEN
    // --------------------------------------------------
    cout << "\n1. BETWEEN" << endl;

    vector<bool> betweenResult = between(data, 10, 20);

    cout << "Values between 10 and 20:" << endl;

    for (bool value : betweenResult)
    {
        cout << boolalpha << value << " ";
    }

    cout << endl;


    // --------------------------------------------------
    // WITHIN
    // --------------------------------------------------
    cout << "\n2. WITHIN" << endl;

    vector<bool> withinResult = within(data, 20, 5);

    cout << "Values within +/-5 of 20:" << endl;

    for (bool value : withinResult)
    {
        cout << boolalpha << value << " ";
    }

    cout << endl;


    // --------------------------------------------------
    // APPROXIMATELY EQUAL
    // --------------------------------------------------
    cout << "\n3. APPROXIMATELY EQUAL" << endl;

    double number1 = 10.0;
    double number2 = 10.0000001;

    cout << number1 << " and " << number2 << ": ";

    cout << boolalpha
         << approximately_equal(number1, number2)
         << endl;


    // --------------------------------------------------
    // CLAMP
    // --------------------------------------------------
    cout << "\n4. CLAMP" << endl;

    double value1 = 5;
    double value2 = 15;
    double value3 = 25;

    cout << "Clamp 5  between 10 and 20: "
         << clamp(value1, 10, 20) << endl;

    cout << "Clamp 15 between 10 and 20: "
         << clamp(value2, 10, 20) << endl;

    cout << "Clamp 25 between 10 and 20: "
         << clamp(value3, 10, 20) << endl;


    // --------------------------------------------------
    // CLIP
    // --------------------------------------------------
    cout << "\n5. CLIP" << endl;

    vector<double> clippedData = clip(data, 10, 20);

    cout << "Original values:" << endl;

    for (double value : data)
    {
        cout << value << " ";
    }

    cout << endl;

    cout << "Clipped values (10 to 20):" << endl;

    for (double value : clippedData)
    {
        cout << value << " ";
    }

    cout << endl;


    return 0;
}

/*Expected output

GROUP 33 - COMPARISONS
========================

1. BETWEEN
Values between 10 and 20:
false true true true false

2. WITHIN
Values within +/-5 of 20:
false false true true true

3. APPROXIMATELY EQUAL
10 and 10.0000001: true

4. CLAMP
Clamp 5  between 10 and 20: 10
Clamp 15 between 10 and 20: 15
Clamp 25 between 10 and 20: 20

5. CLIP
Original values:
5 10 15 20 25

Clipped values (10 to 20):
10 10 15 20 20*/