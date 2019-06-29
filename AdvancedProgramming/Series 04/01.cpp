#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct TA
{
    float x;
    float y;
    string name;
    float distance;
};

struct myFriend
{
    float x;
    float y;
};

void InputTAInfo(vector<TA> &TAInfo)
{
    for (int index = 0; index < TAInfo.size(); index++)
    {
        cin >> TAInfo[index].x >> TAInfo[index].y;
        cin.ignore();
        getline(cin, TAInfo[index].name);
    }
}

void InputFriendInfo(myFriend &friendInfo)
{
    cin >> friendInfo.x >> friendInfo.y;
}

float CalcDistance(TA TAInfo, myFriend friendInfo)
{
    return sqrt(pow(friendInfo.x - TAInfo.x, 2) + pow(friendInfo.y - TAInfo.y, 2));
}

bool sortRule(TA a, TA b)
{
    if (a.distance != b.distance)
        return a.distance < b.distance;
    return a.name < b.name;
}

void PrintTANames(vector<TA> TAInfo)
{
    for (unsigned int index = 0; index < TAInfo.size(); index++)
        cout << TAInfo[index].name << endl;
}

int main()
{
    int countOfTAs;
    cin >> countOfTAs;
    vector<TA> TAInfo(countOfTAs);
    myFriend friendInfo;

    InputTAInfo(TAInfo);
    InputFriendInfo(friendInfo);

    for (unsigned int index = 0; index < TAInfo.size(); index++)
        TAInfo[index].distance = CalcDistance(TAInfo[index], friendInfo);

    sort(TAInfo.begin(), TAInfo.end(), sortRule);
    PrintTANames(TAInfo);

    return 0;
}