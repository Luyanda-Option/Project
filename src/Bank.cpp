#include "Bank.h"

using namespace std;
Bank::Bank()
{
    this-> name = "FingerTips";
    this-> code = "4001";
}

void Bank::addAccount(account *sav,account *cur, Customer *c)
{
    fstream file("account.txt",ios::app);
    if(file.is_open()){
        long accNo = sav->getAccountNo();
        string accN = to_string(accNo);
        file<<accN+" ";

        double balance = sav->getBalance();
        string bal = to_string(balance);
        file<<bal+" ";

        accNo = cur->getAccountNo();
        accN = to_string(accNo);
        file<<accN+" ";

        balance =cur->getBalance();
        bal=to_string(balance);
        file<<bal+" ";
        file<<c->getTittle()+" ";
        file<<c->getName()+" ";
        file<<c->getSurname()+" ";
        file<<c->getUserName()+" ";
        file<<c->getPassword()+" ";
        file<<c->getId()+" ";
        file<<c->getAddress()+" ";
        file<<c->getGender()+" ";
        file<<c->getCellphone()+" ";
        file<<endl;
    }
    file.close();
}

void Bank::removeAccount(ifstream &infile,string filename, string name, string surname, string sav_acc , string cur_acc){
    string line , word;
    istringstream iss;
    ofstream temp("temp.txt");
    bool isName = false, isSurname=false,isSav_acc = false, isCurr_acc=false;

    infile.open(filename);
    if(infile.is_open()){
    while(!infile.eof()){
        getline(infile, line);
        if(infile.good()){
            iss.clear();
            iss.str(line);

            while(iss.good()){
                iss>>word;
                if(word == name){
                    isName =true;
                }else if(word == surname){
                    isSurname =true;
                }else if(word == sav_acc){
                    isSav_acc =true;
                }else if(word == cur_acc){
                    isCurr_acc =true;
                }else{}
            }
            if(isName && isSurname && isCurr_acc && isSav_acc){}
            else{
                temp<<line<<endl;
                isName=false;
                isSav_acc= false;
                isCurr_acc=false;
                isSurname = false;
            }
        }
    }
    infile.close();
    temp.close();
    remove("account.txt");
    rename("temp.txt","account.txt");
    }else{exit(-1);}
}
