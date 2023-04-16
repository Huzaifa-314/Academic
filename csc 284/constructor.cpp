#include<iostream>
using namespace std;
class test
{
    int x=10;
public:
    test()
    {
        x=0;
    }
    test(int a)
    {
        x=a;
    }
    test(test &t)
    {
        x=t.x;
    }
    void show(void)
    {
        cout<<x;
    }
};
int main()
{
    test t(20);
    test t1(t);
    t.show();
    t1.show();
    return 0;
}
