#include<iostream>
using namespace std;

class Account{
    protected:
 int accountnum;
 float balance;
 string accountHoldername;
 string accountType;

Account(int accNum, float bal, string name, string type){
    this->accountnum=accNum;
    this->balance=bal;
    this->accountHoldername=name;
    this->accountType=type;
}
virtual void deposit(int amount){
if(amount>0){
    balance+=amount;
    cout<<"Money deposited: "<< amount << endl;
    cout<<"Updated Balance:" << balance << endl;
}
else{
    cout<<"Invalid Entry"<<endl;
}
} 

virtual void withdraw(int amount){
 if(amount>0){
    balance-=amount;
    cout<<"Money withdrawn: "<< amount << endl;
    cout<<"Updated Balance:" << balance << endl;
}
else{
    cout<<"Invalid Entry"<<endl;
}
}
virtual void CalculateInterest(){}
virtual void printstatement(int amount){
    cout<<"----Bank Details----"<<endl;
    Account::deposit(amount);
    Account::withdraw(amount);
 }
 virtual void getAccountinfo(){
    cout<<"Account Number: "<<accountnum<<endl;
    cout<<"Account Balance: "<<balance<<endl;
    cout<<"Account Holder Name: "<<accountHoldername<<endl;
    cout<<"Account Type: "<<accountType<<endl;
 }

};

class SavingsAccount : public Account{
    float interestRate;
    float minimumbalance;

};
