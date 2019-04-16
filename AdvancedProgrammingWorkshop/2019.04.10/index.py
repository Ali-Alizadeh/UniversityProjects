class Student():
    def __init__(self, name, last_name, marks):
        self.name = name
        self.last_name = last_name
        self.marks = marks
        self.avg = self.calc_avg()

    def __str__(self):
        return "{} {} {} {}".format(self.name, self.last_name, self.marks, self.avg)

    def calc_avg(self):
        sum = 0
        # for i in range(len(self.marks)):
        #     sum += self.marks.pop()
        for item in self.marks:
            sum += item
        return sum / len(self.marks)


students_list = []

for i in range(1):
    name = input('Name: ')
    last_name = input('Last Name: ')
    marks = []
    for i in range(4):
        marks.append(float(input('Mark {}: '.format(i + 1))))
    students_list.append(Student(name, last_name, marks))

print(students_list[0])
