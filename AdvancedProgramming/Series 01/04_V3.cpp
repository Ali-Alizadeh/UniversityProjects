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

    if (length == 1)
    {
        cout << max;
    }
    else if (length == 2)
    {
        for (int index = 1; index >= 0; index--)
            cout << (int)max[index];
    }

    cout << endl;

    for (int index = 0; index < length; index++)
        cout << (int)max[index];

    return 0;
}