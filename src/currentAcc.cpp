#include "currentAcc.h"
#include "savingAcc.h"
#include "account.h"
#include "Customer.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

currentAcc::currentAcc(Customer *c){
    this->balance = c->getCurrent_acc_balance();
    this->accountNo = c->getCurrent_account_no();
}
currentAcc::currentAcc(){}
currentAcc::currentAcc(double initialDeposit){
    this->balance = initialDeposit;
    this->create_acc_no = create_acc_no+1;
    this-> accountNo = create_acc_no;
}
double currentAcc::getBalance(){
    return balance;
}
long currentAcc::getAccountNo(){
    return accountNo;
}
/*string currentAcc::getAccountType(){
    return "Current";
}*/
void currentAcc::deposit(double amount){
    balance+=amount;
}
void currentAcc::transfere(account p , double amount){
    if(verifySufficientFunds(amount)){
        balance-= amount;
        p.recievedPayment(amount);
        string details = "FingerTips : Transfer -R";
        details.append(to_string(amount));
        details.append(" into saving account, available balance R");
        details.append(to_string(balance));
        transaction(details);
    }
}
void currentAcc::makePayment(account *acc , double amount){
    if(verifySufficientFunds(amount)){
        balance -= amount;
        acc->recievedPayment(amount);
        string details = "FingerTips : Payment -R";
        details.append(to_string(amount));
        details.append(" from current account, available balance R");
        details.append(to_string(balance));
        transaction(details);
    }
}
bool currentAcc::verifySufficientFunds(double amount){
    if((balance - amount) >= 0){
        return true;
    }
return 0;
}
void currentAcc::bank_statement(){
    fstream file;
    file.open("files.txt",ios::in);
    if(file.is_open()){
        string name;
        while(getline(file,name)){
            cout<<name<<endl;
        }
        file.close();
    }
}
void currentAcc::transaction(string details){
    fstream files;
    files.open("transactions.txt",ios::app);
        if(files.is_open()){
            files<<details<<endl;
        }
        files.close();
}
void currentAcc::recievedPayment(double amount){
    this->balance += amount;
    string details = "FingerTips : Recived Payment +R";
    details.append(to_string(amount));
    details.append(" from saving account, available balance R");
    details.append(to_string(balance));
    transaction(details);
}
void currentAcc::deductedPayment(double amount){
    balance -= amount;
    string details = "FingerTips : deducted Payment -R";
    details.append(to_string(amount));
    details.append(" from saving account, available balance R");
    details.append(to_string(balance));
    transaction(details);
}
long currentAcc:: create_acc_no = 500;


