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

#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <chrono>

namespace seneca {


	class TimedTask{

        struct Task {
            std::string taskName;
            std::string units;
            std::chrono::nanoseconds duration;
        };

        static const int maxNumberOfEvent = 10;
        int m_numOfRecord = 0;
        std::chrono::steady_clock::time_point m_start;
		std::chrono::steady_clock::time_point m_end;
		Task m_tasks[maxNumberOfEvent];
    public:
        TimedTask() = default;
        void startClock();
        void stopClock();
        void addTask(const char* taskName);
        friend std::ostream& operator<<(std::ostream& os, const TimedTask& task);
    };

}

#endif // !SENECA_TIMEDTASK_H
