class Person {
    constructor(name, fName,age) {
        this.name = name
        this.fName = fName
        this.age = age
    }
}

let person = new Person("Ali", "Alizadeh", 19)
let person2 = new Person("Sepehr", "Sarjami", 19)
console.log(person, person2)