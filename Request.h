#ifndef REQUEST_H
#define REQUEST_H
#include "Member.h"
#include <string>

using namespace std;

class Request : public Member {
    public:
        Request();
        int ifRequest();
};

#endif