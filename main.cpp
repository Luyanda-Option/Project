#include <iostream>
#include <string>
#include <fstream>

#include "currentAcc.h"
#include "savingAcc.h"
#include "account.h"
#include "Prepaid.h"
#include "Customer.h"
#include "Login.h"
#include "Bank.h"
#include "Virtual_card.h"
#include "Run.h"


using namespace std;

int main()
{

    Run obj;
    /*ifstream infile;
    Customer c(infile,"Sipho","Gwala");
    long int acc = c.getCurrent_account_no();
    long int sav = c.getSaving_account_no();
    Customer *reff = &c;
    savingAcc s(reff);
    currentAcc f(reff);
    account *acc1 = &s;
    account *acc2 = &f;
    reff->updateDetails();
    Bank b;
    b.removeAccount(infile,"account.txt","Sipho","Gwala",to_string(sav),to_string(acc));*/
    //b.addAccount(acc1,acc2,reff);

  /*  cout<<"Acount number : "<<acc1->getAccountNo()<<"  Balance :"<<acc1->getBalance()<<endl;
    cout<<"Acount number : "<<acc2->getAccountNo()<<"  Balance :"<<acc2->getBalance()<<endl;

    b.addAccount(acc1,acc2,reff);

    b.removeAccount(infile,"account.txt","Sipho","Gwala","401","501");*/
    return 0;
}
