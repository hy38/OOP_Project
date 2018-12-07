#define MAX_MEMBERS 5
#include "Member.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Member::Member() {}
//  constructor

char Member::getStatus() { return status; }
string Member::getIdNumber() { return idNumber; }
string Member::getPassword() { return password; }
string Member::getMajor() { return major; }
bool Member::getSchedule() { return schedule; }
//  getter

void Member::setStatus(char _status) { status = _status; }
void Member::setIdNumber(string _idNumber) { idNumber = _idNumber; }
void Member::setPassword(string _password) { password = _password; }
void Member::setMajor(string _major) { major = _major; }
void Member::setSchedule(bool _schedule) { schedule = _schedule; }
//  setter


// int Member::searchIndexOfVector(vector<Member> _Members, string _id){
//     try
//     {
//         for (int i = 0; i < _Members.size(); i++)
//         {                                                //  search
//             if (!_Members[i].getIdNumber().compare(_id)) //  check the validity of_inputID. ==> if(same)
//                 return i;
//         }
//         throw "No SUCH ID! Please check your ID again.";
//     }
//     catch (char const *msg)
//     {
//         cerr << msg << endl;
//         exit(0);
//     }
// }