#ifndef IO_HPP
#define IO_HPP

class IO {
    private:
    int choice;
    public:

    IO();

    // get integer input in range [lowerBound, upperBound]
    void getChoice(int lowerBound, int upperBound);

    bool operator==(const int);
    int getChoice() const;
};

#endif