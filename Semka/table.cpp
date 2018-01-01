#include "stdafx.h"
#include "table.h"
#include <errno.h>


Table::Table(string pTableName)
{
	fstream file; // nevytvori ziadny subor ak by neexistoval
	file.open(pTableName + ".txt");   	
	if (file.is_open())  //ak neexistuje neotvori sa
	{
		cout << "This table name already exists" << endl;
		file.close();
	}
	else {
		ofstream file;
		file.open(pTableName + ".txt"); //ak neexistuje vytvori  	
		cout << "TabulkaVytvorena! \n" << endl;
		checkErr = 0;
	}

	/*
	FILE *files;
	errno_t err;
	err = fopen_s(&files, pTableName.c_str(), "r");
	if (files != nullptr) {
		//fclose(files);
		cout << "This table name already exists" << endl;
		checkErr = -1;
	}
	else {
		ofstream file;
		file.open(pTableName + ".txt"); //ak neexistuje vytvori  	
		file.close();
		cout << "TabulkaVytvorena! \n" << endl;
		checkErr = 0;
	}
	*/
	
}

int Table::getErrCheckResult()
{
	return checkErr;
}


bool Table::addColumns()
{
	return false;
}

string Table::toStringTable()
{


	return string();
}

Table::~Table()
{
}
