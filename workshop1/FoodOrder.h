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


#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>
#include <iomanip>


// DEFINING CONSTANTS TO REDUCE REPETITION
const int MAX_NAME_LENGTH = 10;
const int MAX_DESC_LENGTH = 25;

namespace seneca {

	/*
	* USING THE KEYWORD EXTERN TO MAKE THE 
	* VARIABLES AVAILABLE TO OTHER FILES
	*/ 
	extern double g_taxrate;
	extern double g_dailydiscount;

	class FoodOrder {
		char m_customerName[MAX_NAME_LENGTH]; // STORE CUSTOMER NAME
		char* m_foodDescription; // STORE CUSTOMER FOOD DESCRIPTION
		double m_price; // STORE PRICE OF THE PRICE
		bool m_dailySpecial; // CONVERT THE CHARACTER TO BOOLEAN TO CHECK IF IT IS A DAILY SPECIAL
	public:
		FoodOrder(); // RUNS THE DEFAULT CONSTRUCTOR

		FoodOrder(const FoodOrder& src); // COPY CONSTRUCTOR

		FoodOrder& operator=(const FoodOrder& src); // COPY ASSIGNMENT OPERATOR

		~FoodOrder();

		std::istream& read(std::istream& is); // MODIFIER FUNCTION TO READ THE DATA FROM THE FILE

		std::ostream& display(std::ostream& os = std::cout) const; // GETTER FUNCTION TO DISPLAY THE DATA
	};
}

#endif // !SENECA_FOODORDER_H
