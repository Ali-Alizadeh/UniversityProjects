#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number;
    cin >> number;

    for (int index = 0; index < number.size(); index++)
    {
        cout << number[index] << ": ";
        for (int j = 0; j < (int)number[index] - 48; j++)
            cout << number[index];
        cout << endl;
    }

    return 0;
}