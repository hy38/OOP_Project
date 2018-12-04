#include <iostream>
#include "Member.h"
#include "Login.h"
#include <vector>
using namespace std;

struct Rooms{
    int classroom;
    bool isBooked;
};

int main(){

    Member admin = Member(); //  Member tjsdjsgkdu epdlxj dlqfur gn ahems ekdma wkrdjq tlfgod! tjsrufwhrjsdla
    vector<Member> dataVector = admin.saveFileData("datafile.csv");

	int select = 0;

	Member user;

	Login anObject = Login(dataVector);
	user = anObject.getIdentify(dataVector);
	// user = dataVector[anObject.getIdentify(dataVector)]; if getIdentiry return int

	cout << "Login Successful! you are a '" << user.getStatus() << "'!" << endl;
	while (select != 4) {
        
		cout << "[1.검색] [2.추가 및 변경] [3.삭제] [4.종료] \n" << endl;
		cin >> select;
		switch (select) {
		case 1:

			system("cls");
			while (1) {
				system("cls");
				printf("검색 메뉴 입니다.\n[1.전체 리스트] [2.이름 검색] [3.뒤로가기]\n");
				scanf("%d", &select);
				if (select == 1) {
					system("cls");
					printf("-------------- [내림차순 정렬] --------------\n");
					system("pause");
				}
				else if (select == 2) {
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
			while (1) {
				system("cls");
				printf("추가 및 변경 메뉴 입니다.\n[1.학생 추가] [2.학점 변경] [3.뒤로가기]\n");
				scanf("%d", &select);
				if (select == 1) {
					system("cls");
					printf("-------------- [학생 추가] --------------\n");
				}
				else if (select == 2) {
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