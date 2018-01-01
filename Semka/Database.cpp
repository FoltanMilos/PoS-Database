#include "stdafx.h"
#include "Database.h"


Database::Database()
{
}

bool Database::createTable(string pTableName)
{
	Table *tbl = new Table(pTableName);
	return true;
}


Database::~Database()
{
}
