// Розділ 10 - №3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "golf.h"

int main()
{
	setlocale(LC_ALL, "Ukr");
	Golf ann("Ann Birdfree", 24);
	Golf andy[len];
	Golf prov;
	prov.Golf::Golf();
	int i;
	for (i = 0; i < len; i++) {
		andy[i].setgolf();
		if (prov.sravnenie(andy[i]) == 1) {
			break;
		}
	}
	for (int j = 0; j < i; j++) {
		andy[j].showgolf();
		std::cout << std::endl;
	}
	ann.hhandicap(200);
	std::cout << std::endl;
	ann.showgolf();
	std::cout << std::endl << std::endl;
	return 0;
}

