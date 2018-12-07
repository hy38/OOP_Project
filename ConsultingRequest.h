#ifndef CONSULTINGREQUEST_H
#define CONSULTINGREQUEST_H
#include "Request.h"
#include "Professor.h"
#include "UndergraduateStudent.h"

using namespace std;

class ConsultingRequest : public Request
{
private:
  vector<Professor> professorList;

public:
  ConsultingRequest(vector<Professor> _Members);
  int ifRequest();
  void printProfessorInfo(Professor _consultedProfessor);
  vector<Professor> getProfessorList();
};

#endif