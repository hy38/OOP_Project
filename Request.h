#ifndef REQUEST_H
#define REQUEST_H
#include "Member.h"
#include <string>

using namespace std;

class Request : public Member {

    private:
        string RequestList[0];   // 신청을 받는다면 main에서 저장할지? 아니면 member들의 질문 리스트로 가질 지.
        
    public:
        Request();
        int ifRequest();
        int ifRequest(Member _bookingMember) {};    // will override in classroomRent
};

#endif