// Розділ 9 - №1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "golf.h"

int main()
{
	setlocale(LC_ALL, "Ukr");
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	golf andy[len];
	int i;
	for (i = 0; i < len; i++) {
		if (setgolf(andy[i]) == 0) {
			break;
		}
	}
	for (int j  = 0; j < i; j++) {
		showgolf(andy[j]);
		std::cout << std::endl;
	}
	handicap(ann, 200);
	std::cout << std::endl;
	showgolf(ann);
	std::cout << std::endl << std::endl;
	return 0;
}
