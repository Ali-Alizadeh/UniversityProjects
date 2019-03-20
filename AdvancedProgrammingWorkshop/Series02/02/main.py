class Person():
    def __init__(self, name, family_name, weight, height):
        self.name = name
        self.family_name = family_name
        self.weight = weight
        self.height = height
        self.BMI = self.calc_bmi()

    def show_info(self):
        print(self.name.capitalize(), self.family_name.capitalize(), '\b:')
        print('    Weight:', self.weight)
        print('    Height:', self.height)
        dot = str(self.BMI).index('.')
        print('    BMI:', str(self.BMI)[:dot + 3], '\n')

    def calc_bmi(self):
        return self.weight / (self.height ** 2)


people = []
size = 4

for i in range(size):
    print('Person', i + 1, 'Information:')
    name = input('    Name: ')
    family_name = input('    Last Name: ')
    weight = int(input('    weight: '))
    height = float(input('    Height: '))
    people.append(Person(name, family_name, weight, height))
    print()

print()

for i in range(size):
    people[i].show_info()
