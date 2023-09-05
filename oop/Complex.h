// Class declaration

// Include Guards

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
    double real, imaginary;
public: 
    Complex (double real, double imaginary);

    double get_real ();
    double get_imaginary ();

    Complex operator+ (const Complex &other);
};

#endif