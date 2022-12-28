#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <Windows.h>
#include "home_page.h"
#include "User.h"


void register_new_user(){
    std::string new_username, new_password;
    std::ofstream user_file;

    while (1){
        std::cout << "Choose Username: ";
        std::cin >> new_username;
        std::ifstream file("UserFiles/" + new_username + "User.txt");
        if (!file.is_open()){
            break;
        }
        file.close();
        std::cout << "Username already used. Please pick another" << std::endl;
    }
    std::cout << "Choose Password: ";
    std::cin >> new_password;

    user_file.open("UserFiles/" + new_username + "User.txt", std::ios::app);
    user_file << new_password << std::endl;
    user_file.close();

    std::cout << std::endl;
    std::cout << "Thank you. Registered as " << new_username << std::endl;
    std::cout << std::endl;
    Sleep(1000);
}


bool check_for_user(std::string& username, std::string& password){
    std::string user_info, line;
    std::ifstream file("UserFiles/" + username + "User.txt");

    if (file.is_open()){
        while (file){
            std::getline(file, line);
            if (line == password){
                return true;
            }
        }
    }
    file.close();
    return false;
}


bool log_in(User& user){
    std::string username, password;

    std::cout << "Enter Username: ";
    std::getline(std::cin >> std::ws, username);
    std::cout << "Enter Password: ";
    std::getline(std::cin >> std::ws, password);

    bool log_in_status = check_for_user(username, password);
    if (log_in_status){
        user.set_username(username);
        user.set_password(password);
        std::cout << std::endl;
        std::cout << "Welcome " << username <<  std::endl;
        std::cout << std::endl;
        Sleep(1000);
        return true;
    }
    else{
        std::cout << std::endl;
        std::cout << "Invalid log in" << std::endl;
        std::cout << std::endl;
        Sleep(1000);
        return false;
    }
    
}


void home_page(User& user){

    bool log_in_status;
    int choice;
    bool condition {true};
    bool log_in_successful;

    while (condition){
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "Log In:   1" << std::endl;
        std::cout << "Register: 2" << std::endl;
        std::cout << "Exit:     3" << std::endl;
        std::cout << "Enter Number: ";
        std::cin >> choice;

        if (choice == 1){
            log_in_successful = log_in(user);
            if (log_in_successful){
                condition = false;
            }
            else{
                condition = true;
            }
        }
        else if (choice == 2){
            register_new_user();
        }
        else if (choice == 3){
            exit(0);
        }
        else if (!std::cin){
            std::cout << std::endl;
            std::cout << "Please enter 1, 2, or 3" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
        else{
            std::cout << std::endl;
            std::cout << "Please enter 1, 2, or 3" << std::endl;
            std::cout << std::endl;
            Sleep(1000);
        }
    }
}
