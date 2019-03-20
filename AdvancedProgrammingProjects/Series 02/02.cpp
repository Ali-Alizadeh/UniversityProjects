#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<string> movies(size);
    cin.ignore();
    for (int index = 0; index < movies.size(); index++)
        getline(cin, movies[index]);

    for (int index = 0; index < movies.size(); index++)
        for (int currentCharIdx = 0; currentCharIdx < movies[index].size(); currentCharIdx++)
        {
            if (isupper(movies[index][currentCharIdx]))
            {
                if (movies[index][currentCharIdx - 1] != 32 && currentCharIdx != 0)
                    movies[index][currentCharIdx] += 32;
            }
            else if (islower(movies[index][currentCharIdx]))
                if (movies[index][currentCharIdx - 1] == 32 || currentCharIdx == 0)
                    movies[index][currentCharIdx] -= 32;
        }
    cout << endl;

    for (int i = 0; i < movies.size(); i++)
        cout << movies[i] << endl;

    return 0;
}
