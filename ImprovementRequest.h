#ifndef IMPROVEMENTREQUEST_H
#define IMPROVEMENTREQUEST_H
#include "Request.h"
#include <string>

class ImprovementRequest : public Request{
    private:
        string Opinions[];      // 신청을 받는다면 main에서 저장할지? 아니면 member들의 질문 리스트로 가질 지.
        int OpinionNumber=0;    // 개선요청 의견 개수

    public:
        ImprovementRequest();
        int ifRequest();
        void InputOpinion(string _opinions[]);
};

#endif