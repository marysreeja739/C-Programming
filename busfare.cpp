#include <iostream>
#include <string>
using namespace std;
class Bus
{
 private:
    string vehicle_number;
    string driver_name;
    int route_number;
    float fare_per_passenger;
    static int count;
 public:
    string getVehicleNumber()
    {
       return vehicle_number;
    }
    void setVehicleNumber(string vnum)
    {
       vehicle_number = vnum;
    }
    string getDriverName()
    {
       return driver_name;
    }
    void setDriverName(string dname)
    {
       driver_name = dname;
    }
    int getRouteNumber()
    {
       return route_number;
    }
    void setRouteNumber(int rnum)
    {
       route_number = rnum;
    }
    float getFarePerPassenger()
    {
       return fare_per_passenger;
    }
    void setFarePerPassenger(float fare)
    {
       fare_per_passenger = fare;
    }
    static int getCount()
    {
        return count;
    }
    float computeTicket(int passengers = 1)
    {
        return fare_per_passenger * passengers;
    }
    void display()
    {
        cout << "Vehicle Number: " << vehicle_number << endl;
        cout << "Driver Name: " << driver_name << endl;
        cout << "Route Number: " << route_number << endl;
        cout << "Fare per Passenger: " << fare_per_passenger << endl;
        cout << "Total Fare for 1 Passenger: " << computeTicket() << endl;
    }
    static void displayCount()
    {
        cout << "Total number of buses: " << count << endl;
    }
    friend void swapBuses(Bus &bus1, Bus &bus2);
};
int Bus::count = 0;
void swapBuses(Bus &bus1, Bus &bus2)
{
    Bus temp = bus1;
    bus1 = bus2;
    bus2 = temp;
}
void sortBusesByVehicleNumber(Bus buses[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (buses[i].getVehicleNumber() > buses[j].getVehicleNumber())
            {
                swapBuses(buses[i], buses[j]);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of buses: ";
    cin >> n;
    Bus buses[n];
    for (int i = 0; i < n; i++)
    {
        string vehicle_number, driver_name;
        int route_number;
        float farep;
        cout << "\nEnter details for Bus " << i + 1 << ":\n";
        cout << "Vehicle Number: ";
        cin >> ws;
        buses[i].setVehicleNumber(ws);
        cout << "Driver Name: ";
        cin>>driver_name;
        buses[i].setDriverName(driver_name);
        cout << "Route Number: ";
        cin >> route_number;
        buses[i].setRouteNumber(route_number);
        cout << "Fare per Passenger: ";
        cin >> farep;
        buses[i].setFarePerPassenger(farep);
    }
    cout << "\n--- Bus Details (Before Sorting) ---\n";
    for (int i = 0; i < n; i++)
    {
        buses[i].display();
        cout << endl;
    }
    sortBusesByVehicleNumber(buses, n);
    cout << "\nBus Details (After Sorting by Vehicle Number)\n";
    for (int i = 0; i < n; i++)
    {
        buses[i].display();
        cout << endl;
    }
    Bus::displayCount();
    return 0;
}
