# Calculator
# while True:
#     str = input("Enter: ")
#     if str.find('+') != -1:
#         pos = str.find('+')
#         print(int(str[:pos]) + int(str[pos+1:]))
#     elif str.find('-') != -1:
#         pos = str.find('-')
#         print(int(str[:pos]) - int(str[pos+1:]))
#     elif str.find('*') != -1:
#         pos = str.find('*')
#         print(int(str[:pos]) * int(str[pos+1:]))
#     elif str.find('/') != -1:
#         pos = str.find('/')
#         print(int(str[:pos]) / int(str[pos+1:]))

l = ['Ali', 'Mmd', 'Reza', 'Gholi', 'John']
# for item in range(len(l)):
#     print(item, l[item])

for index, name in enumerate(l):
    print(index, name)

name = input('name: ')
lName = input('Last name: ')

print(f'{name} {lName}')
