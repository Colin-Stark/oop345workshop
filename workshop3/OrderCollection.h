#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {
    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        bool operator+=(const T& item) override {
            unsigned i = 0;
            for (i = 0; i < this->size(); ++i) {
                if (item < this->m_items[i])
                    break;
            }
            for (unsigned j = this->size(); j > i; --j) {
                this->m_items[j] = this->m_items[j - 1];
            }
            this->m_items[i] = item;
            this->incrSize();
            return true;
        }
    };
}

#endif // !SENECA_ORDEREDCOLLECTION_H
