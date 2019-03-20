class Customer {
    constructor(accountId, name, familyName, credit) {
        this.accountId = accountId
        this.name = name
        this.familyName = familyName
        this.credit = credit
    }

    showInfo() {
        console.log(this)
    }

    kharid(amount) {
        this.credit -= amount
    }

    afzayeshHesab(amount) {
        this.credit += amount
    }
}

let list = []

// list.push(new Customer(987, 'Ali', 'Alizadeh', 1000))
// list.push(new Customer(654, 'Sepehr', 'Sarjami', 1000000))
// list.push(new Customer(321, 'Mmd', 'Jafari', 550000))
// list.push(new Customer(148, 'Elnaz', 'Mehrabi', 987100))

// list[0].kharid(10)
// list[0].afzayeshHesab(1000)



const readline = require('readline')
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

let input = (prompt, callback) => {
    rl.question(prompt, (x) => {
        rl.close()
        callback(x)
    })
}

let value = (x) => x

let recive = async () => {
    for (let i = 0; i < 4; i++) {
        let name = input('Name: ', value);
        let familyName = input('Family Name: ', value);
        let accountId = input('Account ID: ', value);
        let credit = input('Credit: ', value);
        list.push(new Customer(name, familyName, accountId, credit))
    }
}

//recive().then(await() => list.map((item) => item.showInfo()))



