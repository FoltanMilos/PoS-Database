#include "stdafx.h"
#include "Database.h"


Database::Database()
{
}

bool Database::createTable(string pTableName)
{
	Table *tbl = new Table(pTableName);
	if (tbl->getErrCheckResult() < 0) {
		return false;
	}
	else {
		return true;
	}
	
}


Database::~Database()
{
}
