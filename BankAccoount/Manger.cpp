#include "Manger.h"
Manger::Manger() {
	
}
void Manger::makeAcc(const std::string& name, int age, const std::string& number, const std::string& password) {

	for (auto& ptr : Box)
	{
		if (ptr.getNumber() == number)
			return;
	}

	Account newAcc(name, age, number, password);
	Box.push_back(newAcc);
}

unsigned int Manger::Input_m(const int input) {
	for (auto& ptr : Box)
	{
		ptr.deposit(input);
		return ptr.getAmount();
	}
	return 0;
}

unsigned int Manger::Output_m(const int output) {
	for (auto& ptr : Box)
	{
		ptr.withdraw(output);
		return ptr.getAmount();
	}
	return 0;
}

Account* Manger::Find(const string& number, const string& password) {
	if (Box.empty()) {
		return nullptr;
	}

	for (auto& ptr : Box) {
		if (ptr.getNumber() == number) { // 먼저 계좌가 맞는지 확인
			if (ptr.getPassword() == password) { // 그 다음 비밀번호가 맞는지 확인
				return &ptr;
			}
			else {
				return nullptr;
			}
		}
	}
	return nullptr; // 모든 항목을 검사한 후에도 일치하는 항목이 없으면 nullptr 반환
}