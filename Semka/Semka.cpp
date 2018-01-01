// Semka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Logins.h"
#include "Database.h"
#include <fstream>

using namespace std;

int main()
{
	//nacitanie loginov zo suboru Logins
	Logins *log = new Logins();

	string prikaz,username,password = "";
	cout << "Log in Foltan&Sarina's database:\nUsername:\n";
	cin >> username;
	cout << "password:\n";
	cin >> password;
	while (!log->checkUserAndPass(username,password)) { //overenie hesla
		cout << "nespravne meno alebo heslo:\nZnovu zadajte: \n";
		cin >> username;
		cout << "password:\n";
		cin >> password;
	}
	cout << "Login sucesfully! \n [1]createTable";
	Database *database = new Database(); //uz prihlaseny v DB
	cin >> prikaz;
	database->createTable(prikaz);
	

	cin >> prikaz;
    return 0;
}

