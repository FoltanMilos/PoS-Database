#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Table
{
public:
	Table(string pTableName);


	//alters
	bool addColumns(); 
	bool delColumn();
	string toStringTable();
	~Table();
};

