//
// Created by adri on 26-Feb-22.
//

#ifndef DLOGICO_PROYECTO1_HAMMING_H
#define DLOGICO_PROYECTO1_HAMMING_H
#include <string>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

class Hamming {
private:
    string initialBinaryNumberString;
    int binaryNumber;
    vector<int> binaryNumberCharVector;
    vector<int> binaryNumberVector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> binaryNumberVectorWithParity = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> binaryNumberVectorWithoutParity = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> parity1BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> parity2BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> parity4BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> parity8BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> incorrectBitVector;
    bool evenParityBool;
    int parityBit1;
    int parityBit2;
    int parityBit4;
    int parityBit8;
    int newParityBit1;
    int newParityBit2;
    int newParityBit4;
    int newParityBit8;
    int incorrectBit;

public:

    Hamming();
    bool verify(string parity);
    void generateHammingCode(string bn);
    void generateHammingCode();
    void setBinaryNumber(string bn);
    void generateBinaryNumberVector();
    void generateBinaryNumberVectorWithParity(bool parity, vector<int> *binaryVectorWithParity);
    void generateParityVectorWithParity(int bit, vector<int> vec, vector<int> *vecWithParity);
    void calculateParityBit(int bit, int *parityBit);
    void printVectorContents(string vectorName, vector<int> vector, bool parityTest);
    void modifyDataBit(int position);
    void modifyDataBitVector(int position, vector<int> *vec);
    void parityTest(int parity1, int parity2, int bit);

    void printParityTable1();
    void printParityTable2();

    void initialization();
};


#endif //DLOGICO_PROYECTO1_HAMMING_H
