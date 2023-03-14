#ifndef IO_HPP
#define IO_HPP

class IO {
    private:
    int choice;
    public:
    
    // Ctor
    IO();

    // ========== Operators ==========

    bool operator==(const int);

    // ========== Getters ==========
    
    int getChoice() const;

    // ========== Other Method ========== 

    // get integer input in range [lowerBound, upperBound]
    void getInput(int lowerBound, int upperBound);

    // ========== Static Method ========== 

    static void newl();
    static void border();
    
};

#endif