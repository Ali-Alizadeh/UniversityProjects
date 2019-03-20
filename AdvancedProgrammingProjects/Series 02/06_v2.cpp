#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // int size, temp;
    vector<vector<int>> rows{
        {5, 4, 3, 2, 1, 6, 7},
        {5, 5, 1, 1, 3, 4, 7},
        {3, 7, 1, 4, 5, 6, 2}};
    // cin >> size;
    // for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++)
    //     for (int index = 0; index < size; index++)
    //     {
    //         cin >> temp;
    //         rows[rowIndex].push_back(temp);
    //     }

    vector<int> repeatedNumIndex;
    vector<int> deletionCases;

    for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++)
        for (int i = 0; i < rows[rowIndex].size(); i++)
            for (int j = i + 1; j < rows[rowIndex].size(); j++)
                if (rows[rowIndex][i] == rows[rowIndex][j])
                {
                    repeatedNumIndex.push_back(i);
                    repeatedNumIndex.push_back(j);
                }

    for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++)
        for (int i = 0; i < rows[rowIndex].size(); i++)
            for (int j = i + 1; j < rows[rowIndex].size(); j++)
                if (rows[rowIndex][i] == rows[rowIndex][j])
                {
                    deletionCases.push_back(i);
                    deletionCases.push_back(j);
                }

    for (int i = 0, i < repeatedNumIndex.size(), i++)
        cout << repeatedNumIndex[i] << endl;
    cout << endl;

    for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++)
    {
        for (int index = 0; index < rows[rowIndex].size(); index++)
            cout << rows[rowIndex][index] << " ";
        cout << endl;
    }

    return 0;
}
