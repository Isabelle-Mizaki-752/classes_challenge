/*
 *Author: Isabelle Aurora Mizaki
 *Date: 2/5/26
 *Purpose: Bank account and bank activities
 *Generative AI: No
 *Speciallized tools: besides the laptop, nothing else
*/
#include <iostream>
#include <string>
#include <vector>
#include "BankAccount.h"
int displayBankMenu(); //displays the bank menu
void runBankMenu(); //how the bank menu funcgtions
bool findaccount(const std::string accountID); //a function to find any bank account in the vector by using the ID
bool findaccountID(const std::string accountName); //a function to find any bank account in the vector by using the assigned name (assuming the account had a name)
BankAccount currAccount; //accesses the bank account class
std::vector<BankAccount> accounts; //list of bank accounts present
bool foundaccount = false; //important for finding accounts, as I planned for if multiple accounts are present at once
int main() {
    runBankMenu(); //initiallizes the bank
    return 0;
}
int displayBankMenu() { //the bank menu
    std::cout << "Kitten Banking Menu" << std::endl;
    std::cout << "What would you like to do today here at the Kitten Bank." << std::endl;
    std::cout << "1. Create a new bank account today." << std::endl;
    std::cout << "2. set a name for your bank account." << std::endl;
    std::cout << "3. deposit money into your bank account." << std::endl;
    std::cout << "4. withdraw money from your account." << std::endl;
    std::cout << "5. Get your bank account ID." << std::endl;
    std::cout << "6. Get your bank account holder name" << std::endl;
    std::cout << "7. Get your bank account balance" << std::endl;
    std::cout << "8. Quit." << std::endl;
    std::cout << "What would you like to do (Just a number): " << std::endl;
    int choice; //how you would decide what bank option you'll do
    std::cin >> choice; //Im banking on only integers being inputed
    std::cout << std::endl;
    return choice;
}
void runBankMenu() {
    std::string currAccountName = "";
    std::string response; //used to set up if a name will be set up with the account or not
    int choice;
    std::string accountId;
    double amount = 0.0;
    do {
        switch (choice = displayBankMenu()) {
            case 1: //make account
                std::cout << "Alright :3. Welcome to Kitten banking, could you state you're name?" << std::endl;
                std::cout << "(yes or no)" << std::endl;
                std::cin >> response;
                if (response == "yes" or response == "y" or response == "Yes" or response == "YES" or response == "Y") { //to keep my bases covered just in case
                    std::cout << "Alright, what name would you like the account under: ";
                    std::cin >> currAccountName; //inputing your name
                    std::cout << std::endl;
                    BankAccount newbankAccount(currAccountName); //creates the new bank account and initiallizes the name
                    accounts.push_back(newbankAccount); //adds the bank account in question to the list
                }else if (response == "no" or response == "n" or response == "No" or response == "NO" or response == "N") { //again, keeping my bases covered
                    std::cout << "Alright, let me get your account set up for you" << std::endl;
                    BankAccount newbankAccount; //initiallizes the bank account with
                    accounts.push_back(newbankAccount);//adds the bank account in question to the list
                }else {
                    std::cout << "What reply is that >^>.<^*< try again later" << std::endl; //just in case a bad response slips in here
                }
                break;
            case 2: //set name
                if (accounts.empty() == true) { //makes sure there are bank accounts in existence
                    std::cout << "There are no accounts here. Make an account first. >^>.<^*<" << std::endl;
                }else {
                    std::cout << "I see, well what is your account ID: " << std::endl;
                    std::cin >> accountId;
                    foundaccount = findaccount(accountId); //looks to see if the bank account in question even exists first
                    if (foundaccount == false) {
                        std::cout << "could not find account. Try again" << std::endl; //if it doesn't
                    }else {//if it does
                        for (unsigned int i = 0; i < accounts.size(); i++) { //to pull the bank account in question back up, as I found that not including this leads to difficulty
                            currAccount = accounts.at(i);
                            if (currAccount.GetAccountNumber() == accountId) {
                                std::cout << "Alright, found it :3. Now, what's your name: ";
                                std::cin >> currAccountName; //set name
                                currAccount.SetAccountHolderName(currAccountName); //sets the name onto the account
                                std::cout << "Thank you very much." << std::endl;
                            }
                        }
                    }
                }
                break; //it's going to get repetitive
            case 3: //deposit
                if (accounts.empty() == true) { //makes sure there are bank accounts in the first place
                    std::cout << "There are no accounts here. Make an account first. >^>.<^*<" << std::endl;
                }else {
                    std::cout << "I see, well what is your account ID: " << std::endl;
                    std::cin >> accountId;
                    foundaccount = findaccount(accountId); //to make sure the account in question exists in the first place
                    if (foundaccount == false) { //if it doesn't exist
                        std::cout << "could not find account. Try again" << std::endl;
                    }else {//if it does exist
                        for (unsigned int i = 0; i < accounts.size(); i++) {
                            currAccount = accounts.at(i);
                            if (currAccount.GetAccountNumber() == accountId) {
                                std::cout << "Alright, found it :3. Now, how much would you like to deposit: ";
                                std::cin >> amount;
                                currAccount.deposit(amount);
                                std::cout << "Thank you very much." << std::endl;
                            }
                        }
                    }
                }
                break;
            case 4: //withdraw
                if (accounts.empty() == true) {
                    std::cout << "There are no accounts here. Make an account first. >^>.<^*<" << std::endl;
                }else {
                    std::cout << "I see, well what is your account ID: " << std::endl;
                    std::cin >> accountId;
                    if (foundaccount == false) {
                        std::cout << "could not find account. Try again" << std::endl;
                    }else {
                        for (unsigned int i = 0; i < accounts.size(); i++) {
                            currAccount = accounts.at(i);
                            if (currAccount.GetAccountNumber() == accountId) {
                                std::cout << "Alright, found it :3. Now, how much would you like to withdraw: ";
                                std::cin >> amount;
                                currAccount.withdraw(amount);
                                std::cout << "Thank you very much." << std::endl;
                            }
                        }
                    }
                }
                break;
            case 5: //get ID
                if (accounts.empty() == true) {
                    std::cout << "There are no accounts here. Make an account first. >^>.<^*<" << std::endl;
                }else {
                    std::cout << "I see, well what is your account Name: " << std::endl;
                    std::cin >> currAccountName;
                    foundaccount = findaccountID(currAccountName);
                    if (foundaccount == false) {
                        std::cout << "could not find account. Try again" << std::endl;
                    }else {
                        for (unsigned int i = 0; i < accounts.size(); i++) {
                            currAccount = accounts.at(i);
                            if (currAccount.GetAccountHolderName() == currAccountName) {
                                std::cout << "your account ID is " << currAccount.GetAccountNumber() << std::endl;
                                std::cout << "Thank you very much." << std::endl;
                            }
                        }
                    }
                }
                break;
            case 6: //get name
                if (accounts.empty() == true) {
                    std::cout << "There are no accounts here. Make an account first. >^>.<^*<" << std::endl;
                }else {
                    std::cout << "I see, well what is your account ID: " << std::endl;
                    std::cin >> accountId;
                    foundaccount = findaccount(accountId);
                    if (foundaccount == false) {
                        std::cout << "could not find account. Try again" << std::endl;
                    }else {
                        for (unsigned int i = 0; i < accounts.size(); i++) {
                            currAccount = accounts.at(i);
                            if (currAccount.GetAccountNumber() == accountId) {
                                std::cout << "Alright. Your account name is " << currAccount.GetAccountHolderName() << std::endl;
                                std::cout << "Thank you very much." << std::endl;
                            }
                        }
                    }
                }
                break;
            case 7: //get balance
                if (accounts.empty() == true) {
                    std::cout << "There are no accounts here. Make an account first. >^>.<^*<" << std::endl;
                }else {
                    std::cout << "I see, well what is your account ID: " << std::endl;
                    std::cin >> accountId;
                    foundaccount = findaccount(accountId);
                    if (foundaccount == false) {
                        std::cout << "could not find account. Try again" << std::endl;
                    }else {
                        for (unsigned int i = 0; i < accounts.size(); i++) {
                            currAccount = accounts.at(i);
                            if (currAccount.GetAccountNumber() == accountId) {
                                std::cout << "Alright. Your account name is " << currAccount.GetBalance() << std::endl;
                                std::cout << "Thank you very much." << std::endl;
                            }
                        }
                    }
                }
                break;
            case 8: //quit
                std::cout << "Thank you for using kitten banking. I hope to see you again soon" << std::endl;
                break;
            default:
                std::cout << "That's not a real option for this. Please put a real option" << std::endl;
                break;
        }
    }while (choice != 8);
}
bool findaccount(const std::string accountId) {
    bool foundaccount = false;//sets it to false, just to be safe
    for (unsigned int i = 0; i < accounts.size(); i++) {//searches through the vector
        currAccount = accounts.at(i);
        if (currAccount.GetAccountNumber() == accountId) {
            foundaccount = true; //sets the bool to true if it finds the account in question based on the provided ID
        }
    }
    return foundaccount;
}
bool findaccountID(const std::string AccountName) {
    bool foundaccount = false;//sets it to false, just to be safe
    for (unsigned int i = 0; i < accounts.size(); i++) { //searches through the vector
        currAccount = accounts.at(i);
        if (currAccount.GetAccountHolderName() == AccountName) {//to make sure the account in question is the desired account
            foundaccount = true;
        }
    }
    return foundaccount;
}