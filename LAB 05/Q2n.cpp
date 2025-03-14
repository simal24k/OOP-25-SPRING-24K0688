#include <iostream>
using namespace std;

class LoanHelper {
    const float interestPercent;  
    float loanTotal;     
    double monthlyPayment; 
    int totalMonths;  

public:
    LoanHelper(const float rate = 0, float loanAmt = 0, int numMons = 0) 
        : interestPercent(rate), loanTotal(loanAmt), totalMonths(numMons) {}

    void calcLoan() {
        monthlyPayment = loanTotal / totalMonths;  
        monthlyPayment += monthlyPayment * (interestPercent / 100); 
    }

    double getAmountPerMonth() { return monthlyPayment; }

    int getNumMonths() { return totalMonths; }
};

int main() {
    cout << "Enter interest rate (between 0 and 0.5): ";
    float percentage;
    cin >> percentage;

    if (percentage >= 0 && percentage <= 0.5) {
        float principal;
        int duration;

        cout << "Enter the amount of loan: ";
        cin >> principal;

        cout << "Enter number of months to repay the loan: ";
        cin >> duration;

        if (principal > 0 && duration > 0) {
            LoanHelper loanHelper(percentage, principal, duration);
            loanHelper.calcLoan();

            cout << "You have to pay " << loanHelper.getAmountPerMonth() 
                 << " every month for " << loanHelper.getNumMonths() 
                 << " months to repay your loan." << endl;
        } else {
            cout << "Loan amount and months must be greater than zero!" << endl;
        }
    } else {
        cout << "Interest rate must be between 0 and 0.5!" << endl;
    }

    return 0;
}
