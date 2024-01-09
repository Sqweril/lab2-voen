#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>


class Vus
{
public:
	Vus();
	Vus(std::string name, std::string fakul, int kurse, std::string naprav);
	~Vus();

	std::string Getname() const;
	std::string Getfakul() const;
	int Getkurse() const;
	std::string Getnaprav() const;
	void Input();


private:
	std::string name;
	std::string fakul;
	int kurse;
	std::string naprav;

};




Vus::Vus()
{
	name = "Не указано";
	fakul = "Не указано";
	kurse = 0;
	naprav = "Не указано";
}


Vus::Vus(std::string name, std::string fakul, int kurse, std::string naprav)
{
	this->name = name;
	this->fakul = fakul;
	this->kurse = kurse;
	this->naprav = naprav;
}

Vus::~Vus()
{
}


std::string Vus::Getname() const {
	return name;
}

std::string Vus::Getfakul() const {
	return fakul;
}

int Vus::Getkurse() const {
	return kurse;
}

std::string Vus::Getnaprav() const {
	return naprav;
}

void Vus::Input() {
	std::string name;
	std::string fakul;
	int kurse;
	std::string naprav;
	std::cout << "\tВвод данных от учеб завед\n";
	std::cout << "Введите название уч завед: ";
	while (getchar() != '\n');
	std::getline(std::cin, name);
	std::cout << "Введите название факультета: ";
	std::getline(std::cin, fakul);
	std::cout << "Введите курс: ";
	std::cin >> kurse;
	while (getchar() != '\n');
	std::cout << "Введите название нправления: ";
	std::getline(std::cin, naprav);
	this->name = name;
	this->fakul = fakul;
	this->kurse = kurse;
	this->naprav = naprav;
}
