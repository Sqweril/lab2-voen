#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Snils.h"
#include "Pasport.h"


class Docs
{
public:
	Docs();
	Docs(SNILS snils, Pasport pasport);
	~Docs();

	SNILS GetSNILS() const;
	Pasport GetPasport() const;
	void Input();


private:
	SNILS snils;
	Pasport pasport;

};



Docs::Docs()
{
	snils = SNILS();
	pasport = Pasport();
}


Docs::Docs(SNILS snils, Pasport pasport)
{
	this->snils = snils;
	this->pasport = pasport;
}

Docs::~Docs()
{
}


SNILS Docs::GetSNILS() const {
	return snils;
}

Pasport Docs::GetPasport() const {
	return pasport; 
}

void Docs::Input() {
	SNILS snils;
	Pasport pasport;
	std::cout << "\tВвод документов\n";
	std::cout << "\tВвод СНИЛСА\n";
	snils.Input();
	std::cout << "\tВвод паспорта\n";
	pasport.Input();
	this->snils = snils;
	this->pasport = pasport;
}