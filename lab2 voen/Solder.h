#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Voen.h"
#include "Vkaf.h"

class Solder
{
public:
	Solder();
	Solder(Voen voen, Vkaf vkaf, std::string data, std::string time, int status);
	~Solder();

	Voen Getvoen() const;
	Vkaf Getvkaf() const;
	std::string Getdata() const;
	std::string Gettimes() const;
	int Getstatus() const;
	void Input();
	void Print() const;
	void Setstatus(int status);

private:
	Voen voen;
	Vkaf vkaf;
	std::string data;
	std::string time;
	int status;

	bool CheckArguments(Voen voen, Vkaf vkaf, std::string data, std::string time, int status);
};

bool Solder::CheckArguments(Voen voen, Vkaf vkaf, std::string data, std::string time, int status) {
	return status > 0 && status < 3;
}


Solder::Solder()
{
	voen = Voen();
	vkaf = Vkaf();
	data = "Не указано";
	time = "Не указано";
	status = 0;
}


Solder::Solder(Voen voen, Vkaf vkaf, std::string data, std::string time, int status)
{
	this->voen = voen;
	this->vkaf = vkaf;
	this->data = data;
	this->time = time;
	this->status = status;
}

Solder::~Solder()
{
}


Voen Solder::Getvoen() const {
	return voen;
}

Vkaf Solder::Getvkaf() const {
	return vkaf;
}

std::string Solder::Getdata() const {
	return data;
}
std::string Solder::Gettimes() const {
	return time;
}
int Solder::Getstatus() const {
	return status;
}
void Solder::Setstatus(int status) {
	this->status = status;
}

void Solder::Input() {
	Voen voen;
	Vkaf vkaf;
	std::string data;
	std::string time;
	int status;
	std::cout << "\tВвод данных о призывнике\n";
	voen.Input();
	//vkaf.Input();
	std::cout << "Введите дату явки в военкомат: ";
	while (getchar() != '\n');
	std::getline(std::cin, data);
	std::cout << "Введите время явки в военкомат: ";
	std::getline(std::cin, time);
	std::cout << "Введите (1-годен, 2- не годен): ";
	std::cin >> status;
	if (CheckArguments(voen, vkaf, data, time, status)) {
		this->voen = voen;
		this->vkaf = vkaf;
		this->data = data;
		this->time = time;
		this->status = status;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

void Solder::Print() const {
	std::cout << "\tИнформация о призывнике\n";
	std::cout << "Дата: " << this->data << "\tВремя: " << this->time << "\t(1-годен, 2- не годен): " << this->status << "\n\n";
}