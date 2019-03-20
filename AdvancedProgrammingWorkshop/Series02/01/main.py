class Customer():
    def __init__(self, name, family_name, credit, account_id):
        self.name = name
        self.family_name = family_name
        self.credit = credit
        self.account_id = account_id

    def show_info(self, index):
        print(self.name.capitalize(), self.family_name.capitalize(), 'Information:')
        print('    Credit:', self.credit)
        print('    Account ID:', self.account_id, '\n')

    def kharid(self, amount):
        self.credit -= amount

    def afzayesh_hesab(self, amount):
        self.credit += amount


customers = []
size = 4

for i in range(size):
    print('Customer', i + 1, "Information:")
    name = input('    Name: ')
    family_name = input('    Last Name: ')
    credit = int(input('    Credit: '))
    account_id = input('    Account ID: ')
    customers.append(Customer(name, family_name, credit, account_id))
    print()

print()

# customers[0].kharid(1000)
# customers[1].afzayesh_hesab(10000)

for i in range(size):
    customers[i].show_info(i)