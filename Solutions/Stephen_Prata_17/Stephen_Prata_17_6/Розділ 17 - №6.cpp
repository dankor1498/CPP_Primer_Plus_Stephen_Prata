// Розділ 17 - №6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "emp.h"

using namespace std;

const int MAX = 2;
const char *file = "test.txt";

void fiopen(ifstream & fin);

int main(void)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
		
	ifstream fin;
	fin.open(file);
	fiopen(fin);
	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output. \n"; 
		exit(EXIT_FAILURE);
	}		abstr_emp *pc[MAX];
	for (size_t i = 0; i < MAX; i++)
	{
		cout << "Employee - 1  Manager - 2  Fink - 3  Highfink - 4: ";
		int c;
		cin >> c;
		switch (c)
		{
		case abstr_emp::classkind::Employee:
			pc[i] = new employee;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		case abstr_emp::classkind::Manager:
			pc[i] = new manager;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		case abstr_emp::classkind::Fink:
			pc[i] = new fink;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		case abstr_emp::classkind::Highfink:
			pc[i] = new highfink;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		default:
			cout << "Invalid input. Repeat.\n";
			i--;
			break;
		}
	}
	
	fin.open(file);
	fiopen(fin);

	return 0;
}

void fiopen(ifstream & fin) {
	char ch;
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";

		int classtype;
		while ((fin >> classtype).get(ch)) {
			abstr_emp *pc = nullptr;
			switch (classtype)
			{
			case abstr_emp::classkind::Employee:
				pc = new employee;
				pc->GetAll(fin);
				pc->ShowAll();
				cout << endl;
				delete pc;
				break;
			case abstr_emp::classkind::Manager:
				pc = new manager;
				pc->GetAll(fin);
				pc->ShowAll();
				cout << endl;
				delete pc;
				break;
			case abstr_emp::classkind::Fink:
				pc = new fink;
				pc->GetAll(fin);
				pc->ShowAll();
				cout << endl;
				delete pc;
				break;
			case abstr_emp::classkind::Highfink:
				pc = new highfink;
				pc->GetAll(fin);
				pc->ShowAll();
				cout << endl;
				delete pc;
				break;
			default:
				break;
			}		}		fin.close();
	}
}
