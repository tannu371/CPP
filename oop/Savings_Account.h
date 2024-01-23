// Class declaration
#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

// access sepecifier - public private and protected
class Savings_Account: public Account {
    public:
        double int_rate;
        Savings_Account();          // no-args constructor
        ~Savings_Account();         // destructor
        void deposit(double amount);
        void withdraw(double amount);
};

#endif
