//
// Created by fukud on 2/5/2026.
//

#ifndef CLASSESCHALLENGE_BANKACCOUNT_H
#define CLASSESCHALLENGE_BANKACCOUNT_H
#include <iostream>
#include <string>

class BankAccount {
public:
    BankAccount(); //the default constructor. What it does is it incriments the IDNumber up by one, sets the name to "No Name Presented", sets the Account number to the current IDNumber, and then sets the balance to 0.
    BankAccount(std::string AccountName); //The paramized instructor. What it does is it incriments the IDNumber up by one, Sets the name to the presented name, sets the account number to the current IDNumber, and then sets the balance to 0.
    void SetAccountHolderName(std::string accountholder); //sets the current bank account's account holder name to the provided name.
    std::string const GetAccountHolderName(); //retrieves the current account's account holder name
    std::string const GetAccountNumber(); //retrieves the current account's id number
    double const GetBalance(); //retrieves the current account's balance
    void deposit(double& amount);//deposits money into the current account, adding the amount to the balance
    void withdraw(double& amount);//withdraws money from the current account, subtracting the amount from the balance, assuming the total won't be less than 0
private:
    std::string accountNumber; //the current accounts number, or id number
    double temptotal = 0; //the temporary total to make sure that it won't end up less than 0 before commiting any withdrawl
    int IDnumber; //temporary ID number which incriments with every new account
    std::string accountHolderName; //the name of the account holder
    double balance; //how much money is on the current account
};


#endif //CLASSESCHALLENGE_BANKACCOUNT_H