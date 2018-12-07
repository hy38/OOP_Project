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
        cin >> select;

        if (select > 4 || 0 >= select)
            throw "신청 목록에 맞게 번호를 입력해주세요.";
        system("clear");
        return select;
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        return 0;
    }
}
