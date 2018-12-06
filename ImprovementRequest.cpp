#include "ImprovementRequest.h"
#include <iostream>

using namespace std;

ImprovementRequest::ImprovementRequest(string _opinions[])
{
    try
    {
        if (_opinions == NULL)
        {
            throw "improvementRequestList pashing error";
        }
        else
            opinions[0] = _opinions[0]; //main문의 requestlist을 가져올 수 있는지?
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

int ImprovementRequest::ifRequest()
{
    try
    {
        char ifRe;
        cout << "기능개선을 요청하려면 y, 취소하려면 n를 입력해주세요: ";
        cin >> ifRe;

        if (ifRe == 'y')
            return 1;
        else if (ifRe == 'n')
            return 0;
        else
            throw "기능개선요청 여부입력이 잘못되었습니다.";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

void ImprovementRequest::inputOpinion()
{
    try
    {
        if (ifRequest())
        {
            system("clear");
            string Opinion;
            cout << "의견을 입력해주세요: ";
            cin >> Opinion;

            if (Opinion.empty())
            {
                throw "의견이 입력되지 않았습니다.";
            }
            else
            {
                opinions[getOpinionNumber()] = Opinion;
                cout << "요청 등록이 완료되었습니다." << endl;
            }
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

int ImprovementRequest::getOpinionNumber()
{
    try
    {
        if (opinions == NULL)
        {
            throw "기능개선요청 리스트가 비어있어 인덱스를 가져올 수 없습니다.";
        }
        else{
            int index = 0;
            while (!(opinions[index].empty())){
                index++;
            }
            return index;
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

void ImprovementRequest::printOpinions()
{
    try
    {
        if (opinions == NULL)
        {
            throw "기능개선요청 리스트가 비어있어 출력이 불가능합니다.";
        }
        else
        {
            for (int i = 0; i < getOpinionNumber(); i++)
            {
                cout << "----- Opinion list -----" << endl;
                cout << i << ". " << opinions[i] << endl;
            }
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}
