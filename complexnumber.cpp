#include <iostream>
using namespace std;
class Complex
{
 private:
    int real;
    int imag;

 public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }
    friend Complex addComplex(Complex &c1, Complex &c2);
    void display()
    {
        if (imag < 0)
        {
            cout << real << " - " << -imag << "i" << endl;
        }
        else
        {
            cout << real << " + " << imag << "i" << endl;
        }
    }
};
Complex addComplex(Complex &c1, Complex &c2)
{
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}
int main()
{
    Complex c1(3, 2);
    Complex c2(1, -4);
    cout << "First complex number: ";
    c1.display();
    cout << "Second complex number: ";
    c2.display();
    Complex sum = addComplex(c1, c2);
    cout << "Sum of the complex numbers: ";
    sum.display();
    return 0;
}
