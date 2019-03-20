class Customer {
    constructor(accountId, name, familyName, credit) {
        this.accountId = accountId
        this.name = name
        this.familyName = familyName
        this.credit = credit
    }

    showInfo() {
        document.getElementById('res').innerHTML += `
        <div>
            <span>Name: ${this.name}</span>
            <span>Family Name: ${this.familyName}</span>
            <div>Account ID: ${this.accountId}</div>
            <div>Credit: ${this.credit}</div>
        </div>`;
    }

    kharid(amount) {
        this.credit -= amount
    }

    afzayeshHesab(amount) {
        this.credit += amount
    }
}

let list = []

function addAccount() {
    let accountId = info.accountId.value
    let name = info.name.value
    let familyName = info.familyName.value
    let credit = info.credit.value
    list.push(new Customer(accountId, name, familyName, credit))
    list.map((item) => item.showInfo())
}

// list.map((item) => item.showInfo())


// list.push(new Customer(987, 'Ali', 'Alizadeh', 1000))
// list.push(new Customer(654, 'Sepehr', 'Sarjami', 1000000))
// list.push(new Customer(321, 'Mmd', 'Jafari', 550000))
// list.push(new Customer(148, 'Elnaz', 'Mehrabi', 987100))

// list[0].kharid(10)
// list[0].afzayeshHesab(1000)



// const readline = require('readline')
// const rl = readline.createInterface({
//     input: process.stdin,
//     output: process.stdout
// })


// let input = async() => {
//     let res
//     rl.question('Hello? ', (answer) => {
//         res = answer
//         rl.close()
//     })
//     return res
// }