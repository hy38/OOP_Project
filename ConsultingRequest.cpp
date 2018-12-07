#include "ConsultingRequest.h"
#include <iostream>
#include <string>

using namespace std;

ConsultingRequest::ConsultingRequest(vector<Professor> _Members){
    professorList = _Members;
 }

int ConsultingRequest::ifRequest(){
    string _IdNumber;
    cout << "상담하고싶은 교수님의 ID를 입력해주세요: ";
    cin>>_IdNumber;
    int index = professorList[0].searchIndexOfVector(professorList,_IdNumber);
    // search professor
    if (professorList[index].getSchedule()){
        professorList[index].setSchedule(!professorList[index].getSchedule());
        cout << "상담 신청이 완료되었습니다." << endl;
        printProfessorInfo(professorList[index]);
    }
    else{
        cout << "교수님이 바빠 상담 신청이 불가능합니다." << endl;
    }
}

vector<Professor> ConsultingRequest::getProfessorList() { return professorList;}    

void ConsultingRequest::printProfessorInfo(Professor _consultedProfessor){
    cout << "교수님 ID: " << _consultedProfessor.getIdNumber() << endl ;
    if (!_consultedProfessor.getSchedule())
        cout << "상담신청이 예약됨." << endl;
}


