#ifndef DLOGICO_PROYECTO1_NUMBER_H
#define DLOGICO_PROYECTO1_NUMBER_H

#include <string>
#include <cmath>

using namespace std;

class Number{ //Class to represent the general existence of the number, and all number forms of it
public:
    bool valid{}; //Boolean used to verify the validity of the input
    int length{}; //length of the input
    int num_decimal{};
    string num_binary;

    int num_octal{};

    bool verify (string input);

    int hex_to_decimal(string input);

    int decimal_to_octal();

    string decimal_to_binary();

    string binary_to_NRZI();
};

#endif //DLOGICO_PROYECTO1_NUMBER_H
