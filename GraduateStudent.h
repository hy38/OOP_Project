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
    void getAll();
};

#endif
