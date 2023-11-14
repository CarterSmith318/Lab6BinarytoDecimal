#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '1') {
            decimal += pow(2, binary.length() - i - 1);
        }
        else if (binary[i] != '0') {
            return -1;
        }
    }
    return decimal;
}

int main() {
    ifstream inputFile("BinaryIn.dat");
    string line;
    cout << "Binary Number\tDecimal Equivalent" << endl;
    while (getline(inputFile, line)) {
        line.erase(0, line.find_first_not_of(" "));
        int decimal = binaryToDecimal(line);
        if (decimal == -1) {
            cout << line << "\t\tBad digit on input" << endl;
        }
        else {
            cout << line << "\t\t" << decimal << endl;
        }
    }
    inputFile.close();
    return 0;
}
