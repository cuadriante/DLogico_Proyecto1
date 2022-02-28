//
// Created by adri on 26-Feb-22.
//

#include "Hamming.h"


Hamming::Hamming() {

}

void Hamming::generateHammingCode(string binaryNumberString) {
    cout << "Calculating Hamming Code for " << binaryNumber << " . . . " << endl;
    setBinaryNumber(binaryNumberString);
    generateBinaryNumberVector();
    calculateParityBit(1);
    calculateParityBit(2);
    calculateParityBit(4);
    //calculateParityBit(8);

}

bool Hamming::verify(string parity) {
    if (parity == "o" || parity == "O"){
        evenParityBool = false;
        return true;
    }
    else if (parity == "e" || parity == "E"){
        evenParityBool = true;
        return true;
    } else {
        return false;
    }
}

int Hamming::xorOperation(int bit1, int bit2) {
    int result = bit1 ^ bit2; // xor
    cout << result << endl;
    return result;
}

int Hamming::getBinaryNumber() const {
    return binaryNumber;
}

void Hamming::setBinaryNumber(string binaryNumber) {
    Hamming::binaryNumber = stoi(binaryNumber);

}

void Hamming::generateBinaryNumberVector() {
    cout << "Generating binary number vector . . . " << endl;
    int tempBinaryNumber = binaryNumber;

    for (int i = 11; i >= 0; i--){
        int currentBit = tempBinaryNumber % 10;
        binaryNumberVector.at(i) = currentBit;
        tempBinaryNumber = tempBinaryNumber/10;
    }

}

void Hamming::calculateParityBit(int bit) {
    cout << "Calculating Parity Bit " << bit << " . . . ";
    int parity = 0;
    int oneBitSum = 0;
    for (int i = 0; i <= binaryNumberVector.size() - 1; i ++){
        i = i + bit - 1;
        for (int e = i; e <= i + bit - 1; e++) {
            if (e == binaryNumberVector.size() - 1){
                break;
            }
            if (binaryNumberVector.at(e) == 1) {
                oneBitSum++;
            }
        }
    }
    cout << "Sum = "<< oneBitSum << "  . . .";
    if (oneBitSum%2 == 0){
        if (evenParityBool){
            parity = 1;
        }
    } else {
        if (!evenParityBool){
            parity = 1;
        }
    }
    cout << "Parity:" << parity << endl;

}

