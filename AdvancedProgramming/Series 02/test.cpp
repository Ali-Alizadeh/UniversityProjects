#include <iostream>
using namespace std;
int DigitOfNumber(int number)
{
	int i;
	for (i = 0; number; i++)
		number = number / 10;
	return i;
}
int SumStatistics(int number)
{
	int i, sum = 0;
	for (i = 0; number; i++)
	{
		sum += number % 10;
		number = number / 10;
	}
	return sum;
}
int main()
{
	int number;
	cin >> number;
	int count = DigitOfNumber(number);
	int amount = SumStatistics(number);
	for (int point = number + 1; point < 1000000; point++)
	{
		int amountP = SumStatistics(point);
		if (amountP == amount)
		{
			cout << point;
			return 0;
		}
	}
	return 0;
}
