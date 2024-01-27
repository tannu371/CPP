// Class Method or Function Implementations
#include "Account.h"
using namespace std;

// delegating no-args constructor
// Account::Account()  
//     : Account("An Account", 0.0) {}

// using initializer list
Account::Account(string name, double balance) : name{name}, balance{balance} {}

// Implementing Copy Constructor
Account::Account (const Account &source)
    :name{source.name}, balance{source.balance} {}

// Setter method
void Account :: set_balance(double balance) { this -> balance = balance;}    // this pointer - disambiguate identifier use
double Account ::  get_balance() const {return balance;}                  // Getter method

bool Account :: deposit(double amount) {
    cout << "Account deposit called with " << amount  << endl;
    if(amount < 0) return false;
    balance += amount;
    return true;
}

bool Account :: withdraw (double amount) {
    cout << "Account withdraw called with " << amount << endl;
    if (balance >= amount) {
        balance -= amount;
        // cout << amount << " withdrawn" << endl;
        return true;
    }  
    else {
        // cout << "Insufficient funds" << endl;
        return false;
    }     
}

ostream &operator<<(ostream &os, const Account &account) {
    os << "[Account name: " << account.name << ": " << account.balance << "]\n";
    return os;
}

Account::~Account() {}