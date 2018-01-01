#pragma once
#include <string>

enum Prikazy //mozne prikazy
{
	CreateTable,
	DropTable,
	EndProgram,
	ZlyPrikaz,
};


inline Prikazy checkInput(std::string command) //ropoznavanie prikazov
{
	if (command == "CreateTable") { return CreateTable; }
	if (command == "EndProgram" || command == "exit") {	return CreateTable;	}
	return Prikazy::ZlyPrikaz;
}