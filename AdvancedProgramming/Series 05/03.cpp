#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Time
{
  public:
    Time(int H, int M);
    Time(int H);
    void SetTime(int H, int M);
    void PtintTime();
    int Compare(Time secondTime);
    string TimeOfDayString();

    int GetHour() { return hour; }
    int GetMin() { return min; }

  private:
    int hour;
    int min;
};

bool isHourValid(int hour)
{
    if (hour < 0 || hour > 23)
        return false;
    return true;
}

Time::Time(int H, int M)
{
    SetTime(H, M);
}

Time::Time(int H)
{
    if (!isHourValid(H))
        abort();

    hour = H;
    min = 0;
}

void Time::SetTime(int H, int M)
{
    if (!isHourValid(H) ||
        M < 0 ||
        M > 59)
    {
        abort();
    }
    hour = H;
    min = M;
}

int Time::Compare(Time secondTime)
{
    if (hour < secondTime.hour)
        return -1;
    else if (hour > secondTime.hour)
        return 1;
    else if (hour == secondTime.hour)
        if (min < secondTime.min)
            return -1;
        else if (min > secondTime.min)
            return 1;
        else if (min == secondTime.min)
            return 0;
}

string Time::TimeOfDayString()
{
    if (hour <= 11)
        return "Morning";
    else if (hour == 12 && min == 0)
        return "Noon";
    else if (hour >= 12 && hour <= 16)
        return "Afternoon";
    else if (hour >= 17 && hour <= 19)
        return "Evening";
    else if (hour >= 20)
        return "Night";
}

void Time::PtintTime()
{
    if (hour < 10)
        cout << 0 << hour;
    else
        cout << hour;

    cout << ":";

    if (min < 10)
        cout << 0 << min;
    else
        cout << min;
}

int main()
{
    Time time1(15, 11);
    Time time2(9);

    cout << "Time 1: ";
    time1.PtintTime();

    cout << "\nTime 2: ";
    time2.PtintTime();

    cout << "\n\nTime 1 is made by passing the hour and the minute to the constructor: ";
    time1.PtintTime();

    time1.SetTime(23, 54);
    cout << "\n\nEdited time 1 via the setter: ";
    time1.PtintTime();

    cout << "\n\nTime 2 is made by passing just the hour to the constructor: ";
    time2.PtintTime();

    cout << "\n\nPrinted hour snd minute via getter functions: ";
    cout << time1.GetHour() << ":" << time1.GetMin();

    cout << "\n\nCompare time 1 with time 2: " << time1.Compare(time2);

    cout << "\n\nThe string for time 1: " << time1.TimeOfDayString();
    cout << "\nThe string for time 2: " << time2.TimeOfDayString() << endl;

    return 0;
}
