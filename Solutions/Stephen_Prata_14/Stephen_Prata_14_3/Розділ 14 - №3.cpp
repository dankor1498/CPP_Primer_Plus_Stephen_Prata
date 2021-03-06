// Розділ 14 - №3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "workermi.h"

int SIZE = 2;

int main()
{
	Queue<Worker*> qe(SIZE);
	Worker *w = nullptr;

	while(!qe.isfull())
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':   
			w = new Waiter;
			qe.enqueue(w);
			break;
		case 's':   
			w = new Singer;
			qe.enqueue(w);
			break;
		case 't':   
			w = new SingingWaiter;
			qe.enqueue(w);
			break;
		}
		cin.get();
		w->Set();
	}

	cout << "\n\n-------The queue is full-------\n\n";
	while (!qe.isempty()) {
		qe.dequeue(w);
		w->Show();
	}

	cout << "Bye.\n";
	cin.get();
	return 0;
}