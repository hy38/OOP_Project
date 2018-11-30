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
    bool successIdentifying;

  public:
    Login(string _ID, string _PW){}
    //  constructor

    string getInputID();
    string getInputPassword();
    bool getsuccessIdentifying();
    //  getter

    void setInputID(string _ID);
    void setInputPassword(string _password);
    void setsuccessIdentifying(bool); 
    //  setter : need??

    void Login::setMemberStatus(string _inputID);    //  gets the first character of ID

    bool Login::getIdentify(string _inputID, string _inputPassword);  //  gets userInput ID/PW's to confirm with the ones in Member's database

    int Login::search(string _inputID);    //  searches the Member's ID and returns the ID's password

};
#endif