// Розділ 10 - №2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Class.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	
	Person one;                      // используется конструктор по умолчанию
	Person two("Smythecraft");       // используется конструктор #2
							         // с одним аргументом по умолчанию
	Person three("Dimwiddy", "Sam"); // используется конструктор #2,
									 // без аргументов по умолчанию
	one.Show();
	one.FormalShow();
	std::cout << std::endl;
	two.Show();
	two.FormalShow();
	std::cout << std::endl;
	three.Show();
	three.FormalShow();
	std::cout << std::endl << std::endl;
	std::cin.get();
	return 0;
}

