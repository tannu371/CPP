// Class Specification/Declaration

// Include Guards

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

using namespace std;

class Account {
    friend ostream &operator<<(ostream &os, const Account &account);

private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

protected:
    std::string name;
    double balance;

public:
    // no-args constructor (default)
    // Account();

    // constructor with default parameters (default) - Take care of all forms of initialiation
    // Account(string name = "None", double balance=0.0);
    Account(string name = def_name, double balance = def_balance);

    // overloaded constructor
    // Account(string name, double balance);

    // Declaring Copy Constructor
    Account(const Account &source);

    void set_balance(double balance);
    double get_balance () const;

    bool deposit (double amount);
    bool withdraw (double amount);
    
    // no-arg constructor
    // Account();

    ~Account();
};

#endif 

// By default c++ uses static binding