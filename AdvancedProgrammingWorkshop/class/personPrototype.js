function People(size) {
    this.people = new Array(size)
    this.size = size;
}

People.prototype.yearOfBirth = function () {
    return 1398 - this.age
}

People.prototype.addPerson = function (name, fName, age) {
    this.name = name
    this.fName = fName
    this.age = age
    this.yearOfBirth = 1398 - age
}

let peopleList = new People(30)

peopleList.addPerson("Ali", "Alizadeh", 18)
peopleList.addPerson("Sepehr Sarjami", 19)
peopleList.addPerson("Ahmad", "Varasteh", 24)
peopleList.addPerson("Gholi", "Rezaei", 60)

console.log(peopleList);
