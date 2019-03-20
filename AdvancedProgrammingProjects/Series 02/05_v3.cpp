/* AA was here */
#include <iostream>
#include <vector>
#include <algorithm>    // std::find

using namespace std;

int extractDigits(int number, vector<int> &digits)
{
    int sum = 0;
    while (number > 0)
    {
        digits.insert(digits.begin(), number % 10);
        number /= 10;
    }
}

int sum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main()
{
    int number, resultNumber, mainNumber;
    cin >> number;
    mainNumber = number;
    vector<int> digits;

    extractDigits(number, digits);

    int mainSum = sum(number);
    bool flag = false;
    while (!flag)
    {
        number++;
        if (sum(number) == mainSum)
        {
            number = mainNumber;
            while (number)
            {
                int rem = number % 10;
                if (any_of(digits.back(), digits.end(), rem) == digits.end())
                    flag = false;
                else
                    flag = true;
            }
        }
    }

    
    cout << number;
}