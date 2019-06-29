#include <iostream>
using namespace std;

int main()
{
    int xMostafa, yMostafa, xManager, yManager;
    cin >> xMostafa >> yMostafa >> xManager >> yManager;
    if (xMostafa == xManager)
        cout << "Vertical";
    else if (yMostafa == yManager)
        cout << "Horizontal";
    else
        cout << "Try again";
    return 0;
}
