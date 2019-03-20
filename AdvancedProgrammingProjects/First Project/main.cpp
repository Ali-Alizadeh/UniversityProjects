#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

vector<int> CalcRandomCell(int countOfMines)
{
    int row = rand() % countOfMines;
    int col = rand() % countOfMines;
    return {row, col};
}

bool IsCellEmpty(vector<vector<string>> gameTable, vector<int> cellCoordinates)
{
    if (gameTable[cellCoordinates[0]][cellCoordinates[1]] == "#")
        return true;
    return false;
}

void InsertMines(vector<vector<string>> &gameTable, int countOfMines)
{
    srand(time(NULL));
    int insertedMines = 0;
    while (insertedMines < 10)
    {
        vector<int> cellCoordinates = CalcRandomCell(countOfMines);
        bool isCellEmpty = IsCellEmpty(gameTable, cellCoordinates);
        if (isCellEmpty)
        {
            gameTable[cellCoordinates[0]][cellCoordinates[1]] = "M";
            insertedMines++;
        }
    }
}

void InsertCountOfMines(vector<vector<string>> &gameTable)
{
    
}

void printTable(vector<vector<string>> gameTable)
{
    for (int row = 0; row < gameTable.size(); row++)
    {
        for (int col = 0; col < gameTable[row].size(); col++)
            cout << gameTable[row][col] << " ";
        cout << endl;
    }
}

void GetGameReady()
{
    const int sizeOfTable = 10;
    const int countOfMines = 10;
    vector<vector<string>> gameTable(sizeOfTable, vector<string>(sizeOfTable, "#"));
    InsertMines(gameTable, countOfMines);
    InsertCountOfMines(gameTable);
    printTable(gameTable); // pritns the table itself, should be changed to print a hidden table
}

int main()
{
    GetGameReady();

    return 0;
}