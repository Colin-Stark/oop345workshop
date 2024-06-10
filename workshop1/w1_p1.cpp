/*
*                             Workshop - #1 Part 2
* Full Name  : COLLINS OLOKPEDJE
* Student ID#: 183341213
* Date	   : May 19, 2024
*
* Authenticity Declaration:
* I declare this submission is the result of my own work and has not been
* shared with any other student or 3rd party content provider. This submitted
* piece of work is entirely of my own creation.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include "FoodOrder.h"
#include "FoodOrder.h"

// Checking if header guards exist and follow convention.
#ifndef SENECA_FOODORDER_H
#error "The header guard for 'FoodOrder.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

/* input file format: a comma separated set of fields with a consistent format of
<Order Tag>,<Customer Name>,<Order Description>,<Price>,<Daily Special Status>

<Order Tag> can be one of:
	I - In house order
	D - Delivery order

<Daily Special Status> can be one of:
	Y - Is a daily special
	N - Is not a daily special
*/

// TODO: write the prototype for the main function
//         to accept command line arguments
int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	// TODO: print the command line here, in the format
	//   1: first argument
	//   2: second argument
	//   3: third argument
	//   ...

	for(int i = 0; i < argc; i++)
		std::cout << "  " << i + 1 << ": " << argv[i] << std::endl;


	std::cout << "--------------------------\n\n";

	// Keep a record of the In House and Delivery orders separately
	seneca::FoodOrder recordedDeliveryOrders[6];
	// Keep a count of how many orders recorded
	size_t numDeliveries = 0;

	seneca::FoodOrder currentOrder;

	for (auto day = 1; day < argc; ++day)
	{

		// Rates change from day 1 to day 2
		if (day == 1) {
			seneca::g_taxrate = 0.13;
			seneca::g_dailydiscount = 1.15;
		}
		else {
			seneca::g_taxrate = 0.14;
			seneca::g_dailydiscount = 1.20;
		}

		// each parameter contains the orders from one day, process each one at a time
		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::cout << "Name          |Order Description        |Price w/Tax |Special Price" << std::endl;
		std::ifstream in(argv[day]);
		if (in.is_open() == false)
		{
			std::cout << "Cannot open file [" << argv[day] << "]. Ignoring it!\n";
			continue; // go to the next iteration of the loop
		}
		char ordertag = '\0';

		// loop through each order in the file
		while (in) {

			// read in the ordertag
			in >> ordertag;
			// skip the delimiter
			in.ignore();

			// end of the file
			if (in.fail())
				break;

			// read in the rest of the data as a FoodOrder
			currentOrder.read(in);

			// Handle the in house and delivery orders differently
			if (ordertag == 'I') {
				seneca::FoodOrder copy = currentOrder;
				copy.display();
			}
			else if (ordertag == 'D') { // adds the delivery orders to the record
				recordedDeliveryOrders[numDeliveries++] = currentOrder;
				currentOrder.display();
			}
		}
	}

	// print the recorded orders
	std::cout << "--------------------\n";
	std::cout << "Recorded Delivery Food Orders\n";
	std::cout << "--------------------\n";
	std::cout << "Name          |Order Description        |Price w/Tax |Special Price" << std::endl;
	for (auto i = 0u; i < numDeliveries; ++i)
		recordedDeliveryOrders[i].display();
	std::cout << "--------------------\n";

	return cout;
}