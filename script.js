let balance = 0;
let accountCreated = false;

function createAccount() {
    let name = document.getElementById("name").value;
    let amt = Number(document.getElementById("amount").value);

    if (!name || amt <= 0) {
        show("Enter valid details");
        return;
    }

    balance = amt;
    accountCreated = true;
    show(`Account created for ${name}. Balance: ₹${balance}`);
}

function deposit() {
    if (!accountCreated) return show("Create account first");
    let amt = Number(document.getElementById("amount").value);
    balance += amt;
    show(`Deposited ₹${amt}. Balance: ₹${balance}`);
}

function withdraw() {
    if (!accountCreated) return show("Create account first");
    let amt = Number(document.getElementById("amount").value);

    if (amt > balance) {
        show("Insufficient balance");
    } else {
        balance -= amt;
        show(`Withdrawn ₹${amt}. Balance: ₹${balance}`);
    }
}

function checkBalance() {
    if (!accountCreated) return show("Create account first");
    show(`Current Balance: ₹${balance}`);
}

function exitApp() {
    show("Thank you for using our banking system");
}

function show(msg) {
    document.getElementById("output").innerText = msg;
}
