//
// Created by adri on 26-Feb-22.
//

#include "Hamming.h"


Hamming::Hamming() {

}

void Hamming::generateHammingCode(string bn) {
    cout << "Calculating Hamming Code for " << binaryNumber << " . . . " << endl;
    //initialization();
    setBinaryNumber(bn);
    calculateParityBit(1, &parityBit1);
    calculateParityBit(2, &parityBit2);
    calculateParityBit(4, &parityBit4);
    calculateParityBit(8, &parityBit8);
    generateBinaryNumberVectorWithParity(true, &binaryNumberVectorWithParity);
    generateBinaryNumberVectorWithParity(false, &binaryNumberVectorWithoutParity);
    printParityTable1();
}

void Hamming::initialization() {
    binaryNumberVector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    parity1BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    parity2BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    parity4BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    parity8BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    parityBit1 = 0;
    parityBit2 = 0;
    parityBit4 = 0;
    parityBit8 = 0;
    newParityBit1 = 0;
    newParityBit2 = 0;
    newParityBit4 = 0;
    newParityBit8 = 0;
}

void Hamming::generateHammingCode() {
    parity1BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    parity2BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    parity4BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    parity8BinaryNumberVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    calculateParityBit(1, &newParityBit1);
    calculateParityBit(2, &newParityBit2);
    calculateParityBit(4, &newParityBit4);
    calculateParityBit(8, &newParityBit8);
    generateBinaryNumberVectorWithParity(true, &binaryNumberVectorWithParity);
    generateBinaryNumberVectorWithParity(false, &binaryNumberVectorWithoutParity);
    printParityTable2();
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

void Hamming::setBinaryNumber(string bn) {
    vector<char> v;
    copy(bn.begin(), bn.end(), std::back_inserter(binaryNumberCharVector));
   // Hamming::binaryNumber = stoi(bn);
    stringstream iss(bn);
    int number;
    std::vector<int> intVector;
    while ( iss >> number )
        intVector.push_back(number);


    int i = 11;
    int condition = i - intVector.size();
    int index = intVector.size() - 1;
    while (i >= 0){
        if (i <= condition){
            break;
        } else {
            binaryNumberVector.at(i) = (int) intVector.at(index);
            index--;
        }
        i--;
    }
//    for (int i = 11; i >= 0; i--){
//        if (i == condition){
//            break;
//        } else {
//            //int currentBit = tempBinaryNumber % 10;
//            binaryNumberVector.at(i) = (int) intVector.at(i);
//            //tempBinaryNumber = tempBinaryNumber/10;
//        }
//    }

}

void Hamming::generateBinaryNumberVector() {
    cout << "Generating binary number vector . . . " << endl;
    //int tempBinaryNumber = binaryNumber;

    for (int i = binaryNumberCharVector.size() - 1; i >= 0; i--){
        //int currentBit = tempBinaryNumber % 10;
        binaryNumberVector.at(i) = (int) binaryNumberCharVector.at(i);
        //tempBinaryNumber = tempBinaryNumber/10;
    }

}

void Hamming::calculateParityBit(int bit, int *parityBit) {
    //cout << "Calculating Parity Bit " << bit << " . . . " << endl;
    *parityBit = 0;
    vector<int> parityVector = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int oneBitSum = 0;
    int increment = bit*2;
    int i = bit - 1;
    while (i <= binaryNumberVector.size() - 1) {
        for (int e = i; e <= i + bit - 1; e++) {
            //cout << "databit " << e << ": " << binaryNumberVector.at(e) << endl;
            parityVector.at(e) = binaryNumberVector.at(e);
            if (binaryNumberVector.at(e) == 1) {
                oneBitSum++;
            }
            //cout << "sum: " << oneBitSum << endl;
            if (e == binaryNumberVector.size() - 1) {
                break;
            }
        }
        i = i + increment;
    }
   // cout << "Final sum = "<< oneBitSum << "  . . .";
    if (oneBitSum%2 == 0){
        if (evenParityBool){
            cout << " Even ";
            *parityBit = 1;
        } else{
            cout << " Odd ";
        }
    } else {
        if (!evenParityBool){
            cout << " Odd ";
            *parityBit = 1;
        } else {
            cout << " Even ";
        }
    }
    switch(bit){
        case 1:
            generateParityVectorWithParity(bit, parityVector, &parity1BinaryNumberVector);
            break;
        case 2:
            generateParityVectorWithParity(bit, parityVector, &parity2BinaryNumberVector);
            break;
        case 4:
            generateParityVectorWithParity(bit, parityVector, &parity4BinaryNumberVector);
            break;
        case 8:
            generateParityVectorWithParity(bit, parityVector, &parity8BinaryNumberVector);
            break;
    }

    cout << "Parity: " <<  *parityBit << endl;
}

void Hamming::generateBinaryNumberVectorWithParity(bool parity, vector<int> *binaryVectorWithParity) {
    int index = 0;

    for (int i = 0; i <= 15; i++){
        if (i == 0 || i == 1 || i == 3 || i == 7){
            if (parity){
                switch(i){
                    case 0:
                        binaryVectorWithParity->at(i) = parityBit1;
                        break;
                    case 1:
                        binaryVectorWithParity->at(i) = parityBit2;
                        break;
                    case 3:
                        binaryVectorWithParity->at(i) = parityBit4;
                        break;
                    case 7:
                        binaryVectorWithParity->at(i) = parityBit8;
                        break;
                }
            } else {
                binaryVectorWithParity->at(i) = -1;
            }
        } else {
            binaryVectorWithParity->at(i) = binaryNumberVector.at(index);
            index++;
        }
    }
}

void Hamming::generateParityVectorWithParity(int bit, vector<int> vec, vector<int> *vecWithParity) {
    int index = 0;

    for (int i = 0; i <= 15; i++){
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

void Hamming::printVectorContents(string vectorName, vector<int> vector, bool parityTest) {
    cout << vectorName << ": ";
    for(int i = 0; i <= 15; i++){
        if (i > 13){
            cout << " ";
        }
        if (vector.at(i) != -1){
            cout << " " << vector.at(i) << " ";
        } else {
            cout << "   ";
        }
    }
    if (!parityTest){
        cout << endl;
    }
}

void Hamming::printParityTable1() {
    int pIndex = 1;
    int dIndex = 1;

    cout << endl;
    cout << "       Table No. 1: Parity bit Calculation with Hamming Code" << endl;
    cout << "             ";
    for (int i = 1; i <= 16; i++){
        if (i == 1 || i == 2 || i == 4 || i == 8){
            cout << "p" << pIndex;
            pIndex = pIndex*2;
        }   else {
            cout << "d" << dIndex;
            dIndex++;
        }
        cout << " ";
    }
    cout << endl;
    printVectorContents("no   parity", binaryNumberVectorWithoutParity, false);
    printVectorContents("p1         ", parity1BinaryNumberVector, false);
    printVectorContents("p2         ", parity2BinaryNumberVector, false);
    printVectorContents("p4         ", parity4BinaryNumberVector, false);
    printVectorContents("p8         ", parity8BinaryNumberVector, false);
    printVectorContents("with parity", binaryNumberVectorWithParity, false);
}

void Hamming::modifyDataBit(int position) {
    modifyDataBitVector(position, &binaryNumberVector);
    generateHammingCode();
}

void Hamming::modifyDataBitVector(int position, vector<int> *vec) {
    int index = 0;
    position = position - 1;
    if (vec->size() == 12){
        for (int i = 0; i <= 11; i++){
            if (i == position){
   //             vec->at(i) = 5;
                if (vec->at(i) == 0){
                    vec->at(i) = 1;
                }
                if (vec->at(i) == 1){
                    vec->at(i) = 0;
                }
            }
        }
    } else {
        for (int i = 0; i <= 15; i++){
            if (i == 0 || i == 1 || i == 3 || i == 7) {
                index = index;
            } else {
                if (index == position){
                   // vec->at(index) = 5;
                    if (vec->at(index) == 0){
                        vec->at(index) = 1;
                    } else {
                        vec->at(index) = 0;
                    }

                }
                index++;
            }
        }
    }
}

void Hamming::printParityTable2() {
    int pIndex = 1;
    int dIndex = 1;

    cout << endl;
    cout << "               Table No.2: Parity bit Verification with Hamming Code" << endl;
    cout << "             ";
    for (int i = 1; i <= 16; i++){
        if (i == 1 || i == 2 || i == 4 || i == 8){
            cout << "p" << pIndex;
            pIndex = pIndex*2;
        }   else {
            cout << "d" << dIndex;
            dIndex++;
        }
        cout << " ";
    }
    cout << "   Parity Test    Parity Bit" << endl;
    printVectorContents("no   parity", binaryNumberVectorWithoutParity, false);
    printVectorContents("p1         ", parity1BinaryNumberVector, true);
    parityTest(parityBit1, newParityBit1);
    printVectorContents("p2         ", parity2BinaryNumberVector, true);
    parityTest(parityBit2, newParityBit2);
    printVectorContents("p4         ", parity4BinaryNumberVector, true);
    parityTest(parityBit4, newParityBit4);
    printVectorContents("p8         ", parity8BinaryNumberVector, true);
    parityTest(parityBit8, newParityBit8);
    printVectorContents("with parity", binaryNumberVectorWithParity, false);
}

void Hamming::parityTest(int parity1, int parity2) {
    if (parity1 != parity2){
        cout << "     Error  ";
    } else {
        cout << "     Correct";
    }
    cout << "            " << parity2 << "   " << endl;

}


