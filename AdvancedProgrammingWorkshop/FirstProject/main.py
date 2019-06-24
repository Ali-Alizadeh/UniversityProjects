import random
import os

accounts_list = []


class Person():
    def __init__(self, name, last_name, password, account_credit):
        self.name = name
        self.last_name = last_name
        self.password = password
        self.account_credit = account_credit
        self.account_id = str(self.generate_random_id())

    def __str__(self):
        return "\n    {} {}\n    ID: {}\n    Credit: {}".format(self.name, self.last_name, self.account_id, self.account_credit)

    def generate_random_id(self):
        generated_id = random.randint(100000, 999999)
        if self.is_id_used(generated_id, accounts_list) == False:
            return generated_id
        else:
            return self.generate_random_id()

    def is_id_used(self, id, list):
        for account in list:
            if account.account_id == str(id):
                return True
        return False


def clear():
    # for windows
    if os.name == 'nt':
        os.system('cls')
    # for mac and linux(here, os.name is 'posix')
    else:
        os.system('clear')


def isPasswordValid(password):
    if len(password) == 4:
        try:
            for i in password:
                if int(i) < 0 and int(i) > 9:
                    return False
            return True
        except ValueError:
            return False
    return False


def new_account():
    clear()
    name = input('\n    First Name: ')
    last_name = input('    Last Name: ')
    while True:
        password = input('    Password (4 Digits): ')
        if isPasswordValid(password):
            break
        else:
            print(
                '\n    The entered password is not valid. It should be a four-digit number.\n')
    account_credit = input('    Account Credit: ')
    accounts_list.append(Person(name, last_name, password, account_credit))
    id = accounts_list[len(accounts_list) - 1].account_id
    print('\n    Account was created successfully with this id: {}'.format(id))


def confirm(confirm_text):
    while True:
        answer = input('{} (yes / no): '.format(confirm_text))
        if answer == 'yes':
            return True
        elif answer == 'no':
            return False
        else:
            print('\n    Please enter a valid answer!')


def editName(person_account):
    clear()
    name = input('\n    Enter your new name: ')
    last_name = input('    Enter your new last name: ')
    if confirm('\n    Are you sure of changing your name?'):
        person_account.name = name
        person_account.last_name = last_name
        clear()
        print('\n    Your name and last name were changed successfully!')
    else:
        clear()
        print('\n    Operation was canceled.')


def editPassword(person_account):
    clear()
    while True:
        old_pass = input('\n    Enter your old password: ')
        if old_pass == person_account.password:
            while True:
                password = input('\n    Enter your new password: ')
                if isPasswordValid(password):
                    break
                else:
                    print(
                        '\n    The entered password is not valid. It should be a four-digit number.')
            password_repeat = input('    Repeat ur new password: ')
            if password == password_repeat:
                if confirm('\n    Are you sure of changing your password?'):
                    person_account.password = password
                    clear()
                    print('\n    Your password was changed successfully!')
                    break
                else:
                    clear()
                    print('\n    Operation was canceled.')
                    break
            else:
                print('\n    Passwords didnt match! Pleasse try agin.')
        else:
            clear()
            print('\n    Incorrect password! Please try agin.')


def editAccountMenu(person_account):
    while True:
        print('\n    1. Edit Name')
        print('    2. Change Password\n')
        print('    3. Back')
        print('    4. Exit')

        option = input('\n    Select an option: ')
        if option == '1':
            editName(person_account)
        elif option == '2':
            editPassword(person_account)
        elif option == '3':
            clear()
            break
        elif option == '4':
            clear()
            quit()
        else:
            clear()
            print('\n    Please enter a valid option from the below list.')


def deleteAccount(person_aaccount):
    clear()
    if confirm('\n    Are you sure? \n    This will delete your account and all of it\'s information.\n    This action can not be reverted!.'):
        accounts_list.remove(person_aaccount)
        print('\n    Your account was deleted successfully.')
        clear()
        menu()
    else:
        print('\n    Operation was canceled.')


def logged_in_menu(person_account):
    while True:
        print('\n    1. Show Account Information')
        print('    2. Edit Account Info')
        print('    3. Delete Account\n')
        print('    4. Back')
        print('    5. Exit')

        option = input('\n    Select an option: ')
        if option == '1':
            clear()
            print(person_account)
        elif option == '2':
            clear()
            editAccountMenu(person_account)
        elif option == '3':
            deleteAccount(person_account)
        elif option == '4':
            clear()
            menu()
        elif option == '5':
            clear()
            quit()
        else:
            clear()
            print('\n    Please enter a valid option from the below list.')


def log_in():
    clear()
    id = input("\n    Please enter you account's ID: ")
    found = False
    for account in accounts_list:
        if id == account.account_id:
            found = True
            password = input("    Please enter your password: ")
            if password == account.password:
                logged_in_menu(account)
            else:
                print("\n    Wrong password!")
            break

    if found == False:
        print("\n    There's no account with such ID!")


def search():
    clear()
    id = input('\n    Enter the ID of the account your looking for: ')
    found = False
    for account in accounts_list:
        if id == account.account_id:
            print(account)
            found = True
            break
    if found == False:
        print('\n    There is no account with such ID!')


def menu():
    # clear()
    while True:
        print('\n    1. Create New Account')
        print('    2. Log In')
        print('    3. Search')
        print('    4. Exit')

        option = input('\n    Select an option: ')
        if option == '1':
            new_account()
        elif option == '2':
            log_in()
        elif option == '3':
            search()
        elif option == '4':
            clear()
            quit()
        elif option == 'l':
            clear()
            for account in accounts_list:
                print(account.account_id)
        else:
            clear()
            print('\n    Please enter a valid option from the below list.')


clear()


# for test popuses only

accounts_list.append(Person('Ali', 'Alizadeh', '0', 978465))
accounts_list.append(Person('Sep', 'Sarjami', '1', 789654))
accounts_list.append(Person('mmd', 'mmdi', '2', 10000))
accounts_list.append(Person('gholi', 'rajabi', '3', 132150))


menu()
