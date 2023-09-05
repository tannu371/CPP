// Class Specification / Declaration

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include<iostream>

class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &obj);
    char *str;                              // declaring pointer
public:
    // Overloaded constructors
    Mystring();
    Mystring (const char *s);
    Mystring (const Mystring &source);
    Mystring (Mystring &&source);

    ~Mystring();

    Mystring operator= (const Mystring &rhs);            // Overloading Copy Assignment operator
    Mystring operator= (Mystring &&rhs);                 // Overloading Move Assignment operator

    Mystring operator- () const;

    bool operator==(const Mystring &rhs) const;

    Mystring operator+ (const Mystring &rhs) const;

    void display () const;
    int get_length () const;
    const char *get_str () const;
  
};

#endif