#ifndef MEMBER_h
#define MEMBER_h
#include <iostream>
#define MAX_ARRAY_SIZE 5
using namespace std;

struct memberStruct{
  string idNumber;
  string password;
  int semester;
  string major;
  string AccountNumber;
  int AccountPassword;
  bool isPayed;
  float gradePointAverage;
  // schedule;
};
struct memberStruct memberStructs[MAX_ARRAY_SIZE];

class Member
{
  private:
    string idNumber;
    string password;
    char status;
    int sizeOfArray;

  public:
    Member();
	  string getIdNumber();
    string getPassword();
    char getStatus();
    int getSizeOfArray();

	  void setIdNumber(string _idNumber);
    void setPassword(string _password);
    /* virtual  */void setStatus(char _status);

    void Member::saveFileData();
};

#endif