#ifndef CARDINTERFACE_HPP
#define CARDINTERFACE_HPP

class CardInterface {
   public:
    // CTOR
    CardInterface();

    // DTOR
    virtual ~CardInterface();

    // Getter for value as specified weights in spec
    float virtual getValue() const = 0;
};

#endif