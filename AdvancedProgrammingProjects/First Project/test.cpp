#include <iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    char ch = '#';
    int x = 5, y = 5;
    gotoxy(x, y);
    cout << ch;
    system("pause>0");

    while (x < 14 || y < 14)
    {
        Sleep(1000);

        gotoxy(x, y);
        cout << ' ';
        if (y < 14)
            gotoxy(x, ++y);
        else
            gotoxy(++x, y);
        cout << ch;
    }
    system("pause>0");
    return 0;
}