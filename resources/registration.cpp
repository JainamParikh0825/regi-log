#include<iostream>
#include "../headers/registration.h"
#include "../headers/utility.h"
#include "../entities/user.cpp"

void registration(string serviceTitle){
    serviceHeader(serviceTitle);
    cout << "🙏 Welcome to User Registration 🙏" << endl;
    cout << "Please fill out the form information below." << endl;

    User* u = new User();
    u->registerUser();
}