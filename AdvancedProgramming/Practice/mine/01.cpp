#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> a(5, vector<int>(5, 5));
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < a[i].size(); j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
