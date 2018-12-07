#ifndef STUDENT_H
#define STUDENT_H

#include "Member.h"
#include "SizeInfo.h"
// #include "UndergraduateStudent.h"
// #include "GraduateStudent.h"
#include <iostream>
#include <fstream>

using namespace std;

struct grade
{
  string subject;
  char grade = ' ';
};

class Student : public Member
{
private:
  int semester;
  grade Grades[MAX_GRADE_SIZE];

public:
  Student();
  void setSemester(int _semester);
  void setGrades(string _subject, char _grade, int _index);
  void getGrades();

  int getSemester();
};

#endif
