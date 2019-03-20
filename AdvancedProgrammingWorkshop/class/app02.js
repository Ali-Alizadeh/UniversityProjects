function People() {
    this.people = [];
}

function Person(name, fName, age) {
    this.name = name
    this.fName = fName
    this.age = age
}

People.prototype.addPerson = function(name, fName, age) {
    this.people.push(new Person(name, fName, age))
}

let peopleArr = new People();
peopleArr.addPerson("Ali", "Alizadeh", 19)
peopleArr.addPerson("Sepehr", "Sarjami", 19)

console.log(peopleArr)
