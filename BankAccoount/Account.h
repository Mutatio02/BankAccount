#pragma once
#include <string>
using namespace std;

class Account{

public:
	Account();
	Account(string name, int age, string number, string password);
	~Account();
	const string& getName() const; // 이름 가져오기
	const string& getNumber() const; // 계좌번호 가져오기
	const string& getPassword() const; // 비밀번호 가져오기
	unsigned int& getAmountref(); // 계좌 잔액 가져오기 -- 원본에 대한 변경이 가능해야됨
	unsigned int getAmount() const; // 계좌 잔액 가져오기- 원본에 대한 복사본 가져오기
	void deposit(int money); // 계좌에 돈이 입금
	void withdraw(int money); // 계좌에 돈이 출금

private:
	string name; // 이름
	int age = 0;// 나이
	string number; // 계좌 번호 -- 변경 불가
	string password; // 비밀 번호 -- 변경 불가
	unsigned int amount = 0; // 계좌 금액 -- 변경 가능
};

