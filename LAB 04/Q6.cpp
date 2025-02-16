#include<iostream>
using namespace std;

class FinancialInstitution {

    private:
    int accountID;
    string accountHolder;
    double funds;

    public:
    FinancialInstitution (): funds(0.0) {};
    FinancialInstitution(int accountID, string accountHolder, double funds) {
        this->accountID = accountID;
        this->accountHolder = accountHolder;
        this->funds = funds;
    }
    
    void addFunds(double amount) {
      funds += amount;
    }
    
    void withdrawFunds(double amount) {
        if(amount < 0 || amount > funds) {
            cout << "Sorry! Cannot withdraw amount" << endl;
        }
        else {
            funds -= amount;
            cout << "Transaction Successful! You have withdrawn $" << amount << ". Your remaining balance is $1,500." << funds << endl;
        }
    }
    
    void showAccountInfo() {
        cout << "Account Number: " << this->accountID << endl;
        cout << "Owner Name: " << this->accountHolder << endl;
        cout << "Available Balance: " << funds << endl;
        cout << "-----------------------" << endl << endl;
     }
};

int main() {
    FinancialInstitution client1(1020, "Hassan", 100000.0);
    FinancialInstitution client2(205, "Simal", 2000.0);

    client1.showAccountInfo();
    client2.showAccountInfo();

    client1.addFunds(15000);
    client2.withdrawFunds(1500);

    cout << "After Transactions: " << endl;
    client1.showAccountInfo();
    client2.showAccountInfo();

    return 0;
}
