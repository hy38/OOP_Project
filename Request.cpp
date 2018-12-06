#include "Request.h"
#include <iostream>
#include <string>

using namespace std;

Request::Request() {}

int Request::ifRequest()
{
    int select;
    try
    {
        cout << "신청하실 번호를 입력해 주세요." << endl;
        cout << "1. classroom 예약신청 2. 교수면담신청 3. 기능개선요청" << endl;
        cin >> select;

        if (select != 1 && select != 2 && select != 3)
            throw "신청 목록에 맞게 번호를 입력해주세요.";
        return select;
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}
