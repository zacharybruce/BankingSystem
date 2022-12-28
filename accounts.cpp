#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>
#include "accounts.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"


void add_savings_account(SavingsAccount& savings_account){
    if (savings_account.has_savings()){
        std::cout << std::endl;
        std::cout << "Account already exists" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
    else{
        std::ofstream out_file("UserFiles/" + savings_account.get_username() +
            "SavingsAccount.txt");
        if (out_file.is_open()){
            out_file << 0.00;
            savings_account.set_amount(0.00);
            out_file.close();

            std::cout << std::endl;
            std::cout << "Savings account created" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "Could not create account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
}


void add_checking_account(CheckingAccount& checking_account){
    if (checking_account.has_checking()){
        std::cout << std::endl;
        std::cout << "Checking Account already exists" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
    else{
        std::ofstream out_file("UserFiles/" + checking_account.get_username() +
            "CheckingAccount.txt");
        if (out_file.is_open()){
            out_file << 0.00;
            checking_account.set_amount(0.00);
            out_file.close();

            std::cout << std::endl;
            std::cout << "Checking account created" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "Could not create account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
}


void delete_savings_account(SavingsAccount& savings_account,
                            CheckingAccount& checking_account){
        
    std::ifstream savings_file ("UserFiles/" + savings_account.get_username() +
        "SavingsAccount.txt");
    double amount_in_savings;

    if (savings_file.is_open()){
        savings_file >> amount_in_savings;
    }
    savings_file.close();

    if (!std::filesystem::remove("UserFiles/" +
            savings_account.get_username() + "SavingsAccount.txt")){
        std::cout << std::endl;
        std::cout << "Unable to delete account" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
        return;
    }

    if (checking_account.has_checking() && savings_account.get_amount() > 0){
        deposit_checking(checking_account, amount_in_savings);
    }

    std::filesystem::remove("UserFiles/" + savings_account.get_username() +
        "SavingsAccount.txt");
    
    if (checking_account.has_checking()){
        std::cout <<  std::endl;
        std::cout << "Savings Account Deleted. Funds transferred to checking ";
        std::cout << std::endl;
    }
    else{
        std::cout << std::endl;
        std::cout << "Savings Account Deleted" << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    Sleep(1000);
}


void delete_checking_account(CheckingAccount& checking_account,
                             SavingsAccount& savings_account){
                                
    std::ifstream checking_file ("UserFiles/" + checking_account.get_username()
        + "CheckingAccount.txt");
    double amount_in_checking;
    if (checking_file.is_open()){
        checking_file >> amount_in_checking;
    }
    checking_file.close();

    if (!std::filesystem::remove("UserFiles/" +
        checking_account.get_username() + "CheckingAccount.txt")){

        std::cout << std::endl;
        std::cout << "Unable to delete account" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
        return;
    }

    if (savings_account.has_savings() && checking_account.get_amount() > 0){
        deposit_savings(savings_account, amount_in_checking);
    }
    
    std::filesystem::remove("UserFiles/" + checking_account.get_username() +
                            "CheckingAccount.txt");
    
    if (savings_account.has_savings()){
        std::cout << std::endl;
        std::cout << "Checking Account Deleted. Funds transferred to savings ";
        std::cout << "account" << std::endl;
    }
    else{
        std::cout << std::endl;
        std::cout << "Checking Account Deleted" << std::endl;
    }
    std::cout << std::endl;
    Sleep(1000);
}


void deposit_savings(SavingsAccount& savings_account,
                     const double amount_to_add){

    if (amount_to_add > 0){
        if (savings_account.has_savings()){
            savings_account.set_amount(savings_account.get_amount() +
                amount_to_add);
            std::ofstream file("UserFiles/" + savings_account.get_username() +
                "SavingsAccount.txt");
            file << savings_account.get_amount();
            file.close();

            std::cout << std::endl;
            std::cout << "Added $" << amount_to_add << " to savings account" <<
                std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "No savings account available" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
    else{
        std::cout << std::endl;
        std::cout << "Amount to be added must be greater than 0" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
}
void deposit_checking(CheckingAccount& checking_account,
                      const double amount_to_add){

    if (amount_to_add > 0){
        if (checking_account.has_checking()){
            checking_account.set_amount(checking_account.get_amount() +
                amount_to_add);
            std::ofstream file("UserFiles/" + checking_account.get_username() +
                "CheckingAccount.txt");
            file << checking_account.get_amount();
            file.close();

            std::cout << std::endl;
            std::cout << "Added $" << amount_to_add << " to checking account" <<
                std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "No checking account available" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
    else{
        std::cout << std::endl;
        std::cout << "Amount to be added must be greater than 0" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
}


void withdraw_from_savings(SavingsAccount& savings_account,
                           const double amount_to_withdraw){
    
    if (amount_to_withdraw > 0){
        if (savings_account.has_savings()){
            savings_account.set_amount(savings_account.get_amount() -
                amount_to_withdraw);
            std::ofstream file("UserFiles/" + savings_account.get_username() +
                "SavingsAccount.txt");
            file << savings_account.get_amount();
            file.close();

            std::cout << std::endl;
            std::cout << "Withdrew $" << amount_to_withdraw;
            std::cout  << " from savings account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "No savings account available" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
    else{
        std::cout << std::endl;
        std::cout << "Amount to be withdrawn must be greater than 0" <<
            std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
}
void withdraw_from_checking(CheckingAccount& checking_account,
                            const double amount_to_withdraw){
    if (amount_to_withdraw > 0){
        if (checking_account.has_checking()){
            checking_account.set_amount(checking_account.get_amount() - 
                amount_to_withdraw);
            std::ofstream file("UserFiles/" + checking_account.get_username() +
                "CheckingAccount.txt");
            file << checking_account.get_amount();
            file.close();

            std::cout << std::endl;
            std::cout << "Withdrew $" << amount_to_withdraw;
            std::cout << " from checking account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "No checking account available" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
    else{
        std::cout << std::endl;
        std::cout << "Amount to be withdrawn must be greater than 0" <<
            std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
}


void transfer_to_savings(SavingsAccount& savings_account, 
                         CheckingAccount& checking_account,
                         const double transfer_amount){

    if (transfer_amount > 0 && transfer_amount <= checking_account.get_amount()){

        if (checking_account.has_checking() && savings_account.has_savings()){
            savings_account.set_amount(savings_account.get_amount() +
                transfer_amount);
            checking_account.set_amount(checking_account.get_amount() -
                transfer_amount);

            std::ofstream savings_file("UserFiles/" +
                savings_account.get_username() + "SavingsAccount.txt");

            std::ofstream checking_file("UserFiles/" +
                checking_account.get_username() + "CheckingAccount.txt");

            savings_file << savings_account.get_amount();
            checking_file << checking_account.get_amount();
            savings_file.close();
            checking_file.close();

            std::cout << std::endl;
            std::cout << "Transferred $" << transfer_amount <<
                " to savings account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "Need both checking and savings account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
    else{
        std::cout << std::endl;
        std::cout << "Error with transfer amount" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
}
void transfer_to_checking(SavingsAccount& savings_account,
                          CheckingAccount& checking_account,
                          const double transfer_amount){

    if (transfer_amount > 0 && transfer_amount <= savings_account.get_amount()){
        if (checking_account.has_checking() && savings_account.has_savings()){

            savings_account.set_amount(savings_account.get_amount() -
                transfer_amount);
            checking_account.set_amount(checking_account.get_amount() +
                transfer_amount);

            std::ofstream savings_file("UserFiles/" +
                savings_account.get_username() + "SavingsAccount.txt");

            std::ofstream checking_file("UserFiles/" +
                checking_account.get_username() + "CheckingAccount.txt");

            savings_file << savings_account.get_amount();
            checking_file << checking_account.get_amount();
            savings_file.close();
            checking_file.close();

            std::cout << std::endl;
            std::cout << "Transferred $" << transfer_amount <<
                " to checking account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
        else{
            std::cout << std::endl;
            std::cout << "Need both checking and savings account" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
    else{
        std::cout << std::endl;
        std::cout << "Error with transfer amount" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
    }
}
