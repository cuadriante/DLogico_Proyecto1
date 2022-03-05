#include <iostream>
#include "Number.h"
#include "Hamming.h"

bool inputParity();

using namespace std;
Hamming hamming;

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
                cout<<"Please type your hexadecimal input from 000 to FFF"<<endl;
                string input; //string to receive any input the user puts
                Number num;
                cin >> input;

                if (num.verify(input)){ //Case when a valid input is used

                    cout<<"Awesome! next step lets go"<<endl;
                    cout << "The number in the decimal form is: " << num.hex_to_decimal(input) << endl; //the valid hexadecimal input in decimal
                    cout << "The number in the binary form is: " << num.decimal_to_binary() << endl;
                    cout << "The number in the octal form is: " << num.decimal_to_octal() << endl;

                    cout << "The number in NRZI Form is: " << num.binary_to_NRZI() << endl;

                    if (inputParity()){
                        cout << "Great!" << endl;
                        hamming.generateHammingCode(num.decimal_to_binary());

                        cout << "Which data bit position would you like to change? (Range: 1-12)" << endl;
                        int pos;
                        cin >> pos;
                        if (1 <= pos && pos <= 12){
                            hamming.modifyDataBit(pos);
                        } else {
                            cout << "Invalid position." << endl;
                        }


                    } else {
                        cout << "Invalid parity." << endl;
                    }

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

bool inputParity() {
    cout << "Please choose between odd parity and even parity (O/E)" << endl;
    string parityInput; //string to receive any input the user puts
    cin >> parityInput;
    //Hamming hamming;
    if (hamming.verify(parityInput)){
        return true;
    } else {

        return false;
    }
}
