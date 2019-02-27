#include <iostream>
using namespace std;

bool IsPerfect(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
        if (number % i == 0)
            sum += i;
    if (sum == number)
        return 1;
    else
        return 0;
}

int main()
{
    int number, sum;
    cin >> number;

    if (IsPerfect(number))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
