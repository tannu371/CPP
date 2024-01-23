/* 
Global variables are known throughout the program and may be used by any piece of code. 
Also, they will hold their value throughout the program's execution.
Storage for global variables is in a fixed region of memory set aside for this purpose by the compiler.
If a global variable and a local variable have the same name, all references to that variable name inside the code block in which the local variable is declared will refer to that local variable and have no effect on the global variable.

Variables of type const may not be changed by your program. It must be given an initial value.
The const qualifier can be used to protect the objects pointed to by the arguments to a function from being modified by that function.
A variable of type const can be modified by something outside your program. For example, a hardware device may set its value. However, by declaring a variable as const, you can prove that any changes to that variable occur because of external events.

The principal use of extern is to specify that an object is declared with external linkage elsewhere in the program.

static variables are permanent variables within their own function or file.
Unlike global variables, they are not known outside their function or file, but they maintain their values between calls.

The key difference between a static local variable and a global variable is that the static local variable remains known only to the block in which it is declared. 
A static local variable is a local variable that retains its value between function calls.

Applying the specifier static to a global variable instructs the compiler to create a global variable that is known only to the file in which you declared it. This means
that even though the variable is global, routines in other files may have no knowledge of it or alter its contents directly, keeping it free from side effects. 

*/

/*
The preprocessors are the directives, which give instruction to the compiler to preprocess the information before actual compilation starts.
All preprocessor directives begin with #, and only white-space characters may appear before a preprocessor directive on a line. 
Preprocessor directives are not C++ statements, so they do not end in a semicolon ; 

#include is used to include a header file into the source file.
pointy brackets includes file from one of the standard directories
double quotes includes file from current working directory

#define preprocessor directive creates symbolic constants. 
The symbolic constant is called a macro.
When this line appears in a file, all subsequent occurrences of macro in that file will be replaced by replacement-text before the program is compiled.
function like macros define a macro which will take argument.
The # operator causes a replacement-text token to be converted to a string surrounded by quotes.
The ## operator is used to concatenate two tokens. 

__LINE__    contain the current line number of the program
__FILE__    contain the current file name of the program 
__DATE__    contains a string of the form month/day/year that is the date of the translation of the source file into object code.
__TIME__    contains a string of the form hour:minute:second that is the time at which the program was compiled.

*/

/*
A namespace is designed to differentiate similar functions, classes, variables etc. with the same name available in different libraries.
Namespaces, unlike classes, do not require instantiation; you do not need an object to use a specific namespace. You only need to prefix the function you wish to call with namespace_name:: -- similar to how you would call a static member function of a class.
using is used to call functions from within the namespace without having to specify the namespace of the function while in the current scope.

*/

/*
struct - to model data, public by default
class - model object, private by default

By default, functions and data declared within a class are private to that class and may be accessed only by other members of the class. 
The public access specifier allows functions or data to be accessible to other parts of your program. 
The protected access specifier is needed only when inheritance is involved.
Access to a protected member is the same as access to a private member—it can be accessed only by other members of its class. 
By using protected, you can create class members that are private to their class but that can still be inherited and accessed by a derived class.

The base-class access specifier must be either public, private, or protected. 
If no access specifier is present, the access specifier is private by default if the derived class is a class. 
If the derived class is a struct, then public is the default in the absence of an explicit access specifier. 

When the access specifier for a base class is public, all public members of the base become public members of the derived class, and all protected members of the base become protected members of the derived class. 
If the base class is inherited as public, then the base class' protected members become protected members of the derived class and are, therefore, accessible by the derived class.

When the base class is inherited by using the private access specifier, all public and protected members of the base class become private members of the derived class.
This means that they are still accessible by members of the derived class but cannot be accessed by parts of your program that are not members of either the base or derived class.

When the base class is inherited by using the protected access specifier, all public and protected members of the base class become protected members of the derived class.

In all cases, the base's private elements remain private to the base and are not accessible by members of the derived class.
a private member of a base class is not accessible by other parts of your program, including any derived class.  

*/

/*
In computing, object code or object module is the product of a compiler. 
In a general sense object code is a sequence of statements or instructions in a computer language, usually a machine code language or an intermediate language such as register transfer language.
*/