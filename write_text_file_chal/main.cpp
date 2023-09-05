#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>

int main (){
    std::ifstream in_file {"romeoandjuliet.txt"};
    std::ofstream out_file {"romeoandjuliet_out.txt"};

    if(!in_file) {
        std::cout << "File opening error" << std::endl;
        return 1;
    }
    if(!out_file) {
        std::cout << "File creating error" << std::endl;
        return 1;
    }

    std::string line;
    int line_number=0;

    // while(std::getline(in_file, line)) {
    //     out_file << std::setw(5) << std::left << ++line_number << line << std::endl; 
    // }

    // while(std::getline(in_file, line)) {
    //     if (line.length() > 1)
    //         out_file << std::setw(5) << std::left << ++line_number << line << std::endl;
    //     else
    //         out_file << line << std::endl;
    // }

    while(std::getline(in_file, line)) {
        if(line == "")
            out_file << std::endl;
        else {
            out_file << std::setw(5) << std::left << ++line_number << line << std::endl;
        }
    }

    std::cout << "\nCopy complete" << std::endl;

    in_file.close();
    out_file.close();

    return 0;
}