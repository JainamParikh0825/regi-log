#include <iostream>
#include "../headers/login.h"
#include "../headers/utility.h"
#include "../entities/user.cpp"

void login(string serviceTitle){
    serviceHeader(serviceTitle);
    cout << "🙏 Welcome to User Login 🙏" << endl;
    cout << "Please enter your username and password to login." << endl;

    User *u = new User();
    u->loginUser();
}