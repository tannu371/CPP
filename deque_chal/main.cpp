#include <iostream>
#include <iomanip>
#include <string>
#include <deque>

bool isPalindrome (std::string &str) {
    std::deque<char> d;
    for(char c:str)
        d.push_back(c);
    
    auto it1 = d.begin();
    auto it2 = d.rbegin();
    for(size_t i=0; i<d.size()/2; i++) {
        if (*it1 != *it2)
            return false;
    }
    return true;
}

// Frank's Function
bool is_Palindrome (std::string &s) {
    std::deque<char> d;
    for(char c : s) {
        if(std::isalpha(c))
            d.push_back(std::toupper(c));
    }

    while(d.size() >1) {
        if(d.front() != d.back())
            return false;
        d.pop_front();
        d.pop_back();
    }
    return true;
}

int main () { 
    std::string s;
    std::cout << "Enter the string: ";
    std::cin >> s;

    bool is_palindrome =  is_Palindrome(s);
    std::cout << std::boolalpha;
    std::cout << is_palindrome;

    return 0;
}