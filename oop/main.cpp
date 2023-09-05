#include <iostream>
#include <iomanip>

#include "Mystring.h"
#include "Account.h"
#include "Player.h"

#include <string>

#include <numeric>

#include <array>
#include <vector>

// struct - to model data, public by default
// class - model object, private by default

void display_balance(Account p) {
        // p is copy of sam
        std::cout << "balance: " << p.get_balance() << std::endl;

    }

void display_active_players() {
    std::cout << "Active Players: " << Player::get_num_players() << std::endl;
}

int main () {

    // Declaring
    std::string s1;                         // Empty

    // Initializing
    std::string s2 {"Frank"};               // Frank
    std::string s3 {s2};                    // Frank
    std::string s4 {"Frank", 3};            // Fra
    std::string s5 {s3, 0, 2};              // Fr
    std::string s6 (3, 'X');                // XXX

    // Assignment
    s1 = "C++ Rocks!";
    s2 = s1;

    // Concatenation
    std::string part1 {"C++"};
    std::string part2 {"is a powerfull"};
    std::string sentence;
    sentence = part1 + part2 + "language";          // Atleast one C++ String should be there

    std::cout << s3[2] << std::endl;                // Accessing character using []
    std::cout << s3.at(3) << std::endl;             // Accessing character using at() method

    s3[0] = 'f';
    s3.at(0) = 'p';

    /* Pointer  - value is an address
                - we must know the type of data the pointer is pointing to
    */
    // Declaring pointer
    int *int_ptr;
    std::string *string_ptr;

    // Initializing pointer variables to 'point nowhere'
    double *double_ptr{};
    char *char_ptr{nullptr};

    // & - address operator
    int num{10};                                    // Variable Initialization
    std::cout << "Value of num is: " << num << std:: endl; 
    std::cout << "Address of num is: " << &num << std::endl;
    std::cout << "Size of num is: " << sizeof(num) << std::endl;

    double *p;                                      // Pointer Declartion
    std::cout << "Value of p is: " << p << std::endl;
    std::cout << "Address of p is: " << &p << std:: endl;
    std::cout << "Size of p is: " << sizeof(p) << std::endl;

    p = nullptr;                                    // Pointer Assignment
    std::cout << "Value of p is: " << p << std::endl;
    std::cout << "Size of p is: " << sizeof(p) << std::endl;
    std::cout << "Address of p is: " << &p << std:: endl;

    int score {10};                                 // Variable Initialization
    int *score_ptr {nullptr};                       // Pointer Initialization
    score_ptr = &score;                             // Pointer Assignment

    double high_temp {100.7};                       // Variable Initialization
    double *temp_ptr {&high_temp};                  // Pointer Initialization 

    std::string *name {nullptr};                    // Pointer Initialization
    name = new std::string;                         // Allocating storage on heap
    delete name;                                    // Deallocate storage

    std::cout << *temp_ptr << std::endl;            // Deferencing Pointer
    *score_ptr = 20;                                // Deferencing Pointer
    std::cout << score << std::endl;

    int *array_ptr;
    int size {};
    std::cout << "How big do you want the array ? " << std::endl;
    std::cin >> size;
    array_ptr = new int[size];                      // Allocating storage
    delete array_ptr;

    int scores[] {10, 20, 30, 40, 50};              // Array Initialization
    score_ptr = scores;                             // Pointer Assignment
    
    std::cout << scores[2] << std::endl;            // Subscript Notation
    std::cout << score_ptr[2] << std::endl;         // Subscript Notation
    std::cout << *(scores + 2) << std::endl;        // Offset Notation
    std::cout << *(score_ptr + 2) << std::endl;     // Offset Notation

    score_ptr++;                                    // Points to next element
    score_ptr--;                                    // Points to previous element

    score_ptr += 3;                                 // Increment pointer by 3 * sizeof(type)
    score_ptr -= 2;                                 // Decrement pointer by 2 * sizeof(type)

    int *int_ptr1 {scores};
    int *int_ptr2 {scores + 2};
    int n = int_ptr2 - int_ptr1;
    std::cout << *(scores+2) << " is " << n << "character away from " << scores[0] << std::endl; 

    Player empty;
    Player frank{"Frank"};
    Player villan {"Villan"};
    Player sam{"sam", 100, 4}; 
    Player *enemy = new Player("Enemy", 100, 4);

    display_active_players();
    
    Account frank_account;
    Account jim_account;
    Account *marry_account = new Account;
    
    // frank.name = "Frank";                            // Private  Attribute                             
    frank.talk("Ready to Battle");                      // Dot Operator 

    // (*enemy).name = "Sam";                           // Private Attribute
    (*enemy).talk("I will Hunt You down");              // Dot Operator

    // marry_account -> balance = 100.0;                // Private Attribute
    marry_account -> withdraw(20.5);                    // Arrow Operator

    frank_account.set_balance(10000.0);
    double bal = frank_account.get_balance();
    std::cout << bal << std::endl;

    display_balance(frank_account);
    
    delete enemy;                                       // Destructor called
    delete marry_account;                               // Destructor called

    Mystring s_1 {"Frank"};
    Mystring s_2 = s_1;                                   // Not Assignment (same as Mystring s2{s1}; )

    s_2 = s_1;                                            // Assignment (default - shallow copy)
    s2.operator=(s1);                                   // operator= method called (deep copy)

    Mystring s_3;
    s_3 = Mystring {"Frank"};                            // Move operator= called
    s_3 = "Joe";                                         // Move operator= called 

}