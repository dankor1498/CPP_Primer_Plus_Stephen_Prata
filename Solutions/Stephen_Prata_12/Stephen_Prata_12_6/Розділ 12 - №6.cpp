// Розділ 12 - №6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "queue.h"

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting things up
	std::srand(std::time(0));  //  random initializing of rand()
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);         // line queue holds up to qs people
	Queue line_1(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;              //  hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles
	cout << "Enter the average number of customers per hour: ";
	double perhour;         //  average # of arrival per hour
	cin >> perhour;
	double min_per_cust;    //  average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;              //  new customer data
	long turnaways = 0;     //  turned away by full queue
	long customers = 0, customers_1 = 0;     //  joined the queue
	long served = 0, served_1 = 0;        //  served during the simulation
	long sum_line = 0, sum_line_1 = 0;      //  cumulative line length
	int wait_time = 0, wait_time_1 = 0;      //  time until autoteller is free
	long line_wait = 0, line_wait_1 = 0;     //  cumulative time in line


							// running the simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))  // have newcomer
		{
			if (line.isfull() && line_1.isfull())
				turnaways++;
			else
			{
				if (line.queuecount() > line_1.queuecount()){
					customers_1++;
					temp.set(cycle);      // cycle = time of arrival
					line_1.enqueue(temp); // add newcomer to line
				}
				else {
					customers++;
					temp.set(cycle);    // cycle = time of arrival
					line.enqueue(temp); // add newcomer to line
				}
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);      // attend next customer
			wait_time = temp.ptime(); // for wait_time minutes
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time_1 <= 0 && !line_1.isempty())
		{
			line_1.dequeue(temp);      // attend next customer
			wait_time_1 = temp.ptime(); // for wait_time minutes
			line_wait_1 += cycle - temp.when();
			served_1++;
		}
		if (wait_time > 0)
			wait_time--;
		if (wait_time_1 > 0)
			wait_time_1--;
		sum_line += line.queuecount();
		sum_line_1 += line_1.queuecount();
	}

	// reporting results
	cout << "Bank #1: \n";
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Bank #2: \n";
	if (customers_1 > 0)
	{
		cout << "customers accepted: " << customers_1 << endl;
		cout << "  customers served: " << served_1 << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line_1 / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait_1 / served_1 << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Bank #1 and #2: \n";
	if (customers_1 + customers > 0)
	{
		cout << "customers accepted: " << (customers_1 + customers) << endl;
		cout << "  customers served: " << (served_1 + served) << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << ((double)sum_line_1 / cyclelimit + (double)sum_line / cyclelimit) / 2 << endl;
		cout << " average wait time: "
			<< ((double)line_wait_1 / served_1 + (double)line_wait / served) / 2 << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	cin.get();
	return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
	