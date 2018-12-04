#include <iostream>
#include "Login.h"

using namespace std;

Login::Login(vector<Member> _Member){
    cout << "ID :";
	cin >> inputID;
	cout << "Password :";
	cin >> inputPassword;
}   //  constructor

string Login::getInputID() { return inputID; }
string Login::getInputPassword() { return inputPassword; }

//  getIdentify() calls search() for compare and calls setStatus() for SETTING the Member::status
Member Login::getIdentify(vector<Member> _Member){   //  gets userInput ID/PW's to compare with the ones in Member's database
    int index = Member::searchIndexOfVector(_Member, inputID);   //  search exception handled in search() function

        if(! _Member[index].getPassword().compare(inputPassword)){
            successIdentifying = true;
            setMemberStatus(inputID);    // set Member::status
            return _Member[index];
        }
        else
            throw "Password disMatch!";

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
        else
            throw "First letter must be a 'char'!"; //  first letter is int not char.
        }
    else
        throw "Identification ERROR";
    }
//  setter
