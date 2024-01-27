#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Account : public Account {
    friend ostream &operator<<(ostream &os, const Checking_Account &account);

private:
    static constexpr const char *def_name = "Unknown checking account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee = 1.5;
    
protected:
    double fee;

public:
    // constructor with dfault parameter (default)
    Checking_Account(string name = def_name, double balance = def_balance, double fee = def_fee);

    bool withdraw(double amount);

    // destructor
    ~Checking_Account();

};

#endif