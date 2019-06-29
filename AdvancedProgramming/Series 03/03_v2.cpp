#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Inverse(string word, int charIndex)
{
    if (charIndex == word.size())
        return "";
    string temp;
    temp.push_back(word[charIndex]);
    return Inverse(word, charIndex + 1) + temp;
}

int main()
{
    vector<string> words;
    string temp;
    while (getline(cin, temp))
        words.push_back(temp);
    for (int index = 0; index < words.size(); index++)
        cout << Inverse(words[index], 0) << endl;
    return 0;
}