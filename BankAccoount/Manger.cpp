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
		if (ptr.getNumber() == number) { // ���� ���°� �´��� Ȯ��
			if (ptr.getPassword() == password) { // �� ���� ��й�ȣ�� �´��� Ȯ��
				return &ptr;
			}
			else {
				return nullptr;
			}
		}
	}
	return nullptr; // ��� �׸��� �˻��� �Ŀ��� ��ġ�ϴ� �׸��� ������ nullptr ��ȯ
}