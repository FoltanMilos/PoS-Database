#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Table
{
	int checkErr;
public:
	Table(string pTableName);
	int getErrCheckResult();
	

	//alters
	bool addColumns(); 
	bool delColumn();
	string toStringTable();
	~Table();
};

