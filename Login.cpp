#include <iostream>
#include "Login.h"
#include "Member.h"

using namespace std;

Login::Login(string _ID, string _PW) : Member(){
    inputID = _ID;
    inputPassword = _PW;
}

string Login::getID() { return inputID; }
string Login::getPassword() { return inputPassword; }
// char Login::getStatus() { return status; }
//  getter

void Login::setID(string _idNumber) { inputID = _idNumber; }
void Login::setPassword(string _password) { inputPassword = _password; }
// void Login::setStatus(char _status) { status = _status; }
//  setter

bool Login::getIdentify(string _inputID, string _inputPassword){   //  gets userInput ID/PW's to confirm with the ones in Member's database


}

string Login::search(){ //  searches the Member's ID and returns the ID's password

}

void Login::setStatus(){    //  gets the first character of ID
        if(success){
            if(!isdigit(inputID.at(0)))
                Member::setStatus(inputID.at(0));   //  the first character of ID; must not be int but char
            else
                throw exception();  //  first letter is int not char.
        }
        else
            throw exception();
    }