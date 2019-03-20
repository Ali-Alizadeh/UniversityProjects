/* AA was here */
#include <iostream>
using namespace std;

int main()
{
    string number;
    cin >> number;
    string mainNumber = number;
    string firstDigit;

    // for (int i = number.size() - 1; i >= 0; i++)
    // {
    for (int j = number.size() - 2; j >= 0; j--)
    {
        if (number[number.size() - 1] > number[j])
        {
            swap(number[number.size() - 1], number[j]);
            if(number > mainNumber)
                break;
        }
    }
    // }
















    /*if (number < maniNumber)
        for (int index = 1; index < number.size(); index++)
        {
            if (number[0] < number[index])
            {
                swap(number[0], number[index]);
            }
        }*/

    /*strign firstDigit = number[0];
    for (int index = 1; index < number.size(); index++)
    {
        if (firstDigit > number[index] && number[0] < number[index])
        {
            swap(number[0], number[index]);
        }
    }*/
    // if (maniNumber < number)
    cout << number << endl;

    return 0;
}