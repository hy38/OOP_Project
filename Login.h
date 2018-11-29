#ifndef LOGIN_h
#define LOGIN_h
#include <iostream>
#include "Member.h"

using namespace std;

class Login : public Member
{
  private:
    string inputID;
    string inputPassword;
    bool success;

  public:
    Login(string _ID, string _PW)
    {

        // inputID = _ID;
        // inputPassword = _PW;
    } //  constructor

    string getID() { return inputID; }
    string getPassword() { return inputPassword; }
    //  getter

    void setID(string _ID);
    void setPassword(string _password);
    //  setter : need??

    void Login::setStatus(){}    //  gets the first character of ID

    bool Login::getIdentify(string _inputID, string _inputPassword){}   //  gets userInput ID/PW's to confirm with the ones in Member's database

    string Login::search(){}    //  searches the Member's ID and returns the ID's password


};
#endif