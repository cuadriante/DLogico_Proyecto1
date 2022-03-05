#include "Number.h"

using namespace std;

bool Number::verify (string input){
    valid = true;
    length = input.length();
    if (length == 3){ // Length validation
        int i = 0;
        while (i < 3){ //Hexadecimal validation, nothing that isn't a number or A, B, C, D, E or F
            switch(input.at(i)){
                case '0':
                    break;
                case '1':
                    break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    break;
                case '5':
                    break;
                case '6':
                    break;
                case '7':
                    break;
                case '8':
                    break;
                case '9':
                    break;
                case 'A':
                    break;
                case 'B':
                    break;
                case 'C':
                    break;
                case 'D':
                    break;
                case 'E':
                    break;
                case 'F':
                    break;
                default: //The input contains an unknown letter or symbol
                    valid = false;
                    i += 4;
                    break;
            }
            i += 1;
        }
    } else { //The input does not have a length of 3
        valid = false;
    }
    return valid;
}

int Number::hex_to_decimal(string input){
    num_decimal = 0;
    int i = 0;
    int exp = 2;
    while (i < 3){
        switch(input.at(i)){
            case '0':
                exp -= 1;
                break;
            case '1':
                num_decimal += (1 * pow(16,exp));
                exp -= 1;
                break;
            case '2':
                num_decimal += (2 * pow(16,exp));
                exp -= 1;
                break;
            case '3':
                num_decimal += (3 * pow(16,exp));
                exp -= 1;
                break;
            case '4':
                num_decimal += (4 * pow(16,exp));
                exp -= 1;
                break;
            case '5':
                num_decimal += (5 * pow(16,exp));
                exp -= 1;
                break;
            case '6':
                num_decimal += (6 * pow(16,exp));
                exp -= 1;
                break;
            case '7':
                num_decimal += (7 * pow(16,exp));
                exp -= 1;
                break;
            case '8':
                num_decimal += (8 * pow(16,exp));
                exp -= 1;
                break;
            case '9':
                num_decimal += (9 * pow(16,exp));
                exp -= 1;
                break;
            case 'A':
                num_decimal += (10 * pow(16,exp));
                exp -= 1;
                break;
            case 'B':
                num_decimal += (11 * pow(16,exp));
                exp -= 1;
                break;
            case 'C':
                num_decimal += (12 * pow(16,exp));
                exp -= 1;
                break;
            case 'D':
                num_decimal += (13 * pow(16,exp));
                exp -= 1;
                break;
            case 'E':
                num_decimal += (14 * pow(16,exp));
                exp -= 1;
                break;
            case 'F':
                num_decimal += (15 * pow(16,exp));
                exp -= 1;
                break;
        }
        i += 1;
    }
    return num_decimal;
}

int Number::decimal_to_octal(){  //Doesn't work for binary bc of issue with giant binary representations
    int dividend = num_decimal;
    int result = 0;
    int remainder;
    int product = 1;
    while (dividend != 0) {
        remainder = dividend % 8;
        result = result + (remainder * product);
        dividend = dividend / 8;
        product *= 10;
    }
    num_octal = result;
    return result;
}

string Number::decimal_to_binary(){
    int dividend = num_decimal;
    string result;
    int remainder;
    while (dividend != 0) {
        remainder = dividend % 2;
        if (remainder == 0){
            result = "0 " + result;
        }
        else{
            result = "1 " + result ;
        }
        dividend = dividend / 2;
    }

    int post_len = result.length();
    if (post_len < 24){
        while (post_len < 24){
            result = "0 " + result;
            post_len += 2;
        }
    }

    num_binary = result;
    return num_binary;
}

string Number::binary_to_NRZI(){
    int len = num_binary.length();
    string result;
    int j;
    for (int i = 0; i < len; i += 2) {
        if (i > 0){
            if (num_binary[i] == '0'){
                result += result[j-1];
            }
            else{
                if (result[j-1] == '_'){
                    result += "|-";
                }
                else{
                    result += "|_";
                }
                j += 1;
            }
            j += 1;
        }
        else {
            if (num_binary[i] == '0'){
                result = "_";
                j = 1;
            }
            else{
                result = "|-";
                j = 2;
            }
        }
    }
    return result;
}
