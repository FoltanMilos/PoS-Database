#include "stdafx.h"
#include "Database.h"


Database::Database()
{
}

bool Database::createTable(string pTableName)
{
	bool tmp;
	fstream file; // nevytvori ziadny subor ak by neexistoval
	file.open(pTableName + ".txt");
	if (file.is_open())  //ak neexistuje neotvori sa
	{
		cout << "This table name already exists" << endl;
		file.close();
		tmp = false;
	}
	else {
		ofstream file;
		file.open(pTableName + ".txt"); //ak neexistuje vytvori  	
		cout << "TabulkaVytvorena! \n" << endl;
		tmp = true;

	}
	return tmp;
}

bool Database::findTable(string pTableName)
{
	fstream file; // nevytvori ziadny subor ak by neexistoval
	file.open(pTableName + ".txt");
	if (file.is_open())  //ak existuje otvori sa
	{
		file.close();
		return true;
	}
	else {
		cout << "Tabulka neexistuje \n ";
		return false;
	}
}


string Database::toString(string pTableName)
{
	//pridanie moznosti citania zo zasobnika
	//pripad ked tabulka neexistuje 
	Table *tbl = new Table(pTableName);
	tbl->initTable();
	return tbl->toStringTable();
	
}

Database::~Database()
{
}
