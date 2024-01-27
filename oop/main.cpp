#include <iostream>
#include <iomanip>

#include <memory>       // smart pointer 

#include <numeric>
#include <string>
#include <array>
#include <vector>

#include "Mystring.h"
#include "Player.h"

#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

void display_balance(Account p) {
        // p is copy of sam
        std::cout << "balance: " << p.get_balance() << std::endl;

    }

void display_active_players() {
    std::cout << "Active Players: " << Player::get_num_players() << std::endl;
}

void deriving_first_class() {
    // Use the Account class
    cout << "\n===Account =================================" << endl;
    Account acc {};             // create an object
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    cout << endl;

    Account *p_acc{nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

    // Use the Saving Account class
    cout << "\n===Savings Account =========================" << endl;
    Savings_Account sav_acc {};
    sav_acc.deposit(1000.0);
    sav_acc.withdraw(500.0);

    cout << endl;

    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;

    cout << "\n============================================" << endl;
}

class Base {
    // Note : friends of Base have access to all
    private:
        int value;
    protected:
        int b{0};
    public:
        int a{0};
        void display() { cout << a << ", " << b << ", " << value << endl; }      // member methods has access to all

        // no-args constructor
        Base():value{0} {cout << "Base no-args constructor" << endl; }

        // overloaded constructor
        Base(int x):value{x} {cout << "Base (int) overloaded constructor" << endl; }

        // overloaded copy constructor
        Base(const Base &other) : value{other.value} {
            cout << "Base copy constructor" << endl;
        }

        // overloaded copy assignment operator
        Base &operator=(const Base &rhs) {
            cout << "Base operator=" << endl;
            if(this == &rhs) return *this;
            value = rhs.value;
            return *this;
        }

        void say_hello() const {
            cout << "Hello! - I am a Base Class Object\n" << endl;
        }

        // destructor
        ~Base() {cout << "Base destructor" << endl;}
};

class Derived: public Base {
    // Note friends of Derived have access to only what Derived has access to

    // a will be public
    // b will be protected
    // value will not be accessible

    using Base::Base;           // allows us to inherit the non-special constructor from base class, it will take care of initializing base part but it won't take care of initializing the derived part.
    // Special constructor - default constructors

    private:
        int doubled_value;

    public:
        void access_base_members() {
            a = 100;        // OK
            b = 200;        // OK
            // value = 300;        // not accessible
        }

        /* first derived class constructor gets invoked
           then base class constructor gets invoked and base part is initialized from it's initalization list
           then derived part is intialized and rest of derived class constructor executes

           Before the body of derived class constructor is initialized, the base part of it will be initialized
        */

        // no-args constructor
        // explicitly invoking base no-args constructor (default behaviour of compiler)
        Derived() : Base{}, doubled_value{0} {cout << "Derived no-args constructor" << endl; }

        // overloaded constructor
        // invoking base class overloaded constructor
        Derived(int x) : Base{x}, doubled_value{x*2} {cout << "Derived (int) overloaded constructor" << endl;}

        /* Copy and Move constructors and Copy and Move assignment operators are not automatically inherited from the base class 
        Slicing - slice base part of the derived object */

        /* If we provide overloaded copy/move constructor and overloaded copy/move assignment operator in derived class, then we must invoke the base versions explicitly
           If we don't explicitly call base class overloaded assignment operator, then the base part will not be assigned */

        // overloaded copy constructor
        Derived(const Derived &other) :Base{other}, doubled_value{other.doubled_value} {
            cout << "Derived copy constructor" << endl;
        }

        // overloaded copy assignment operator
        Derived &operator=(const Derived &rhs) {
            cout << "Derived operator=" << endl;
            if(this == &rhs) return *this;
            Base::operator=(rhs);           // calling base class overloaded assignment operator
            doubled_value = rhs.doubled_value;
            return *this;
        }

        // destructor
        ~Derived() {cout << "Derived destructor" << endl;}

        void say_hello() const {
            cout << "Hello! - I am a derived class object\n" << endl;
        }
};

void greetings(const Base &obj) {
    cout << "Greetings: ";
    obj.say_hello();
}

// Inheritance

void ProtectedMemberClassAccess () {
    cout << "=== Base member access from base objects ===========" << endl;
    Base base;
    base.a = 100;       // OK
    // base.b = 200;       // Compiler error
    // base.c = 300;       // Compiler error

    cout << "=== Base member access from derived objects ========" << endl;
    Derived d;
    d.a = 100;      // OK
    // d.b = 200;      // Compiler error
    // d.value = 300;      // Compiler error
}

void constructor_and_destructor() {
    // Base b;
    // Base b{100};

    // Derived d;
    Derived d{1000};
}

void BaseClassInitialization() {
    // Derived d;
    Derived d{1000};
}

void CopyConstructorAssignmentOperator() {
    // Base b{100};        // Overloaded constructor
    // Base b1{b};         // Copy constructor
    // b = b1;             // Copy assignment (l-value)

    Derived d{100};
    Derived d1{d};
    d = d1;
}

void RedefiningBaseClassMethods() {
    cout << "\n===== Account class ===================" << endl;
    Account a1{"a1", 1000.0};
    cout << a1 << endl;

    a1.deposit(500.0);
    cout << a1 << endl;

    a1.withdraw(1000.0);
    cout << a1 << endl;

    a1.withdraw(5000.0);
    cout << a1 << endl;

    cout << "\n===== Savings Account class ===========" << endl;
    Savings_Account s1{"s1", 1000.0, 5.0};
    cout << s1 << endl;

    s1.deposit(1000.0);
    cout << s1 << endl;

    s1.withdraw(2000.0);
    cout << s1 << endl;

    s1.withdraw(1000.0);
    cout << s1 << endl;

}

void challenge() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larray"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonderwomwn", 5000, 5.0});

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
}

// Polymorphism

void TheProblem() {
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    // Satitc binding

    greetings(b);
    greetings(d);

    // Derived is a base;
    Base *ptr = new Derived();
    ptr->say_hello();

    unique_ptr<Base> ptr1 = make_unique<Derived>();         // create a smart pointer
    ptr1->say_hello();

    delete ptr;

}

void BaseClassPointers() {
    cout << "\n= = = = Pointers = = = =" << endl;
    Account *p1 = new Account();
    Account *p2 = new Savings_Account();
    Account *p3 = new Checking_Account();
    Account *p4 = new Trust_Account();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    cout << "\n= = = = Array = = = =" << endl;
    Account *array[] = {p1, p2, p3, p4};
    for(auto i=0; i<4; i++) array[i]->withdraw(1000);

    cout << "\n= = = = Array = = = =" << endl;
    array[0] = p4;
    for(auto i=0; i<4; i++) array[i]->withdraw(1000);

    cout << "\n= = = = Vector = = = =" << endl;
    vector<Account*> accounts {p1, p2, p3, p4};
    for(auto acc_ptr : accounts) acc_ptr->withdraw(1000);

    cout << "\n= = = = CleanUp = = = =" << endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;

}

int series_num = 100;

int series__(void) {
    series_num = series_num+23;
    return series_num;
}

int series_(void) {
    int series_num = 100;
    series_num = series_num+23;
    return series_num;
}

int series(void) {
    static int series_num = 100;
    series_num = series_num+23;
    return series_num;
}

int main () {

    // // Declaring
    // std::string s1;                         // Empty

    // // Initializing
    // std::string s2 {"Frank"};               // Frank
    // std::string s3 {s2};                    // Frank
    // std::string s4 {"Frank", 3};            // Fra
    // std::string s5 {s3, 0, 2};              // Fr
    // std::string s6 (3, 'X');                // XXX

    // // Assignment
    // s1 = "C++ Rocks!";
    // s2 = s1;

    // // Concatenation
    // std::string part1 {"C++"};
    // std::string part2 {"is a powerfull"};
    // std::string sentence;
    // sentence = part1 + part2 + "language";          // Atleast one C++ String should be there

    // std::cout << s3[2] << std::endl;                // Accessing character using []
    // std::cout << s3.at(3) << std::endl;             // Accessing character using at() method

    // s3[0] = 'f';
    // s3.at(0) = 'p';

    // /* Pointer  - value is an address
    //             - we must know the type of data the pointer is pointing to
    // */
    // // Declaring pointer
    // // int *int_ptr;
    // // std::string *string_ptr;

    // // Initializing pointer variables to 'point nowhere'
    // // double *double_ptr{};
    // // char *char_ptr{nullptr};

    // // & - address operator
    // int num{10};                                    // Variable Initialization
    // std::cout << "Value of num is: " << num << std:: endl; 
    // std::cout << "Address of num is: " << &num << std::endl;
    // std::cout << "Size of num is: " << sizeof(num) << std::endl;

    // double *p;                                      // Pointer Declartion
    // std::cout << "Value of p is: " << p << std::endl;
    // std::cout << "Address of p is: " << &p << std:: endl;
    // std::cout << "Size of p is: " << sizeof(p) << std::endl;

    // p = nullptr;                                    // Pointer Assignment
    // std::cout << "Value of p is: " << p << std::endl;
    // std::cout << "Size of p is: " << sizeof(p) << std::endl;
    // std::cout << "Address of p is: " << &p << std:: endl;

    // int score {10};                                 // Variable Initialization
    // int *score_ptr {nullptr};                       // Pointer Initialization
    // score_ptr = &score;                             // Pointer Assignment

    // double high_temp {100.7};                       // Variable Initialization
    // double *temp_ptr {&high_temp};                  // Pointer Initialization 

    // std::string *name {nullptr};                    // Pointer Initialization
    // name = new std::string;                         // Allocating storage on heap
    // delete name;                                    // Deallocate storage

    // std::cout << *temp_ptr << std::endl;            // Deferencing Pointer
    // *score_ptr = 20;                                // Deferencing Pointer
    // std::cout << score << std::endl;

    // int *array_ptr;
    // int size {};
    // std::cout << "How big do you want the array ? " << std::endl;
    // std::cin >> size;
    // array_ptr = new int[size];                      // Allocating storage
    // delete array_ptr;

    // int scores[] {10, 20, 30, 40, 50};              // Array Initialization
    // score_ptr = scores;                             // Pointer Assignment
    
    // std::cout << scores[2] << std::endl;            // Subscript Notation
    // std::cout << score_ptr[2] << std::endl;         // Subscript Notation
    // std::cout << *(scores + 2) << std::endl;        // Offset Notation
    // std::cout << *(score_ptr + 2) << std::endl;     // Offset Notation

    // score_ptr++;                                    // Points to next element
    // score_ptr--;                                    // Points to previous element

    // score_ptr += 3;                                 // Increment pointer by 3 * sizeof(type)
    // score_ptr -= 2;                                 // Decrement pointer by 2 * sizeof(type)

    // int *int_ptr1 {scores};
    // int *int_ptr2 {scores + 2};
    // int n = int_ptr2 - int_ptr1;
    // std::cout << *(scores+2) << " is " << n << "character away from " << scores[0] << std::endl; 

    // Player empty;
    // Player frank{"Frank"};
    // Player villan {"Villan"};
    // Player sam{"sam", 100, 4}; 
    // Player *enemy = new Player("Enemy", 100, 4);

    // display_active_players();
    
    // Account frank_account;
    // Account jim_account;
    // Account *marry_account = new Account;
    
    // // frank.name = "Frank";                            // Private  Attribute                             
    // frank.talk("Ready to Battle");                      // Dot Operator 

    // // (*enemy).name = "Sam";                           // Private Attribute
    // (*enemy).talk("I will Hunt You down");              // Dot Operator

    // // marry_account -> balance = 100.0;                // Private Attribute
    // marry_account -> withdraw(20.5);                    // Arrow Operator

    // frank_account.set_balance(10000.0);
    // double bal = frank_account.get_balance();
    // std::cout << bal << std::endl;

    // display_balance(frank_account);
    
    // delete enemy;                                       // Destructor called
    // delete marry_account;                               // Destructor called

    // Mystring s_1 {"Frank"};
    // Mystring s_2 = s_1;                                   // Not Assignment (same as Mystring s2{s1}; )

    // s_2 = s_1;                                            // Assignment (default - shallow copy)
    // s2.operator=(s1);                                   // operator= method called (deep copy)

    // Mystring s_3;
    // s_3 = Mystring {"Frank"};                            // Move operator= called
    // s_3 = "Joe";                                         // Move operator= called 

    // Inheritance
    // deriving_first_class();
    // ProtectedMemberClassAccess();
    // constructor_and_destructor();
    // BaseClassInitialization();
    // CopyConstructorAssignmentOperator();
    // RedefiningBaseClassMethods();
    // challenge();

    // Polymorphism
    // TheProblem();
    BaseClassPointers();

    return 0;
}