// Implementation

#include <iostream> 
#include "Savings_Account.h"
using namespace std;

Savings_Account::Savings_Account() : int_rate {3.0} {           // initializer list
    
}

Savings_Account::~Savings_Account() {

}

void Savings_Account::deposit(double amount) {
    cout << "Savings Account deposit called with " << amount << endl;
}

void Savings_Account::withdraw(double amount) {
    cout << "Savings Account withdraw called with " << amount << endl;
}