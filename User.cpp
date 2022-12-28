#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include "User.h"

User::User()
{
}
User::User(std::string_view username, std::string_view password) :
            m_username(username), m_password(password)
{
}
User::~User()
{
}


// getters
std::string User::get_username(){
    return m_username;
}
std::string User::get_password(){
    return m_password;
}


// setters
void User::set_username(std::string_view username){
    m_username = username;
}
void User::set_password(std::string_view password){
    m_password = password;
}


bool User::has_savings(){
    std::ifstream file("UserFiles/" + m_username + "SavingsAccount.txt");
    if (file.is_open()){
        return true;
    }
    file.close();
    return false;
}
bool User::has_checking(){
    std::ifstream file("UserFiles/" + m_username + "CheckingAccount.txt");
    if (file.is_open()){
        return true;
    }
    file.close();
    return false;
}
