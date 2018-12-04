#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
#include "Student.h"
#include "Member.h"

class Professor : public Member{
private:
  char studentGrade;

public:
  Professor();
  Professor(string _inputStringLine);
  void setStudentGrade(vector<Member>, string);
  void getSemester();

};


#endif