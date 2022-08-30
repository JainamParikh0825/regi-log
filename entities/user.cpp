#include<iostream>
#include<fstream>
#include <string.h>
#include "../headers/utility.h"
using namespace std;

class User{
private:
    string name;
    int age;
    string username;
    string password;
    char gender;
    void addUser(const string &name, const int &age, const string &username, const string &password, const char &gender){
        ofstream fout;

        fout.open("database/users.txt", ios::app);

        fout << "-------------------------\n";
        fout << "Name: " << name << '\n';
        fout << "Age: " << age << '\n';
        fout << "Username: " << username << '\n';
        fout << "Password: " << password << '\n';
        fout << "Gender: " << gender << '\n';

        fout.close();

        cout << "\nUser successfully added ✅" << endl;
    }
    bool checkUserCredentials(const string &username, const string &password){
        ifstream fin;
        fin.open("database/users.txt");

        int fieldNo = -1;
        bool isLoginSuccessful = false;

        string temp = "";
        while (!fin.eof())
        {
            fieldNo++;
            temp = "";
            getline(fin, temp);
            if (temp.starts_with("-"))
                continue;
            else if (temp.starts_with("Name"))
            {
                this->name = temp.substr(6);
            }
            else if (temp.starts_with("Age"))
            {
                this->age = stoi(temp.substr(4));
            }
            else if (temp.starts_with("Username"))
            {
                this->username = temp.substr(10);
            }
            else if (temp.starts_with("Password"))
            {
                this->password = temp.substr(10);
            }
            else if (temp.starts_with("Gender"))
            {
                this->gender = (temp.substr(8))[0];
            }

            if ((this->username == username) && (this->password == password) && (fieldNo == 5))
            {
                isLoginSuccessful = true;
                break;
            }
            else if (fieldNo == 5)
            {
                fieldNo = -1;
            }
        }

        fin.close();

        return isLoginSuccessful;
    }
    void loginSuccess(){
        cout << "\n✅ Logged In Successfully ✅" << endl;
        if (this->gender == 'M')
            cout << "\nHello " << this->name << "🙋‍♂️, here is your profile." << endl;
        else
            cout << "\nHello " << this->name << "🙋‍♀️, here is your profile." << endl;

        cout << "Age: " << this->age << endl;
        cout << "Username: " << this->username << endl;
        cout << "Gender: " << this->gender << endl;
    }
    void loginFailure(){
        cout << "\nUsername or Password Incorrect ❌." << endl;
        retryLogin();
    }
    void retryLogin(){
        char response = ' ';
        cout << "Do you want to try again?🙇‍♂️ (Y / N):  ";
        cin >> response;

        if(response == 'Y' || response == 'y'){
            loginUser();
        }
    }
    void logout(){
        char response = ' ';
        cout << "\nDo you want to log out?🧘‍♀️ (Y / N): ";
        cin >> response;

        if(response == 'Y' || response == 'y'){
            return;
        }

        logout();
    }

public:
    User(){
        name = "";
        age = 0;
        username = "";
        password = "";
        gender = ' ';
    }

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    string getUsername(){
        return username;
    }

    string getPassword(){
        return password;
    }

    char getGender(){
        return gender;
    }

    void setName(string name){
        this->name = name;
    }

    void setAge(int age){
        this->age = age;
    }

    void setUsername(string username){
        this->username = username;
    }

    void setPassword(string password){
        this->password = password;
    }

    void setGender(char gender){
        this->gender = gender;
    }

    void registerUser(){
        cin.ignore();

        cout << "\nName: ";
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "Username (should not contain spaces): ";
        cin >> username;

        cout << "Password (should not contain spaces): ";
        cin >> password;

        cout << "Gender (M / F): ";
        cin >> gender;

        addUser(name, age, username, password, gender);
    }

    void loginUser(){
        cin.ignore();

        string u = "", p = "";

        cout << "\nUsername: ";
        cin >> u;

        cout << "Password: ";
        cin >> p;

        if(checkUserCredentials(u, p)){
            loginSuccess();
            logout();
        } else{
            loginFailure();
        }
    }
};