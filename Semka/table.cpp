#include "stdafx.h"
#include "table.h"


Table::Table(string pTableName)
{
	ofstream file(pTableName);
	if (file) {
		cout << "This table name already exists" << endl;
	}
	else {
		file.open(pTableName + ".txt"); //ak neexistuje vytvori ?? 	
		file.close();
		cout << "TabulkaVytvorena! \n" << endl;
	}
	
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
