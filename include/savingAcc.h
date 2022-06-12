#ifndef SAVINGACC_H
#define SAVINGACC_H
#include "account.h"
#include "currentAcc.h"
#include <vector>
class Customer;

class savingAcc : public account
{
private:
    //vector<int> statement;
    string account_type;
    long accountNo;
    double balance;
    float interest_rate;
    static long create_acc_no;
public:
    savingAcc();
    savingAcc(Customer *c);
    savingAcc(double initialDeposit);
    string getAccountType();
    double getBalance();
    long getAccountNo();
    void deposit(double amount);
    void transfere(account cur ,double amount);
    void makePayment(account *acc, double amount);
    bool verifySufficientFunds(double amount);
    void bank_statement();
    void transaction(string details);
    void recievedPayment(double amount);
    void deductedPayment(double amount);
};

#endif // SAVINGACC_H
