#include <iostream>
#include <vector>
using namespace std;

unsigned long long int TransformBase(long int number)
{
    if (number == 0)
        return 0;
    return (number % 2 + 10 * TransformBase(number / 2));
}

void Input(vector<long int> &numbers)
{
    for (int index = 0; index < numbers.size(); index++)
        cin >> numbers[index];
}

void Print(vector<unsigned long long int> resultNumbers)
{
    for (int index = 0; index < resultNumbers.size(); index++)
        cout << resultNumbers[index] << endl;
}

int main()
{
    int countOfNumbesrs;
    cin >> countOfNumbesrs;
    vector<long int> numbers(countOfNumbesrs);
    vector<unsigned long long int> resultNumbers(countOfNumbesrs);

    Input(numbers);
    for (int index = 0; index < numbers.size(); index++)
        resultNumbers[index] = TransformBase(numbers[index]);
    Print(resultNumbers);

    return 0;
}
