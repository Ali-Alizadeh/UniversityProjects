#include <iostream>
#include <string>
using namespace std;

struct stu
{
    string name;
    string ID;
    string fName;
    int failedTerms;
    double avg;
};

void print(stu[], int n);

int main()
{
    // count of the students
    const int n = 4;
    stu stuArr[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "  |  " << "name: ";
        if(i != 0) cin.ignore();
        getline(cin, stuArr[i].name);
        cout << "  |  " << "ID: ";
        cin >> stuArr[i].ID;
        cout << "  |  " << "father's name: ";
        cin.ignore();
        getline(cin, stuArr[i].fName);
        cout << "  |  " << "failed terms: ";
        cin >> stuArr[i].failedTerms;
        cout << "  |  " << "avg: ";
        cin >> stuArr[i].avg;
        cout << "  |________________________________" << endl << endl;
        // system("clear");
    }

    print(stuArr, n);
    return 0;
}

void print(stu stuArr[], int n)
{
    cout <<"\n\n\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "  |  " << "name: " << stuArr[i].name << endl;
        cout << "  |  " << "ID: " << stuArr[i].ID << endl;
        cout << "  |  " << "father's name: " << stuArr[i].fName << endl;
        cout << "  |  " << "failed terms: " << stuArr[i].failedTerms << endl;
        cout << "  |  " << "avg: " << stuArr[i].avg << endl;
        cout << "  |________________________________" << endl << endl;
    }
}