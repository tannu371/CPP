// Class declaration
#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"

// Savings Account is a type of Account
// adds an intrest rate

// Deposit method increments amount to be deposited by amount * int_rate percentage!! (amount * int_rate/100)
// and then updated amount will be deposited
// Withdraw method does not specialize so we can use parent's withraw method

// access sepecifier - public private and protected
class Savings_Account: public Account {
    friend ostream &operator<<(ostream &os, const Savings_Account &account);

private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:
    double int_rate;

public:
    // no-args constructor (default)
    // Savings_Account();         

    // constructor with default parameter (default) 
    Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // overloaded constructor
    // Savings_Account(string name, double balance, double int_rate);   

    bool deposit(double amount);
    // withdraw is inherited

    ~Savings_Account();         // destructor
};

#endif
