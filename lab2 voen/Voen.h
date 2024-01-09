#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "PersData.h"

class Voen
{
public:
	Voen();
	Voen(PersData persdata, int kategor, int otsroch);
	~Voen();

	PersData Getpersdata() const;
	int Getkategor() const;
	int Getotsroch() const;
	void Input();
	void Print() const;
	void Setotsroch(int otsroch);


private:
	PersData persdata;
	int kategor;
	int otsroch;

	bool CheckArguments(PersData persdata, int kategor, int otsroch);
};

bool Voen::CheckArguments(PersData persdata, int kategor, int otsroch) {
	return kategor > 0 && otsroch > 0;
}


Voen::Voen()
{
	persdata = PersData();
	kategor = 0;
	otsroch = 0;
}


Voen::Voen(PersData persdata, int kategor, int otsroch)
{
	this->persdata = persdata;
	this->kategor = kategor;
	this->otsroch = otsroch;
}

Voen::~Voen()
{
}


PersData Voen::Getpersdata() const {
	return persdata;
}

int Voen::Getkategor() const {
	return kategor;
}

int Voen::Getotsroch() const {
	return otsroch;
}
void Voen::Setotsroch(int otsroch) {
	this->otsroch = otsroch;
}

void Voen::Input() {
	PersData persdata;
	int kategor;
	int otsroch;
	std::cout << "\t���� ������ ���������� � ����������\n";
	persdata.Input();
	std::cout << "������� ���������: ";
	std::cin >> kategor;
	std::cout << "������� ��������: ";
	std::cin >> otsroch;
	if (CheckArguments(persdata, kategor, otsroch)) {
		this->persdata = persdata;
		this->kategor = kategor;
		this->otsroch = otsroch;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

void Voen::Print() const {
	std::cout << "\t���������� � ���������� � ����������\n";
	std::cout << "���: " << this->persdata.Getfio() << "\t���������: " << this->kategor << "\t������� ��������: " << this->otsroch << "\n\n";
}