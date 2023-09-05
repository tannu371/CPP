#include "Account.h"

// Initializer list (Delegating Constructor)
Account :: Account(std::string name, double balance)
    : name{name}, balance{balance} {}                                   
// Implementing Copy Constructor
Account::Account (const Account &source)
    :name{source.name}, balance{source.balance} {}

// Setter method
void Account :: set_balance(double balance) { this -> balance = balance;}    // this pointer - disambiguate identifier use
double Account ::  get_balance() {return balance;}                  // Getter method

bool Account :: withdraw (double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }  
    else 
        return false;
}
bool Account :: deposit(double amount) {
    balance += amount;
    return true;
}