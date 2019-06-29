#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int size, temp;
    vector<vector<int>> rows(3);
    cin >> size;
    for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++)
        for (int index = 0; index < size; index++)
        {
            cin >> temp;
            rows[rowIndex].push_back(temp);
        }

    for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++)
        for (int i = 0; i < rows[rowIndex].size(); i++)
            for (int j = i; j < rows[rowIndex].size(); j++)
                if (rows[rowIndex][i] > rows[rowIndex][j])
                    swap(rows[rowIndex][i], rows[rowIndex][j]);

    int first = 1, second = 2;
    for (int index = 0; index < rows[first].size(); index++)
    {
        if (rows[first][index] > rows[second][index])
        {
            rows[second].erase(rows[second].begin() + index);
            index--;
        }
        else if (rows[first][index] < rows[second][index])
        {
            rows[first].erase(rows[first].begin() + index);
            index--;
        }
    }

    while (rows[first].size() != rows[second].size())
    {
        if (rows[first].size() > rows[second].size())
            rows[first].erase(rows[first].begin() + rows[first].size() - 1);
        else if (rows[first].size() < rows[second].size())
            rows[second].erase(rows[second].begin() + rows[second].size() - 1);
    }

    first = 0;
    second = 1;
    for (int index = 0; index < rows[first].size(); index++)
    {
        if (rows[first][index] > rows[second][index])
        {
            rows[second].erase(rows[second].begin() + index);
            index--;
        }
        else if (rows[first][index] < rows[second][index])
        {
            rows[first].erase(rows[first].begin() + index);
            index--;
        }
    }

    //rows[0][0].erase(1);
    //rows[0].erase(rows[0].begin());

    for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++)
    {
        for (int index = 0; index < rows[rowIndex].size(); index++)
            cout << rows[rowIndex][index] << " ";
        cout << endl;
    }
    // for (int i = 0; i < 6; i++)
    //     cout << endl
    //          << rows[1][i];
    if (rows[0].size() == rows[1].size() && rows[1].size() == rows[2].size())
        cout << size - rows[0].size();
    return 0;
}
