#include <iostream>
#include <string>
using namespace std;

union myType {
  int number;
  string name;
};

int main()
{
  /* pointer */
  int a = 0;
  int *pa = &a;

  cout << *pa << endl;
  cout << pa << endl;
  cout << &pa << endl;

  /* union */
  myType one = 2;
  return 0;
}
