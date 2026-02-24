#include <iostream>
#include <string>
using namespace std;
struct Date {
    int day, month, year;
};
typedef struct Date Date;

class OnlineBank {
private:
    int accountNumber;
    string name;
    Date accountCreationDate;
    float balance;
    string username;
    string password;
    static int customerCount;
    static float min_bal;
public:
    // Constructor to initialize default values
    //OnlineBank() : accountNumber(0), balance(0.0) {}
    void readInput() {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter account holder's name: ";
        cin >> name;
        cout << "Enter date of account creation (dd mm yyy): ";
        cin >> accountCreationDate.day >> accountCreationDate.month >> accountCreationDate.year;
        cout << "Enter initial balance: ";
        cin >> balance;
        while (balance < min_bal) {
            cout << "Initial balance cannot be less than the minimum balance " << min_bal << ". Please enter again: ";
            cin >> balance;
        }
        cout << "Create a username: ";
        cin >> username;
        cout << "Create a password: ";
        cin >> password;
        customerCount++;
    }
    static void getTotalCustomers() {
        cout << "Total number of customers: " << customerCount << endl;
    }
    bool authenticate(string uName, string pass) {
        return (username == uName && password == pass);
    }
    void withdraw(float amount) {
        if (balance - amount >= min_bal) {
            balance -= amount;
            cout << "Withdrawal successful! Your new balance is: $" << balance << endl;
        } else {
            cout << "Withdrawal failed! Your balance cannot go below the minimum balance of $" << min_bal << endl;
        }
    }
    void deposit(float amount) {
        balance += amount;
        cout << "Deposit successful! Your new balance is: " << balance << endl;
    }
    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Account Creation Date: " << accountCreationDate.day << "/"
             << accountCreationDate.month << "/" << accountCreationDate.year << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};
int OnlineBank::customerCount = 0;
float OnlineBank::min_bal = 500.00;

int main() {
    int numOfCustomers;
    cout << "Enter the number of customers: ";
    cin >> numOfCustomers;
    OnlineBank customers[numOfCustomers];
    for (int i = 0; i < numOfCustomers; i++) {
        cout << "\nEnter details for customer " << i + 1 << ":\n";
        customers[i].readInput();
    }
    OnlineBank::getTotalCustomers();
    string enteredUsername, enteredPassword;
    bool authenticated = false;
    int Index = -1;
    cout << "\nAuthenticate to Access Account\n";
    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;
    for (int i = 0; i < numOfCustomers; i++) {
        if (customers[i].authenticate(enteredUsername, enteredPassword)) {
            authenticated = true;
            Index = i;
            break;
        }
    }
    if (authenticated) {
        cout << "\nAuthentication successful " << enteredUsername << "!\n";
        int choice;
        do {
            cout << "\n1. Display Account Details\n2. Withdraw Money\n3. Deposit Money\n4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    customers[Index].displayAccountDetails();
                    break;
                case 2: {
                    float amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    customers[Index].withdraw(amount);
                    break;
                }
                case 3: {
                    float amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    customers[Index].deposit(amount);
                    break;
                }
                case 4:
                    cout << "Thank you for using our bank system. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 4);
    } else {
        cout << "Authentication failed! Incorrect username or password.\n";
    }
    return 0;
}
