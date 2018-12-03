#ifndef LEAVEREQUEST_H
#define LEAVEREQUEST_H
#include "Member.h"
#include <string>

class LeaveRequest : public Member {

    private:
        string RequestList[];   // 신청을 받는다면 main에서 저장할지? 아니면 member들의 질문 리스트로 가질 지.
        
    public:
        LeaveRequest();
        void addRequest(string _questionList[], int _questionNumber);
        bool ifRequest();
}; 

#endif