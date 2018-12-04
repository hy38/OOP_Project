#define MAX_MEMBERS 5
#include "Member.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Member::Member(){}
//  constructor

char Member::getStatus() { return status; }
string Member::getIdNumber() { return idNumber; }
string Member::getPassword() { return password; }
string Member::getMajor() { return major; }
bool Member::getSchedule() { return schedule; }
//  getter

void Member::setStatus(char _status){status = _status;}
void Member::setIdNumber(string _idNumber) { idNumber = _idNumber; }
void Member::setPassword(string _password) { password = _password; }
void Member::setMajor(string _major) { major = _major; }
void Member::setSchedule(bool _schedule) { schedule = _schedule; }
//  setter


/* vector<Member> Member::saveFileData(string fileName){

    vector<Member> MemberLists;

    if(!fileName.compare(NULL))
        throw "[File Input] : NULL File";

    for(int i=0; i<MAX_MEMBERS; i++){   //  WHILE EOF convert NEED!
        fstream inFile;
        inFile.open(fileName);  //  file open exception handle NEED!
        string str;
        getline(inFile, str); //  Not Taking the First Line

        try
        {
            getline(inFile, str, ','); //  idNumber : string
            idNumber = str; //  put parsed string into idNumber 

            //  getStatus works properly because we setted the status while login. 
            if(getStatus() == 'p'){ //  if professor

                getline(inFile, str);
                Professor aProfessor = Professor(str);  //  gives rest of the string of 'str' to the constructor of Professor
                                
                MemberLists.push_back(aProfessor);                
            }
            
            else if(getStatus() == 'u'){ //  if undergraduated student

                getline(inFile, str);
                UndergraduateStudent anUndergraduate = UndergraduateStudent(str);
                 
                MemberLists.push_back(anUndergraduate);
                      
            }
            
            else if(getStatus() == 'g'){ //  if graduated student

                getline(inFile, str);
                GraduateStudent aGraduated = GraduateStudent(str);

                MemberLists.push_back(aGraduated);
            }

            else{
                throw "Undefined Status simbol!";
            }
          
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
 */
int Member::searchIndexOfVector(vector<Member> _Members, string _id)
{
    try
    {
        for (int i = 0; i < _Members.size(); i++)
        {                                                //  search
            if (!_Members[i].getIdNumber().compare(_id)) //  check the validity of_inputID. ==> if(same)
                return i;

            else //  there is no such ID!
                throw "No SUCH ID! Please check your ID again.";
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}