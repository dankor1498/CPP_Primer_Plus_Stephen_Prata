// Розділ 14 - №4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "person.h"

const int SIZE = 5;

int main()
{
	Person p = Person("Ghon", "Grin");
	Person *lolas[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		char choice;
		cout << "Enter the employee category:\n"			
			<< "p: Person g: Gunslinger " 
			<< "k: PokerPlayer b: BadDude " 
			<< "q: quit\n"; 
		cin >> choice;
		while (strchr("pgkbq", choice) == NULL)
		{
			cout << "Please enter a p, g, k, b or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
			case 'p': lolas[i] = new Person("Ghon","Grin");
				break;
			case 'g': lolas[i] = new Gunslinger("Ben", "Grinn", 1.56, 45);
				break;
			case 'k': lolas[i] = new PokerPlayer("Ted", "Gons");
				break;
			case 'b': lolas[i] = new BadDude("Kit", "Gron", 2.19, 14);
				break;
		}
		cin.get();
	}

	cout << "\nHere is your staff:\n"; // вывод списка работников
	int j;
	for (j = 0; j < i; j++)
	{
		cout << endl;
		lolas[j]->Show();
	}
	for (j = 0; j < i; j++)
		delete lolas[j];
	cout << "Bye.\n";
	return 0;
}


