#ifndef STUDENT_H
#define STUDENT_H
#define MAX_GRADE_SIZE 5

#include "Member.h"
#include "UndergraduatedStudent.h"
#include "GraduatedStudent.h"
#include <iostream>
#include <fstream>

struct grade{
  string subject;
  char grade;
};
struct grade Grades[MAX_GRADE];


class Student{
private:
  int semester;

public:
  void setSemester(int _semester);
  void setGrades(string _subject, char _grade, int _index);


  int getSemester();
};

#endif