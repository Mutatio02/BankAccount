#pragma once
#include "Account.h"
#include <vector>
using namespace std;
class Manger{
	friend class Account;
public:
	Manger();
	void makeAcc(const string& name, int age, const string& number, const string& password);
	unsigned int Input_m(const int input);
	unsigned int Output_m(const int output);
	Account* Find(const string& number, const string& password);
	
private:
	vector<Account> Box;
};

