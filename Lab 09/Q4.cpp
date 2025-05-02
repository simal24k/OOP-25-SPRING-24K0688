#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod {
    string cardNumber;
public:
    CreditCard(string number) : cardNumber(number) {}

    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << " using card " << cardNumber << endl;
    }
};

class DigitalWallet : public PaymentMethod {
    double balance;
public:
    DigitalWallet(double bal) : balance(bal) {}

    void processPayment(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Digital wallet payment of $" << amount << " successful. Remaining balance: $" << balance << endl;
        } else {
            cout << "Digital wallet payment failed. Insufficient balance." << endl;
        }
    }
};

// SLEFNOTE: Tested Abstraction, inheritance, and dynamic polymorphism for extensible payment processing system.
