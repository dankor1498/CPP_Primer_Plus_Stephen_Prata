// Розділ 11 - №5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stonewt.h"

#include <iostream>

using std::cout;

void display(const Stonewt & st, int n);
int main()
{
	Stonewt incognito(275, Stonewt::INT_F);     // uses constructor to initialize
	Stonewt wolfe(285.7, Stonewt::DOUBLE_F);    // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8, Stonewt::ST);

	cout << "The celebrity weighed ";
	/*incognito.show_stn();*/ cout << incognito;
	cout << "The detective weighed ";
	/*wolfe.show_stn();*/ cout << wolfe;
	cout << "The President weighed ";
	/*taft.show_lbs();*/ cout << taft;
	incognito = Stonewt(276.8, Stonewt::DOUBLE_F);  // uses constructor for conversion
	taft = Stonewt(325, Stonewt::INT_F); // same as taft = Stonewt(325);
	cout << "After dinner, the celebrity weighed (incognito)";
	cout << incognito;
	cout << "After dinner, the President weighed (taft)";
	cout << taft;
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(Stonewt(422, Stonewt::INT_F), 2);
	cout << "No stone left unearned\n";

	cout << "taft + incognito: " << taft + incognito << std::endl;
	cout << "taft - incognito: " << taft - incognito << std::endl;
	cout << "incognito - taft: " << incognito - taft << std::endl;
	cout << "taft * incognito: " << taft * incognito << std::endl;

	std::cin.get();
	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		cout << st;
	}
}

