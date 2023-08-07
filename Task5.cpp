#include <iostream>
#include <stdio.h>
using namespace std;
class Bank
{
private:
    int total;
    string ID;

    struct person
    {
        int Id;
        string name, Address;
        float balance;
    } person[100];

public:
    Bank()
    {
        total = 0;
    }
    void Menu();
    void createAccount();
    void showCustomers();
    void showData();
    void deposit();
    void withdrawl();
};

void Bank::Menu()
{
    int ch;
    while (1)
    {
        cout << "\t------------------------------------------\n";
        cout << "\t||--------- Welcome to The Bank---------||\n";
        cout << "\t------------------------------------------\n";
        cout << "1. Create a New Account.\n";
        cout << "2. Display the Account Information.\n";
        cout << "3. Display the list of customers.\n";
        cout << "4. Deposit the money.\n";
        cout << "5. Withdraw the money.\n";
        cout << "6. Exit.\n";
        cout << "Enter the choice: ";
        cin >> ch;
        if (ch == 1)
            createAccount();
        else if (ch == 2)
            showData();
        else if (ch == 3)
            showCustomers();
        else if (ch == 4)
            deposit();
        else if (ch == 5)
            withdrawl();
        else if (ch == 6)
        {
            cout << "\t------------------------------------------\n";
            cout << "\t||-------------- Thank You -------------||\n";
            cout << "\t------------------------------------------\n";
            break;
        }
        else
        {
            cout << "Invalid Input";
            continue;
        }
    }
}

void Bank::createAccount()
{
    char x[100];
    cout << "Enter the Details Asked below: \n";
    cout << "Enter the name: ";
    gets(x);
    getline(cin, person[total].name);
    cout << "Enter the ID: ";
    cin >> person[total].Id;
    cout << "Enter your address: ";
    gets(x);
    getline(cin, person[total].Address);
    cout << "Enter the minimum Balance: ";
    cin >> person[total].balance;
    cout << "Account Created Successfully.\n";
    total = total + 1;
    cout << "--------------------------------------------\n";
}
void Bank::showData()
{
    int ser, j = -1;
    cout << "Enter the Id of the Account: ";
    cin >> ser;
    for (int i = 0; i < total; i++)
    {
        if (ser == person[i].Id)
        {
            cout << "Data found\n";
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        cout << "Data not found.\n";
        return;
    }
    else
    {
        cout << "The Information for the Given Id is:\n";
        cout << person[j].name << endl;
        cout << person[j].Address << endl;
        cout << person[j].balance << endl;
        cout << "--------------------------------------------\n";
    }
}
void Bank::showCustomers()
{
    cout << "The data of all tha customers is: \n\n";
    for (int i = 0; i < total; i++)
    {
        cout << person[i].name << endl;
        cout << person[i].Address << endl;
        cout << person[i].balance << endl;
        cout << "--------------------------------------------\n";
    }
}
void Bank::deposit()
{
    int ser,dep, j = -1;
    cout << "Enter the Id of the Account: ";
    cin >> ser;
    for (int i = 0; i < total; i++)
    {
        if (ser == person[i].Id)
        {
            cout << "Account found\n";
            j = i;
            break;
        }
    }
        if (j == -1)
    {
        cout << "Data not found.\n";
        return;
    }
    else
    {
        cout<<"Enter the amount to be deposited: ";
        cin>>dep;
        person[j].balance=person[j].balance+dep;
        cout<<"Deposit Successful.";
        cout << "--------------------------------------------\n";
    }
    
}
void Bank::withdrawl()
{
    int ser,with, j = -1;
    cout << "Enter the Id of the Account: ";
    cin >> ser;
    for (int i = 0; i < total; i++)
    {
        if (ser == person[i].Id)
        {
            cout << "Account found\n";
            j = i;
            break;
        }
    }
        if (j == -1)
    {
        cout << "Data not found.\n";
        return;
    }
    else
    {
        cout<<"Enter the amount to be withdrawn: ";
        cin>>with;
        person[j].balance=person[j].balance-with;
        cout<<"Withdrawl Successful.";
        cout << "--------------------------------------------\n";
    }
}

int main()
{
    Bank b;
    b.Menu();
    return 0;
}