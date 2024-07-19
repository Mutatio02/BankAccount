#include "UserInterface.h"
#include "Account.h"
#include "Manger.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Manger;


UserInterface::UserInterface() { manger = new Manger(); }
UserInterface::~UserInterface() { delete manger; }
int UserInterface::printUI() {
    system("cls");
    cout << "[1] 계좌 생성\t" << "[2] 계좌 입금\t" <<
        "[3] 계좌 출금\t" << "[4] 계좌 검색\t" << "[5] 종료\t" << endl;
    int input = 0;
    cout << "번호선택: ";
    cin >> input;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
    return input;
}
int UserInterface::Run() {
    int menu= 0;

    while ((menu = printUI()) != 5)
    {
        switch (menu) 
        {
        case 1:
            Make();
            break;
        case 2:
            Input();
            break;
        case 3:
            Output();
            break;
        case 4:
            Search();
            break;
        default:
            cout << "잘못된 선택!" << endl;
            //
        }
    }
    return menu;
}

void UserInterface::Make() {

    string username;
    cout << "이름: ";
    getline(cin, username);

    int userage;
    cout << "나이: ";
    cin >> userage;
    cin.ignore();

    string usernumber;
    cout << "계좌번호: ";
    getline(cin, usernumber);

    string userpass;
    cout << "비밀번호: ";
    getline(cin, userpass);

    manger->makeAcc(username, userage, usernumber, userpass);
    cout << "계좌생성 완료" << endl;

    
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
    
}
bool UserInterface::Search() {

    string usernumber;
    cout << "계좌번호: ";
    getline(cin,usernumber);
    cout << "계좌번호 검색 완료" << endl;

    string userpass;
    cout << "비밀번호: ";
    getline(cin, userpass);
    cout << "비밀번호 검색 완료" << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Account* find = manger->Find(usernumber, userpass);
    if (find == nullptr)
    {
        cout << "계좌번호 존재 안함" << endl;
        return false;
    }
    else {
        cout << "계좌번호: " << find->getNumber() << endl;
        cout << "잔액: " << find->getAmount() << endl;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
    return true;
}

void UserInterface::Input() {
    if (Search() != true) {
        cout << "다시 입력해주세요!" << endl;
        return;
    }
    int m_input = 0;
    cout << "입금 금액: ";
    cin >> m_input;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기

    cout << "입금중입니다..." << endl;

    unsigned int total = 0;
    total = manger->Input_m(m_input);
    cout << "잔고: " << total << "원";

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
    
    
}
void UserInterface::Output() {
    if (Search() != true) {
        cout << "다시 입력해주세요!" << endl;
        return;
    }
    int m_output = 0;
    cout << "출금 금액: ";
    cin >> m_output;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기

    cout << "출금중입니다..." << endl;

    unsigned int total = 0;
    total = manger->Output_m(m_output);
    cout << "잔고: " << total << "원";

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
    
}
