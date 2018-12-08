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
        string ifRe;
        cout << "기능개선을 요청하려면 1번, 기능개선요청 리스트를 보려면 2번을 입력해주세요: ";

        cin >> ifRe;
        if (ifRe == "1")
            return 1;
        else if (ifRe == "2")
            return 2;
        else
            throw "기능개선요청 여부입력이 잘못되었습니다.";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        return 0;
    }
    catch (string msg){
        cerr << msg << endl;
        return 0;
    }
}

void ImprovementRequest::inputOpinion()
{
    try
    {
        int ifQuestorPrint = (int)ifRequest();
        if (ifQuestorPrint == 1)
        {
            system("clear");
            string Opinion;
            cout << "의견을 입력해주세요: ";
            cin.ignore(256,'\n');
            getline(cin, Opinion);

            if (Opinion == "")
            {
                throw "의견이 입력되지 않았습니다.";
            }
            else if (Opinion != "")
            {
                opinions[getOpinionNumber()] = Opinion;
                cout << "요청 등록이 완료되었습니다." << endl;
            }
            
        }
        else if (ifQuestorPrint == 2)
        {
            printOpinions();
        }
        else
            throw "입력에 오류가 발생하였습니다.";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        return;
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
        else
        {
            int index = 0;
            while (!(opinions[index].empty()))
            {
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
            cout << "-------- Opinion list --------" << endl;
            for (int i = 0; i < getOpinionNumber(); i++)
            {
                cout << i << ". " << opinions[i] << endl;
            }
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        return;
    }
}
