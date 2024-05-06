#include <iostream>
using namespace std;

int main() {
    int balance = 5000;
    int withdraw, deposit;
    int choice;
    while (true)
    {
        cout << "\t\t\t\t\t\t\tMust ATM" << endl;
        cout << "1. for Withdraw" << endl;
        cout << "2. for Deposit" << endl;
        cout << "3. for Check Balance" << endl;
        cout << "4. for EXIT" << endl;
        cout << "Choose the operation you want to perform: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter money to be withdrawn: ";
            cin >> withdraw;
            if (balance >= withdraw)
            {
                balance -= withdraw;
                cout << "\nMoney has been successfully withdraw" << endl;
            }
            else
            {
                cout << "\nSorry you can't withdraw this amount!" << endl;
            }
            cout << endl;
            break;
        case 2:
            cout << "\nEnter money to be deposited:";
            cin >> deposit;
            balance += deposit;
            cout << "\nYour Money has been successfully deposited" << endl;
            cout << endl;
            break;
        case 3:
            cout << "\nBalance: " << balance << endl;
            cout << endl;
            break;
        case 4:
            cout << "\nExiting the ATM" << endl;
            return 0;
        default:
            cout << "\nInvalid Choice! Please enter a valid option." << endl;
        }
    }
    return 0;
}