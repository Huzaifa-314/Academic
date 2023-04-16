#include<iostream>
using namespace std;
class Complex
{
    int re,im;
public:
    Complex(){};
    Complex(int a,int b)
    {
        re=a;
        im=b;
    }
    Complex operator+(Complex &c)
    {
        Complex sum;
        sum.re=re+c.re;
        sum.im=im+c.im;
        return sum;
    }
    void show()
    {
        cout << re<<"+"<<im<<"i"<<endl;
    }
};
int main()
{
    Complex c1(10,2),c2(2,3),c3;
    c3=c1+c2;
    c3.show();
    return 0;
}
