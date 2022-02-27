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
    bool evenParityBool;
    int parityBit1;
    int parityBit2;
    int parityBit4;

public:

    Hamming();
    bool verify(string parity);
    void generateHammingCode(string binaryNumberString);
    int xorOperation(int bit1, int bit2);
    int getBinaryNumber() const;
    void setBinaryNumber(string binaryNumber);
    void generateBinaryNumberVector();
    void calculateParityBit(int bit);
};


#endif //DLOGICO_PROYECTO1_HAMMING_H
