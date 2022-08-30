#include <iostream>
#include "../headers/utility.h"

using namespace std;

int choice(){
    int choiceNo = 0;
    cout << "\nEnter the choice no.: ";
    cin >> choiceNo;
    return choiceNo;
}

void serviceHeader(std::string serviceTitle){
    cout << "\n---- " << serviceTitle << " 📝 ----" << endl;
}

void invalidInput(){
    cout << "You've entered wrong input ❌." << endl;
    cout << "Please select any of the below available inputs." << endl;
}