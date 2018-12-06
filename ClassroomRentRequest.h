#ifndef CLASSROOMRENTREQUEST_H
#define CLASSROOMRENTREQUEST_H
#include "Request.h"
#include "Member.h";

using namespace std;

struct Rooms{
    int classroom;
    string bookMember;      // booked membersId
    bool isBooked;
};

class ClassroomRentRequest : public Request{
    private:
        Rooms classroom[];

    public:
        ClassroomRentRequest(Rooms _classroom[]);   // 객체가 생성될 때, main으로부터 값을 받아오기.
        int ifRequest();
        int ifRequest(Member _bookingMember);
        void setClassroomBooked(Member _member, int _roomNumber);
        bool getClassroomBooked(int _roomNumber);
        void setPracticalRoomBooked(Member _member, int _roomNumber);
        bool getPracticalRoomBooked(int _roomNumber);
        void printAllRooms(Rooms _rooms);
};

#endif