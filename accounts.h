#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "SavingsAccount.h"
#include "CheckingAccount.h"

void add_savings_account(SavingsAccount& savings_account);
void add_checking_account(CheckingAccount& checking_account);

void delete_savings_account(SavingsAccount& savings_account,
    CheckingAccount& checking_account);

void delete_checking_account(CheckingAccount& checking_account,
    SavingsAccount& savings_account);

void deposit_savings(SavingsAccount& savings_account,
    const double amount_to_add);

void deposit_checking(CheckingAccount& checking_account,
    const double amount_to_add);

void withdraw_from_savings(SavingsAccount& savings_account,
    const double amount_to_add);

void withdraw_from_checking(CheckingAccount& checking_account,
    const double amount_to_add);

void transfer_to_savings(SavingsAccount& savings_account,
    CheckingAccount& checking_account, const double transfer_amount);
    
void transfer_to_checking(SavingsAccount& savings_account, 
    CheckingAccount& checking_account, const double transfer_amount);

#endif