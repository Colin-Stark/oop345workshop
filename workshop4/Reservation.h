#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <iostream>
#include <string>

namespace seneca {

	class Reservation {
		char* m_reservationId{ nullptr };
		std::string m_name; // name of the reserver
		std::string m_email; // email of the reserver
		int m_numOfPeople{0}; // number of people in the party
		int m_day{ 0 }; // day of the reservation
		int m_hour{ 0 }; // hour of the reservation
	public:
		Reservation() = default;
		Reservation(const std::string& res);
		Reservation(const Reservation& src); // copy constructor
		Reservation(Reservation&& src) noexcept; // move constructor
		~Reservation(); // destructor
		Reservation& operator=(const Reservation& src); // copy assignment operator
		Reservation& operator=(Reservation&& src) noexcept; // move assignment operator

		void update(int day, int time); // modifier

		void display(std::ostream& os) const; // query

		friend std::ostream& operator<<(std::ostream& os, const Reservation& src); // friend helper function
	};

}

#endif // !SENECA_RESERVATION_H

