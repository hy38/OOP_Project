#include <iostream>
#include <fstream>
#include "Member.h"
using namespace std;

Member::Member(){
    sizeOfArray = MAX_ARRAY_SIZE;


}
//  constructor

// string Member::getIdNumber() { return idNumber; }
// string Member::getPassword() { return password; }
char Member::getStatus() { return status; }
int Member::getSizeOfArray() { 

    for(int i=0; i<MAX_ARRAY_SIZE; i++){
        if(!memberStructs[i].idNumber.compare("null"))  //  if idNumber == "null"
            return i;
        //Exceptions?
    }
}
//  getter

// void Member::setIdNumber(string _idNumber) { idNumber = _idNumber; }
// void Member::setPassword(string _password) { password = _password; }
// void Member::setStatus(char _status) { status = _status; }
void Member::setStatus(char _status){status = _status;}  // /*   virtual function for inheritance : Child MUST override!*/ 
//  setter

void Member::saveFileData(string fileName){
    for(int i=0; i<getSizeOfArray(); i++){
        fstream inFile;
        // inFile.open("datafile.csv");
        inFile.open(fileName);  //  file open exception handle NEED!
        string str;
        getline(inFile, str); //  Not Taking the First Line

        try
        {
            getline(inFile, str, ','); //  idNumber : string
            for (int i = 0, count = 0; i < str.length(); i++)
            {
                if (isdigit(str[i]))
                    count++;

                if (count == str.length())
                    throw "s";
            }
            memberStructs[i].idNumber = str;

            getline(inFile, str, ','); //  password : string
            for (int i = 0, count = 0; i < str.length(); i++)
            {
                if (isdigit(str[i]))
                    count++;

                if (count == str.length())
                    throw "s";
            }
            memberStructs[i].password = str;

            getline(inFile, str, ','); //  semester : int
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].semester = stoi(str);  //  Error warning

            getline(inFile, str, ','); //  major : string
            for (int i = 0, count = 0; i < str.length(); i++)
            {
                if (isdigit(str[i]))
                    count++;

                if (count == str.length())
                    throw "s";
            }
            memberStructs[i].major = str;

            //  schedule not sure
            getline(inFile, str, ','); //  schedule : bool?
            if (str.compare("TRUE") == 0)
                memberStructs[i].schedule = true;
            else if (str.compare("FALSE") != 0)
                memberStructs[i].schedule = false;
            else
                throw "data must be \"TRUE\" or \"FALSE\"";

            getline(inFile, str, ','); //  gradePointAverage : float
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].gradePointAverage = stof(str);

            getline(inFile, str, ','); //  subject1 : string
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].grades[0].subject = str;

            getline(inFile, str, ','); //  grade1 : char
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].grades[0].grade = str.at(0);   //  exception when using str.at(0)

            getline(inFile, str, ','); //  subject2 : string
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].grades[1].subject = str;

            getline(inFile, str, ','); //  grade2 : char
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].grades[1].grade = str.at(0);   //  exception when using str.at(0)

            getline(inFile, str, ','); //  subject3 : string
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].grades[2].subject = str;

            getline(inFile, str, '\n'); //  grade3 : char
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                    throw 0;
            }
            memberStructs[i].grades[2].grade = str.at(0);   //  exception when using str.at(0)

        }   //  try end
        catch (int expn)
        {
            cout << "MyError : type must be 'int'" << endl;
            exit(0);
        }
        catch (char const *expn)
        {
            cout << "MyError : type must be 'string' " << endl;
            exit(0);
        }   //  catch end

        inFile.close();
    }   //  for end

}   //  end of function Member::saveFileData()

