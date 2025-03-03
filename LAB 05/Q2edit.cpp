#include<iostream>
using namespace std;

class LoanHelper{
    const float irate; //variable that stores interest rate for the loan as a user defined constant value.
    float amount;
    int months;

    public:
    LoanHelper(float amount, int months, float rate):irate(rate),amount(amount),months(months){}
    LoanHelper() : irate(0.0), amount(0.0), months(0) {
        if(irate <= 0.0 || irate >= 0.005 ){
            cout << "Error - it. Interest rate should be a value between 0-0.5%" <<endl;
exit(1);        
        }
    }
    void PerMonth(){
        float pmonth = amount/months;
        float imonth = pmonth * irate;
        float tmonth = pmonth + imonth;

        cout << "You have to pay " << tmonth << " every month for " << months
        << " months to repay your loan." << endl;

    }

};
int main(){
    float Lamount;
    float m;
    float intrate;
    cout << "Enter the loan amount: ";
    cin >> Lamount;
    cout << "Enter the number of months for repayment: ";
    cin >> m;
    cout << "Enter the interest rate (between 0 and 0.5%): ";
    cin >> intrate;
    LoanHelper l1(Lamount,m,intrate/100);
    l1.PerMonth();
    return 0;
}
