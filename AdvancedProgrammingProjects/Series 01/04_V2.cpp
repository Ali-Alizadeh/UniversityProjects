#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int length, summation;
    cin >> length >> summation;
    char min[length], max[length];
    int currentSum = summation;

    for (int index = 0; index < length; index++)
    {
        int number = 9;
        while (number > currentSum)
            number--;

        max[index] = number;
        currentSum -= number;
    }

    currentSum = summation;
    for (int index = length - 1; index >= 0; index--)
    {
        int number;
        if (length > 1 && index == 0)
            number = 1;
        else
            number = 0;
        while (number < currentSum && number < 9)
            number++;

        min[index] = number;
        currentSum -= number;
    }

    int sum = 0;
    for (int index = 0; index < length; index++)
        sum += min[index];
    if (sum == summation)
        for (int index = 0; index < length; index++)
            cout << (int)min[index];
    else
        cout << -1;

    cout << " ";
    sum = 0;
    for (int index = 0; index < length; index++)
        sum += max[index];
    if (sum == summation)
        for (int index = 0; index < length; index++)
            cout << (int)max[index];
    else
        cout << -1;

    return 0;
}