#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; 

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {} 
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {} 
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.013) {} 
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(100);

    cout << "Currency Details and Conversion to USD:" << endl;
    d.displayCurrency();
    cout << "Converted to Base: " << d.convertToBase() << " USD" << endl;

    e.displayCurrency();
    cout << "Converted to Base: " << e.convertToBase() << " USD" << endl;

    r.displayCurrency();
    cout << "Converted to Base: " << r.convertToBase() << " USD" << endl;

    return 0;
}
//selfnote:Tested: Polymorphism and class hierarchy with method overriding for currency conversion and display.
