// Розділ 10 - №4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"

int main()
{
	double ar[] = { 11111.1, 22222.2, 33333.3, 44444.4 };
	SALES::Sales van(ar, SALES::QUARTERS);
	van.showSales();

	SALES::Sales tuu;
	tuu.setSales(tuu);
	tuu.showSales();

	return 0;
}

