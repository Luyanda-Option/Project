#include "Customer.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Customer::Customer(){}
Customer::Customer(ifstream &infile, string username , string password){
    string line , word;
    bool isUsername = false, isPassword = false;
    istringstream iss, css;

    infile.open("account.txt");
    if(infile.is_open()){
    while(!infile.eof()){
        getline(infile, line);
        if(infile.good()){
            css.clear();
            css.str(line);
            while(css.good()){
                css>>word;
                if(word == username){
                    isUsername =true;
                }else if(word == password){
                    isPassword = true;
                }else{}
            }
            if(isUsername && isPassword){
                iss.clear();
                iss.str(line);
                iss>>word;
                string storeAccounts=word;
                string storeBalance;
                saving_account_no = atol(storeAccounts.c_str());
                iss>>storeBalance;
                this-> saving_acc_balance = stod(storeBalance);

                iss>>storeAccounts;
                this->current_account_no = atol(storeAccounts.c_str());

                iss>>storeBalance;
                this->current_acc_balance = stod(storeBalance);
                iss>>this->tittle;
                iss>>this->name;
                iss>>this->surname;
                iss>>this->username;
                iss>>this->password;
                iss>>this->id;
                iss>>this->address;
                iss>>this->gender;
                iss>>this->cellphone;
                break;
            }
        }

    }
     infile.close();
    }else{
        cout<<" File cannot be opened";
        exit(-1);
    }
}
Customer::Customer(string tittle,string name,string surname, string id, string cellphone,
                    string username,string password,string address, string gender)
{
    this-> tittle = tittle;
    this-> name = name;
    this-> surname = surname;
    this-> id = id;
    this-> cellphone = cellphone;
    this-> username = username;
    this-> password = password;
    this-> address = address;
    this-> gender = gender;
}

string Customer::getTittle(){return tittle;}
string Customer::getName(){return name;}
string Customer::getSurname(){return surname;}
string Customer::getUserName(){return username;}
string Customer::getId(){return id;}
string Customer::getPassword(){return password;}
string Customer::getCellphone(){return cellphone;}
string Customer::getGender(){return gender;}
string Customer::getAddress(){return address;}
long Customer:: getSaving_account_no(){return saving_account_no;}
long Customer:: getCurrent_account_no(){return  current_account_no;}
double Customer:: getSaving_acc_balance(){return saving_acc_balance;}
double Customer:: getCurrent_acc_balance(){return current_acc_balance;}

Customer Customer::updateDetails(){
    cout<<" Name       : ";
    cin>>this->name;

    cout<<" surname    : ";
    cin>>this->surname;

    cout<<" username  : ";
    cin>>this->username;

    cout<<" password  : ";
    cin>>this->password;

    cout<<" cellphone : ";
    cin>>this->cellphone;

    cout<<" address  : ";
    cin>>this->address;
    return Customer();
}
