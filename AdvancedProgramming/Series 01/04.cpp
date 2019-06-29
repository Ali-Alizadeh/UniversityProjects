#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int length, summation;
    cin >> length >> summation;

    if (length == 1 && summation == 0)
    {
        cout << 0 << " " << 0;
        return 0;
    }

    long long int startOfPeriod = pow(10, length - 1), endOfPeriod = pow(10, length), min = endOfPeriod, max = startOfPeriod;
    for (long long int currentNumber = startOfPeriod; currentNumber < endOfPeriod; currentNumber++)
    {
        startOfPeriod = currentNumber;
        int sumOfDigits = 0;
        while (startOfPeriod > 0)
        {
            sumOfDigits += startOfPeriod % 10;
            startOfPeriod /= 10;
        }
        if (sumOfDigits == summation)
        {
            if (currentNumber < min)
                min = currentNumber;
            else if (currentNumber > max)
                max = currentNumber;
        }
    }
    if (min <= max)
        cout << min << " " << max;
    else if (min != endOfPeriod && max == pow(10, length - 1))
        cout << min << " " << min;
    else
        cout << -1 << " " << -1;

    return 0;
}
