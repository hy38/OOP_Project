#include <sstream>
#include <iostream>
#include "Student.h"
#include "Member.h"
#include "Professor.h"

using namespace std;

Professor::Professor(string _inputStringLine){

    string input = _inputStringLine;
    string parsed;
    stringstream input_stringstream(input);

    try{
        if (getline(input_stringstream, parsed, ',')){
            Member::setPassword(parsed);    //  password parse
        }
        else throw "password parsing error!";

        if (getline(input_stringstream, parsed, ',')){  //  skip semester
            if (getline(input_stringstream, parsed, ',')){
                Member::setPassword(parsed);    //  major parse
            }
        }

        if (getline(input_stringstream, parsed, '\n')){    
            if (parsed.compare("TRUE") == 0)
            Member::setSchedule(true);  //  schedule parse
        else if (parsed.compare("FALSE") == 0)
            Member::setSchedule(false); //  schedule parse
        else
            throw "schedule parsing error";
        }

    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        // exit(0);
    }
}

void Professor::setStudentGrade(vector<Student> _Members, string _id){   //  student id?
    
    int index = searchIndexOfVector(_Members, _id);
    string inputSubject;
    char inputGrade;
    if(_Members[index].getStatus() == 'u' | _Members[index].getStatus() == 'g'){
        
        cout << "input the subject :";
        cin >> inputSubject;
        cout << "input the grade :";
        cin >> inputGrade;
        _Members[index].setGrades(inputSubject, inputGrade);

    }

    else{
        throw "input ID is Not a Student ID!";
    }
}