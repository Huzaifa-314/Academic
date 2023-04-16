#include <iostream>
using namespace std;
class matrix
{
    int **p;
    int row;
    int col;
public:
    matrix(int row, int col)
    {
        p=new int*[row];
        for(int i=0;i<row;i++)
        {
            p[i]=new int[col];
        }
    }
    ~matrix()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] p[i];
        }
        delete[] p;
    }
    get_element(int i,int j,int value)
    {
        p[i][j]=value;
    }
    show_element(int i,int j)
    {
        cout << p[i][j];
    }
};

int main() {
    int row,col;
    cin >> row>> col;
    matrix m(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int value;
            cin >> value;
            m.get_element(i,j,value);
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            m.show_element(i,j);
            cout << " ";
        }
        cout << "\n";
    }


    return 0;
}
