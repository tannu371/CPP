# include "Complex.h"

Complex :: Complex (double real, double imaginary) 
    : real{real}, imaginary{imaginary} {}                               // Initializer list

double Complex :: get_real () {return real;}
double Complex :: get_imaginary () {return imaginary;}

Complex Complex :: operator+ (const Complex &other) {
    return Complex(real + other.real, imaginary + other.imaginary);     // Returning by value
}

