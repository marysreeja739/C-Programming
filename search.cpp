#include <iostream>
#include <string>
using namespace std;
void Search(long int arr[], int size,long int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = 1;
            break;
        }
    }
    if (found==1) {
        cout << "Number found!" << endl;
    } else {
        cout << "Number not found!" << endl;
    }
}

// Search for a lucky character in a character array
void Search(char arr[], int size, char luckyChar) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == luckyChar) {
            found = 1;
            break;
        }
    }
    if (found==1) {
        cout << "Lucky char found!" << endl;
    } else {
        cout << "Lucky char not found!" << endl;
    }
}

// Search for a username in a string array
void Search(string arr[], int size, string username) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == username) {
            found = 1;
            break;
        }
    }
    if (found==1) {
        cout << "Username found!" << endl;
    } else {
        cout << "Username not found!" << endl;
   }
}

int main() {
    int n;

    // Integer array search
    cout << "Enter the number of integers: ";
    cin >> n;
    long int* numbers=new long int[n];
    char* luckyChars=new char[n];
    string* usernames=new string[n];
    for(int i=0;i<n;i++)
    {
       cout<<"Enter the phone number:";
       cin>>numbers[i];
       cout<<"Enter the characters:";
       cin>>luckyChars[i];
       cout<<"Enter the user name:";
       cin>>usernames[i];
    }
    long int target;
    char lucky;
    string name;
    cout<<"Enter the number to be searched :";
    cin>>target;
    cout<<"Enter the lucky character to be searched:";
    cin>>lucky;
    cout<<"Enter the username to be searched:";
    cin>>name;
    Search(numbers,n,target);
    Search(luckyChars,n,lucky);
    Search(usernames,n,name);

    // Clean up dynamic arrays
    delete[] numbers;
    delete[] luckyChars;
    delete[] usernames;

    return 0;
}
