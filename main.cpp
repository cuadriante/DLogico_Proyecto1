#include <iostream>
#include <sstream>

using namespace std;

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
                bool valid = true; //Boolean used to verify the validity of the input
                cin >> input;
                int length = input.length(); //length of the input

                if (length == 3){ // Length validation
                    int i = 0;
                    while (i < 3){ //Hexadecimal validation, nothing that isnt a number or A, B, C, D, E or F
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
                if (valid == true){ //Case when a valid input is used
                    cout<<"Awesome next step lets go"<<endl;
                    int x;
                    stringstream ss;
                    ss << hex << input;
                    ss >> x;
                    cout << "The number in the decimal form is: " << x << endl; //x is the valid hexadecimal input in decimal

                    int binary_dividend = x; //We do not want to modify x directly so we can use it for the octal conversion as well
                    int x_binary = 0;
                    int binary_remainder;
                    int binary_product = 1;
                    while (binary_dividend != 0) {
                        binary_remainder = binary_dividend % 2;
                        x_binary = x_binary + (binary_remainder * binary_product);
                        binary_dividend = binary_dividend / 2;
                        binary_product *= 10;
                    }
                    cout << "The number in the binary form is: " << x_binary << endl;

                    int octal_dividend = x;
                    int x_octal = 0;
                    int octal_remainder;
                    int octal_product = 1;
                    while (octal_dividend != 0) {
                        octal_remainder = octal_dividend % 8;
                        x_octal = x_octal + (octal_remainder * octal_product );
                        octal_dividend = octal_dividend / 8;
                        octal_product *= 10;
                    }
                    cout << "The number in the octal form is: " << x_octal << endl;

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



    /*
    string input;
    cin >> input;
    cout << "\n";
    stringstream s;
    s << hex << input;
    s >> x;
    cout << "x = " << x << "\n";
    */

    return 0;
}