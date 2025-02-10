#include<iostream>
#include <conio.h>
using namespace std;

class BankAccount {
    private:
        string accountNo;
        string accountHolder;
        double currentBalance;

    public:
        BankAccount() : currentBalance(0.0) {}

        BankAccount(string accountNo, string accountHolder, double initialBalance) {
            this->accountNo = accountNo;
            this->accountHolder = accountHolder;
            this->currentBalance = initialBalance;
        }

        void depositMoney(double depositAmount) {
            if(depositAmount > 0) {
                currentBalance += depositAmount;
                cout << "Money Deposited Successfully" << endl;
            } else {
                cout << "Deposit amount must be greater than zero" << endl;
            }
        }
1
        void withdrawMoney(double withdrawAmount) {
            if(withdrawAmount > 0 && currentBalance >= withdrawAmount) {
                currentBalance -= withdrawAmount;
                cout << "Withdrawn amount: " << withdrawAmount << endl;
            } else if (withdrawAmount > currentBalance) {
                cout << "Insufficient balance" << endl;
            } else {
                cout << "Invalid withdrawal amount" << endl;
            }
        }

        void displayBalance() {
            cout << "Current Balance: " << currentBalance << endl;
        }
};

int main() {
    BankAccount account1 = BankAccount("K24I23", "Laiba", 25000.0);

    char userChoice;
    double depositAmount, withdrawalAmount;

    while(true) {
        cout << "What would you like to do:\n1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Exit\n";
        userChoice = _getch();

        switch(userChoice) {
            case '1':
                cout << "Enter the amount to deposit: ";
                cin >> depositAmount;
                account1.depositMoney(depositAmount);
                break;
            case '2':
                cout << "Enter the amount to withdraw: ";
                cin >> withdrawalAmount;
                account1.withdrawMoney(withdrawalAmount);
                break;
            case '3':
                account1.displayBalance();
                break;
            case '4':
                cout << "Thank you for visiting!" << endl;
                return 0;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }

    return 0;
}
