// Розділ 13 - №4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "port.h"

const int CLIENTS = 5;

int main()
{
	Port * p_port[CLIENTS];

	Port shirt("Gallo", "tawny", 8);
	VintagePort balloon("Gallo_1", 7, "The Noble", 1988);
	VintagePort balloon1("Gallo_2", 6, "Old Velvet", 1999);
	VintagePort balloon2(balloon);
	Port map("Gallo_3", "ruby", 6);
	Port map2;
	map2 = map;

	*p_port = &shirt;
	*(p_port + 1) = &balloon;
	*(p_port + 2) = &map;
	*(p_port + 3) = &map2;
	*(p_port + 4) = &balloon2;
		
	(*p_port)->Show();
	cout << endl;
	(*(p_port + 1))->Show();
	cout << endl;
	(*(p_port + 2))->Show();
	cout << endl;
	(*(p_port + 3))->Show();
	cout << endl;
	(*(p_port + 4))->Show();
	cout << endl;
	balloon1.Show();
	cout << endl;

	cout << endl << "----------------------------------------\n";
	cout << endl << endl;
	
	cout << shirt << endl << balloon 
		<< endl << balloon2 << endl 
		<< map << endl << map2 
		<< endl << balloon1 << endl;

	return 0;
}

