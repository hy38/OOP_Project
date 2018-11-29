#include <iostream>
#include "Member.h"

using namespace std;

Member::Member() {}

string Member::getIdNumber() { return idNumber; }
string Member::getPassword() { return password; }
char Member::getStatus() { return status; }
//  getter

void Member::setIdNumber(string _idNumber) { idNumber = _idNumber; }
void Member::setPassword(string _password) { password = _password; }
void Member::setStatus(char _status) { status = _status; }
//  setter
