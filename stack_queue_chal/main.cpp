#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>
#include <string>

bool is_palindrome (std::string s) {
    std::stack<int> q1;
    std::queue<int> q2;
    for(int i=0; i<s.length();i++) {
        if(isalpha(s[i])) {
            q1.push(std::toupper(s[i]));
            q2.push(std::toupper(s[i]));
        }   
    }
    while(!q1.empty()) {
        if(q1.top() != q2.front())
            return false;
        q1.pop();
        q2.pop();
    }
    return true;  
}

int main () {
    std::vector<std::string> test_strings {"a", "aa", "abba", "abbcbba", "ab", "abc", 
        "radar", "bob", "ana", "avid diva", "Amore,Roma", "A Toyota's toyota", 
        "A Santa at NASA", "C++", "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Pananma!", 
        "This is s palindrome", "palindrome"};

    std::cout << std::setw(15) << std::left << "Result" << "String" << std::endl;
    
    for(const auto &s: test_strings) {
        std::string result = (is_palindrome(s) == 0 ? "false" : "true");
        std::cout << std::setw(15) << std::left << result << s << std::endl;
    }
    
}