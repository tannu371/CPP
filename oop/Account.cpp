// Class Method or Function Implementations
#include<iostream>
#include "Account.h"
using namespace std;

Account::Account()  
    : name{"An Account"}, balance{0.0} {
}

Account::~Account()
{
}

// Initializer list (Delegating Constructor)
// Account :: Account(std::string name, double balance)
//     : name{name}, balance{balance} {} 

// Implementing Copy Constructor
Account::Account (const Account &source)
    :name{source.name}, balance{source.balance} {}

// Setter method
void Account :: set_balance(double balance) { this -> balance = balance;}    // this pointer - disambiguate identifier use
double Account ::  get_balance() {return balance;}                  // Getter method

bool Account :: withdraw (double amount) {
    cout << "Account withdraw called with " << amount << endl;
    if (balance >= amount) {
        balance -= amount;
        return true;
    }  
    else 
        return false;
}

bool Account :: deposit(double amount) {
    balance += amount;
    cout << "Account deposit called with " << amount  << endl;
    return true;
}