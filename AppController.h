#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H
#include "SizeInfo.h"
#include "Member.h"
#include "Professor.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "Student.h"
#include "Login.h"
#include "Request.h"
#include "ClassroomRentRequest.h"
#include "ImprovementRequest.h"
#include "ConsultingRequest.h"
#include "CertificateIssuing.h"

class AppController {
    public:
        AppController();
        void runProject();
};

#endif