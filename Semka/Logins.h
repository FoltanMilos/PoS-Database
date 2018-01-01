#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Logins
{
private:
	vector<string> *logins;
	vector<string> *passwords;
	bool loadLoginsTXT();
public:
	Logins();
	bool findUser(string pUsername);
	bool checkUserAndPass(string pUsername,string pPassword);
	~Logins();
};


