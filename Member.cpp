#include <iostream>
#include "Member.h"
using namespace std;

Member::Member(){




}
//  constructor
 
// struct memberStruct memberStructs[MAX];
// struct memberStruct memberstruct;

string Member::getIdNumber() { return idNumber; }
string Member::getPassword() { return password; }
char Member::getStatus() { return status; }
int Member::getSizeOfArray() { return sizeOfArray; }
//  getter

void Member::setIdNumber(string _idNumber) { idNumber = _idNumber; }
void Member::setPassword(string _password) { password = _password; }
// void Member::setStatus(char _status) { status = _status; }
void Member::setStatus(char _status){status = _status;}  // /*   virtual function for inheritance : Child MUST override!*/ 
//  setter

void Member::saveFileData(){




}