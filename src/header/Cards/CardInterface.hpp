#ifndef CARDINTERFACE_HPP
#define CARDINTERFACE_HPP

class CardInterface {
   protected:
    double value;

   public:
    CardInterface(double);
    virtual ~CardInterface();

    // ========== Operators ==========

    bool operator==(const CardInterface&);
    bool operator>(const CardInterface&);
    bool operator<(const CardInterface&);
    bool operator>=(const CardInterface&);
    bool operator<=(const CardInterface&);

    // ========== Getters ==========
    
    // Getter for value as specified weights
    double virtual getValue() const = 0;
};

#endif