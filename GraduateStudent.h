#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include "Member.h"
#include "Student.h"

using namespace std;

class GraduateStudent : public Student
{

  private:
  public:
    GraduateStudent();
    GraduateStudent(string _inputStringLine);
    int searchIndexOfVector(vector<GraduateStudent> _Members, string _id);
};

#endif