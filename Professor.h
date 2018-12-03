#ifndef PROFESSOR_h
#define PROFESSOR_h
#include <iostream>
#include "Member.h"

class Professor : public Member{

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
    

public:
    void setStudentGrade();
    void getSemester();


};


#endif