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
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#define ARRAY_SIZE 5
using namespace std;

struct Rooms
{
	int classroom;
	string bookMember;
	bool isBooked;
};	struct Rooms RoomArray[ARRAY_SIZE];

int main()
{
	int select = 0;

	vector<Member> MemberLists;

	fstream inFile;
	inFile.open("datafile.csv"); //  file open exception handle NEED!
	string str;
	Member a = Member();
	getline(inFile, str); //  Not Taking the First Line
	while (!inFile.eof())
	{
		try
		{
			getline(inFile, str, ','); //  idNumber : string
			a.setIdNumber(str);		   //  put parsed string into idNumber
			a.setStatus(str.at(0));
			/* getStatus works properly because we setted the status while login. */
			if (a.getStatus() == 'p')
			{ //  if professor
				getline(inFile, str);
				Professor aProfessor = Professor(str); //  gives rest of the string of 'str' to the constructor of Professor
				aProfessor.setIdNumber(a.getIdNumber());
				aProfessor.setStatus(a.getStatus());
				MemberLists.push_back(aProfessor);
			}

			else if (a.getStatus() == 'u')
			{ //  if undergraduated student
				getline(inFile, str);
				UndergraduateStudent anUndergraduate = UndergraduateStudent(str);
				anUndergraduate.setIdNumber(a.getIdNumber());
				anUndergraduate.setStatus(a.getStatus());
				MemberLists.push_back(anUndergraduate);
			}

			else if (a.getStatus() == 'g')
			{ //  if graduated student

				getline(inFile, str);
				GraduateStudent aGraduated = GraduateStudent(str);
				aGraduated.setIdNumber(a.getIdNumber());
				aGraduated.setStatus(a.getStatus());
				MemberLists.push_back(aGraduated);
			}
			else
			{
				throw "Undefined Status simbol!";
			}

		} //  try end
		catch (char const *msg)
		{
			cerr << msg << endl;
			exit(0);
		}
	} //  while end
	inFile.close();


	Login anObject = Login(/* MemberLists */);
	Member user = anObject.getIdentify(MemberLists);
	ClassroomRentRequest cRent = ClassroomRentRequest(RoomArray);
	ImprovementRequest improvement = ImprovementRequest();
	Request aRequest = Request();
	ConsultingRequest consult = ConsultingRequest();
	CertificateIssuing certificate = CertificateIssuing();
	
	if (user.getStatus() == 'u')
		select = 1;
	else if (user.getStatus() == 'g')
		select = 2;
	else
		select = 3;

	while (select != 4)
	{
		switch (select)
		{
		case 1:	//	Undergrdaduate

			system("clear");
			while (1)
			{
				system("clear");
				cout << "학생 계정 입니다.\n[1.Grade Information] [2.Request] [3.뒤로가기]\n"
					 << endl;
				cin >> select;
				if (select == 1)	//	Student Information
				{
					system("clear");
					cout << "[Grade Information Menu]\n" << endl;
					cout << "your ID is :" << user.getIdNumber() << endl;
					cout << "your grade is :" << endl;
//	Implement!!!!	cout << grades.showGrade();	//	iterates all grade struct members
					system("pause");
				}
				else if (select == 2)	//	Request
				{
					system("clear");
					cout <<  "[Request Menu for]\n" << endl;
					select = aRequest.ifRequest();
					// cout << "[1.ClassroomRent] [2.Improvement] [3.Professor Consulting] [4.Certificate] [5.Go Back]" << endl;
					// cin >> select;
					if(select == 1){
						// cRent.
					}
					else if(select == 2){
						// improvement.InputOpinion();
						// improvement.
					}
					else if(select == 3){
						// consult.
					}
					else if(select == 4){
						// certificate.
					}
					else
						break;
					system("pause");
				}
				else
					break;
			}
			break;
		case 2:	//	Graduate

			system("clear");
			while (1)
			{
				system("clear");
				cout << "추가 및 변경 메뉴 입니다.\n[1.학생 추가] [2.학점 변경] [3.뒤로가기]\n"
					 << endl;
				cin >> select;
				if (select == 1)
				{
					system("clear");
					cout << "-------------- [학생 추가] --------------\n"
						 << endl;
				}
				else if (select == 2)
				{
					system("clear");
					cout << "-------------- [학점 변경] -------------\n"
						 << endl;
					cout << "변경할 학생 학번 입력 : " << endl;
				}
				else
					break;
			}
			break;
		case 3:	//	Professor
			system("clear");
			cout << "교수 계정 입니다.\n[1.Classroom Rent] [2.Input Grade]" << endl;
			cin >> select;
			if(select == 1){
				// cRent.
			}
			else if(select == 2){
				// user.
			}
			else
				break;

			// break;
		default:
			break;
		}
		system("clear");
	}
}
