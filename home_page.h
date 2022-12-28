#ifndef HOME_PAGE
#define HOME_PAGE

#include <iostream>
#include <string>
#include "User.h"

void register_new_user();

bool check_for_user(std::string& username, std::string& password);

bool log_in(User& user);

void home_page(User& user);

#endif