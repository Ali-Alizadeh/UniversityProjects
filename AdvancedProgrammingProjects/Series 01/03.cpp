#include <iostream>
using namespace std;

void IsPrime(int firstNumber, int secondNumber)
{
    while (firstNumber <= secondNumber)
    {
        bool flag = true;
        if (firstNumber == 1)
            firstNumber++;
        for (int i = 2; i < firstNumber; i++)
        {
            if (firstNumber % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << firstNumber << endl;
        firstNumber++;
    }
}

int main()
{
    int firstNumber, secondNumber;
    cin >> firstNumber >> secondNumber;
    IsPrime(firstNumber, secondNumber);
    return 0;
}
