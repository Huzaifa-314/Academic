#include<iostream>
#include<string>
using namespace std;
class account
{
    string name;
    int account_number;
    string account_type;
    int balance;
public:
    void input(void)
    {
        cout << "Enter Your Name:";
        getline(cin,name);
        cout << "Enter Account Number: ";
        cin >> account_number;
        cout << "Account Type: ";
        cin.ignore();
        getline(cin,account_type);
        cout<< "Initial Balance: ";
        cin >> balance;
    }
    void deposit(int x)
    {
        balance+=x;
        cout << "Your New balance after deposit: "<<balance;
    }
    void withdraw(int x)
    {
        if(balance>x)
        {
            balance=balance-x;
            cout<< x<<" balance has withdrawn \n New balance: "<<balance;
        }else
        {
            cout<< "not enough money to withdraw";
        }
    }
    void display_info(void)
    {
        cout << name<< endl << "balance: "<< balance;
    }

};

int main()
{
    account a;
    a.input();
    a.display_info();
    return 0;
}
