#pragma once
#include <iostream>

using namespace std;

class BaseException
{
private:
	string data, where, what;

public:
	BaseException(string, string, string);
	void ShowInfo();
};