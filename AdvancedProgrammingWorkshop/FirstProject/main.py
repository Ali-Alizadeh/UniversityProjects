import random
import os


class Person():
    def __init__(self, name, last_name, password, account_credit):
        self.name = name
        self.last_name = last_name
        self.password = password
        self.account_credit = account_credit
        self.account_id = self.generate_random_id()

    def __str__(self):
        return "{} {}\nAccount ID: {}\nAccount Credit: {}".format(self.name, self.last_name, self.account_id, self.account_credit)

    def generate_random_id(self):
        return random.randint(100000, 999999)

    def is_id_used(self, id, listArr):
        res = list(filter(lambda account: account['id'] == id, listArr))
        if res == []:
            return False
        return True


def clear():
    # for windows
    if os.name == 'nt':
        os.system('cls')
    # for mac and linux(here, os.name is 'posix')
    else:
        os.system('clear')


def new_account():
    name = input('First Name: ')
    last_name = input('Last Name: ')
    password = input('Password (4 Digits): ')
    account_credit = input('Account Credit: ')
    accounts_list.append(Person(name, last_name, password, account_credit))


def menu():
    while True:
        print('1. Create New Account')
        print('2. Delete an Account')
        print('3. Edit Account Info')
        print('4. Search Accounts')  # and show its info
        print('5. Save Accounts in a txt File')

        option = input('\nSelect an option: ')
        if option == '1':
            clear()
            new_account()
        elif option == '2':
            clear()
            print('two')
        elif option == '3':
            clear()
            print('three')
        elif option == '4':
            clear()
            print('four')
        elif option == '5':
            clear()
            print('five')
        elif option == '6':
            clear()
            print('six')
        else:
            clear()
            print('\nPlease enter a valid option from the below list.\n')


accounts_list = []


# person = Person("ali", "alizadeh", 1234, 100000000)
# print(person)


# list2 = [1, 2, 3, 4, 5, 6]
# print(list2)

# list2.pop(0)
# print(list2)

# list2.remove(2)
# print(list2)


# print(list2.index(5))

arr = [
    {
        'name': 'ali 1',
        'id': 1
    },
    {
        'name': 'ali 2',
        'id': 2
    },
]


def check(account, id):
    if account['id'] == id:
        return arr.index(account)


def look(id):
    res = []
    list(filter(lambda account: res.append(check(account, id)), arr))
    return res


print(look(3))
