#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Member.h"
#include "Student.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include <iostream>
#include <vector>

using namespace std;

class Professor : public Member
{
private:
  bool Schedule;
  // char studentGrade;

public:
  Professor();
  Professor(string);
  void setSchedule(bool _schedule);
  void setStudentGrade(vector<UndergraduateStudent>, string);
  void setStudentGrade(vector<GraduateStudent>, string);
  bool getSchedule();
  int searchIndexOfVector(vector<Professor> _Members, string _id);
};

#endif
