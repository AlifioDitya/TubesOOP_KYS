/**
 * @file InventoryHolder.hpp
 * @brief Header file for the InventoryHolder abstract base class. This class defines an abstract base class
 * that holds the inventory of different types of objects specified by the class that inherits this base class.
 * 
 */
#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include "../Cards/Card.hpp"

/**
 * @class InventoryHolder
 * @brief an Abstract base class for a child class that holds an inventory
 * 
 * @tparam T Element of the inventory
 */
template <class T>
class InventoryHolder {

public:

    /**
     * @brief Destroy the Inventory Holder object
     * 
     */
    virtual ~InventoryHolder() {
        
    }

    /**
     * @brief Returns the number of items in the inventory.
     * 
     * @return the Number of items in the inventory 
     */
    virtual int countItems() const = 0;

    /**
     * @brief Adds an item to the inventory
     * 
     */
    virtual void addItem(const T&) = 0;

    /**
     * @brief Removes all of the items in the inventory
     * 
     */
    virtual void clear() = 0;
};


#endif