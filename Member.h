#ifndef MEMBER_H
#define MEMBER_H

#include "Professor.h"
#include "Student.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include <iostream>
#include <vector>

using namespace std;

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