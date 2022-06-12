#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "currentAcc.h"
#include "savingAcc.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Customer
{
    public:
        Customer();
        Customer(ifstream &infile, string username, string password);// existing
        Customer(string tittle,string name,string surname, string id, string cellphone, string username,
                 string password,string address, string gender);// first user

        void update_login_details();
        string getName();
        string getUserName();
        string getPassword();
        string getSurname();
        string getId();
        string getGender();
        string getTittle();
        string getCellphone();
        string getAddress();
        long getSaving_account_no();
        long getCurrent_account_no();
        double getSaving_acc_balance();
        double getCurrent_acc_balance();
        Customer updateDetails();


    private:
        string name;
        string surname;
        string tittle;
        string id;
        string cellphone;
        string username;
        string password;
        string address;
        string gender;
        long saving_account_no;
        long current_account_no;
        double saving_acc_balance;
        double current_acc_balance;
        ifstream customer_login_details_input;
        ofstream customer_login_details_output;
};

#endif // CUSTOMER_H
