// Розділ 13 - №3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "dma.h"

#include <iostream>

const int CLIENTS = 5;

int main()
{
	using std::cout;
	using std::endl;
	
	ABC_BaseDMA * p_clients[CLIENTS];

	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	lacksDMA balloon2(balloon);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	hasDMA map2;
	map2 = map;

	*p_clients = &shirt;
	*(p_clients + 1) = &balloon;
	*(p_clients + 2) = &map;
	*(p_clients + 3) = &map2;
	*(p_clients + 4) = &balloon2;

	cout << "Displaying baseDMA object:\n";
	(*p_clients)->View();
	cout << endl;
	cout << "Displaying lacksDMA object:\n";
	(*(p_clients + 1))->View();
	cout << endl;
	cout << "Displaying hasDMA object:\n";
	(*(p_clients + 2))->View();
	cout << endl;
	cout << "Result of lacksDMA copy:\n";
	(*(p_clients + 4))->View();
	cout << endl;
	cout << "Result of hasDMA assignment:\n";
	(*(p_clients + 3))->View();
	
	return 0;
}