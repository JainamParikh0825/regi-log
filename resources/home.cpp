#include <iostream>
#include "../headers/home.h"
#include "../headers/utility.h"
#include "../headers/registration.h"
#include "../headers/login.h"

using namespace std;

void title(){
    cout << "----------------------------------------" << endl;
    cout << "    🔐 Welcome to Regi-Log System 🔐    " << endl;
    cout << "----------------------------------------" << endl;
}

void aboutUs(){
    cout << "\n---- About Us 👨‍💻 ----" << endl;
    cout << "We here at Regi-Log, manage user data " << endl;
    cout << "by registering an user's information and" << endl;
    cout << "login user to check their information." << endl;
    cout << "We tend to make user's sensitive information secure" << endl;
}

void services(){
    int choiceNo = 0;
    bool option = false;

    cout << "\n---- Services 👩‍🔧 ----" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    choiceNo = choice();

    switch(choiceNo){
        case 1:
            registration("Registration");
            services();
            break;
        case 2:
            login("Login");
            services();
            break;
        case 3:
            break;
        default:
            invalidInput();
            services();
    }
}
