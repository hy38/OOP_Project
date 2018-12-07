#include "Student.h"
// #include "SizeInfo.h"
#include <iostream>
#include <fstream>

Student::Student(){

}

void Student::setSemester(int _semester) { semester = _semester;}

void Student::setGrades(string _subject, char _grade, int _index){
    
    Grades[_index].subject = _subject;
    Grades[_index].grade = _grade;

}

int Student::getSemester(){ return semester; }

void Student::getGrades()
{
    for (int i =0; i<MAX_GRADE_SIZE; i++){
     cout << Grades[i].subject << "  ";
     cout << Grades[i].grade << endl;
    }
}