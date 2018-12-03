#ifndef MEMBER_h
#define MEMBER_h
#include <iostream>
#define MAX_ARRAY_SIZE 10 //  capacity problem exception?
#define MAX_SUBJECT_SIZE 3
#include <vector>

using namespace std;

struct grade{
  string subject;
  char grade;
};

struct memberStruct{
  string idNumber;
  string password;
  // int semester;
  string major;
  bool schedule;
  // bool isPayed;
  // float gradePointAverage;
  // struct grade grades[MAX_SUBJECT_SIZE];
};
struct memberStruct memberStructs[MAX_ARRAY_SIZE];

class Member{
  
private:
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
  void setStatus(char _status);

  vector<Member> saveFileData(string fileName);
};

#endif