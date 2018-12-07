#include <iostream>
#include "Login.h"

using namespace std;

Login::Login()
{
    cout << "ID :";
    cin >> inputID;
    cout << "Password :";
    cin >> inputPassword;
    setStatus(inputID.at(0));
} //  constructor

string Login::getInputID() { return inputID; }
string Login::getInputPassword() { return inputPassword; }

UndergraduateStudent Login::getIdentify(vector<UndergraduateStudent> _Member)
{ //  gets userInput ID/PW's to compare with the ones in Member's database
    UndergraduateStudent temp;
    int index = temp.searchIndexOfVector(_Member, getInputID());
    try
    {
        if (!_Member[index].getPassword().compare(inputPassword))
        {
            return _Member[index];
        }
        else
            throw "Password disMatch!";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}
GraduateStudent Login::getIdentify(vector<GraduateStudent> _Member)
{ //  gets userInput ID/PW's to compare with the ones in Member's database
    GraduateStudent temp;
    int index = temp.searchIndexOfVector(_Member, getInputID());
    try
    {
        if (!_Member[index].getPassword().compare(inputPassword))
        {
            return _Member[index];
        }
        else
            throw "Password disMatch!";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}
Professor Login::getIdentify(vector<Professor> _Member)
{ //  gets userInput ID/PW's to compare with the ones in Member's database
    Professor temp;
    int index = temp.searchIndexOfVector(_Member, getInputID());
    try
    {
        if (!_Member[index].getPassword().compare(inputPassword))
        {
            return _Member[index];
        }
        else
            throw "Password disMatch!";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}
//  getter

void Login::setInputID(string _idNumber) { inputID = _idNumber; }
void Login::setInputPassword(string _password) { inputPassword = _password; }
//  setter
