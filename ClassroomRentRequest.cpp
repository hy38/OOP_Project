#include "ClassroomRentRequest.h"
#include <iostream>

using namespace std;

ClassroomRentRequest::ClassroomRentRequest(Rooms _classRoom[])
{
    try
    {
        if (_classRoom == NULL)
        {
            throw "classRoom pashing error";
        }
        else{
            classroom[0] = _classRoom[0]; //main문의 강의실을 가져올 수 있는지?
        }
        for (int i = 0; i<CLASSROOM_SIZE; i++){
            classroom[i].classroom = i+100;
            classroom[i].isBooked = false;
            classroom[i].bookMember = "";
        }

    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

int ClassroomRentRequest::ifRequest() 
{
    try
    {
        char ifRe;
        cout << "강의실을 예약하시려면 y, 취소하려면 n을 입력해주세요: ";
        cin >> ifRe;
        
        if (ifRe == 'y')
            return 1;
        else if (ifRe == 'n')
            return 0;
        else
            throw "강의실 예약요청 여부입력이 잘못되었습니다.";
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

void ClassroomRentRequest::ifRequest(Member _bookingMember)
{
    try
    {
        if (ifRequest())
        {
            system("clear");
            printAllRooms(classroom);
            int roomNumber;
            cout << "예약할 강의실 호 수를 입력해주세요:"; // 100~104 is classroom, 105~108 is practicalroom
            cin >> roomNumber;

            if ((roomNumber >= 100) && (roomNumber <= 108))
            {
                if (roomNumber < 105)
                {
                    setClassroomBooked(_bookingMember, roomNumber);
                }
                else
                    setPracticalRoomBooked(_bookingMember, roomNumber);
            }
            else
            {
                throw "강의실 호 수 입력이 잘못되었습니다.";
            }
        }
    }
    catch (char const *msg)
    {
        cerr << msg << endl;
        exit(0);
    }
}

void ClassroomRentRequest::setClassroomBooked(Member _member, int _roomNumber)
{
    system("clear");
    if (classroom[_roomNumber - 100].isBooked)
    { // 102 classroom is loaded at classroom[1]
        cout << "강의실이 이미 예약되어있습니다." << endl;
    }
    else
    {
        classroom[_roomNumber - 100].bookMember = _member.getIdNumber();
        classroom[_roomNumber - 100].isBooked = true;
        cout << _roomNumber << "호 강의실 예약이 완료되었습니다." << endl;
    }
}

void ClassroomRentRequest::setPracticalRoomBooked(Member _member, int _roomNumber)
{
    system("clear");
    if (_member.getStatus() != 'p')
    {
        cout << "교수님 이외에는 실습실 예약이 불가능합니다." << endl;
    }
    else
    {
        if (classroom[_roomNumber - 100].isBooked)
        {
            cout << "강의실이 이미 예약되어있습니다." << endl;
        }
        else
        {
            classroom[_roomNumber - 100].bookMember = _member.getIdNumber();
            classroom[_roomNumber - 100].isBooked = true;
            cout <<  _roomNumber << "호 강의실 예약이 완료되었습니다." << endl;
        }
    }
}

void ClassroomRentRequest::printAllRooms(Rooms _classrooms[]){
    cout << "----- current classroom booking information -----"<< endl;
    cout << "classroom      " << "isBooked       " << "bookedMemberID" << endl;
    string isBooked;
    for(int i = 0; i<CLASSROOM_SIZE; i++){
        if (_classrooms[i].isBooked){
            isBooked = "booked";
        }
        else{
            isBooked = "not booked";
        }
        if (i == 5)
            cout << "---- practical Room ------";
        cout << "   "<<_classrooms[i].classroom << "         " << 
        isBooked << "       " << _classrooms[i].bookMember << endl;
    }
}