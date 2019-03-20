#include <iostream>
#include <vector>
using namespace std;

class Person
{
  private:
  public:
    string accountId;
    string name;
    string familyName;
    unsigned long long int credit;

    Person();
    Person(string id, string firstName, string lastName, unsigned long long int accountCredit)
    {
        accountId = id;
        name = firstName;
        familyName = lastName;
        credit = accountCredit;
    }

    void kharid(unsigned long long int amount)
    {
        credit -= amount;
    }

    void afzayesh_hesab(unsigned long long int amount)
    {
        credit += amount;
    }
};

int main()
{
    string id, firstName, lastName;
    unsigned long long int accountCredit;
    cin >> id >> firstName >> lastName >> accountCredit;
    Person list(id, firstName, lastName, accountCredit);

    return 0;
}