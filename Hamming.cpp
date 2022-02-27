//
// Created by adri on 26-Feb-22.
//

#include "Hamming.h"


Hamming::Hamming() {

}

bool Hamming::verify(string parity) {
    if (parity == "o" || parity == "O"){
        even = false;
        return true;
    }
    else if (parity == "e" || parity == "E"){
        even = true;
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

void Hamming::numberToVector() {

}

int Hamming::getBinaryNumber() const {
    return binaryNumber;
}

void Hamming::setBinaryNumberAndVector(string binaryNumber) {
    Hamming::binaryNumber = stoi(binaryNumber);
    cout << "Calculating Hamming Code for " << binaryNumber << " . . . " << endl;
    setBinaryNumberVector();
}

void Hamming::setBinaryNumberVector() {
    int tempBinaryNumber = binaryNumber;

    cout << "TEST! Binary Vector: ";
    for (int i = 11; i >= 0; i--){
        int currentBit = tempBinaryNumber % 10;
        binaryNumberVector.at(i) = currentBit;
        tempBinaryNumber = tempBinaryNumber/10;
        cout << binaryNumberVector.at(i);

    }
    cout << endl;
    Hamming::binaryNumberVector = binaryNumberVector;
}
