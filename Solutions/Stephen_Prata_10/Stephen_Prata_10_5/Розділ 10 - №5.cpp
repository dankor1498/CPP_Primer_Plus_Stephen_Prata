// Розділ 10 - №5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stack.h"

 
int main()
{
	using namespace std;
	double prom_suma = 0.0;
	Stack st; 
	char ch;
	customer po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a': cout << "Enter a PO number to add: ";
			cout << "Fullname:  ";
			cin >> po.fullname;
			cout << "Payment:  ";
			cin >> po.payment;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p': if (st.isempty())
			cout << "stack already empty\n";
				  else {
					  st.pop(po);
					  prom_suma += po.payment;
					  cout << "PO # " << po.fullname << " popped\n";
				  }
				  break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Prom_suma " << prom_suma << endl;
	cout << "Bye\n";
	return 0;
}
