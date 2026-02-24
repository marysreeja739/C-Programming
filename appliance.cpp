#include <iostream>
#include <string>
using namespace std;
class Appliance {
public:
    Appliance(string brand, string model) : brand(brand), model(model) {}
    void showDetails() {
        cout <<"Appliance Details:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Model: " << model << "\n";
    }
private:
    string brand;
    string model;
};
class Refrigerator : public Appliance {
public:
    Refrigerator(string brand, string model, int capacity)  : Appliance(brand, model), capacity(capacity) {}
    void showDetails()  {
        cout<<"Refrigerator details:\n";
        Appliance::showDetails();
        cout << "Capacity: " << capacity << " liters\n";
    }
private:
    int capacity;
};
class WashingMachine : public Appliance {
public:
      WashingMachine(string brand, string model, int load)
        : Appliance(brand, model), load(load) {}
    void showDetails(){
        cout<<"Washing Machine details:\n";
        Appliance::showDetails();
        cout << "Load: " << load << " kg\n";
    }
private:
    int load;
};
int main() {
    Appliance a("Samsung","RT28");
    Appliance *ptr;
    Refrigerator fridge("Samsung", "RT28", 253);
    WashingMachine washer("LG", "T7288", 6);
    cout<<"\nBase class\n\n";
    a.showDetails();
    cout<<"\nDerived class Refrigirator\n\n";
    fridge.showDetails();
    cout<<"\nDerived class Washing machine\n\n";
    washer.showDetails();
    cout<<"\nCreating pointer to Base class\n";
    ptr=&fridge;
    cout<<"\nWhen assigning to Refrigirator\n";
    ptr->showDetails();
    cout<<"\nWhen assiging to Washing Machine\n";
    ptr=&washer;
    ptr->showDetails();
    return 0;
}
