#include <iostream>
using namespace std;

class Bill {
private:
    float amount;
public:
    // Constructor to initialize the bill
    Bill()
    {
       amount=0.0;
    }
    Bill(float amt)
    {
       amount=amt;
    }

    // Friend function to compute the total sale for a day
    friend float computeTotalSale(Bill bills[], int n);
};

// Friend function to compute total sale
float computeTotalSale(Bill bills[], int n) {
    float totalSale = 0.0;
    for (int i = 0; i < n; i++) {
        totalSale += bills[i].amount;  // Accessing the private member "amount"
    }
    return totalSale;
}

int main() {
    int n;
    cout << "Enter the number of bills for the day: ";
    cin >> n;
    Bill* bills = new Bill[n];
    for (int i = 0; i < n; i++) {
        float billAmount;
        cout << "Enter bill amount for bill " << i + 1 << ": ";
        cin >> billAmount;
        bills[i]=Bill(billAmount);
    }

    // Compute the total sale for the day
    float totalSale = computeTotalSale(bills, n);
    cout << "Total sale for the day: $" << totalSale << endl;

    // Clean up dynamically allocated memory
    delete[] bills;

    return 0;
}
