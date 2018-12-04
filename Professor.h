#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Member.h"
#include "Student.h"
#include <iostream>
#include <vector>

using namespace std;

class Professor : public Member
{
private:
  // char studentGrade;

public:
  Professor();
  Professor(string);
  void setStudentGrade(vector<Member>, string);
  void getSemester();
};

#endif