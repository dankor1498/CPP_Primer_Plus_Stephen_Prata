// Розділ 11 - №2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "vect_2.h"

#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include <fstream> 

int main()
{
	using namespace std;
	ofstream fout;
	fout.open("thewalk.txt");
	using VECTOR::Vector;
	srand(time(0));     // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int i = 0;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		fout << "Target Distance: " << target << ", Step Size: ";
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			fout << i++ << ": " << result << endl;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		fout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		fout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	/* keep window open
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	*/
	return 0;
}