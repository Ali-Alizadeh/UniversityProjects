#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    string ID;
    string name;
    int lessons;
    vector<float> marks;
    vector<int> units;
    float average;
};

float CalcAvg(vector<float> marks, vector<int> units)
{
    float sum = 0;
    int sumOfUnits = 0;
    for (int index = 0; index < marks.size(); index++)
    {
        sum += marks[index] * units[index];
        sumOfUnits += units[index];
    }
    return sum / sumOfUnits;
}

void Input(vector<student> &students, string ID)
{
    student temp;
    temp.ID = ID;
    cin.ignore();
    getline(cin, temp.name);
    cin >> temp.lessons;
    float mark;
    int unit;
    for (int index = 0; index < temp.lessons; index++)
    {
        cin >> mark >> unit;
        temp.marks.push_back(mark);
        temp.units.push_back(unit);
    }
    temp.average = CalcAvg(temp.marks, temp.units);
    students.push_back(temp);
}

bool isFailed(float average)
{
    if (average < 12)
        return true;
    return false;
}

bool isAGrade(float average)
{
    if (average >= 17)
        return true;
    return false;
}

int PrintAGradeStudents(vector<student> students)
{
    int aGradeCounter = 0;
    for (int index = 0; index < students.size(); index++)
        if (isAGrade(students[index].average))
            aGradeCounter++;
    return aGradeCounter;
}

int PrintFailedSrudents(vector<student> students)
{
    int failedCounter = 0;
    for (int index = 0; index < students.size(); index++)
        if (isFailed(students[index].average))
            failedCounter++;
    return failedCounter;
}

bool sortRule(student a, student b)
{
    return a.average > b.average;
}

student PrintTopStudent(vector<student> &students)
{
    sort(students.begin(), students.end(), sortRule);
    return students[0];
}

void Print(vector<student> students)
{
    student topStudent = PrintTopStudent(students);
    cout << topStudent.name << " ";
    cout << fixed << setprecision(2) << topStudent.average << endl;
    cout << PrintAGradeStudents(students) << endl;
    cout << PrintFailedSrudents(students);
}

int main()
{
    vector<student> students;
    string ID;

    while (cin >> ID && ID != "0")
        Input(students, ID);
    Print(students);
}