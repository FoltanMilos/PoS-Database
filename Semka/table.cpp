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
	//while (!file.eof())
	//{
		string tmp = "";
		
		while (1)
		{
			getline(file, tmp, ',');
			if (tmp == "typPrava") {
				break;
			}
			prava->push_back(tmp); //prava
		}
		while (tmp != "columns")
		{
			getline(file, tmp, ',');
			columns->push_back(tmp); //stplce
		}
		
	//}
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
	string tmp = "";
	for(string var : *prava)
	{
		tmp = tmp + var;
	}

	return tmp;
}

Table::~Table()
{
}
