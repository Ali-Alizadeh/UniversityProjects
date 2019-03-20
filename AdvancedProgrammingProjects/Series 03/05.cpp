#include <iostream>
#include <vector>
using namespace std;

const int size = 10;

void Input(vector<vector<int>> &matrix)
{
    for (int row = 0; row < ::size; row++)
        for (int col = 0; col < ::size; col++)
            cin >> matrix[row][col];
}

int Solve(vector<vector<int>> matrix, int row, int col)
{
    if (row == ::size || col == ::size)
        return 0;
    int shiftRight = Solve(matrix, row, col + 1);
    int shiftBottom = Solve(matrix, row + 1, col);
    return matrix[row][col] + max(shiftRight, shiftBottom);
}

int main()
{
    vector<vector<int>> matrix(size, vector<int>(size));
    Input(matrix);
    cout << Solve(matrix, 0, 0);
    return 0;
}
