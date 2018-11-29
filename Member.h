#ifndef MEMBER_h
#define MEMBER_h
#include <iostream>

using namespace std;

class Member
{
  private:
    string idNumber;
    string password;
    char status;


  public:
    Member()
    {
    }

	string getIdNumber();
  string getPassword();
  char getStatus();

	void setIdNumber(string _idNumber);
  void setPassword(string _password);
  virtual void setStatus(char _status);

};

#endif