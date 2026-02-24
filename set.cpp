#include <iostream>
using namespace std;

template <typename T = char, int N = 5>
class Set {
private:
    T elements[N];
    int count;
    static int objectCount;

public:
    Set() : count(0) {
        objectCount++;
    }

    ~Set() {
        objectCount--;
    }

    static int getCount() {
        return objectCount;
    }

    bool addElement(const T& element) {
        if (count < N) {
            for (int i = 0; i < count; ++i) {
                if (elements[i] == element) {
                    cout << "Element " << element << " is already in the set." << endl;
                    return false; // Element already exists
                }
            }
            elements[count++] = element;
            return true;
        } else {
            cout << "Set is full. Cannot add more elements." << endl;
            return false;
        }
    }

    Set<T> unionSet(const Set<T>& other) const {
        Set<T> result;
        for (int i = 0; i < count; ++i) {
            result.addElement(elements[i]);
        }
        for (int j = 0; j < other.count; ++j) {
            result.addElement(other.elements[j]);
        }
        return result;
    }

    Set<T> intersectionSet(const Set<T>& other) const {
        Set<T> result;
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < other.count; ++j) {
                if (elements[i] == other.elements[j]) {
                    result.addElement(elements[i]);
                }
            }
        }
        return result;
    }

    Set<T> differenceSet(const Set<T>& other) const {
        Set<T> result;
        for (int i = 0; i < count; ++i) {
            bool found = false;
            for (int j = 0; j < other.count; ++j) {
                if (elements[i] == other.elements[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.addElement(elements[i]);
            }
        }
        return result;
    }

    void printSet() const {
        cout << "{ ";
        for (int i = 0; i < count; ++i) {
            cout << elements[i] << " ";
        }
        cout << "}" << endl;
    }
};

// Initialize the static member
template <typename T, int N>
int Set<T, N>::objectCount = 0;

int main() {
    Set<> set1; // Default set of chars
    int N=5;
    int numElements;
    cout << "Enter the number of elements to add to Set 1 (max " << N << "): ";
    cin >> numElements;

    if (numElements > N) {
        cout << "Cannot add more than " << N << " elements. Adjusting to " << N << "." << endl;
        numElements = N;
    }

    for (int i = 0; i < numElements; ++i) {
        char element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        set1.addElement(element);
    }

    Set<> set2; // Another default set of chars

    cout << "Enter the number of elements to add to Set 2 (max " << N << "): ";
    cin >> numElements;

    if (numElements > N) {
        cout << "Cannot add more than " << N << " elements. Adjusting to " << N << "." << endl;
        numElements = N;
    }

    for (int i = 0; i < numElements; ++i) {
        char element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        set2.addElement(element);
    }

    cout << "\nSet 1: ";
    set1.printSet();

    cout << "Set 2: ";
    set2.printSet();

    Set<> unionSet = set1.unionSet(set2);
    cout << "Union of Set 1 and Set 2: ";
    unionSet.printSet();

    Set<> intersectionSet = set1.intersectionSet(set2);
    cout << "Intersection of Set 1 and Set 2: ";
    intersectionSet.printSet();

    Set<> differenceSet = set1.differenceSet(set2);
    cout << "Difference of Set 1 and Set 2: ";
    differenceSet.printSet();

    cout << "Number of Set objects created (char type): " << Set<>::getCount() << endl;

    return 0;
}
