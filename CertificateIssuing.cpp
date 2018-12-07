#include "CertificateIssuing.h"
#include <iostream>
#include <string>

using namespace std;

CertificateIssuing::CertificateIssuing(){}

void CertificateIssuing::printAll(UndergraduateStudent _Member){
    cout.fill(' ');
    cout << "             " << "재  학  증  명  서" << endl;
    cout << "   " << "학  번 : " << _Member.getIdNumber() << endl;
    cout << "   " << "대 학 교 :  충 남 대 학 교" << endl;
    cout << "   "  << "전 공 : " << _Member.getMajor() << endl;
    cout << "   "  << "학 기 : " << _Member.getSemester() << endl;
    cout << endl << endl << "           " <<"위 사실을 증명함" << endl;
    cout << endl << "           " << "2018년  12월  7일" << endl << endl;
}

void CertificateIssuing::printAll(GraduateStudent _Member){
    cout.fill(' ');
    cout << "             " << "재  학  증  명  서" << endl;
    cout << "   " << "학  번 : " << _Member.getIdNumber() << endl;
    cout << "   " << "대 학 교 :  충 남 대 학 교" << endl;
    cout << "   "  << "전 공 : " << _Member.getMajor() << endl;
    cout << "   "  << "학 기 : " << _Member.getSemester() << endl;
    cout << endl << endl << "           " <<"위 사실을 증명함" << endl;
    cout << endl << "           " << "2018년  12월  7일" << endl << endl;
}

