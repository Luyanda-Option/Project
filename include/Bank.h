#ifndef BANK_H
#define BANK_H
#include "account.h"
#include "currentAcc.h"
#include "savingAcc.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Bank
{
    public:
        Bank();
        void addAccount(account *sav,account *cur, Customer *c); //add new customer to our system
        void removeAccount(ifstream &infile,string filename, string name, string surname, string sav_acc , string cur_acc);// remove account

    private:
        string name = "FingerTips";
        string code = "3557";
};

#endif // BANK_H
