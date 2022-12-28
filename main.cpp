#include "User.h"
#include "home_page.h"
#include "accounts_page.h"
#include <iostream>

int main(){

    User user;

    while (1){
        home_page(user);
        accounts_page(user);
    }
    
    return 0;
}