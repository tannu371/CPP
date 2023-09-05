#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <cctype>
#include <string>

void display_words(std::map<std::string, int> map) {
    std::cout << std::left << std::setw(15) << "Word" 
              << std::right << std::setw(5) << "Count" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << '-' << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << '-' << std::endl;
    std::cout << std::setfill(' ');

    for(auto pair:map)
        std::cout << std::setw(12) << std::left << pair.first
                  << std::setw(7) << std::right << pair.second << std::endl;

    // auto it = map.begin();
    //     while (it != map.end()) {
    //         std::cout << std::left << std::setw(15) << it->first
    //         << std::right << std::setw(5) << it->second
    //         << std::endl;
    //         it++;
    //     }

}

void display_words(std::map<std::string, std::set<int>> map) {
    std::cout << std::left << std::setw(15) << "Word" 
              << "Occurrences" << std::endl;
    std::cout << std::setw(30) << std::setfill('-') << '-' << std::endl;
    std::cout << std::setw(30) << std::setfill('-') << '-' << std::endl;
    std::cout << std::setfill(' ');

    auto it = map.begin();
    while (it != map.end()) {
        std::cout << std::left << std::setw(15) << it->first
        << "[ "; 
        auto it2 = it->second.begin();
        while (it2 != it->second.end()) {
            std::cout << *it2 << " ";
            it2++;
        }
        std::cout << "]" << std::endl;
        it++;
    }

}

std::string clear_stirng(std::string &s) {
    for (int i=0; i<s.length(); i++) {
        if(!std::isalpha(s[i]))
            s.erase(i, 1);
    }
    return s;
}

void part1 () {

    std::string word;
    std::ifstream in_file {"words.txt"};
    if(in_file) {
        std::map <std::string, int> unique_word_count;
        while (in_file >> word) {
            word = clear_stirng(word);
            unique_word_count[word] ++;
        }
        in_file.close();
        display_words(unique_word_count);
    } else {
        std::cout << "File opening error" << std::endl;  
    }
    
    // Using set and multi-set
    // std::multiset <std::string> words;
    // std::set <std::string> unique_words;
    // while (in_file >> word) {
    //     word = clear_stirng(word);
    //     words.insert(word);
    //     unique_words.insert(word);
    // }
    // auto it = unique_words.begin();
    // while(it != unique_words.end()){
    //     std::cout << std::left << std::setw(15) << *it 
    //               << std::right << std::setw(5) << words.count(*it) 
    //               << std::endl;
    //     it++;
    // }
    
    std::cout << std::endl;
    
}

void part2() {
    
    std::string word;
    std::ifstream in_file {"words.txt"};
    if(!in_file) {
        std::cout << "File opening error" << std::endl;   
    }

    std::map<std::string, std::set<int>> unique_word_occurrence;
    std::string line;
    int line_number = 0;
    while(std::getline(in_file, line)) {
        std::istringstream iss{line};
        while(iss >> word) {
            line_number++;
            word = clear_stirng(word);
            unique_word_occurrence[word].insert(line_number);
        }
    }
    in_file.close();
    display_words(unique_word_occurrence);

    std::cout << std::endl;

}

int main () {
    part1();

    std::cout << std::endl;

    part2();

    std::cout << std::endl;
    
    return 0;

}


 