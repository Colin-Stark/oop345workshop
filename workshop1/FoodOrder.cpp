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

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include <string>
#include "FoodOrder.h"
using namespace std;

namespace seneca {

	// DEFINING THE EXTERN VARIABLES
	double g_taxrate = 0.0;
	double g_dailydiscount = 0.0;


	// SET VARIABLES TO EMPTY STATE
	FoodOrder::FoodOrder()
	{
		m_customerName[0] = '\0';
		m_foodDescription = nullptr;
		m_price = 0.0;
		m_dailySpecial = false;
	}

	// COPY CONSTRUCTOR
	FoodOrder::FoodOrder(const FoodOrder& src)
	{
		// USING DIRECT CALL
		m_foodDescription = nullptr;
		*this = src;
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& src)
	{
		// 1. check for self-assignment (and NOTHING else)
		if (this != &src) {

			// 2. deallocate any memory that your object is using
			delete[] m_foodDescription;

			// 3. shallow copy (copy non-resource variables)
			strcpy(m_customerName, src.m_customerName);
			m_price = src.m_price;
			m_dailySpecial = src.m_dailySpecial;

			// 4. deep copy (copy the resource)

			if (src.m_foodDescription != nullptr && src.m_foodDescription[0] !=  '\0')
			{
				m_foodDescription = new char[strlen(src.m_foodDescription) + 1];
				strcpy(m_foodDescription, src.m_foodDescription);
			}
			else
			{
				m_foodDescription = nullptr;
			}

		}
		return *this;
	}

	// DESTRUCTOR
	FoodOrder::~FoodOrder()
	{
		// DEALLOCATE MEMORY TO PREVENT MEMORY LEAKS
		delete[] m_foodDescription;
		m_foodDescription = nullptr;
	}

	std::istream& FoodOrder::read(std::istream& is)
	{
		// READ THE DATA FROM THE FILE
		if (is) {
			char deliveryStatus;
			is.getline(m_customerName, MAX_NAME_LENGTH, ',');

			// READ THE DESCRIPTION
			string tempDescription;
			// READ THE DESCRIPTION FROM FILE
			getline(is, tempDescription, ',');
			// DEALLOCATE MEMORY TO PREVENT MEMORY LEAKS
			delete [] m_foodDescription;
			// ALLOCATE MEMORY TO PREVENT MEMORY LEAKS
			m_foodDescription = new char[tempDescription.length() + 1];

			// COPY THE DESCRIPTION TO THE MEMORY
			strcpy(m_foodDescription, tempDescription.c_str());

			// READ THE PRICE
			is >> m_price;
			is.ignore();

			// READ THE DELIVERY STATUS
			is >> deliveryStatus;
			m_dailySpecial = (deliveryStatus == 'Y') ? true : false;
		}
		return is;
	}

	ostream& FoodOrder::display(std::ostream& os) const
	{
		// CREATE A COUNTER TO KEEP TRACK OF THE NUMBER OF ORDERS UNTILPROGRAM ENDS
		static int counter = 0;
		counter++;
		os << left 
			<< setw(2) 
			<< counter 
			<< ". ";
		if (m_customerName[0] != '\0') {

			double priceWithTax = m_price * (1 + g_taxrate);

			os <<left<<setw(MAX_NAME_LENGTH)<<m_customerName<<"|"
				<<left<<setw(MAX_DESC_LENGTH)<< m_foodDescription<< "|"
				<<left<<setw(12)<<fixed<<setprecision(2)
				<<priceWithTax 
				<< "|";
			if (m_dailySpecial) 
			{
				os << right
					<< setw(13)
					<< priceWithTax - g_dailydiscount;
			}
			os << endl;
		}
		else {
			os << "No Order" << endl;
		}

		return os;
	}

}