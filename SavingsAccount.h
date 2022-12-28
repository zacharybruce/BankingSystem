#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <string>
#include <string_view>
#include "User.h"

class SavingsAccount : public User{

    public:
        SavingsAccount();
        SavingsAccount(std::string_view username, std::string_view password,
                       std::string_view name, double amount);
        ~SavingsAccount();


        // getters
        std::string get_name();
        double get_amount();


        // setters
        void set_name(std::string_view name);
        void set_amount(double amount);


    private:
        std::string m_name;
        double m_amount; // Amount in savings account in dollars
};

#endif