#include "ImprovementRequest.h"
#include <iostream>
#include <string>

using namespace std;

ImprovementRequest::ImprovementRequest() {}

int Request::ifRequest()
{
    char ifRe;
    cout << "기능개선을 요청하려면 y, 취소하려면 n를 입력해주세요: ";
    cin >> ifRe;

    if (ifRe == 'y')
        return 1;
    else if (ifRe == 'n')
        return 0;
    else
        throw "입력이 잘못되었습니다.";
}

void ImprovementRequest::InputOpinion(string _Opinions[])
{
    if (ifRequest())
    {
        string Opinion;
        cout << "의견을 입력해주세요: ";
        cin >> Opinion;

        if (Opinion.empty())
        {
            throw "의견이 입력되지 않았습니다.";
        }
        else
        {
            _Opinions[OpinionNumber++] = Opinion;
            cout << "요청 등록이 완료되었습니다. thank you" << endl;
        }
    }
}