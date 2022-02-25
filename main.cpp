#include <iostream>
#include <cmath>

using namespace std;

class Number{ //Class to represent the general existence of the number, and all number forms of it
    public:
        bool valid{}; //Boolean used to verify the validity of the input
        int length{}; //length of the input
        int num_decimal{};
        string num_binary;
        int num_octal{};

        bool verify (string input){
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

        int hex_to_decimal(string input){
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

        int decimal_to_octal(){  //Doesn't work for binary bc of issue with giant binary representations
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

        string decimal_to_binary(){
            int dividend = num_decimal;
            string result;
            int remainder;
            while (dividend != 0) {
                remainder = dividend % 2;
                if (remainder == 0){
                    result = '0' + result;
                }
                else{
                    result = '1' + result;
                }
                dividend = dividend / 2;
            }
            num_binary = result;
            return result;
        }
};

int main() {
    bool on = true; //Boolean to indicate whether the user still wishes to use the program
    int option; //Integer to indicate which option the user chooses in the main menu

    while(on){
        cout<<"Welcome to the parity error detection app! What would you like to do?"<<endl;
        cout<<"Type the number corresponding to the option you'd like to pick"<<endl;
        cout<<"1. Input a hexadecimal number"<<endl;
        cout<<"2. Close the app"<<endl;
        cin>>option;
        switch(option){ //Navigation of the main menu
            case 1: //Hexadecimal input chosen
            {
                cout<<"Please input your hexadecimal input from 000 to FFF"<<endl;
                string input; //string to receive any input the user puts
                Number num;
                cin >> input;

                if (num.verify(input)){ //Case when a valid input is used
                    cout<<"Awesome next step lets go"<<endl;
                    cout << "The number in the decimal form is: " << num.hex_to_decimal(input) << endl; //the valid hexadecimal input in decimal
                    cout << "The number in the binary form is: " << num.decimal_to_binary() << endl;
                    cout << "The number in the octal form is: " << num.decimal_to_octal() << endl;
                }
                else { //Case when the users input is invalid
                    cout<<"Please input a valid number"<<endl;
                }
                break;
            }
            case 2:
                on = false;
                break;
            default:
                cout<<"Please choose a valid option"<<endl;
                break;
        }

        cout<<"\n"<<endl;
    }
    cout<<"The program will now shut down"<<endl;

    return 0;
}