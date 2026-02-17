//
// Created by fukud on 2/5/2026.
//

#include "BankAccount.h"
#include <iostream>
#include <string>
BankAccount::BankAccount() { //default constructor
    ++IDnumber; //i wanted unique ids, so I had the ID incriment with every new account
    accountNumber = std::to_string(IDnumber);//but it's an int, so I turned it into a string
    accountHolderName = "No Name Presented";//default account name
    balance = 0; //everyone starts with 0 dollars
}
BankAccount::BankAccount(std::string AccountName) { //if you wanted to start with a name, then it would 0
    ++IDnumber;
    accountNumber = std::to_string(IDnumber);
    accountHolderName = AccountName;
    balance = 0;
}
void BankAccount::SetAccountHolderName(std::string accountholder) {
    accountHolderName = accountholder; //sets the current account's account holder name to
}
std::string const BankAccount::GetAccountHolderName() {
    return accountHolderName; //returns the current account's account holder name
}
std::string const BankAccount::GetAccountNumber() {
    return accountNumber; //returns the current account's account number
}
double const BankAccount::GetBalance() {
    return balance; //returns the current account's balance
}
void BankAccount::deposit(double& amount) {
    balance = this->balance + amount; //adds the amount to the current account's balance
}// checks if subracting the amount provided will put the balance below 0 before either taking the amount out of the balance or saying 
void BankAccount::withdraw(double& amount) {
    temptotal = this->balance - amount;
    if (temptotal < 0.0) {
        std::cout << "Invalid amount to withdraw. You don't have that much" << std::endl;
    }else {
        balance = temptotal;
    }
}
