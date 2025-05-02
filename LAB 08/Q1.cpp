#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance) {}

    virtual double calculateInterest() { return 0.0; }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit of $" << amount << " successful. New balance: $" << balance << std::endl;
    }

    void deposit(double amount, std::string type) {
        balance += amount;
        std::cout << "Deposit of $" << amount << " via " << type << " successful. New balance: $" << balance << std::endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << std::endl;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    BankAccount operator+(const BankAccount& other) {
        BankAccount temp("Temp", balance + other.balance);
        return temp;
    }

    BankAccount operator-(double amount) {
        BankAccount temp("Temp", balance - amount);
        return temp;
    }

    BankAccount operator*(double interestRate) {
        BankAccount temp("Temp", balance * (1 + interestRate));
        return temp;
    }

    BankAccount operator/(int installments) {
        BankAccount temp("Temp", balance / installments);
        return temp;
    }

    void displayBalance() const {
        std::cout << "Account Number: " << accountNumber << ", Balance: $" << balance << std::endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(std::string accNumber, double initialBalance) : BankAccount(accNumber, initialBalance) {}

    double calculateInterest() override { return balance * 0.05; }

    void withdraw(double amount) override {
        if (balance - amount >= 500) {
            BankAccount::withdraw(amount);
        } else {
            std::cout << "Cannot withdraw. Minimum balance of $500 must be maintained." << std::endl;
        }
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(std::string accNumber, double initialBalance) : BankAccount(accNumber, initialBalance) {}

    void withdraw(double amount) override {
        if (balance - amount >= -1000) {
            BankAccount::withdraw(amount);
        } else {
            std::cout << "Cannot withdraw. Overdraft limit of $1000 exceeded." << std::endl;
        }
    }
};

int main() {
    SavingsAccount savingsAcc("SA123", 1000);
    CurrentAccount currentAcc("CA456", 2000);

    savingsAcc.deposit(500);
    savingsAcc.deposit(500, "online transfer");
    savingsAcc.withdraw(200);
    savingsAcc.withdraw(900);

    currentAcc.deposit(1000, "check");
    currentAcc.withdraw(3000);

    savingsAcc.displayBalance();
    currentAcc.displayBalance();

    BankAccount combined = savingsAcc + currentAcc;
    combined.displayBalance();

    savingsAcc = savingsAcc * 0.05;
    savingsAcc.displayBalance();

    currentAcc = currentAcc / 3;
    currentAcc.displayBalance();

    return 0;
}
//selfnote:Tested the humanize function for various durations in seconds, including seconds, minutes, hours, days, months, and years.
