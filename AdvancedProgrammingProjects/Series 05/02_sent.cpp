int Date::Compare(Date date)
{
  if (year < date.year)
    return -1;
  else if (year > date.year)
    return 1;
  else if (year == date.year)
    if (month < date.month)
      return -1;
    else if (month > date.month)
      return 1;
    else if (month == date.month)
      if (day < date.day)
        return -1;
      else if (day > date.day)
        return 1;
      else if (day == date.day)
        return 0;
}

int days_between(Date d1, Date d2)
{
  int count = 1;
  if (d1.Compare(d2) == -1 || d1.Compare(d2) == 0)
    while (!d1.equals(d2))
    {
      d1.inc_one_day();
      count++;
    }
  else if (d1.Compare(d2) == 1)
    while (!d2.equals(d1))
    {
      d2.inc_one_day();
      count++;
    }

  return count;
}