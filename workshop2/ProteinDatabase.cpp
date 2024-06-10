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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "ProteinDatabase.h"
using namespace std;

namespace seneca{
	ProteinDatabase::ProteinDatabase(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file) {
			throw std::runtime_error("Cannot open file: " + filename);
		}

		// First pass: count the number of protein sequences
		std::string line;
		while (std::getline(file, line)) {
			if (!line.empty() && line[0] == '>') {
				++m_size;
			}
		}

		if (m_size == 0) {
			throw std::runtime_error("No protein sequences found in file: " + filename);
		}

		// Allocate memory for protein sequences
		m_protein = new std::string[m_size];

		// Second pass: read the proteins
		file.clear();
		file.seekg(0, std::ios::beg);
		std::string protein;
		size_t index = 0;

		while (std::getline(file, line)) {
			if (!line.empty() && line[0] == '>') {
				// Save the previous protein sequence if there is one
				if (!protein.empty()) {
					m_protein[index++] = protein;
					protein.clear();
				}
			}
			else if (!line.empty()) {
				protein += line;
			}
		}

		// Save the last protein sequence if there is one
		if (!protein.empty()) {
			m_protein[index++] = protein;
		}

		// Check if we have read the correct number of protein sequences
		if (index != m_size) {
			delete[] m_protein;
			throw std::runtime_error("Mismatch in the number of protein sequences read: expected " + std::to_string(m_size) + ", but read " + std::to_string(index));
		}
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src)
	{
		//DIRECT CALL TO THE COPY ASSIGNMENT OPERATOR
		m_protein = nullptr;
		*this = src;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src)
	{
		//DIRECT CALL TO THE MOVE ASSIGNMENT OPERATOR
		m_protein = nullptr;
		*this = move(src);
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		// 1. check for self-assignment (and NOTHING else)
		if (this != &src)
		{
			// 2. clean up (deallocate previously allocated dynamic memory)
			delete[] m_protein;
			// 3. shallow copy (copy non-resource variables)
			m_size = src.m_size;
			// 4. deep copy (copy the resource)
			if (src.m_size != 0)
			{
				// 4.1 allocate new dynamic memory, if needed
				m_protein = new string[m_size];
				// 4.2 copy the resource data
				for (size_t i = 0; i < m_size; i++)
				{
					m_protein[i] = src.m_protein[i];
				}
			}
			else
			{
				m_protein = nullptr;
			}
		}
		return *this;
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src)
	{
		// 1. check for self-assignment (and NOTHING else)
		if (this != &src)
		{
			// 2. clean up (deallocate previously allocated dynamic memory)
			delete[] m_protein;
			// 3. shallow copy (copy non-resource variables)
			m_size = src.m_size;
			// 4. move the resource
			m_protein = src.m_protein;
			// 5. set the source object to a safe state
			src.m_protein = nullptr;
			src.m_size = 0;
		}
		return *this;
	}

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] m_protein;
		m_protein = nullptr;
	}

	size_t ProteinDatabase::size() const
	{
		return m_size;
	}

	std::string ProteinDatabase::operator[](size_t index) const
	{
		if (index < m_size)
		{
			return m_protein[index];
		}
		else
		{
			return "";
		}
	}
}
