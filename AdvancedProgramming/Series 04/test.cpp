#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Collegian
{
    unsigned long long ID;
    string Name;
    vector<float> Score;
    vector<float> Ratio;
    float Avg;
};
bool Clause(Collegian a, Collegian b);
float Calculate_Avg(vector<float> Score, vector<float> Ratio, int Number);
int main()
{
    vector<Collegian> List;
    int Number, Fail = 0, Best = 0;
    int ID;
    while (cin >> ID && ID != 0)
    {
        Collegian Temp;
        Temp.ID = ID;
        cin.ignore();
        getline(cin, Temp.Name);
        cin >> Number;
        for (int i = 0; i < Number; i++)
        {
            float a, b;
            cin >> a >> b;
            Temp.Score.push_back(a);
            Temp.Ratio.push_back(b);
        }
        Temp.Avg = Calculate_Avg(Temp.Score, Temp.Ratio, Number);
        if (Temp.Avg >= 17)
            Best++;
        else if (Temp.Avg < 12)
            Fail++;
        List.push_back(Temp);
    }
    sort(List.begin(), List.end(), Clause);
    cout << List[0].Name << " " << List[0].Avg << endl
         << Best << endl
         << Fail;
    return 0;
}
float Calculate_Avg(vector<float> Score, vector<float> Ratio, int Number)
{
    float Sum = 0, Sum_Ratio = 0;
    for (int i = 0; i < Number; i++)
    {
        Sum_Ratio += Ratio[i];
        Sum += Score[i] * Ratio[i];
    }
    return Sum / Sum_Ratio;
}
bool Clause(Collegian a, Collegian b)
{
    return (a.Avg > b.Avg);
}