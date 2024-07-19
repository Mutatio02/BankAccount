#pragma once
#include <string>
using namespace std;

class Account{

public:
	Account();
	Account(string name, int age, string number, string password);
	~Account();
	const string& getName() const; // �̸� ��������
	const string& getNumber() const; // ���¹�ȣ ��������
	const string& getPassword() const; // ��й�ȣ ��������
	unsigned int& getAmountref(); // ���� �ܾ� �������� -- ������ ���� ������ �����ؾߵ�
	unsigned int getAmount() const; // ���� �ܾ� ��������- ������ ���� ���纻 ��������
	void deposit(int money); // ���¿� ���� �Ա�
	void withdraw(int money); // ���¿� ���� ���

private:
	string name; // �̸�
	int age = 0;// ����
	string number; // ���� ��ȣ -- ���� �Ұ�
	string password; // ��� ��ȣ -- ���� �Ұ�
	unsigned int amount = 0; // ���� �ݾ� -- ���� ����
};

