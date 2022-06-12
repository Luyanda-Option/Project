#include "savingAcc.h"
#include "currentAcc.h"
#include "account.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

savingAcc::savingAcc(Customer *c){
    //this-> customer = c;
    this->balance = c->getSaving_acc_balance();
    this-> accountNo = c->getSaving_account_no();
}
savingAcc::savingAcc(){}

savingAcc::savingAcc(double initialDeposit){
        this->balance = initialDeposit;
        this->create_acc_no = create_acc_no+1;
        this->accountNo = create_acc_no;

    }
double savingAcc::getBalance(){
    return balance;
}
long savingAcc::getAccountNo(){
    return accountNo;
}
string savingAcc::getAccountType(){
    return "Savings";
}
void savingAcc::deposit(double amount){
    balance+=amount;
}
void savingAcc::transfere(account sav ,double amount){
    if(verifySufficientFunds(amount)){
        balance-= amount;
        currentAcc p;
        sav.recievedPayment(amount);
        string details = "FingerTips : Transfer -R";
        details.append(to_string(amount));
        details.append(" from current account, available balance R");
        details.append(to_string(balance));
        transaction(details);
    }

}
void savingAcc::makePayment(account *acc, double amount){
    if(verifySufficientFunds(amount)){
        balance -= amount;
        currentAcc c;
        acc->recievedPayment(amount);
        string details = "FingerTips : Payment -R";
        details.append(to_string(amount));
        details.append(" from saving account, available balance R");
        details.append(to_string(balance));
        transaction(details);
        }
}
bool savingAcc::verifySufficientFunds(double amount){
    if((balance - amount) >= 0){
        return true;
    }
    return 0;
}
void savingAcc::bank_statement(){
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
void savingAcc::transaction(string details){
    fstream files;
    files.open("files.txt",ios::app);
        if(files.is_open()){
            files<<details<<endl;
        }
        files.close();
}
void savingAcc::recievedPayment(double amount){
    balance += amount;
    string details = "FingerTips : Received Payment +R";
    details.append(to_string(amount));
    details.append(" from saving account, available balance R");
    details.append(to_string(balance));
    transaction(details);
}
void savingAcc::deductedPayment(double amount){
    balance -= amount;
    string details = "FingerTips : deducted Payment -R";
    details.append(to_string(amount));
    details.append(" from saving account, available balance R");
    details.append(to_string(balance));
    transaction(details);
}
long savingAcc::create_acc_no = 400;
