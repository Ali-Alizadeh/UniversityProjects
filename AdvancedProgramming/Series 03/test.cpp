#include <iostream>
#include <vector>
using namespace std;

long int increase_unit_of_martin(int num)
{
    if (num == 1)
        return 1;
    return num + increase_unit_of_martin(num - 1);
}

int main()
{
    int number_of_test, number_of_days;
    cin >> number_of_test;
    vector<int> food_prices;
    for (int i = 1; i <= number_of_test; i++)
    {
        cin >> number_of_days;
        food_prices.push_back(increase_unit_of_martin(number_of_days));
    }
    for (int k = 0; k < food_prices.size(); k++)
        cout << food_prices[k] << endl;
}