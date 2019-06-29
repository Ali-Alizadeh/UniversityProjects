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