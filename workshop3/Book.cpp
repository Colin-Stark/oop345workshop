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


#include "Book.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace seneca {

	Book::Book()
	{
		m_title = "";
		m_numChapters = 0u;
		m_numPages = 0u;
	}

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
	{
			m_title = title;
			m_numChapters = nChapters;
			m_numPages = nPages;
			
	}

	bool Book::isValid() const
	{
		return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
	}

	double Book::getRatio() const
	{
		return static_cast<double>(m_numPages) / m_numChapters;
	}

	bool Book::operator<(const Book& other) const
	{
		return getRatio() < other.getRatio();
	}

	bool Book::operator>(const Book& other) const
	{
		return getRatio() > other.getRatio();
	}

	std::ostream& Book::print(std::ostream& os) const
	{
		if (isValid()) {
			os	<< right
				<< setw(56)
				<< m_title 
				+ "," 
				+ to_string(m_numChapters)
				+ ","
				+ to_string(m_numPages)
				<< " | "
				<< left
				<< setw(15)
				<< "("
				+to_string(getRatio())
				+")";
		}
		else {
			os << "| Invalid book data";
		}
		return os;
	}

	bool operator>(const Book& lhs, const Book& rhs)
	{
		return lhs.getRatio() > rhs.getRatio();
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		return bk.print(os);
		return os;
	}
}