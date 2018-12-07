#ifndef IMPROVEMENTREQUEST_H
#define IMPROVEMENTREQUEST_H
#include "Request.h"
#include "SizeInfo.h"
#include <stdlib.h>
#include <string>

class ImprovementRequest : public Request
{
  private:
    string opinions[REQUEST_LIST_SIZE];

  public:
    ImprovementRequest(string _opinions[]);
    int ifRequest();
    void inputOpinion();
    void printOpinions();
    int getOpinionNumber();
};

#endif