#include "Member.h"
#include "Student.h"
#include "UndergraduatedStudent.h"
#include "GraduatedStudent.h"
#include <iostream>
#include <fstream>

Student::Student(){

}



void Student::setSemester(int _semester) { semester = _semester;}
void Student::setGrades(string _subject, char _grade, int _index){
    
    Grades[_index].subject = _subject;
    Grades[_index].grade = _grade;

}

void Student::setGrades(string _subject, char _grade){
    
}

int Student::getSemester(){ return semester; }
