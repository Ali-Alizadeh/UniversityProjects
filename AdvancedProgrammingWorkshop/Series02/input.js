const readline = require('readline')
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

let a;


let input = (prompt, callback) => {
    rl.question(prompt, (x) => {
        rl.close()
        callback(x)
    })
}

let value = (x) => x

let b = input("Hi!", value)
// console.log(b);


// .then(() => console.log(a))
// let a = answer
// console.log(a);
