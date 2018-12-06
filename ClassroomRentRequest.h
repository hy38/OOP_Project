#ifndef CLASSROOMRENTREQUEST_H
#define CLASSROOMRENTREQUEST_H
#include "Request.h"

using namespace std;

struct Rooms{
    int classroom;
    Member bookMember;
    bool isBooked;
};

class ClassroomRentRequest : public Request{
    private:
        Rooms classroom[];

    public:
        ClassroomRentRequest(Rooms _classroom[]);
        int ifRequest(Member _bookingMember);
        void setClassroomBooked(Member _member, int _roomNumber);
        bool getClassroomBooked(int _roomNumber);
        void SetPracticalRoomBooked(Member _member, int _roomNumber);
        bool getPracticalRoomBooked(int _roomNumber);
        void printAllRooms(Rooms _rooms);

};

#endif