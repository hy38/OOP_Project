#ifndef LOGIN_H
#define LOGIN_H
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
    Login(vector<Member> _Member);
    //  constructor

    string getInputID();
    string getInputPassword();
    bool getsuccessIdentifying();
    //  getter

    void setInputID(string _ID);
    void setInputPassword(string _password);
    void setsuccessIdentifying(bool); 
    //  setter : need??

    void setMemberStatus(string _inputID);    //  gets the first character of ID

    Member getIdentify(vector<Member>);  //  gets userInput ID/PW's to confirm with the ones in Member's database

    int search(string _inputID);    //  searches the Member's ID and returns the ID's password

};
#endif