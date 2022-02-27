//
// Created by adri on 26-Feb-22.
//

#ifndef DLOGICO_PROYECTO1_HAMMING_H
#define DLOGICO_PROYECTO1_HAMMING_H
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Hamming {
private:

    int binaryNumber;
    vector<int> binaryNumberVector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool even;
    int parityBit1;
    int parityBit2;
    int parityBit4;

public:

    Hamming();
    bool verify(string parity);
    int xorOperation(int bit1, int bit2);
    void numberToVector();
    int getBinaryNumber() const;
    void setBinaryNumberAndVector(string binaryNumber);

    void setBinaryNumberVector();
};


#endif //DLOGICO_PROYECTO1_HAMMING_H
