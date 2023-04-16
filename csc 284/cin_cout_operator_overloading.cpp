#include <iostream>
using namespace std;

class Complex {
    double re,im;
public:
    Complex()
    {
        re=0;im=0;
    }
    Complex(double a,double b)
    {
        re=a;im=b;
    }
    friend istream &operator>>(istream &,Complex &);
    friend ostream &operator<<(ostream &,Complex &);

};
istream &operator>>(istream &input,Complex &c)
{
    cout<< "enter real part: ";
    input>>c.re;
    cout<< "ente imaginary part: ";
    input>>c.im;
    return input;
}
ostream &operator<<(ostream &output,Complex &c)
{
    output<<c.re<<"+"<<c.im<<"i";
    return output;
}
int main() {
    Complex C;
    cin >> C;
    cout<< C;
    return 0;
}

