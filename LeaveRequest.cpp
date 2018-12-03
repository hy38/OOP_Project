#include "LeaveRequest.h"
#include <iostream>
#include <string>

using namespace std;

LeaveRequest::LeaveRequest(){}

bool LeaveRequest::ifRequest(){
    char ifRequest;
    cout << "if you want to send a Requestion? (Y or N) : ";
    cin>>ifRequest;
    if(ifRequest == 'Y'){
        return true;
    }
    else if (ifRequest == 'N'){
        return false;
    }
    else{
        throw "input is discorrect";
    } 
}

void LeaveRequest::addRequest(string _questionList[], int _questionNumber){
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