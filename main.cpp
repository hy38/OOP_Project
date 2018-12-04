#include <iostream>
#include "Member.h"
#include "Professor.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "Student.h"
#include "Login.h"
#include <vector>
#include <fstream>
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
	for (int i = 0; i < 4; i++)
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
				aProfessor.setIdNumber(str);
				MemberLists.push_back(aProfessor);
			}

			else if (a.getStatus() == 'u')
			{ //  if undergraduated student

				getline(inFile, str);
				UndergraduateStudent anUndergraduate = UndergraduateStudent(str);
				anUndergraduate.setIdNumber(str);
				MemberLists.push_back(anUndergraduate);
			}

			else if (a.getStatus() == 'g')
			{ //  if graduated student

				getline(inFile, str);
				GraduateStudent aGraduated = GraduateStudent(str);
				aGraduated.setIdNumber(str);
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
			// exit(0);
		}
	} //  for end
	inFile.close();

	Login anObject = Login(/* MemberLists */);
	Member user = anObject.getIdentify(MemberLists);
	// user = dataVector[anObject.getIdentify(dataVector)]; if getIdentiry return int

	cout << "Login Successful! you are a '" << user.getStatus() << "'!" << endl;
	while (select != 4)
	{

		cout << "[1.검색] [2.추가 및 변경] [3.삭제] [4.종료] \n"
			 << endl;
		cin >> select;
		switch (select)
		{
		case 1:

			system("cls");
			while (1)
			{
				system("cls");
				printf("검색 메뉴 입니다.\n[1.전체 리스트] [2.이름 검색] [3.뒤로가기]\n");
				scanf("%d", &select);
				if (select == 1)
				{
					system("cls");
					printf("-------------- [내림차순 정렬] --------------\n");
					system("pause");
				}
				else if (select == 2)
				{
					system("cls");
					printf("-------------- [이름 검색] -------------\n");
					printf("검색할 이름 입력 : ");
					system("pause");
				}
				else
					break;
			}
			break;
		case 2:

			system("cls");
			while (1)
			{
				system("cls");
				printf("추가 및 변경 메뉴 입니다.\n[1.학생 추가] [2.학점 변경] [3.뒤로가기]\n");
				scanf("%d", &select);
				if (select == 1)
				{
					system("cls");
					printf("-------------- [학생 추가] --------------\n");
				}
				else if (select == 2)
				{
					system("cls");
					printf("-------------- [학점 변경] -------------\n");
					printf("변경할 학생 학번 입력 : ");
				}
				else
					break;
			}
			break;
		case 3:
			system("cls");
			printf("삭제 메뉴 입니다.\n");

			printf("삭제할 학번을 입력 : ");

			break;
		default:
			break;
		}
		system("cls");
	}
}