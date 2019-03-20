class Person {
    constructor(name, fName, age) {
        this.name = name
        this.fName = fName
        this.age = age
    }

    printInfo() {
        console.log(`${this.name} ${this.fName} ${this.age}`)
    }

    YearOfBirth() {
        console.log(1398 - this.age)
    }
}

let person1 = new Person("Ali", "Alizadeh", 18)
let person2 = new Person("Sepehr", "Sarjami", 19)

person1.printInfo()
person1.YearOfBirth()
// person1.YearOfBirth()
person2.printInfo()
person2.YearOfBirth()