// Розділ 10 - №7.cpp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Class.h"

int main()
{
	Plorg nn;
	Plorg num_1("Plorg Num_1", 65);
	nn.show_plorg();
	num_1.show_plorg();
	
	int n;
	cout << "N: ";
	cin >> n;
	Plorg *mas = new Plorg[n];
	for (int i = 0; i < n; i++) {
		(mas+i)->name_plorg(mas[i]);
	}
	for (int i = 0; i < n; i++) {
		char p_m;
		int k;
		cout << "Enter ( + ) or ( - ) :";
		cin >> p_m;
		cout << "How much to add or subtract? ";
		cin >> k;
		if ((mas + i)->index_ci(k, p_m) == false) {
			i--;
			cout << "ERROR!!!\n";
			continue;
		}
	}
	for (int i = 0; i < n; i++) {
		(mas+i)->show_plorg();
	}

	cin.get();
	return 0;
}

