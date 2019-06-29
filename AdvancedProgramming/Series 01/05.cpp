#include <iostream>
#include <string>
using namespace std;

void Input(string str[], int size)
{
    for (int index = 0; index < size; index++)
        cin >> str[index];
}

void Find(string str[], int size, int index, bool &found)
{
    if (str[index].find("HAFEZ") != string::npos || str[index].find("MOLANA") != string::npos)
    {
        cout << index + 1 << " ";
        found = true;
    }
}

int main()
{
    bool found = false;
    const int size = 5;
    string str[size];
    Input(str, size);
    for (int index = 0; index < size; index++)
        Find(str, size, index, found);
    if (found == false)
        cout << "‫‪NOT FOUND!";
    return 0;
}