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


#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {
	class Book
	{
		std::string m_title;
		unsigned m_numChapters;
		unsigned m_numPages;
	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);
		bool isValid() const;
		double getRatio() const;

		bool operator<(const Book& other) const;

		bool operator>(const Book& other) const;
		
		std::ostream& print(std::ostream& os) const;

	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}

#endif // !SENECA_BOOK_H
