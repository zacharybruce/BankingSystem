#include <string_view>
#include <string>
#include "CheckingAccount.h"
#include "User.h"


CheckingAccount::CheckingAccount()
{
}
CheckingAccount::CheckingAccount(std::string_view username,
                                 std::string_view password, 
                                 std::string_view name, double amount) :
                                 User(username, password), m_name(name),
                                 m_amount(amount)
{
}
CheckingAccount::~CheckingAccount()
{
}


// getters
std::string CheckingAccount::get_name(){
    return m_name;
}
double CheckingAccount::get_amount(){
    return m_amount;
}


// setters
void CheckingAccount::set_name(std::string_view name){
    m_name = name;
}
void CheckingAccount::set_amount(double amount){
    m_amount = amount;
}
