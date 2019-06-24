#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>
using namespace std;

class Rational
{
public:
  Rational(int numerator, int denominator);
  Rational(int numerator);

  Rational operator+(const Rational &number) const;
  Rational operator-(const Rational &number) const;
  Rational operator*(const Rational &number) const;
  Rational operator/(const Rational &number) const;

  Rational operator+(const double &number) const;
  Rational operator-(const double &number) const;
  Rational operator*(const double &number) const;
  Rational operator/(const double &number) const;

  Rational &operator+=(const Rational &number);
  Rational &operator-=(const Rational &number);
  Rational &operator*=(const Rational &number);
  Rational &operator/=(const Rational &number);

  Rational &operator+=(const double &number);
  Rational &operator-=(const double &number);
  Rational &operator*=(const double &number);
  Rational &operator/=(const double &number);

  bool operator==(const Rational &number) const;
  friend ostream &operator<<(ostream &out, const Rational &number);

  void setNumerator(int numerator);
  void setDenominator(int denominator);

  int getNumerator() const { return numerator; }
  int getDenominator() const { return denominator; }

private:
  int numerator;
  int denominator;
};

void Rational::setNumerator(int numerator)
{
  this->numerator = numerator;
}

void Rational::setDenominator(int denominator)
{
  if (denominator != 0)
    this->denominator = denominator;
  else
    abort();
}

Rational::Rational(int numerator, int denominator)
{
  setNumerator(numerator);
  setDenominator(denominator);
}

Rational::Rational(int numerator)
{
  setNumerator(numerator);
  setDenominator(1);
}

Rational Rational::operator+(const Rational &number) const
{
  if (denominator == number.getDenominator())
    return Rational(numerator + number.getNumerator(), denominator);
  else
    return Rational(numerator * number.getDenominator() + number.getNumerator() * denominator, denominator * number.getDenominator());
}

Rational doubleToRational(double number)
{
  string numberStr = to_string(number);
  int pos = numberStr.find("0");
  numberStr = numberStr.substr(0, pos);
  pos = numberStr.find(".");
  int denominator = strlen(numberStr.c_str()) - numberStr.find(".") - 1;
  numberStr = numberStr.substr(0, pos) + numberStr.substr(pos + 1, strlen(numberStr.c_str()));
  denominator = pow(10, denominator);
  int numerator = stoi(numberStr);

  return Rational(numerator, denominator);
}

Rational Rational::operator+(const double &number) const
{
  Rational num = doubleToRational(number);
  if (denominator == num.getDenominator())
    return Rational(numerator + num.getNumerator(), denominator);
  else
    return Rational(numerator * num.getDenominator() + num.getNumerator() * denominator, denominator * num.getDenominator());
}

Rational Rational::operator-(const Rational &number) const
{
  if (denominator == number.getDenominator())
    return Rational(numerator - number.getNumerator(), denominator);
  else
    return Rational(numerator * number.getDenominator() - number.getNumerator() * denominator, denominator * number.getDenominator());
}

Rational Rational::operator-(const double &number) const
{
  Rational num = doubleToRational(number);

  if (denominator == num.getDenominator())
    return Rational(numerator - num.getNumerator(), denominator);
  else
    return Rational(numerator * num.getDenominator() - num.getNumerator() * denominator, denominator * num.getDenominator());
}

Rational Rational::operator*(const Rational &number) const
{
  return Rational(numerator * number.getNumerator(), denominator * number.getDenominator());
}

Rational Rational::operator*(const double &number) const
{
  Rational num = doubleToRational(number);
  return Rational(numerator * num.getNumerator(), denominator * num.getDenominator());
}

Rational Rational::operator/(const Rational &number) const
{
  return Rational(numerator * number.getDenominator(), denominator * number.getNumerator());
}

Rational Rational::operator/(const double &number) const
{
  Rational num = doubleToRational(number);
  return Rational(numerator * num.getDenominator(), denominator * num.getNumerator());
}

Rational &Rational::operator+=(const Rational &number)
{
  if (denominator == number.getDenominator())
  {
    numerator += number.getNumerator();
  }
  else
  {
    numerator = numerator * number.getDenominator() + number.getNumerator() * denominator;
    denominator = denominator * number.getDenominator();
  }

  return *this;
}

Rational &Rational::operator+=(const double &number)
{
  Rational num = doubleToRational(number);
  if (denominator == num.getDenominator())
  {
    numerator += num.getNumerator();
  }
  else
  {
    numerator = numerator * num.getDenominator() + num.getNumerator() * denominator;
    denominator = denominator * num.getDenominator();
  }

  return *this;
}

Rational &Rational::operator-=(const Rational &number)
{
  if (denominator == number.getDenominator())
  {
    numerator -= number.getNumerator();
  }
  else
  {
    numerator = numerator * number.getDenominator() - number.getNumerator() * denominator;
    denominator = denominator * number.getDenominator();
  }

  return *this;
}

Rational &Rational::operator-=(const double &number)
{
  Rational num = doubleToRational(number);
  if (denominator == num.getDenominator())
  {
    numerator -= num.getNumerator();
  }
  else
  {
    numerator = numerator * num.getDenominator() - num.getNumerator() * denominator;
    denominator = denominator * num.getDenominator();
  }

  return *this;
}

Rational &Rational::operator*=(const Rational &number)
{
  numerator *= number.getNumerator();
  denominator *= number.getDenominator();
  return *this;
}

Rational &Rational::operator*=(const double &number)
{
  Rational num = doubleToRational(number);
  numerator *= num.getNumerator();
  denominator *= num.getDenominator();
  return *this;
}

Rational &Rational::operator/=(const Rational &number)
{
  numerator *= number.getDenominator();
  denominator *= number.getNumerator();
  return *this;
}

Rational &Rational::operator/=(const double &number)
{
  Rational num = doubleToRational(number);
  numerator *= num.getDenominator();
  denominator *= num.getNumerator();
  return *this;
}

bool Rational::operator==(const Rational &number) const
{
  if (numerator == number.getNumerator() && denominator == number.getDenominator())
  {
    return true;
  }
  return false;
}

ostream &operator<<(ostream &out, const Rational &number)
{
  out << number.getNumerator() << " / " << number.getDenominator() << endl;
}

int main()
{
  //   Rational num(3, 5);
  //   Rational num2(3, 5);
  //   Rational num3(3, 5);

  //   cout << num + num2;
  //   num += num2;
  //   cout << num;
  // cout << num;
  // cout << num - num2;
  // cout << num * num2;
  // cout << num / num2;
  // cout << (num == num2);
  // cout << (1 == 1 == 3);

  Rational a(3, 5);
  double b = 2.1;
  Rational c = a / b;
  // cout << c;
  a /= b;
  cout << a;
  return 0;
}
