#include <iostream>
#include <vector>
using namespace std;

struct stu
{
    string name;
    string ID;
    double marks[4];
    double avg;
};

void input(stu[], int);
void menu(stu[], int);
void subMenu(stu[], int);
void printNamesIDs(stu[], int);
void printAGradeStudents(stu[], int);
void printFailedStudents(stu[], int);
void printMarks(stu[], int);
void topStudent(stu[], int);

int main()
{
    const int size = 8;
    stu stuArr[size];
    input(stuArr, size);
    menu(stuArr, size);
    return 0;
}

void input(stu stuArr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "  |  " << "name: ";
        if (i != 0)
            cin.ignore();
        getline(cin, stuArr[i].name);
        cout << "  |  " << "ID: ";
        cin >> stuArr[i].ID;
        double sum = 0;
        for (int j = 0; j < 4; j++)
        {
            cout << "  |  " << "Lesson " << j + 1 << " score: ";
            cin >> stuArr[i].marks[j];
            sum += stuArr[i].marks[j];
        }
        stuArr[i].avg = sum / 4;
        cout << "  |________________________________" << endl << endl;
        // system("clear");
    }
}

void menu(stu stuArr[], int size)
{
    cout << "\n1. List of Names and IDs" << endl;
    cout << "2. A Grade Students" << endl;
    cout << "3. Failed Stdents" << endl;
    cout << "4. Marks of the Students" << endl;
    cout << "5. Top student" << endl;
    cout << "6. Exit" << endl;
    char option;
    cout << "\nEnter a number from the above list: ";
    cin >> option;
    switch (option)
    {
    case '1':
        printNamesIDs(stuArr, size);
        break;
    case '2':
        printAGradeStudents(stuArr, size);
        break;
    case '3':
        printFailedStudents(stuArr, size);
        break;
    case '4':
        printMarks(stuArr, size);
        break;
    case '5':
        topStudent(stuArr, size);
        break;
    case '6':
        exit(0);
        break;

    default:
        cout << "\aPlease enter a valid option!\n\n";
        menu(stuArr, size);
        break;
    }
}

void subMenu(stu stuArr[], int size)
{
    cout << "\n1. Main Menu" << endl;
    cout << "2. Exit" << endl;
    char option;
    cout << "\nEnter a number from the above list: ";
    cin >> option;
    switch (option)
    {
    case '1':
        menu(stuArr, size);
        break;
    case '2':
        exit(0);
        break;

    default:
        cout << "\aPlease enter a valid option!\n\n";
        subMenu(stuArr, size);
        break;
    }
}

void printNamesIDs(stu stuArr[], int size)
{
    cout << "\nNames and IDs: \n";
    cout << "\tID\t|\tName\n";
    cout << "_________________________________\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << stuArr[i].ID << "\t|\t" << stuArr[i].name << endl;
    subMenu(stuArr, size);
}

void printAGradeStudents(stu stuArr[], int size)
{
    bool found = false;
    cout << "\nA Grade Students: \n";
    for (int i = 0; i < size; i++)
        if (stuArr[i].avg >= 17)
        {
            cout << stuArr[i].name << endl;
            found = true;
        }
    if (found == false)
        cout << "There's no A grade student.\n";
    subMenu(stuArr, size);
}

void printFailedStudents(stu stuArr[], int size)
{
    bool found = false;
    cout << "\nFailed Students: \n";
    for (int i = 0; i < size; i++)
        if (stuArr[i].avg < 10)
        {
            cout << stuArr[i].name << endl;
            found = true;
        }
    if (found == false)
        cout << "There's no failed student.\n";
    subMenu(stuArr, size);
}

void printMarks(stu stuArr[], int size)
{
    cout << "\nList of Marks:\n";
    cout << "\t\b\b\bLesson 1   |\t\b\b\bLesson 2   |\t\b\b\bLesson 3   |\t\b\b\bLesson 4   |\tName\n";
    cout << "__________________________________________________________________________________\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << "\t" << stuArr[i].marks[j] << "\t|";
        cout << "\t" << stuArr[i].name;
        cout << endl;
    }
    subMenu(stuArr, size);
}

void topStudent(stu stuArr[], int size)
{
    cout << "\nTop Student(s): \n";
    vector<string> top;
    double max = 0;
    for (int i = 0; i < size; i++)
        if (stuArr[i].avg > max)
            max = stuArr[i].avg;

    for (int i = 0; i < size; i++)
        if (stuArr[i].avg == max)
            top.push_back(stuArr[i].name);

    for (int i = 0; i < top.size(); i++)
        cout << top[i] << endl;
    subMenu(stuArr, size);
}
