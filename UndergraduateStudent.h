#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H
#include "Student.h"

using namespace std;

class UndergraduateStudent : public Student
{
public:
  UndergraduateStudent();
  UndergraduateStudent(string _inputStringLine);
  int searchIndexOfVector(vector<UndergraduateStudent> _Members, string _id);
};

#endif