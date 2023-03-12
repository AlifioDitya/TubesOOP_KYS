#ifndef CARDINTERFACE_HPP
#define CARDINTERFACE_HPP

class CardInterface {
   protected:
    double value;

   public:
    CardInterface(double);
    virtual ~CardInterface();
    // Getter for value as specified weights in spec
    double virtual getValue() const = 0;

    // Comparison operators
    bool operator==(const CardInterface&);
    bool operator>(const CardInterface&);
    bool operator<(const CardInterface&);
    bool operator>=(const CardInterface&);
    bool operator<=(const CardInterface&);
};

#endif