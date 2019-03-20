#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;

    for (int a = 1; a <= number; a++)
        for (int b = 1; b <= number; b++)
        {
            int c = number - a - b;
            if (c * c == a * a + b * b)
            {
                if (a < b)
                    cout << a << ' ' << b << ' ' << c;
                else
                    cout << b << ' ' << a << ' ' << c;
                return 0;
            }
        }

    cout << "Impossible";

    return 0;
}