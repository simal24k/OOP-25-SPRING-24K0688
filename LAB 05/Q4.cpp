#include <iostream>
using namespace std;

class BankAccount {
    string accountNumber;        // to store account number
    string accountHolderName;    // name of account holder
    double balance;             // current balance in account
    
public:
    // constructor to set up account details
    BankAccount(string accNum = "0000", string holderName = "Unknown", double bal = 0) 
        : accountNumber(accNum), accountHolderName(holderName), balance(bal) {}

    // function to add money to account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " successfully!" << endl;
        } else {
            cout << "Deposit amount must be more than 0!" << endl;
        }
    }

    // function to take money out
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account." << endl;
        } else {
            cout << "Not enough balance or invalid amount!" << endl;
        }
    }

    // show account info
    void display() {
        cout << "Account No: " << accountNumber << endl;
        cout << "Holder Name: " << accountHolderName << endl;
        cout << "Current Balance: " << balance << " rupees" << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    // creating array of 3 bank accounts with some initial details
    BankAccount accounts[3] = {
        {"ACC12345", "Rani Kumar", 1500.0},
        {"ACC67890", "Lamia Najeeb", 3000.0},
        {"ACC11223", "Ayesha Raza", 500.50}
    };

    // loop through each account and do stuff
    for (int i = 0; i < 3; i++) {
        cout << "Initial Details for Account " << i + 1 << ":" << endl;
        accounts[i].display();

        // deposit 500 rupees
        accounts[i].deposit(500.0);
        cout << "After depositing 500:" << endl;
        accounts[i].display();

        // withdraw 200 rupees
        accounts[i].withdraw(200.0);
        cout << "After withdrawing 200:" << endl;
        accounts[i].display();

        cout << endl; // just for some spacing
    }

    return 0;
}
