#ifndef USER_H
#define USER_H

#include <string>
#include <string_view>

class User{
    public:
        User();
        User(std::string_view username, std::string_view password);
        ~User();


        // getters
        std::string get_username();
        std::string get_password();


        // setters
        void set_username(std::string_view username);
        void set_password(std::string_view password);


        bool has_savings();
        bool has_checking();


    private:
        std::string m_username;
        std::string m_password;
};


#endif