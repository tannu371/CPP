#include "Mystring.h"
#include <iostream>

// No-arg Constructor
Mystring::Mystring() 
    :str{nullptr} {
        str = new char [1];
        *str = '\0';
    }

// Overloaded Constructor
Mystring::Mystring(const char *s)
    :str{nullptr} {
        if (s==nullptr) {
            str = new char [1];
            *str = '\0';
        } else {
            str = new char [std::strlen(s) +1];
            std::strcpy(str, s);
        }
    }

// Copy Constructor
Mystring::Mystring(const Mystring &source) 
    :str{nullptr} {
        str = new char [std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;
    }

// Move Constructor
Mystring::Mystring(Mystring &&source) 
    :str{source.str} {
        source.str = nullptr;
        std::cout << "Move Constructor Used" << std::endl;
    }

// Destructor
Mystring::~Mystring(){
    delete [] str;
}

// Copy Assignment Operator
Mystring Mystring ::operator=(const Mystring &rhs) {        // (If we have raw pointer we must deep copy)
    if (this == &rhs)                                       // Check for self assignment
        return *this;                                       // Return current object
    
    delete [] str;                                          // Deallocate storage for this->str since we're overwriting
    str = new char[std::strlen(rhs.str) + 1];               // Allocate storage for deep copy
    std::strcpy(str, rhs.str);                              // Copy

    return *this;                                           // Return the current by reference to allow chain assignment
}

// Move Assignment Operator
Mystring Mystring::operator=(Mystring &&rhs) {              // (If we have raw pointer we should overload the move assignemt operator for efficiency)
    if(this==&rhs)                                          // Check for self assignment
        return *this;                                       // Return current object
    
    delete [] str;                                          // Deallocating storage for this->str since we're overwriting
    str = rhs.str;                                          // Steal the pointer from rhs object and assign it to this->str

    rhs.str = nullptr;                                      // Null out the rhs pointer

    return *this;                                           // Return current object by reference to allow chain assignment
}

// Make lowercase and returning by value
Mystring Mystring::operator-() const {                              
    char *buff = new char [std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i =0; i<std::strlen(buff); i++) 
        buff[i] = std::tolower(buff[i]);                
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Checking for equality 
bool Mystring :: operator== (const Mystring &rhs) const {           
    if (std::strcmp(str, rhs.str) == 0)
        return true;
    else    
        return false;
}

// Concatenation
Mystring Mystring :: operator+ (const Mystring &rhs) const {        
    size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    char *buff = new char [buff_size];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Display Method
void Mystring::display()const{
    std::cout << str << ": " << get_length() << std::endl;
}

// length Getter
int Mystring::get_length()const{return std::strlen(str);}

// string Getter
const char *Mystring::get_str()const{return str;}

// Overloaded Extraction Operator
std::ostream &operator<< (std::ostream &os, const Mystring &obj) {
    os << obj.str;                                          // if a friend function
    // os << obj.get_str();                                    // if not a friend function
    return os;                                              // Return a reference to ostream so we can keep inserting
} 

// Overloaded Insertion Operator
std::istream &operator>> (std::istream &is, Mystring &obj) {
    char *buff = new char [1000];
    is >> buff;
    obj = Mystring{buff};                                   // (If you have copy or move assignment)
    delete [] buff;
    return is;                                              // Return a reference to istrean so we can keep inserting
}

