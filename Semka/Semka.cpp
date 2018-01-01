// Semka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Logins.h"
#include "Database.h"
#include <fstream>
#include "Commands.h"

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
	cout << "Login sucesfully! \n [1]createTable [2]exit";
	Database *database = new Database(); //uz prihlaseny v DB
	cin >> prikaz;

	
	switch (checkInput(prikaz)){
	case(EndProgram):
		return 0; // ukoncenie prirobit destruovanie objektov
		break;
	case(CreateTable):
		cout << "Zadajte nazov tabulky \n";
		cin >> prikaz;
		while (!database->createTable(prikaz)) {
			cout << "Zadajte nazov tabulky \n";
			cin >> prikaz;
			if (prikaz == "exit") {
				break;
			}
		}
		break;
	default:
		break;
	}




	
	

	cin >> prikaz;
    return 0;
}

