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



#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include "Book.h"

namespace seneca {
	template <typename T, unsigned C>
	class Collection {
		

		static T m_smallestItem;
		static T m_largestItem;

	protected:

		T m_items[C];
		unsigned m_size{ 0 };

		void setSmallestItem(const T& item);
		void setLargestItem(const T& item);
		

		// PART 2
		T& operator[](unsigned index) {
			return m_items[index];
		}
		void incrSize() {
			m_size++;
		}

	public:

		T getSmallestItem() const;
		T getLargestItem() const;

		
		unsigned size() const;
		unsigned capacity() const;
		bool operator+=(const T& item);
		std::ostream& print(std::ostream& os) const;

	};

	template <typename T, unsigned C>
	T Collection<T, C>::m_smallestItem;

	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem;

	template<>
	int Collection<int, 10>::m_smallestItem = 9999;

	template<>
	int Collection<int, 10>::m_largestItem = -9999;

	template<>
	double Collection<double, 10>::m_smallestItem = 9999.0;

	template<>
	double Collection<double, 10>::m_largestItem = -9999.0;


	// PART 2 SPECIALIZATION

template<>
Book Collection<Book, 72>::m_smallestItem = Book("", 10000, 1);

template<>
Book Collection<Book, 72>::m_largestItem = Book("", 1, 10000);

template<>
std::ostream& Collection<Book, 10>::print(std::ostream& os) const{
	os  << "| "
		<< "---------------------------------------------------------------------------|" 
		<< std::endl;
	for (unsigned i = 0; i < m_size; i++)
	{
		os << "| " << m_items[i] << " |" << std::endl;
	}
	os << "| "
		<< "---------------------------------------------------------------------------"
		<<"| " << std::endl;
	return os;
}

template <>
std::ostream& Collection<Book, 72>::print(std::ostream& os) const {
	os << "| "
		<< "---------------------------------------------------------------------------|"
		<< std::endl;
	for (unsigned i = 0; i < m_size; i++)
	{
		os << "| " << m_items[i] << " |" << std::endl;
	}
	os << "| "
		<< "---------------------------------------------------------------------------"
		<< "| " << std::endl;
	return os;
}


	template <typename T, unsigned C>
	void Collection<T, C>::setSmallestItem(const T& item) {
		if (item < m_smallestItem) {
			m_smallestItem = item;
		}
	}

	template <typename T, unsigned C>
	void Collection<T, C>::setLargestItem(const T& item) {
		if (item > m_largestItem) {
			m_largestItem = item;
		}
	}

	template <typename T, unsigned C>
	T Collection<T, C>::getSmallestItem() const {
		return m_smallestItem;
	}

	template <typename T, unsigned C>
	T Collection<T, C>::getLargestItem() const {
		return m_largestItem;
	}

	template <typename T, unsigned C>
	unsigned Collection<T, C>::size() const {
		return m_size;
	}

	template <typename T, unsigned C>
	unsigned Collection<T, C>::capacity() const {
		return C;
	}

	template <typename T, unsigned C>
	bool Collection<T, C>::operator+=(const T& item) {
		if (m_size < C) {
			m_items[m_size] = item;
			m_size++;
			setSmallestItem(item);
			setLargestItem(item);
			return true;
		}
		else {
			return false;
		}
	}

	template <typename T, unsigned C>
	std::ostream& Collection<T, C>::print(std::ostream& os) const {
		os << "[";
		for (unsigned i = 0; i < m_size; i++) {
			os << m_items[i];
				if(i < m_size - 1) {
					os << ",";
				}
		}
		os << "]" << std::endl;
		return os;
	}

	template <typename T, unsigned C>
	std::ostream& operator<<(std::ostream& os, const Collection<T, C>& collection) {
		collection.print(os);
		return os;
	}

	

}

#endif // !SENECA_COLLECTION_H
