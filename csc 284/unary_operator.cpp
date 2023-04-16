#include<iostream>
using namespace std;
class Vector
{
    int x,y,z;
public:
    Vector(int a,int b,int c)
    {
        x=a;
        y=b;
        z=c;
    }
    Vector operator-()
    {
        Vector vs(x,y,x);
        vs.x=-x;
        vs.y=-y;
        vs.z=-z;
        return vs;
    }
    void show()
    {
        cout<<x<<" "<<y<<" "<<z<<endl;
    }

};
int main()
{
    Vector v1(2,3,4);
    v1.show();
    Vector v2=-v1;
    v2.show();

}
