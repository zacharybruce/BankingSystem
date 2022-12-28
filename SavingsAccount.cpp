#include <string>
#include <string_view>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
{
}
SavingsAccount::SavingsAccount(std::string_view username,
                               std::string_view password, std::string_view name,
                               double amount) :
                               User(username, password), m_name(name),
                               m_amount(amount)
{
}
SavingsAccount::~SavingsAccount()
{
}


// getters
std::string SavingsAccount::get_name(){
    return m_name;
}
double SavingsAccount::get_amount(){
    return m_amount;
}


// setters
void SavingsAccount::set_name(std::string_view name){
    m_name = name;
}
void SavingsAccount::set_amount(double amount){
    m_amount = amount;
}