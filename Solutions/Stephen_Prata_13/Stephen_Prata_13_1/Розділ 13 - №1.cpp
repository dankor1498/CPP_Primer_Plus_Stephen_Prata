// Розділ 13 - №1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "classic.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Bravo(const Cd & disk);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in В flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	// Непосредственное использование объектов
	cout << "Using object directly:\n";
	c1.Report();  // использование метода Cd
	c2.Report(); // использование метода Classic
	// Использование указателя на объекты типа cd *
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); // использование метода Cd для объекта cd
	pcd = &c2;
	pcd->Report(); // использование метода Classic для объекта classic
	// Вызов функции с аргументом-ссылкой на Cd
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	// Тестирование присваивания
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}
