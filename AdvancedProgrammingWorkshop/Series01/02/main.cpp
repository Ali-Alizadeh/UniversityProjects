#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct point
{
    double x;
    double y;
};

int main()
{
    const int size = 2;
    point points[size];
    srand(time(NULL));
    for (int index = 0; index < size; index++)
    {
        points[index].x = rand() % 100;
        points[index].y = rand() % 100;
    }
    for (int index = 0; index < size; index++)
    {
        cout << "Point " << index + 1 << " Coordinates: (" << points[index].x << ", " << points[index].y << ")" << endl;
    }

    cout << endl << "Line Equation:" << endl;
    double m = (points[1].y - points[0].y) / (points[1].x - points[0].x);
    cout << "y = " << m << " * (" << "x - " << points[0].x << ") + " << points[0].y << "\n";
    cout<< "Or: " << endl;
    cout << "y = " << m << " * (" << "x - " << points[1].x << ") + " << points[1].y << "\n\n";

    int middlPointX = (points[0].x + points[1].x) / 2;
    int middlPointY = (points[0].y + points[1].y) / 2;
    cout<< "Coordinates of The Middle Point: ";
    cout << "(" << middlPointX << " , " << middlPointY << ")" << endl;

    return 0;
}