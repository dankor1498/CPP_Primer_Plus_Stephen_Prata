// Розділ 12 - №4.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "stack.h"


int main()
{
	using namespace std;
	Stack st(5); // create an empty stack
	char ch;
	unsigned long po;
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
			cin >> po;
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
					  cout << "PO #" << po << " popped\n";
				  }
				  break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	Stack st_copy1;
	st_copy1 = st;
	Stack st_copy2 = st;
	cout << st << st_copy1 << st_copy2;
	cout << "Bye\n";
	return 0;
}
