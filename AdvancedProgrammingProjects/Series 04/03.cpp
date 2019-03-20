#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Input(vector<vector<string>> &matrix)
{
    string temp;
    for (int rowIndex = 0; rowIndex < matrix.size(); rowIndex++)
    {
        cin >> temp;
        for (int colIndex = 0; colIndex < matrix[rowIndex].size(); colIndex++)
            matrix[rowIndex][colIndex] = temp[colIndex];
    }
}

int CountStars(vector<vector<string>> matrix)
{
    int countOfStars = 0;
    for (int rowIndex = 0; rowIndex < matrix.size(); rowIndex++)
        for (int colIndex = 0; colIndex < matrix[rowIndex].size(); colIndex++)
            if (matrix[rowIndex][colIndex] == "*")
                countOfStars++;
    return countOfStars;
}

int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<string>> matrix(row, vector<string>(col));
    Input(matrix);
    cout << CountStars(matrix);
    return 0;
}