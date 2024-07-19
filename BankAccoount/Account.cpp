#include "Account.h"


Account::Account() = default;

Account::Account(string name, int age, string number, string password) :
	name(name), age(age), number(number), password(password) {}

Account::~Account() {

}
const string& Account::getName() const {
	return this->name;
}
const string& Account::getNumber() const {
	return this->number;
}
const string& Account::getPassword() const{
	return this->password;
}

unsigned int& Account::getAmountref() {
	return this->amount;
}

unsigned int Account::getAmount() const {
	return this->amount;
}

void Account::deposit(int money) {
	this->amount += money;
}
		
void Account::withdraw(int money) {
	if (this->amount < 0)
		amount =0;
	amount -= money;
}
	