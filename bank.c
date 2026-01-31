#include <stdio.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount(struct Account *a) {
    printf("Enter Account Number: ");
    scanf("%d", &a->accNo);
    printf("Enter Name: ");
    scanf("%s", a->name);
    printf("Enter Initial Balance: ");
    scanf("%f", &a->balance);
}

void deposit(struct Account *a) {
    float amt;
    printf("Enter deposit amount: ");
    scanf("%f", &amt);
    a->balance += amt;
}

void withdraw(struct Account *a) {
    float amt;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amt);
    if (amt > a->balance)
        printf("Insufficient balance\n");
    else
        a->balance -= amt;
}

void display(struct Account a) {
    printf("Account No: %d\nName: %s\nBalance: %.2f\n",
           a.accNo, a.name, a.balance);
}

int main() {
    struct Account acc;
    int choice;

    while (1) {
        printf("\n1.Create\n2.Deposit\n3.Withdraw\n4.Balance\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(&acc); break;
            case 2: deposit(&acc); break;
            case 3: withdraw(&acc); break;
            case 4: display(acc); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
