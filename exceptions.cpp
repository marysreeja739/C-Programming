#include <iostream>
#include <exception>
using namespace std;
void customUnexpected() {
    cout << "Custom unexpected handler called!" << endl;
}
void customTerminate() {
    cout << "Custom terminate handler called!" << endl;
}

void throwException(int choice)
{
    switch (choice) {
        case 1:
            throw 10;
            break;
        case 2:
            throw 'a';
            break;
        case 3:
            throw ("hello");
            break;
        default:
            cout << "No exception thrown!" << endl;
            break;
    }
}
int main() {
    set_unexpected(customUnexpected);
    set_terminate(customTerminate);
    try {
        int choice;
        cout << "Enter choice for throw (1, 2, 3): ";
        cin >> choice;
        throwException(choice);
        cout << "After throwException call" << endl;
    }
    catch (int e) {
        cout << "Caught integer exception: " << e << endl;
    }
    catch (char e) {
        cout << "Caught char exception: " << e << endl;
    }
    catch(...)
    {
       if (uncaught_exception()>0) {
        cout << "There is no uncaught exception!" << endl;
       }
       else
       {
        cout << "There is  uncaught exception." << endl;
       }
    }

    return 0;
}
