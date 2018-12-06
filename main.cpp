#include "SizeInfo.h"
#include "Member.h"
#include "Professor.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "Student.h"
#include "Login.h"
// #include "Request.h"
// #include "ClassroomRentRequest.h"
// #include "ImprovementRequest.h"
// #include "ConsultingRequest.h"
// #include "CertificateIssuing.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

// struct Rooms
// {
// 	int classroom;
// 	string bookMember;
// 	bool isBooked;
// };
// struct Rooms RoomArray[ROOM_ARRAY_SIZE];

int main()
{
	int select = 0;

	vector<UndergraduateStudent> UndergraduateStudentLists;
	vector<GraduateStudent> GraduateStudentLists;
	vector<Professor> ProfessorLists;

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
				ProfessorLists.push_back(aProfessor);
			}

			else if (a.getStatus() == 'u')
			{ //  if undergraduated student
				getline(inFile, str);
				UndergraduateStudent anUndergraduate = UndergraduateStudent(str);
				anUndergraduate.setIdNumber(a.getIdNumber());
				anUndergraduate.setStatus(a.getStatus());
				UndergraduateStudentLists.push_back(anUndergraduate);
			}

			else if (a.getStatus() == 'g')
			{ //  if graduated student

				getline(inFile, str);
				GraduateStudent aGraduated = GraduateStudent(str);
				aGraduated.setIdNumber(a.getIdNumber());
				aGraduated.setStatus(a.getStatus());
				GraduateStudentLists.push_back(aGraduated);
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

	// for(int i=0; i<UndergraduateStudentLists.size(); i++){
	// 	cout << UndergraduateStudentLists[i].getIdNumber() << endl;
	// 	cout << UndergraduateStudentLists[i].getPassword() << endl;
	// 	cout << UndergraduateStudentLists[i].getSemester() << endl;
	// 	cout << UndergraduateStudentLists[i].getMajor() << endl;
	// 	cout << UndergraduateStudentLists[i].getStatus() << endl;
	// 	UndergraduateStudentLists[i].getGrades();
	// }
	// for(int i=0; i<GraduateStudentLists.size(); i++){
	// 	cout << GraduateStudentLists[i].getIdNumber() << endl;
	// 	cout << GraduateStudentLists[i].getPassword() << endl;
	// 	cout << GraduateStudentLists[i].getSemester() << endl;
	// 	cout << GraduateStudentLists[i].getMajor() << endl;
	// 	cout << GraduateStudentLists[i].getStatus() << endl;
	// 	GraduateStudentLists[i].getGrades();
	// }

	// for(int i=0; i<ProfessorLists.size(); i++){
	// 	cout << ProfessorLists[i].getIdNumber() << endl;
	// 	cout << ProfessorLists[i].getPassword() << endl;
	// 	cout << ProfessorLists[i].getMajor() << endl;
	// 	cout << ProfessorLists[i].getStatus() << endl;
	// }
	

	Login anObject = Login(/* MemberLists */);
	//    ClassroomRentRequest cRent = ClassroomRentRequest(RoomArray);
	//    ImprovementRequest improvement = ImprovementRequest();
	//    Request aRequest = Request();
	//    ConsultingRequest consult = ConsultingRequest();
	//    CertificateIssuing certificate = CertificateIssuing();
	if (anObject.getStatus() == 'u')
	{
		select = 1;
	}
	else if (anObject.getStatus() == 'g')
	{
		select = 2;
	}
	else if (anObject.getStatus() == 'p')
	{
		select = 3;
	}
	else
	{
		// Member user = Member();
		cout << "Login failed!" << endl;
		exit(0);
	}

	switch (select)
	{
	case 1: //   Undergrdaduate
	{
		UndergraduateStudent user = anObject.getIdentify(UndergraduateStudentLists);

		system("clear");
		while (1)
		{
			system("clear");
			cout << "your ID is :" << user.getIdNumber() << endl;
			cout << "학생 계정 입니다.\n[1.Grade Information] [2.Request] [3.Exit]" << endl;
			cin >> select;
			if (select == 1) //   Student Information
			{
				system("clear");
				cout << "[Grade Information Menu]" << endl;
				cout << "your ID is :" << user.getIdNumber() << endl;
				cout << "your grade is :" << endl;
				//   Implement!!!!   cout << grades.showGrade();   //   iterates all grade struct members

				/* pause */
				cout << "Press enter to continue...";
				cin.ignore(); // ignores the newline
				cin.get();	//waits for character
			}
			else if (select == 2) //   Request
			{
				system("clear");
				cout << "[Request Menu for]" << endl;
				//       select = aRequest.ifRequest();
				// cout << "[1.ClassroomRent] [2.Improvement] [3.Professor Consulting] [4.Certificate] [5.Go Back]" << endl;
				// cin >> select;
				if (select == 1)
				{
					// cRent.
				}
				else if (select == 2)
				{
					// improvement.InputOpinion();
					// improvement.
				}
				else if (select == 3)
				{
					// consult.
				}
				else if (select == 4)
				{
					// certificate.
				}
				else
					break;
				/* pause */
				cout << "Press enter to continue...";
				cin.ignore(); // ignores the newline
				cin.get();	//waits for character
			}
			else //	exit
				break;
		}
		break;
	}
	case 2: //   Graduate
	{
		GraduateStudent user = anObject.getIdentify(GraduateStudentLists);

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
	}
	case 3: //   Professor
	{
			Professor user = anObject.getIdentify(ProfessorLists);

			system("clear");
			while (1)
			{
				system("clear");

				cout << "교수 계정 입니다.\n[1.Classroom Rent] [2.Input Grade] [3.Exit]" << endl;
				cin >> select;
				if (select == 1)
				{
					cout << "select : 1" << endl;

					/* pause */
					cout << "Press enter to continue...";
					cin.ignore(); // ignores the newline
					cin.get();	//waits for character

					// cRent.
				}
				else if (select == 2)
				{
					string tempString;
					cout << "성적을 입력할 studentID를 입력하시오 :" << endl;
					cin >> tempString;
					if (tempString.at(0) == 'u'){
						user.setStudentGrade(UndergraduateStudentLists, tempString);
					}
					else{
						user.setStudentGrade(GraduateStudentLists, tempString);
					}
					
					/* pause */
					cout << "Press enter to continue...";
					cin.ignore(); // ignores the newline
					cin.get();	//waits for character
				}
				else
					break;
			}
			// break;
		
	}
	default:
		break;
	}
	system("clear");
}
