#ifndef STUDENT_H
#define STUDENT_H
#define MAX_GRADE_SIZE 5

#include "Member.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include <iostream>
#include <fstream>

struct grade{
  string subject;
  char grade;
};
struct grade Grades[MAX_GRADE_SIZE];


class Student{
private:
  int semester;

public:
  Student();
  void setSemester(int _semester);
  void setGrades(string _subject, char _grade, int _index);
  void setGrades(string _subject, char _grade);


  int getSemester();
};

#endif