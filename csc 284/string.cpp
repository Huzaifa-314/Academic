#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char *s;
    int length;
public:
    String()
    {
        length=0;
        s=new char[length+1];
    }
    String(char *x)
    {
        length=strlen(x);
        s=new char[length+1];

        strcpy(s,x);
    }
    void show(void)
    {
        cout << s;
    }
    friend ostream &operator<<(ostream &output,String & q);
    void join(String &a,String &b)
    {
        length=a.length+b.length;
        delete s;
        s=new char[length+1];
        strcpy(s,a.s);
        strcat(s,b.s);

    }
    String operator[](int k)
    {
        char c[2];
        c[0] = s[k];
        c[1] = '\0';
        return String(c);
    }
};

ostream &operator<<(ostream &output,String &q)
{
    for(int i=0;i<strlen(q.s);i++)
    {
        output<<q.s[i];
    }
    return output;
}
int main()
{
    String s1,s2("hello,    "),s3("Muhammad Huzaifa"),sum,sum2;
    sum.join(s2,s3);
    String x = sum[10];
    cout<<x;
    return 0;
}
