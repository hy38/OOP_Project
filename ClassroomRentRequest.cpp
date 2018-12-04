#include "ClassroomRentRequest.h"
#include <iostream>
#include <string>

using namespace std;

ClassroomRentRequest::ClassroomRentRequest(Rooms _classRoom[]) {
    classroom[0] = _classRoom[0];   //main문의 강의실을 가져올 수 있는지?

}

int ClassroomRentRequest::ifRequest(Member _bookingMember)
{
    int roomNumber;
    cout << "예약할 강의실 호 수를 입력해주세요:";  // 100~104 is classroom, 105~108 is practicalroom
    cin >> roomNumber;

    if ((roomNumber >= 100) && (roomNumber <= 108))
    {
        if (roomNumber < 105){
            setClassroomBooked(_bookingMember,roomNumber);
        }
        else
            SetPracticalRoomBooked(_bookingMember, roomNumber);
    }
    else
    {
        throw "강의실 호 수 입력이 잘못되었습니다.";
    }
}

void ClassroomRentRequest::setClassroomBooked(Member _member, int _roomNumber)
{
    if (classroom[_roomNumber-100].isBooked){
        cout << "강의실이 이미 예약되어있습니다." << endl;
    }
    else{
        
    }
}

void ClassroomRentRequest::SetPracticalRoomBooked(Member _member, int _roomNumber){

}