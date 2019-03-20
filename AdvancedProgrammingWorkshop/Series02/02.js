class Person {
    constructor(name, familyName, weight, height) {
        this.name = name
        this.familyName = familyName
        this.weight = weight
        this.height = height
        this.BMI = this.calBMI()
    }

    showInfo() {
        console.log(`${this.name} ${this.familyName}`)
        console.log(`weight: ${this.weight}`)
        console.log(`height: ${this.height}`)
        let BMIStr = this.BMI.toLocaleString();
        let BMITwoDecimals = BMIStr.slice(0, BMIStr.lastIndexOf('.') + 3)
        console.log(`BMI: ${BMITwoDecimals}\n`)
    }

    calBMI() {
        let res = this.weight / (this.height * this.height)
        return res
    }
}

let list = []

list.push(new Person('Ali', 'Alizadeh', 60, 1.73))
list.push(new Person('Sepehr', 'Sarjami', 70, 1.8))
list.push(new Person('Selena', 'Gomez', 90, 1.85))
list.push(new Person('Michealle', 'Fassbender', 80, 1.8))

list.map((item)=>item.showInfo())
