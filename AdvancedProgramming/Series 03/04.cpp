#include <iostream>
using namespace std;

unsigned long long int func(int n, int sign)
{
    if (n == 0)
        return 2;
    return 2 * func(n - 1, -sign) + sign;
}

int main()
{
    int t;
    cin >> t;
    int n, sign = -1;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        sign = n % 2 == 1 ? -1 : 1;
        cout << func(n, sign) << endl;
    }
    return 0;
}