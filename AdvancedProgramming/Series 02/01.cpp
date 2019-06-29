#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int number;
    cin >> number;

    int m = 2;
    long long int a, b, c = 0;
    bool flag = false;
    while (c < 900000)
    {
        for (int n = 1; n < m; n++)
        {
            for (int k = 1; k < 1000; k++)
            {
                a = k * (pow(m, 2) - pow(n, 2));
                b = 2 * k * m * n;
                c = k * (pow(m, 2) + pow(n, 2));

                int sum = a + b + c;
                if (number == sum && c * c == a * a + b * b)
                {
                    if (a < b)
                        cout << a << " " << b << " " << c;
                    else
                        cout << b << " " << a << " " << c;
                    return 0;
                    //flag = true;
                }
            }
        }
        m++;
    }
    // if (flag == false)
    cout << "Impossible";
    return 0;
}
