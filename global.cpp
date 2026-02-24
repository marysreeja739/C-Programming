#include<iostream>
using namespace std;
int count = 100;
int main()
{
    int count = 10;
    cout << "Local count: " << count << endl;
    cout << "Global count: " << ::count << endl;
    return(0);
}
