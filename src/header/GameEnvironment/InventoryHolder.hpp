#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP
#include <vector>

using std::vector;

class InventoryHolder {
public:
    virtual ~InventoryHolder();

    // Returns the number of items in the inventory
    virtual int countItems() const = 0;

    // Adds an item to the inventory
    virtual void addItem() = 0;

    // Removes an item from the inventory
    virtual void removeItem() = 0;
};

#endif