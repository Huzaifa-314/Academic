#include <iostream>
#include<string>
using namespace std;
int main() {
    string name;
    cin >> name;
    for(int i=0;i<name.length();i++)
    {
        cout << name.at(i)<<endl;
    }
    return 0;
}
