// Class Specification/Declaration

#include <string>

// Include Guards

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
    std::string name;
    double balance;

public:
    // Constructor with default parameters
    Account(std::string name = "None", double balance=0.0);

    // Declaring Copy Constructor
    Account(const Account &source);

    void set_balance(double bal);
    double get_balance ();

    bool withdraw (double amount);
    bool deposit (double amount);
};

#endif 