#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    double balance;

public:
    BankAccount(string n, double b) {
        cout << "Constructor called\n";
        if (b < 0) {
            throw "Error: Negative balance not allowed";
        }
        name = n;
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw "Error: Insufficient balance";
        }
        balance -= amount;
        cout << "Withdraw successful. Balance = " << balance << endl;
    }

    ~BankAccount() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {

    // ---------- SCENARIO 1 ----------
    cout << "\n--- Scenario 1: Valid Account + Valid Withdrawal ---\n";
    try {
        BankAccount* acc1 = new BankAccount("Amin", 5000);
        acc1->withdraw(2000);
        delete acc1;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    // ---------- SCENARIO 2 ----------
    cout << "\n--- Scenario 2: Valid Account + Invalid Withdrawal ---\n";
    BankAccount* acc2 = nullptr;
    try {
        acc2 = new BankAccount("Amin", 3000);
        acc2->withdraw(5000);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    delete acc2;

    // ---------- SCENARIO 3 ----------
    cout << "\n--- Scenario 3: Invalid Account Creation ---\n";
    try {
        BankAccount* acc3 = new BankAccount("Amin", -1000);
        delete acc3;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    // ---------- SCENARIO 4 ----------
    cout << "\n--- Scenario 4: Multiple Withdrawals ---\n";
    BankAccount* acc4 = nullptr;
    try {
        acc4 = new BankAccount("Amin", 4000);
        acc4->withdraw(1000);
        acc4->withdraw(1500);
        acc4->withdraw(3000);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    delete acc4;

    return 0;
}
