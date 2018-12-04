#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
#include "Student.h"
#include "Member.h"

class Professor : public Member{
public:
  Professor();
  Professor(string _inputStringLine);
  void Professor::setStudentGrade(vector<Member>, string);
  void getSemester();

private:
  // string idNumber;
  // string password;
  // int semester;
  // string major;
  // bool schedule;
  // bool isPayed;
  // float gradePointAverage;
  // struct grade grades[MAX_SUBJECT_SIZE];
  char studentGrade;



};


#endif