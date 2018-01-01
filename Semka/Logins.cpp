#include "stdafx.h"
#include "Logins.h" 

using namespace std;

Logins::Logins()
{
	logins = new vector<string>();
	passwords = new vector<string>();
	try
	{
		loadLoginsTXT();
	}
	catch (const std::exception& ex)
	{
		cerr << ex.what() << endl;
	}
	
}

bool Logins::findUser(string pUsername)
{
	for (string pom : *logins)
	{
		if (pom == pUsername) {
			return true;
		}
	}
	return false;
}

bool Logins::loadLoginsTXT()
{
	ifstream logInsFile;
	logInsFile.open("logins.TXT");
	while(!logInsFile.eof())
	{
		string tmpUsername, tmpPassword = "";
		getline(logInsFile, tmpUsername, ';');
		getline(logInsFile, tmpPassword, ';');
		logins->push_back(tmpUsername);
		passwords->push_back(tmpPassword);
	}
	return true;
}

bool Logins::checkUserAndPass(string pUsername,string pPassword)
{
	int i = 0;
	for (string pom : *logins)
	{
		if (pom == pUsername && pPassword == "s") { //passwords
			
			return true;
		}
		i++;
	}
	return false;
}


Logins::~Logins()
{
}
