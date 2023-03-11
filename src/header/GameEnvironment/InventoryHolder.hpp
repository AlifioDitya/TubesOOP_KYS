#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include "./Cards/Card.hpp"

template <class T>
class InventoryHolder {

public:
    virtual ~InventoryHolder();

    // Returns the number of items in the inventory
    virtual int countItems() const = 0;

    // Adds an item to the inventory
    virtual void addItem(T) = 0;

    // Removes all item from the inventory
    virtual void clear() = 0;
};

#endif