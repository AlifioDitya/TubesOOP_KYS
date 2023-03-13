#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include "../Cards/Card.hpp"

template <class T>
class InventoryHolder {

public:

    // dtor
    virtual ~InventoryHolder() {
        
    }

    // ========== Getters ==========

    // Returns the number of items in the inventory
    virtual int countItems() const = 0;

    // ========== Other Methods ==========

    // Adds an item to the inventory
    virtual void addItem(const T&) = 0;

    // Removes all item from the inventory
    virtual void clear() = 0;
};


#endif