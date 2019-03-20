#include <iostream>
using namespace std;

class Date
{
  public:
    Student();
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }

    void setYear(int y)
    {
        year = y;
    }

    void setMonth(int m)
    {
        month = m;
    }

    void setDay(int d)
    {
        day = d;
    }

    int getYear()
    {
        return year;
    }

    int getMonth()
    {
        return month;
    }

    int getDay()
    {
        return day;
    }

  private:
    int year;
    int month;
    int day;
};

int main()
{
    Date today(2019, 3, 13);
    cout << today.getYear() << " " << today.getMonth() << " " << today.getDay();

    return 0;
}