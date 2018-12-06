#include "AppController.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

AppController::AppController() {}

void AppController::runProject()
{
    int select = 0;

    Rooms RoomArray[CLASSROOM_SIZE];
    vector<UndergraduateStudent> UndergraduateStudentLists;
    vector<GraduateStudent> GraduateStudentLists;
    vector<Professor> ProfessorLists;
    string RequestList[REQUEST_LIST_SIZE];

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
            a.setIdNumber(str);        //  put parsed string into idNumber
            a.setStatus(str.at(0));
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

    Login anObject = Login();   // start Login

    ClassroomRentRequest cRent = ClassroomRentRequest(RoomArray);
    ImprovementRequest improvement = ImprovementRequest(RequestList);
    Request aRequest = Request();
    ConsultingRequest consult = ConsultingRequest();
    CertificateIssuing certificate = CertificateIssuing();
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
            cout << "학생 계정 입니다.\n[1.Grade Information] [2.Request] [3.ConsultRequest] [4.Exit]" << endl;
            cin >> select;
            if (select == 1) //   Student Information
            {
                system("clear");
                cout << "[Grade Information Menu]" << endl;
                cout << "your ID is :" << user.getIdNumber() << endl;
                cout << "your Grade is:" << endl;
                user.getGrades();

                cout << "Press enter to continue...";
                cin.ignore(); // ignores the newline
                cin.get();    //waits for character
            }
            else if (select == 2) //   Request
            {
                while (1)
                {
                    system("clear");
                    cout << "Request Menu for" << endl;
                    select = aRequest.ifRequest();
                    if (select == 1)
                    {
                        cRent.ifRequest(user);
                    }
                    else if (select == 2)
                    {
                        improvement.inputOpinion();
                    }
                    else if (select == 3)
                    {
                        // consult.
                    }
                    else if (select == 4)
                    {
                        // certificate.
                    }
                    else //	select == 5
                        break;
                    cout << "Press enter to continue...";
                    cin.ignore(); // ignores the newline
                    cin.get();    //waits for character
                }
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

            cout << "교수 계정 입니다.\n[1.Classroom Rent] [2.Input Grade] [3.change isBusy] [4.Exit]" << endl;
            cin >> select;
            if (select == 1)
            {
                cout << "select : 1" << endl;
                cout << "Press enter to continue...";
                cin.ignore(); // ignores the newline
                cin.get();    //waits for character

            }
            else if (select == 2)
            {
                string tempString;
                cout << "성적을 입력할 studentID를 입력하시오 :" << endl;
                cin >> tempString;
                if (tempString.at(0) == 'u')
                {
                    user.setStudentGrade(UndergraduateStudentLists, tempString);
                }
                else
                {
                    user.setStudentGrade(GraduateStudentLists, tempString);
                }

                /* pause */
                cout << "Press enter to continue...";
                cin.ignore(); // ignores the newline
                cin.get();    //waits for character
            }
            else if (select == 3)
            {
                user.setSchedule(!user.getSchedule());
                string ifBusy;
                if (user.getSchedule()){
                    ifBusy = "바쁨";
                }
                else
                    ifBusy = "안바쁨";
                cout << "스케줄이 변경되었습니다(" << ifBusy << ")" << endl;
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