#ifndef IMPROVEMENTREQUEST_H
#define IMPROVEMENTREQUEST_H
#include "Request.h"
#include "SizeInfo.h"
#include <stdlib.h>
#include <string>

class ImprovementRequest : public Request{
    private:
        string opinions[REQUEST_LIST_SIZE];      // 신청을 받는다면 main에서 저장할지? 아니면 member들의 질문 리스트로 가질 지.

    public:
        ImprovementRequest(string _opinions[]);
        int ifRequest();
        void inputOpinion();
        void printOpinions();
        int getOpinionNumber();
};

#endif