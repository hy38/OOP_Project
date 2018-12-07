#ifndef CERTIFICATEISSUING_H
#define CERTIFICATEISSUING_H
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"

using namespace std;

class CertificateIssuing
{

  public:
    CertificateIssuing();
    void printAll(UndergraduateStudent _Member);
    void printAll(GraduateStudent _Member);
};

#endif