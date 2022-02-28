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
    vector<int> binaryNumberVectorWithParity = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> parity1BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> parity2BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> parity4BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> parity8BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    bool evenParityBool;
    int parityBit1;
    int parityBit2;
    int parityBit4;
    int parityBit8;

public:

    Hamming();
    bool verify(string parity);
    void generateHammingCode(string binaryNumberString);
    int xorOperation(int bit1, int bit2);
    int getBinaryNumber() const;
    void setBinaryNumber(string binaryNumber);
    void generateBinaryNumberVector();
    void generateBinaryNumberVectorWithParity();
    void generateParityVectorWithParity(int bit, vector<int> vec, vector<int> *vecWithParity);
    void calculateParityBit(int bit);
    void printVectorContents(string vectorName, vector<int> vector);

    void printParityTable();
};


#endif //DLOGICO_PROYECTO1_HAMMING_H
