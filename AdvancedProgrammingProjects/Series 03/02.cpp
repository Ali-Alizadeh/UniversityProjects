#include <iostream>
#include <vector>
using namespace std;

void Input(vector<int> &days)
{
    for (int index = 0; index < days.size(); index++)
        cin >> days[index];
}

int CalcMartini(int day)
{
    if (day == 1)
        return 1;
    return day + CalcMartini(day - 1);
}

void Print(vector<int> result)
{
    for (int index = 0; index < result.size(); index++)
        cout << result[index] << endl;
}

int main()
{
    int testCases;
    cin >> testCases;
    vector<int> days(testCases);
    vector<int> result(testCases);

    Input(days);
    for (int index = 0; index < days.size(); index++)
        result[index] = CalcMartini(days[index]);

    Print(result);

    return 0;
}