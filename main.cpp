#include "Member.h"
#include "Professor.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "Student.h"
#include "Login.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Rooms
{
	int classroom;
	bool isBooked;
};

int main()
{
	// Member admin = Member(); //  Member tjsdjsgkdu epdlxj dlqfur gn ahems ekdma wkrdjq tlfgod! tjsrufwhrjsdla
	// vector<Member> dataVector = admin.saveFileData("datafile.csv");
	int select = 0;

	vector<Member> MemberLists;

	fstream inFile;
	inFile.open("datafile.csv"); //  file open exception handle NEED!
	string str;
	Member a = Member();
	getline(inFile, str); //  Not Taking the First Line
	while (!inFile.eof())
	{ //  WHILE EOF convert NEED!
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
				// exit(0);
			}

		} //  try end
		catch (char const *msg)
		{
			cerr << msg << endl;
			exit(0);
		}
	} //  for end
	inFile.close();

	Login anObject = Login(/* MemberLists */);
	Member user = anObject.getIdentify(MemberLists);
	// user = dataVector[anObject.getIdentify(dataVector)]; if getIdentiry return int

	cout << "Login Successful! you are a '" << user.getStatus() << "'!" << endl;
	cout << "[1.student] [2.graduate] [3.Professor]" << endl;
	if (user.getStatus() == 'u')
	{
		select = 1;
	}
	else if (user.getStatus() == 'g')
		select = 2;
	else
		select = 3;
	while (select != 4)
	{
		switch (select)
		{
		case 1:

			system("clear");
			while (1)
			{
				system("clear");
				cout << "검색 메뉴 입니다.\n[1.] [2.이름 검색] [3.뒤로가기]\n"
					 << endl;
				cin >> select;
				if (select == 1)
				{
					system("clear");
					cout << "-------------- [내림차순 정렬] --------------\n"
						 << endl;
					system("pause");
				}
				else if (select == 2)
				{
					system("clear");
					cout << "-------------- [이름 검색] -------------\n"
						 << endl;
					cout << "검색할 이름 입력 : " << endl;
					system("pause");
				}
				else
					break;
			}
			break;
		case 2:

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
		case 3:
			system("clear");
			cout << "삭제 메뉴 입니다.\n"
				 << endl;

			cout << "삭제할 학번을 입력 : " << endl;

			break;
		default:
			break;
		}
		system("clear");
	}
}
