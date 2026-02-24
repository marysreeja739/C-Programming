#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

template <typename T>
class Array
{
    T* arr;
    int size;

public:
    Array(int s) : size(s) {
        arr = new T[size];
    }

    ~Array() {
        delete[] arr;
    }

    void setValues() {
        cout << "Enter " << size << " elements for the array:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void search(T element)
    {
        if(typeid(T) == typeid(int)) {
            bool found = false;
            for(int i = 0; i < size; i++) {
                if(arr[i] == element) {
                    found = true;
                    break;
                }
            }
            if(found)
                cout << "Element " << element << " found in the array." << endl;
            else
                cout << "Element " << element << " not found in the array." << endl;
        } else {
            cout << "Search can only be performed on arrays of integers." << endl;
        }
    }

};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Integer array
    Array<int> intArr(size);
    cout<<"Integer:\n";
    intArr.setValues();
    int intSearchElement;
    cout << "Enter an element to search in the integer array: ";
    cin >> intSearchElement;
    intArr.search(intSearchElement);

    // Float array
    Array<float> floatArr(size);
    cout<<"Float:\n";
    floatArr.setValues();
    float floatSearchElement;
    cout << "Enter an element to search in the float array: ";
    cin >> floatSearchElement;
    floatArr.search(floatSearchElement);

    // Char array
    Array<char> charArr(size);
    cout<<"Character:\n";
    charArr.setValues();
    char charSearchElement;
    cout << "Enter an element to search in the char array: ";
    cin >> charSearchElement;
    charArr.search(charSearchElement);

    // String array
    Array<string> strArr(size);
    cout<<"String:\n";
    strArr.setValues();
    string strSearchElement;
    cout << "Enter an element to search in the string array: ";
    cin >> strSearchElement;
    strArr.search(strSearchElement);

    return 0;
}
