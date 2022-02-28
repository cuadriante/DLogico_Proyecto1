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
    calculateParityBit(8);
    generateBinaryNumberVectorWithParity();
    printVectorContents("p1    ", parity1BinaryNumberVector);
    printVectorContents("p2    ", parity2BinaryNumberVector);
    printVectorContents("p4    ", parity4BinaryNumberVector);
    printVectorContents("p8    ", parity8BinaryNumberVector);
    printVectorContents("number", binaryNumberVectorWithParity);
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
    cout << "Calculating Parity Bit " << bit << " . . . " << endl;
    int parity = 0;
    vector<int> parityVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int oneBitSum = 0;
    int increment = bit*2;
    int i = bit - 1;
    while (i <= binaryNumberVector.size() - 1) {
        for (int e = i; e <= i + bit - 1; e++) {
            cout << "databit " << e << ": " << binaryNumberVector.at(e) << endl;
            parityVector.at(e) = binaryNumberVector.at(e);
            if (binaryNumberVector.at(e) == 1) {
                oneBitSum++;
            }
            cout << "sum: " << oneBitSum << endl;
            if (e == binaryNumberVector.size() - 1) {
                break;
            }
        }
        i = i + increment;
    }
    cout << "Final sum = "<< oneBitSum << "  . . .";
    if (oneBitSum%2 == 0){
        if (evenParityBool){
            cout << " Even ";
            parity = 1;
        } else{
            cout << " Odd ";
        }
    } else {
        if (!evenParityBool){
            cout << " Odd ";
            parity = 1;
        } else {
            cout << " Even ";
        }
    }
    switch(bit){
        case 1:
            parityBit1 = parity;
            //parity1BinaryNumberVector = parityVector;
            generateParityVectorWithParity(bit, parityVector, &parity1BinaryNumberVector);
            break;
        case 2:
            parityBit2 = parity;
            //parity2BinaryNumberVector = parityVector;
            generateParityVectorWithParity(bit, parityVector, &parity2BinaryNumberVector);
            break;
        case 4:
            parityBit4 = parity;
            //parity2BinaryNumberVector = parityVector;
            generateParityVectorWithParity(bit, parityVector, &parity4BinaryNumberVector);
            break;
        case 8:
            parityBit8 = parity;
            //parity8BinaryNumberVector = parityVector;
            generateParityVectorWithParity(bit, parityVector, &parity8BinaryNumberVector);
            break;
    }

    cout << "Parity: " << parity << endl;
}

void Hamming::generateBinaryNumberVectorWithParity() {
    //cout << "Generating binary number vector . . . " << endl;
    int tempBinaryNumber = binaryNumber;
    for (int i = 14; i >= 0; i--){
        if (i == 0 || i == 1 || i == 3 || i == 7){
            switch(i){
                case 0:
                    binaryNumberVectorWithParity.at(i) = parityBit1;
                    break;
                case 1:
                    binaryNumberVectorWithParity.at(i) = parityBit2;
                    break;
                case 3:
                    binaryNumberVectorWithParity.at(i) = parityBit4;
                    break;
                case 7:
                    binaryNumberVectorWithParity.at(i) = parityBit8;
                    break;
            }
        } else {

            int currentBit = tempBinaryNumber % 10;
            binaryNumberVectorWithParity.at(i) = currentBit;
            tempBinaryNumber = tempBinaryNumber/10;
        }
    }
}

void Hamming::generateParityVectorWithParity(int bit, vector<int> vec, vector<int> *vecWithParity) {
    int tempBinaryNumber = binaryNumber;
    int index = 0;

    for (int i = 0; i <= 14; i++){
        if (i == 0 || i == 1 || i == 3 || i == 7){
            if (i == bit - 1){
                switch(i){
                    case 0:
                        vecWithParity->at(i) = parityBit1;
                        break;
                    case 1:
                        vecWithParity->at(i) = parityBit2;
                        break;
                    case 3:
                        vecWithParity->at(i) = parityBit4;
                        break;
                    case 7:
                        vecWithParity->at(i) = parityBit8;
                        break;
                }
            } else {
                vecWithParity->at(i) = -1;
            }
        } else {
            vecWithParity->at(i) = vec.at(index);
            index++;
        }
    }
}

void Hamming::printVectorContents(string vectorName, vector<int> vector) {
    cout << vectorName << ": ";
    for(int element: vector){
        cout << element;
    }
    cout << endl;
}

