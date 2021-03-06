// Розділ 10 - №8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "list.h"


int main()
{
	List list_1;
	List list_2;
	Item n;
	
	cout << "Fill in the list_1:  ";
	while (cin >> n && list_1.push(n)) {
		if (list_1.isfull()) {
			cout << "The list_1 is complete.\n";
			break;
		}
	}
	
	if (list_1.isempty()) {
		cout << "The list_1 is empty.\n";
	}

	list_1.visit(Square);
	list_1.showlist();

	

	if (list_2.isempty()) {
		cout << "The list_2 is empty.\n";
	}
	cout << "Fill in the list_2:  ";
	while (cin >> n && list_2.push(n)) {
		if (list_2.isfull()) {
			cout << "The list_2 is complete.\n";
			break;
		}
	}

	list_2.visit(Square);
	list_2.showlist();
	
	return 0;
}

