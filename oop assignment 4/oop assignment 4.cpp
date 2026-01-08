#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    // Constructor
    BankAccount(string n, double b) {
        cout << "Constructor called\n";
        if (b < 0) {
            throw "Error: Initial balance cannot be negative";
        }
        name = n;
        balance = b;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > balance) {
            throw "Error: Insufficient balance";
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }

    // Destructor
    ~BankAccount() {
        cout << "Destructor called for account of " << name << endl;
    }
};

int main() {
    BankAccount* acc = nullptr;

    try {
        acc = new BankAccount("Amin Ali", 5000);
        acc->withdraw(2000);
        acc->withdraw(4000);   // This will throw exception
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    delete acc;   // Safe cleanup
    return 0;
}
