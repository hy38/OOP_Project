#include <iostream>
#include "Login.h"
#include "Member.h"

using namespace std;

Login::Login(string _ID, string _PW) : Member(){
    inputID = _ID;
    inputPassword = _PW;
    getIdentify(_ID, _PW);  //  calls search() for compare and calls setStatus() for SETTING the Member::status
}   //  constructor

string Login::getInputID() { return inputID; }
string Login::getInputPassword() { return inputPassword; }
// char Login::getStatus() { return status; }
//  getter

void Login::setInputID(string _idNumber) { inputID = _idNumber; }
void Login::setInputPassword(string _password) { inputPassword = _password; }
void Login::setStatus(){    //  gets the first character of ID
    char temp;
    if (successIdentifying){
        if (!isdigit(temp = inputID.at(0))) //  Member(Parent) sets => Child gets setted by inheritance. right? ******************88
            Member::setStatus(temp); //  the first character of ID; must not be int but char
        
        else
            throw exception(); //  first letter is int not char.
        }
    else
        throw "Identification ERROR";
    }
//  setter

bool Login::getIdentify(string _inputID, string _inputPassword){   //  gets userInput ID/PW's to compare with the ones in Member's database
    int index;  //  <== ************************************QUESTION*************************************

    if (index = search(_inputID) == -1)
        throw "there's NO SUCH ID!";
    else{   //  valid ID
        if(memberStructs[index].password.compare(_inputPassword)){  // 1. compare the passwords.
            successIdentifying = true;
            setStatus();    // 2. set status variable.
            return true;
        }

    }
    return true;

}   //  if successful, success = true.

int Login::search(string _inputID){ //  searches the Member's ID and returns the ID's structure index. return -1 if fail.

    for(int i=0; i<Member::getSizeOfArray(); i++){
        if(!memberStructs[i].idNumber.compare(_inputID)) //  check the validity of_inputID. ==> if(same)
            return i;
        
        else    //  there is no such ID!
            return -1;
            // throw exception();
    }

}

