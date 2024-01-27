// Implementation

#include "Savings_Account.h"
using namespace std;

// Savings_Account::Savings_Account() : int_rate {3.0} {}         // initializer list   

Savings_Account::Savings_Account(string name, double balance, double int_rate) : Account{name, balance}, int_rate{int_rate} {}          // initializer list

bool Savings_Account::deposit(double amount) {
    cout << "Savings Account deposit called with " << amount << endl;
    amount += (amount * int_rate/100);
    return Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Savings_Account &account) {
    os << "[Savings Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]\n";
    return os;
}

Savings_Account::~Savings_Account() {}