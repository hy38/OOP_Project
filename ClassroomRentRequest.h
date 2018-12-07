#ifndef CLASSROOMRENTREQUEST_H
#define CLASSROOMRENTREQUEST_H
#include "Request.h"
#include "Member.h"
#include "SizeInfo.h"
#include <string>
#include <stdlib.h>

using namespace std;

struct Rooms
{
    int classroom;
    string bookMember; //   member who booked
    bool isBooked;
};

class ClassroomRentRequest : public Request
{
  private:
    Rooms classroom[CLASSROOM_SIZE];

  public:
    ClassroomRentRequest(Rooms _classroom[]);
    int ifRequest();
    void ifRequest(Member _bookingMember);
    void setClassroomBooked(Member _member, int _roomNumber);
    bool getClassroomBooked(int _roomNumber);
    void setPracticalRoomBooked(Member _member, int _roomNumber);
    bool getPracticalRoomBooked(int _roomNumber);
    void printAllRooms(Rooms _classrooms[]);
};

#endif