#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>

class Pasport
{
public:
	Pasport();
	Pasport(int seria, int number);
	~Pasport();

	int Getseria() const;
	int Getnumber() const;
	void Input();


private:
	int seria;
	int number;

	bool CheckArguments(int seria, int number);
};


bool Pasport::CheckArguments(int seria, int number) {
	return number > 0 && seria > 0;
}

Pasport::Pasport()
{
	number = seria = 0;
}


Pasport::Pasport(int seria, int number)
{
	if (CheckArguments(number, seria)) {
		this->number = number;
		this->seria = seria;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

Pasport::~Pasport()
{
}


int Pasport::Getnumber() const {
	return number;
}

int Pasport::Getseria() const {
	return seria;
}

void Pasport::Input() {
	int number;
	int seria;

	std::cout << "Введите серию паспорта: ";
	std::cin >> seria;
	std::cout << "Введите номер паспорта: ";
	std::cin >> number;
	while (getchar() != '\n');
	if (CheckArguments(seria, number)) {
		this->number = number;
		this->seria = seria;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}