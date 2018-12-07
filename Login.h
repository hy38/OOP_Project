#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include "Member.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "Professor.h"

using namespace std;

class Login : public Member
{
private:
  string inputID;
  string inputPassword;

public:
  Login(/* vector<Member> _Member */);
  //  constructor

  string getInputID();
  string getInputPassword();
  //  getter

  void setInputID(string _ID);
  void setInputPassword(string _password);
  //  setter

  void setMemberStatus(string _inputID); //  gets the first character of ID

  UndergraduateStudent getIdentify(vector<UndergraduateStudent> _Member); //  gets userInput ID/PW's to confirm with the ones in data vector
  GraduateStudent getIdentify(vector<GraduateStudent> _Member);
  Professor getIdentify(vector<Professor> _Member);
};
#endif