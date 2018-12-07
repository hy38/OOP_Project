#include "CertificateIssuing.h"
#include <iostream>
#include <string>

using namespace std;

CertificateIssuing::CertificateIssuing(){}

void CertificateIssuing::printAll(UndergraduateStudent _Member){
    cout.fill(' ');
    cout << cout.width(10) << "재 학 증 명 서" << endl;
    cout << cout.width(4) << "학     번: " << _Member.getIdNumber() << endl;
    cout << cout.width(4) << "대 학  교:  충 남 대 학 교" << endl;
    cout << cout.width(4) << "전	 공: " << _Member.getMajor() << endl;
}