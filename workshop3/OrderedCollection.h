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


#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {

    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        bool operator+=(const T& item) {
            if (this->size() < this->capacity()) {
                unsigned index = 0;

                while (index < this->size() && item > this->m_items[index]) {
                    index++;
                }

                for (unsigned i = this->size(); i > index; i--) {
                    this->m_items[i] = this->m_items[i - 1];
                }
                this->operator[](index) = item;
                this->incrSize(); 
                return true;
            }
            return false;
        }
    };

}

#endif // !SENECA_ORDEREDCOLLECTION_H
