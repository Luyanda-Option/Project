#ifndef CURRENTACC_H
#define CURRENTACC_H
#include "savingAcc.h"
#include "account.h"
#include "Customer.h"

class currentAcc : public account{
private:
    //Customer *customer;
    string account_type;
    long accountNo;
    double balance;
    float interest_rate;
    static long create_acc_no;
public:
    currentAcc();
    currentAcc(Customer *c);
    currentAcc(double initialDeposit);
    double getBalance();
    long getAccountNo();
    //string getAccountType();
    void deposit(double amount);
    void transfere(account sav ,double amount);
    void makePayment(account *acc , double amount);
    bool verifySufficientFunds(double amount);
    void bank_statement();
    void transaction(string details);
    void recievedPayment(double amount);
    void deductedPayment(double amount);

};




#endif // CURRENTACC_H
