#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int number, fisrtBase, SecondBase;
    vector<int> resultNumber;

    cin >> number >> fisrtBase >> SecondBase;
    int mainNumber = number;

    int numberInBaseTen = 0, i = 0;
    while (number > 0)
    {
        numberInBaseTen += (number % 10) * pow(fisrtBase, i);
        number /= 10;
        i++;
    }
    number = mainNumber;
    while (numberInBaseTen > 0)
    {
        resultNumber.push_back(numberInBaseTen % SecondBase);
        numberInBaseTen /= SecondBase;
    }

    i = 0;
    int j = resultNumber.size() - 1;
    bool isPalyndorm = true;
    while (i <= j)
    {
        if (resultNumber[i] != resultNumber[j])
        {
            isPalyndorm = false;
            break;
        }
        i++;
        j--;
    }

    if (isPalyndorm)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
