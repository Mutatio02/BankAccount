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
    cout << "[1] ���� ����\t" << "[2] ���� �Ա�\t" <<
        "[3] ���� ���\t" << "[4] ���� �˻�\t" << "[5] ����\t" << endl;
    int input = 0;
    cout << "��ȣ����: ";
    cin >> input;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����
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
            cout << "�߸��� ����!" << endl;
            //
        }
    }
    return menu;
}

void UserInterface::Make() {

    string username;
    cout << "�̸�: ";
    getline(cin, username);

    int userage;
    cout << "����: ";
    cin >> userage;
    cin.ignore();

    string usernumber;
    cout << "���¹�ȣ: ";
    getline(cin, usernumber);

    string userpass;
    cout << "��й�ȣ: ";
    getline(cin, userpass);

    manger->makeAcc(username, userage, usernumber, userpass);
    cout << "���»��� �Ϸ�" << endl;

    
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����
    
}
bool UserInterface::Search() {

    string usernumber;
    cout << "���¹�ȣ: ";
    getline(cin,usernumber);
    cout << "���¹�ȣ �˻� �Ϸ�" << endl;

    string userpass;
    cout << "��й�ȣ: ";
    getline(cin, userpass);
    cout << "��й�ȣ �˻� �Ϸ�" << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Account* find = manger->Find(usernumber, userpass);
    if (find == nullptr)
    {
        cout << "���¹�ȣ ���� ����" << endl;
        return false;
    }
    else {
        cout << "���¹�ȣ: " << find->getNumber() << endl;
        cout << "�ܾ�: " << find->getAmount() << endl;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����
    return true;
}

void UserInterface::Input() {
    if (Search() != true) {
        cout << "�ٽ� �Է����ּ���!" << endl;
        return;
    }
    int m_input = 0;
    cout << "�Ա� �ݾ�: ";
    cin >> m_input;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����

    cout << "�Ա����Դϴ�..." << endl;

    unsigned int total = 0;
    total = manger->Input_m(m_input);
    cout << "�ܰ�: " << total << "��";

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����
    
    
}
void UserInterface::Output() {
    if (Search() != true) {
        cout << "�ٽ� �Է����ּ���!" << endl;
        return;
    }
    int m_output = 0;
    cout << "��� �ݾ�: ";
    cin >> m_output;

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����

    cout << "������Դϴ�..." << endl;

    unsigned int total = 0;
    total = manger->Output_m(m_output);
    cout << "�ܰ�: " << total << "��";

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �Է� ���� ����
    
}
