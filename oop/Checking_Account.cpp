#include "Checking_Account.h"

Checking_Account::Checking_Account(string name, double balance, double fee) : Account{name, balance}, fee {fee} {}

bool Checking_Account::withdraw(double amount) {
    amount += 1.5;
    return Account::withdraw(amount);
}

ostream &operator<<(ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << " : " << account.balance << " : " << account.fee << "]\n";
    return os;
}

Checking_Account::~Checking_Account() {};