#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Vus.h"
#include "PersData.h"

class Vkaf
{
public:
	Vkaf();
	Vkaf(Vus vus, PersData persdata, int exp);
	~Vkaf();

	Vus Getvus() const;
	PersData Getpersdata() const;
	int Getexp() const;
	void Input();


private:
	Vus vus;
	PersData persdata;
	int exp;

	bool CheckArguments(Vus vus, PersData persdata, int exp);
};

bool Vkaf::CheckArguments(Vus vus, PersData persdata, int exp) {
	return exp > 0;
}


Vkaf::Vkaf()
{
	vus = Vus();
	persdata = PersData();
	exp = 0;
}


Vkaf::Vkaf(Vus vus, PersData persdata, int exp)
{
	this->vus = vus;
	this->persdata = persdata;
	this->exp = exp;
}

Vkaf::~Vkaf()
{
}


Vus Vkaf::Getvus() const {
	return vus;
}

PersData Vkaf::Getpersdata() const {
	return persdata;
}

int Vkaf::Getexp() const {
	return exp;
}


void Vkaf::Input() {
	Vus vus;
	PersData persdata;
	int exp;
	std::cout << "\tВвод данных от воен. уч. стола\n";
	vus.Input();
	persdata.Input();
	std::cout << "Введите сколько отслужил на военной кафедре: ";
	std::cin >> exp;
	if (CheckArguments(vus, persdata, exp)) {
		this->vus = vus;
		this->persdata = persdata;
		this->exp = exp;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}