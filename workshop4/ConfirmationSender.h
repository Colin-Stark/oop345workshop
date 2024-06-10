#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace seneca {
    class ConfirmationSender {
        const Reservation** m_reservations{ nullptr }; // Array of pointers to Reservation objects
        size_t m_cnt{ 0 }; // Number of reservations in the array

    public:
        // Default constructor
        ConfirmationSender() = default;

        // Copy constructor
        ConfirmationSender(const ConfirmationSender& src);

        // Copy assignment operator
        ConfirmationSender& operator=(const ConfirmationSender& src);

        // Move constructor
        ConfirmationSender(ConfirmationSender&& src) noexcept;

        // Move assignment operator
        ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;

        // Destructor
        ~ConfirmationSender();

        // Overloaded operator+= to add a reservation
        ConfirmationSender& operator+=(const Reservation& res);

        // Overloaded operator-= to remove a reservation
        ConfirmationSender& operator-=(const Reservation& res);

        // Friend function to output the contents of a ConfirmationSender object
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
    };
}

#endif // SENECA_CONFIRMATIONSENDER_H
