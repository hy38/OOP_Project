#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H
#include "Member.h"
#include "Student.h"

class UndergraduateStudent : public Student{
public:
  UndergraduateStudent();
  UndergraduateStudent(string _inputStringLine);
  void setStudentGrade();
  void getSemester();

private:


};

#endif