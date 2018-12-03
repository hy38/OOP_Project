#include "Request.h"
#include <iostream>
#include <string>

using namespace std;

Request::Request(){}

bool Request::ifRequest(){
    int select;
    cout << "신청 목록을 선택해 주십시오" << endl;
    cout << "1. 휴학신청 2. classroom 예약신청 3. 교수면담신청" << endl;
    cin>>select;
    
    if (select !=1 && select !=2 && select !=3)
        throw "신청 목록에 맞게 번호를 입력해주세요.";
    return select;
    // cout << "if you want to send a Requestion? (Y or N) : ";
    // cin>>ifRequest;
    // if(ifRequest == 'Y'){
    //     return true;
    // }
    // else if (ifRequest == 'N'){
    //     return false;
    // }
    // else{
    //     throw "input is discorrect";
    // } 
} 

void Request::addRequest(string _questionList[], int _questionNumber){
    if (ifRequest()){    // ifRequest is true
        string text;
        cout << "input your requestion: ";
        cin>>text;
        
        if (text.empty()){
            throw "input value is empty";
        }
        else{
            _questionList[_questionNumber] = text;
        }
    }
    else{
        return;
    }
}
