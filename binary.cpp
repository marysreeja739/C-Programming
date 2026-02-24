#include <iostream>
#include <string>

using namespace std;

class Decimal {
    int num;
public:
    Decimal(int n) : num(n) {}

    int getNum() {
        return num;
    }

    void display() {
        cout << "Number in Decimal: " << num << endl;
    }
};

class Binary {
    string num;
public:
    Binary(string n) : num(n) {}

    Binary(Decimal& d) {
        int decimalValue = d.getNum();
        num = decimalToBinary(decimalValue);
    }

    operator Decimal() {
        return Decimal(binaryToDecimal(num));
    }

    void display() {
        cout << "Number in Binary: " << num << endl;
    }

private:
    string decimalToBinary(int decimal) {
        if (decimal == 0) return "0";

        string binary = "";
        while (decimal > 0) {
            binary = (decimal % 2 == 0 ? "0" : "1") + binary;
            decimal /= 2;
        }
        return binary;
    }

    int binaryToDecimal(const string& binary) {
        int decimal = 0;
        int base = 1;
        int length = binary.size();

        for (int i = length - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += base;
            }
            base *= 2;
        }
        return decimal;
    }
};

int main() {
    int decimalInput;
    string binaryInput;

    // Get decimal input from user
    cout << "Enter a decimal number: ";
    cin >> decimalInput;
    Decimal dec(decimalInput);
    Binary bin(dec);
    bin.display();

    // Get binary input from user
    cout << "Enter a binary number: ";
    cin >> binaryInput;
    Binary bin2(binaryInput);
    Decimal dec2 = bin2;
    dec2.display();

    return 0;
}
