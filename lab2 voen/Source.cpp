#include <iostream>
#include <windows.h>  
#include "Solder.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//пример работы с динамическим массивом 
	Solder* solderArray = new Solder[2];
	for (int i = 0; i < 2; i++)
	{
		solderArray[i].Input();
		solderArray[i].Print();
	}
	solderArray[0].Setstatus(2);
	solderArray[0].Print();
	delete[] solderArray;

	//пример работы с массивом динамических 
	Voen* voenArray[2];
	voenArray[0] = new Voen();
	voenArray[0]->Input();
	voenArray[0]->Print();
	(*voenArray[0]).Setotsroch(25);
	voenArray[0]->Print();
	voenArray[1] = new Voen();
	voenArray[1]->Print();
	//voenArray[0]->Input();
	for (size_t i = 0; i < 2; i++) delete voenArray[i];
}