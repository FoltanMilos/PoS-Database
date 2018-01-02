#include "stdafx.h"
#include "table.h"
#include <errno.h>


Table::Table(string pTableName)
{
	name = pTableName;
	prava = new vector<string>();
	typPrava = new vector<string>();
	columns = new vector<string>();
	typ = new vector<string>();
	pk = new vector<string>();
	notNull = new vector<string>();
}

bool Table::initTable()
{
	ifstream file;
	string ch = "";
	file.open(name + ".txt");
	getline(file, ch, ',');
	if (ch == "") { //nacita prve slovo, ak tam neni je prazda
		return false;
	}

	string tmp = "";

	while (1)
	{
		getline(file, tmp, ',');
		if (tmp == "typPrava") {
			break;
		}
		prava->push_back(tmp); //prava
	}
	while (1)
	{
		getline(file, tmp, ',');
		if (tmp == "columns") { break; }
		typPrava->push_back(tmp); //stplce
	}
	//typy
	while (1)
	{
		getline(file, tmp, ',');
		if (tmp == "typ") { break; }
		columns->push_back(tmp);
	}
	//PK
	while (1)
	{
		getline(file, tmp, ',');
		if (tmp == "PK") { break; }
		typ->push_back(tmp); //stplce
	}
	//NN
	while (1)
	{
		getline(file, tmp, ',');
		if (tmp == "NN") { break; }
		pk->push_back(tmp); //stplce
	}
	//NN -- 
	while (1)
	{
		getline(file, tmp, ',');
		if (tmp == "rows") { break; }
		notNull->push_back(tmp); //stplce
	}
	while (!file.eof())
	{
		getline(file, tmp, ';');
		rows = tmp;
	}
	return true;
}


bool Table::addColumns(string pNazov, string pTyp)
{
	return false;
}

bool Table::delColumn()
{
	return false;
}

string Table::toStringTable()
{
	string tmp = name + "\n prava: ";
	for(string var : *prava)
	{
		tmp = tmp + var + " | ";
	}
	tmp = tmp + "\n typPrava: ";
	for (string var : *typPrava)
	{
		tmp = tmp + var + " | ";
	}
	tmp = tmp + "\n columns: ";
	for (string var : *columns)
	{
		tmp = tmp + var + " | ";
	}
	tmp = tmp + "\n typ: ";
	for (string var : *typ)
	{
		tmp = tmp + var + " | ";
	}
	tmp = tmp + "\n PK: ";
	for (string var : *pk)
	{
		tmp = tmp + var + " | ";
	}
	tmp = tmp + "\n NN: ";
	for (string var : *notNull)
	{
		tmp = tmp + var + " | ";
	}
	tmp = tmp + "\n rows: ";
	tmp = tmp + rows;
	return tmp;
}

Table::~Table()
{
}
