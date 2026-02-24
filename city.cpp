#include<iostream>
#include<string>
using namespace std;
class City {
private:
    string name;
    int population;
    string country;
    static int count;
public:
    City(string cname = "", int cpopulation = 0, string ccountry = ""){
    name=cname;
population=cpopulation;
country=ccountry;
        count++;
    }
    ~City() {
        count--;
    }
    void setName(string cname){
   name = cname;
}
    string getName(){
   return name;
}
    void setPopulation(int cpopulation){
   population = cpopulation;
}
    int getPopulation(){
   return population;
}
    void setCountry(string ccountry){
   country = ccountry;
}
    string getCountry(){
   return country;
}
    static void showCount() {
        cout << "Total cities: " << count << endl;
    }
    inline void display() {
        cout << "City: " << name << ", Population: " << population << ", Country: " << country << endl;
    }
    void updatePopulation(int cnt, bool flag = true) {
        if (flag) {
            population += cnt;
        } else {
            population -= cnt;
        }
    }
    friend void sortCities(City* cities, int n);
    static void swapCities(City& c1, City& c2) {
        City temp = c1;
        c1 = c2;
        c2 = temp;
    }
};
int City::count = 0;
void sortCities(City* cities, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cities[i].getName() > cities[j].getName()) {
                City::swapCities(cities[i], cities[j]);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of cities:";
    cin >> n;
    City* cities = new City[n];
    for (int i = 0; i < n; i++) {
        string name, country;
        int population;
        cout << "Enter details for City " << i + 1 << ": " << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Population: ";
        cin >> population;
        cout << "Country: ";
        cin >> country;
        cities[i] = City(name, population, country);
    }
    cout << "\nDetails of all cities:\n";
    for (int i = 0; i < n; i++) {
        cities[i].display();
    }
    sortCities(cities, n);
    cout << "\nCities sorted by name:\n";
    for (int i = 0; i < n; i++) {
        cities[i].display();
    }
    City::showCount();
    cities[0].updatePopulation(1500);
    cout << "\nUpdated details of the first city:\n";
    cities[0].display();
    delete[] cities;
    return 0;
}
