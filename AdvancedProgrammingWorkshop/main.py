class Date():
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    def __str__(self):
        return "{} {} {}".format(self.year, self.month, self.day)

today = Date(2019, 3, 13)
print(today)