#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <Windows.h>
#include "User.h"
#include "accounts.h"
#include "accounts_page.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"


void accounts_page(User& user){

    SavingsAccount savings_account;
    savings_account.set_username(user.get_username());
    savings_account.set_password(user.get_password());

    CheckingAccount checking_account;
    checking_account.set_username(user.get_username());
    checking_account.set_password(user.get_password());

    if (user.has_savings()){
        std::ifstream file("UserFiles/" + user.get_username() +
            "SavingsAccount.txt");
        double savings_amount;
        if (file.is_open()){
            file >> savings_amount;
        }
        file.close();

        savings_account.set_amount(savings_amount);
        savings_account.set_name("Savings");
    }

    if (user.has_checking()){
        std::ifstream file("UserFiles/" + user.get_username() +
            "CheckingAccount.txt");
        double checking_amount;
        if (file.is_open()){
            file >> checking_amount;
        }
        file.close();

        checking_account.set_amount(checking_amount);
        checking_account.set_name("Checking");
    }

    int choice;
    int choice_of_account;
    int choice_to_transfer;

    double amount_to_add;
    double amount_to_withdraw;
    double amount_to_transfer;

    bool condition = true;

    while (condition){

        std::cout << "\tAccounts: " << std::endl;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);

        if (user.has_savings()){
            std::cout << "\tSavings Account Balance: $" << 
                savings_account.get_amount() << std::endl;
        }
        if (user.has_checking()){
            std::cout << "\tChecking Account Balance: $" <<
                checking_account.get_amount() << std::endl;
        }
        if (!(user.has_checking() || user.has_savings())){
            std::cout << "\tNo open accounts" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Deposit Funds:          1" << std::endl;
        std::cout << "Withdraw Funds:         2" << std::endl;
        std::cout << "Transfer Funds:         3" << std::endl;
        std::cout << "Open Savings Account:   4" << std::endl;
        std::cout << "Open Checking Account:  5" << std::endl;
        std::cout << "Close Savings Account:  6" << std::endl;
        std::cout << "Close Checking Account: 7" << std::endl; 
        std::cout << "Log Out:                8" << std::endl;
        std::cout << "Exit:                   9" << std::endl;
        std::cout << "What would you like to do? ";
        std::cin >> choice;

        if(choice == 1){
            std::cout << "Amount to deposit: $";
            std::cin >> amount_to_add;
            if (!std::cin){
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                continue;
            }

            std::cout << "Savings Account:  1" << std::endl;
            std::cout << "Checking Account: 2" << std::endl;
            std::cout << "Choose Account to Add Funds: ";
            std::cin >> choice_of_account;

            if (choice_of_account == 1){
                deposit_savings(savings_account, amount_to_add);
            }
            else if (choice_of_account == 2){
                deposit_checking(checking_account, amount_to_add);
            }
            else if (!std::cin){
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            }
            else{
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
            }
        }
        else if (choice == 2){
            std::cout << "Amount to withdraw: $";
            std::cin >> amount_to_withdraw;

            if (!std::cin){
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                continue;
            }

            std::cout << "Savings Account:  1" << std::endl;
            std::cout << "Checking Account: 2" << std::endl;
            std::cout << "Choose Account to Withdraw Funds: ";
            std::cin >> choice_of_account;

            if (choice_of_account == 1){
                if (!savings_account.has_savings()){
                    std::cout << std::endl;
                    std::cout << "No open savings account" << std::endl;
                    std::cout << std::endl;
                    Sleep(1000);
                    continue;
                }
                else if (amount_to_withdraw > savings_account.get_amount()){
                    std::cout << std::endl;
                    std::cout << "Not enough funds in account" << std::endl;
                    std::cout << std::endl;
                    Sleep(1000);
                    continue;
                }
                withdraw_from_savings(savings_account, amount_to_withdraw);
            }
            else if (choice_of_account == 2){
                if (!checking_account.has_checking()){
                    std::cout << std::endl;
                    std::cout << "No open checking account" << std::endl;
                    std::cout << std::endl;
                    Sleep(1000);
                    continue;
                }
                else if (amount_to_withdraw > checking_account.get_amount()){
                    std::cout << std::endl;
                    std::cout << "Not enough funds in account" << std::endl;
                    std::cout << std::endl;
                    Sleep(1000);
                    continue;
                }
                withdraw_from_checking(checking_account, amount_to_withdraw);
            }
            else if (!std::cin){
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            }
            else{
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
            }
        }
        else if (choice == 3){
            if (!(savings_account.has_savings() &&
                checking_account.has_checking())){

                std::cout << std::endl;
                std::cout << "Need open savings and checking account" <<
                    std::endl;
                std::cout << std::endl;
                Sleep(1000);
                continue;
            }
            std::cout << "From savings to checking: 1" << std::endl;
            std::cout << "From checking to savings: 2" << std::endl;
            std::cout << "Transfer where: ";
            std::cin >> choice_to_transfer;

            if (!std::cin){
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                continue;
            }

            std::cout << "Amount to transfer: $";
            std::cin >> amount_to_transfer;

            if (choice_to_transfer == 1){
                transfer_to_checking(savings_account, checking_account,
                    amount_to_transfer);
            }
            else if (choice_to_transfer == 2){
                transfer_to_savings(savings_account, checking_account,
                    amount_to_transfer);
            }
            else if (!std::cin){
                std::cout << std::endl;
                std::cout << "Invalid entry. Unable to continue" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            }
            else{
                std::cout << std::endl;
                std::cout << "Error in transferring" << std::endl;
                std::cout << std::endl;
                Sleep(1000);
            }
        }
        else if (choice == 4){
            add_savings_account(savings_account);
        }
        else if(choice == 5){
            add_checking_account(checking_account);
        }
        else if (choice == 6){
            delete_savings_account(savings_account, checking_account);
        }
        else if (choice == 7){
            delete_checking_account(checking_account, savings_account);
        }
        else if (choice == 8){
            condition = false;
            std::cout << std::endl;
        }
        else if (choice == 9){
            exit(0);
        }
        else if (!std::cin){
            std::cout << std::endl;
            std::cout << "Please enter number 1-9" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
        }
        else{
            std::cout << std::endl;
            std::cout << "Please enter number 1-9" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
}
