#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

void deleteZero(string &number, int length)
{
    while (number[0] == 48)
        for (int index = 0; index < length; index++)
            number[index] = number[index + 1];
}

int main()
{
    string number;
    int length, z1, max, z2, min;

    cin >> number;
    length = number.size();

    deleteZero(number, length);

    max = length - 1;
    bool found = false;
    for (z1 = length - 2; z1 >= 0; z1--)
        if (number[z1] > number[max])
            max = z1;
        else if (number[z1] < number[max])
        {
            found = true;
            break;
        }
    if (found)
    {
        min = max;
        for (z2 = z1 + 1; z2 < length; z2++)
            if (number[z1] < number[z2] && number[z2] < number[min])
                min = z2;
        z2 = number[min];
        number[min] = number[z1];
        number[z1] = z2;
        sort(&number[z1 + 1], &number[length]);
        cout << number;
    }
    else
        cout << 0;
    return 0;
}