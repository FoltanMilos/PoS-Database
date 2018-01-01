#pragma once
#include <string>
#include "table.h"

using namespace std;

class Database
{
    
public:
	Database();
	bool createTable(string pTableName);
	~Database();
};

