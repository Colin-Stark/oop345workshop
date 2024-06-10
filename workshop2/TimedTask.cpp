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
#include <iomanip>
#include "TimedTask.h"
using namespace std;

namespace seneca {
	void TimedTask::startClock()
	{
		m_start = chrono::steady_clock::now();
	}
	void TimedTask::stopClock()
	{
		m_end = chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* tName)
	{
		if (m_numOfRecord < maxNumberOfEvent) {
			m_tasks[m_numOfRecord].taskName = tName;
			m_tasks[m_numOfRecord].units = "nanoseconds";
			m_tasks[m_numOfRecord].duration = chrono::duration_cast<chrono::nanoseconds>(m_end - m_start);
			m_numOfRecord++;
		}
	}
	std::ostream& operator<<(std::ostream& os, const TimedTask& task)
	{
		os  <<"--------------------------" << endl 
			<< "Execution Times:" <<endl
			<<"--------------------------"<<endl;
		for (int i = 0; i < task.m_numOfRecord; i++) {
			os << left 
				<< setw(21) 
				<< task.m_tasks[i].taskName 
				<< right
				<< setw(13) 
				<< task.m_tasks[i].duration.count() 
				<< " "
				<< task.m_tasks[i].units << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}
