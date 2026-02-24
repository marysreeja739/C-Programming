#include <iostream>
#include <string>
using namespace std;
class Book {
    int book_no;
    string title;
    string author;
    string publisher;
    static int pearson_count;
    static int wiley_count;
    static int tmh_count;
    static int oxford_count;
public:
    Book(int no, string t, string a, string p) {
        book_no = no;
        title = t;
        author = a;
        publisher = p;
        if (publisher == "Pearson")
        {
            pearson_count++;
        }
        else if (publisher == "Wiley")
        {
            wiley_count++;
        }
        else if (publisher == "TMH")
        {
            tmh_count++;
        }
        else if (publisher == "Oxford")
        {
            oxford_count++;
        }
    }
    static int getPearsonCount()
    {
        return pearson_count;
    }
    static int getWileyCount()
    {
        return wiley_count;
    }
    static int getTMHCount()
    {
        return tmh_count;
    }
    static int getOxfordCount()
    {
        return oxford_count;
    }
    void displayBook() {
        cout << "Book No: " << book_no << ", Title: " << title
             << ", Author: " << author << ", Publisher: " << publisher << endl;
    }
};
int Book::pearson_count = 0;
int Book::wiley_count = 0;
int Book::tmh_count = 0;
int Book::oxford_count = 0;

int main()
{
    Book b1(1, "Data Structures", "Seymour Lipschutz", "TMH");
    Book b2(2, "C++ Programming", "Bjarne Stroustrup", "Pearson");
    Book b3(3, "Operating Systems", "Abraham Silberschatz", "Wiley");
    Book b4(4, "Design Patterns", "Erich Gamma", "Pearson");
    Book b5(5, "Discrete Mathematics", "Kenneth H. Rosen", "Oxford");
    b1.displayBook();
    b2.displayBook();
    b3.displayBook();
    b4.displayBook();
    b5.displayBook();
    cout << "\nBooks by Pearson: " << Book::getPearsonCount() << endl;
    cout << "Books by Wiley: " << Book::getWileyCount() << endl;
    cout << "Books by TMH: " << Book::getTMHCount() << endl;
    cout << "Books by Oxford: " << Book::getOxfordCount() << endl;

    return 0;
}
