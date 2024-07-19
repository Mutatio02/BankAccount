#pragma once
#include "Manger.h"

class UserInterface
{
public:
	UserInterface();
	~UserInterface();
	int printUI();
	int Run();
	void Make();
	void Input();
	void Output();
	bool Search();

private:
	Manger* manger;
};

