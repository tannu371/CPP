#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

// int main () {

//     std::cout << std::left << std::setw(20) << "Name"
//               << std::right << std::setw (20) << "Marks Obtained\n"
//               << std::setw(40)<< std::setfill('-') << '*'<< std::endl;
//     std::cout << std::setfill(' ');

//     std::fstream in_file {"responses.txt"};
//     if(!in_file) {
//         std::cerr << "Problem opening file" << std::endl;
//         return 1;
//     }

//     std::string line;

//     std::string answer_key;
//     int num_questions;
//     int num_students=0;
//     const int marks_per_question=1;
//     int marks_obtained=0;
//     int total_marks=0;

//     std::vector <std::string> lines;

//     int count=0;
//     while (std::getline(in_file, line)) {
//         if(count==0) {
//             answer_key = line;
//             num_questions = line.length();
//         }
//         else if(count%2==1) {
//             std::cout << std::left << std::setw(20) << line;
//             num_students++;
//         }   
//         else if(count%2==0) {
//             for(int i=0; i<num_questions; i++){
//                 if(answer_key[i]==line[i])
//                     marks_obtained += marks_per_question;
//             }
//             std::cout << std::right << std::setw(20) << marks_obtained << std::endl;
//             total_marks += marks_obtained;
//             marks_obtained = 0;
//         }
//         count++;
//     }

//     in_file.close();

//     std::cout << std::setw(40) << std::setfill('-') << '*' << std::endl;
//     std::cout << std::setfill(' ');
//     std::cout << std::left << std::setw(20) <<  "Average Marks: " << std::right << std::setw(20) << double(total_marks)/num_students << std::endl;

//     return 0;
// }


// Frank's solution

void print_header () {
    std::cout << std::left << std::setw(15) << "Student"
              << std::setw(5) << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << '-' << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(double average) {
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(20) << std::setfill('-') << '-' << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << std::left << "Average score"
              << std::setw(5) << std::right << average;
}

void print_student(const std::string &student, int score) {
    std::cout << std::setw(15) << std::left << student
              << std::setw(5) << std::right << score << std::endl;
}

// return the number of correct responses
int process_response(const std::string &response, const std::string &answer_key) {
    int score {0};
    for (size_t i=0; i < answer_key.size(); ++i) {
        if(response.at(i) == answer_key.at(i))
            score++;
    }
    return score;
}

int main () {
    std::ifstream in_file;
    std::string answer_key {};
    std::string name {};
    std::string response{};
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};

    in_file.open("responses.txt");
    if(!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    in_file >> answer_key;

    print_header();

    while(in_file >> name >> response) {
        ++total_students;
        int score = process_response(response, answer_key);
        running_sum += score;
        print_student(name, score);
    }

    if(total_students != 0)
        average_score = static_cast<double>(running_sum)/total_students;
    
    print_footer(average_score);

    in_file.close();
    std::cout << std::endl;

    return 0;
}