#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int a, b, c;
    for (a = 1; a <= number; a++)
        for (b = a + 1; b <= number; b++)
        {
            c = number - a - b;
            if (c * c == a * a + b * b)
            {
                cout << a << " " << b << " " << c;
                return 0;
            }
        }

    if (c * c == a * a + b * b)
        cout << "Impossible";
    return 0;
}
