#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

string floattoBinary(string floatPart) {
    string str;

    string fixedFloat = "0.";
    fixedFloat.append(floatPart);

    float floatValueofString = stof(fixedFloat);
    while(floatValueofString != 0){
        floatValueofString *= 2;
        if (floatValueofString >= 1) {
            str.append("1");
            floatValueofString -= 1;
        }
        else{
            str.append("0");
        }
    }

    reverse(str.begin(), str.end());


    return str;
}


string decimaltoBinary(string integerPart) {
    string str;

    int integerValueofString = stoi(integerPart);
    while(integerValueofString != 0) {
        if (integerValueofString % 2 == 1) {
            str.append("1");
            integerValueofString -= 1;
        }
        else {
            str.append("0");
        }
        integerValueofString /= 2;
    }
    reverse(str.begin(), str.end());

    return str;
}


string printStart(){
    cout << endl << "------------" << endl ;
    cout << "enter a number: ";
    string number;
    cin >> number;
    return number;
}

int main() {

    string input = printStart();
    while(input != "q" && input != "Q" ){

        cout << "entered number : " << input << endl;


        std::string delimiter = ".";
        std::string integerPart = input.substr(0, input.find(delimiter));
        string originalInput = input;
        input.erase(0, input.find(delimiter) + delimiter.length());
        std::string floatPart= input.substr(0, input.find(delimiter));
        if (originalInput.compare(input) == 0){
            floatPart = "0";
        }

        cout << "integer Part: " << integerPart << endl << "Float Part: " << floatPart << endl;
        //for integer part

        string binaryTypeIntegerPart = decimaltoBinary(integerPart);
        string binaryTypeFloatPart = floattoBinary(floatPart);

        string fullBinary;
        fullBinary.append(binaryTypeIntegerPart);
        fullBinary.append(".");
        fullBinary.append(binaryTypeFloatPart);

        cout << "binary version of the number is: " << endl << "\t";
        cout << fullBinary;


        input = printStart();
    }
    if (input != "q" && input != "Q" ){
        cout << "PROGRAM TERMINATED" << endl;
    }

return 0;
}



