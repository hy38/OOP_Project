#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>

using namespace std;

// struct memberStruct{
//     // string idNumber;
//     // string password;
//   // int semester; not use
//     // string major;
//     // bool schedule;
//   // bool isPayed; not use
//   // float gradePointAverage; not use
//   // struct grade grades[MAX_SUBJECT_SIZE]; not use
// };
// struct memberStruct memberStructs;

class Member{
  
private:
  char status;
  string idNumber;
  string password;
  string major;
  bool schedule;

public:
  Member();
  char getStatus();
  string getIdNumber();
  string getPassword();
  string getMajor();
  bool getSchedule();

  void setStatus(char _status);
  void setIdNumber(string _idNumber);
  void setPassword(string _password);
  void setMajor(string _major);
  void setSchedule(bool _schedule);

  vector<Member> saveFileData(string fileName);
  int searchIndexOfVector(vector<Member>, string _id);
};

#endif