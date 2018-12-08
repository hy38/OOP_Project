#include <sstream>
#include <iostream>
#include "Professor.h"

using namespace std;

Professor::Professor() {}

Professor::Professor(string _inputStringLine)
{

    string input = _inputStringLine;
    string parsed;
    stringstream input_stringstream(input);

    try
    {
        if (getline(input_stringstream, parsed, ','))
        {
            setPassword(parsed); //  password parse
        }
        else
            throw "password parsing error!";

        if (getline(input_stringstream, parsed, ','))
        { //  skip semester
            if (getline(input_stringstream, parsed, ','))
            {
                setMajor(parsed); //  major parse    !
            }
        }

        if (getline(input_stringstream, parsed, ','))
        { // schedule parse
            if (parsed.compare("TRUE") == 0)
                setSchedule(true); //  schedule parse
            else if (parsed.compare("FALSE") == 0)
                setSchedule(false); //  schedule parse
            else
                throw "schedule parsing error";
        }

        getline(input_stringstream, parsed);
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

void Professor::setStudentGrade(vector<UndergraduateStudent> _Members, string _id)
{
    try
    {
        UndergraduateStudent temp;
        int index = temp.searchIndexOfVector(_Members, _id);
        string inputSubject;
        char inputGrade;
        if (_Members[index].getStatus() == 'u' | _Members[index].getStatus() == 'g')
        {
            cout << "input the subject :";
            cin >> inputSubject;
            cout << "input the grade :";
            cin >> inputGrade;
            UndergraduateStudent a = _Members[index];
            cout << "--이전--" << endl;
            a.getGrades();
            a.setGrades(inputSubject, inputGrade, 3);
            _Members[index] = a;
            cout << "--이후--" << endl;
            a.getGrades();
        }
        else
        {
            throw "input ID is Not a Student ID!";
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

void Professor::setStudentGrade(vector<GraduateStudent> _Members, string _id)
{
    try
    {
        GraduateStudent temp;
        int index = temp.searchIndexOfVector(_Members, _id);
        string inputSubject;
        char inputGrade;
        if (_Members[index].getStatus() == 'u' | _Members[index].getStatus() == 'g')
        {
            cout << "input the subject :";
            cin >> inputSubject;
            cout << "input the grade :";
            cin >> inputGrade;
            GraduateStudent a = _Members[index];
            a.getGrades();
            a.setGrades(inputSubject, inputGrade, 3);
            _Members[index] = a;
            a.getGrades();
        }
        else
        {
            throw "input ID is Not a Student ID!";
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

int Professor::searchIndexOfVector(vector<Professor> _Members, string _id)
{
    try
    {
        for (int i = 0; i < _Members.size(); i++)
        {                                                //  search
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