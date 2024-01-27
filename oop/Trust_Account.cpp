#include "Trust_Account.h"

int Trust_Account::count = 0;

Trust_Account::Trust_Account(string name, double balance, double int_rate) : Savings_Account{name, balance, int_rate} {};

bool Trust_Account::deposit(double amount) {
    if(amount >= 5000) amount += 50;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if(count < 3) {
        count++;
        return Savings_Account::withdraw(amount);
    } 
    return false;
}

ostream &operator<<(ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << " : " << account.balance << " : " << account.int_rate  << "%  number of times money withdrawn : " << account.count;
    return os;
}

Trust_Account::~Trust_Account() {};