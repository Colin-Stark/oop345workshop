/*
*                             Workshop - #1 Part 1
* Full Name  : COLLINS OLOKPEDJE
* Student ID#: 183341213
* Date	   : May 26, 2024
*
* Authenticity Declaration:
* I declare this submission is the result of my own work and has not been
* shared with any other student or 3rd party content provider. This submitted
* piece of work is entirely of my own creation.
*/


#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <iostream>

namespace seneca {
	class ProteinDatabase {
		std::string* m_protein{ nullptr };
		size_t m_size{ 0 };
	public:

		//NO ARGUEMENT DEFAULT CONSTRUCTOR
		ProteinDatabase() = default; 

		//ONE ARGUEMENT CONSTRUCTOR
		ProteinDatabase(const std::string& filename); 

		
		//COPY CONSTRUCTOR
		ProteinDatabase(const ProteinDatabase& src); 

		// MOVE CONSTRUCTOR
		ProteinDatabase(ProteinDatabase&& src);

		// COPY ASSIGNMENT
		ProteinDatabase& operator=(const ProteinDatabase& src);

		// MOVE ASSIGNMENT
		ProteinDatabase& operator=(ProteinDatabase&& src);

		//DESTRUCTOR
		~ProteinDatabase(); 

		size_t size() const;

		std::string operator[](size_t index) const;
	};
}

#endif // !SENECA_PROTEINDATABASE_H
