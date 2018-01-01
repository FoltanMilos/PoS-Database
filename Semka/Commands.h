#pragma once
#include <string>

enum Prikazy //mozne prikazy
{
	CreateTable,
	AlterTable,
	DropTable,
	EndProgram,
	ZlyPrikaz,
};


inline Prikazy checkInput(std::string command) //ropoznavanie prikazov
{
	if (command == "CreateTable") { return CreateTable; }
	if (command == "AlterTable" || command == "3") { return AlterTable; }
	if (command == "EndProgram" || command == "exit") {	return CreateTable;	}
	return Prikazy::ZlyPrikaz;
}