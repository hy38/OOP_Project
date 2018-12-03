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

bool Login::getIdentify(string _inputID, string _inputPassword){   //  gets userInput ID/PW's to compare with the ones in Member's database
    int index = search(_inputID);   //  search exception handled in search() function

        if(!memberStructs[index].password.compare(_inputPassword)){ //  compare the passwords
            successIdentifying = true;
            setMemberStatus(_inputID);    // set Member::status
            return true;
        }
        
    return false;
}   //  if successful, successIdentifying = true.
//  getter

void Login::setInputID(string _idNumber) { inputID = _idNumber; }
void Login::setInputPassword(string _password) { inputPassword = _password; }
void Login::setsuccessIdentifying(bool _successIdentifying) { successIdentifying = _successIdentifying; }

void Login::setMemberStatus(string _inputID){    //  gets the first character of ID
    char temp;
    if (successIdentifying){
        if (!isdigit(temp = _inputID.at(0)))
            Member::setStatus(temp); //  the first character of ID; must not be int but char
            // Member
        else
            throw "First letter must be a 'char'!"; //  first letter is int not char.
        }
    else
        throw "Identification ERROR";
    }
//  setter

int Login::search(string _inputID){ //  searches the Member's ID and returns the ID's structure index. return -1 if fail.

    for(int i=0; i<Member::getSizeOfArray(); i++){
        if(!memberStructs[i].idNumber.compare(_inputID)) //  check the validity of_inputID. ==> if(same)
            return i;
        
        else    //  there is no such ID!
            throw "No SUCH ID! Please check your ID again.";
    }

}