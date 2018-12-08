#include "GraduateStudent.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

GraduateStudent::GraduateStudent() {}

GraduateStudent::GraduateStudent(string _inputStringLine)
{
    string input = _inputStringLine;
    string parsed;
    stringstream input_stringstream(input);
    string tempSubject;
    char tempGrade;

    try
    {
        if (getline(input_stringstream, parsed, ','))
        {
            Member::setPassword(parsed); //  password parse
        }
        else
            throw "password parsing error!";

        if (getline(input_stringstream, parsed, ','))
        {
            setSemester(stoi(parsed)); //  semester parse
        }
        else
            throw "semester parsing error!";

        if (getline(input_stringstream, parsed, ','))
        {
            setMajor(parsed); //  major parse
        }
        else
            throw "major parsing error!";

        if (getline(input_stringstream, parsed, ','))
        {
            if (parsed.compare("TRUE") == 0)
                setSchedule(true); //  schedule parse
            else if (parsed.compare("FALSE") == 0)
                setSchedule(false); //  schedule parse
            else
                throw "schedule parsing error";

            if (getline(input_stringstream, parsed, ','))
            { //  subject0 parse
                tempSubject = parsed;
            }
            else
                throw "subject0 parsing error!";

            if (getline(input_stringstream, parsed, ','))
            {                             //  grade0 parse
                tempGrade = parsed.at(0); //  string to char
            }
            else
                throw "grade0 parsing error!";

            setGrades(tempSubject, tempGrade, 0); //  Grades[0]

            if (getline(input_stringstream, parsed, ','))
            {
                tempSubject = parsed; //  subject1 parse
            }
            else
                throw "subject1 parsing error!";

            if (getline(input_stringstream, parsed, ','))
            {
                tempGrade = parsed.at(0); //  grade1 parse
            }
            else
                throw "grade1 parsing error!";

            setGrades(tempSubject, tempGrade, 1); //  Grades[1]

            if (getline(input_stringstream, parsed, ','))
            {
                tempSubject = parsed; //  subject2 parse
            }
            else
                throw "subject2 parsing error!";

            if (getline(input_stringstream, parsed, ','))
            {                             /* \n?? */
                tempGrade = parsed.at(0); //  grade2 parse
            }
            else
                throw "grade2 parsing error!";

            setGrades(tempSubject, tempGrade, 2); //  Grades[2]
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

int GraduateStudent::searchIndexOfVector(vector<GraduateStudent> _Members, string _id)
{
    try
    {
        for (int i = 0; i < _Members.size(); i++)
        {                                                
            if (!_Members[i].getIdNumber().compare(_id)) //  check the validity of_inputID. ==> if(same)
                return i;
        }
        throw "No SUCH ID! Please check your ID again.";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}