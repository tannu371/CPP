#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

int main () {

    // // Creating fstream object for reading / input mode
    

    // // std::fstream in_file {"C:\\dir\\dir2\\test.txt", std::ios::in};                     // file name On windows  
    // // std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary};            // read in binary mode

    // // Creating ifstream object for reading / input mode
    // // std::ifstream in_file {"/dir/dir2/test.txt", std::ios::in};                         // file name On mac
    // std::ifstream in_file {"test.txt"};                                                     // file name In vscode / codeblock
    // // std::ifstream in_file {"../myfile.txt", std::ios::binary};                          // file name In codelite / clion - so it puts the file in our parent directory

    // // second parameter specifies the mode and properties of the file that's being opened.

    // // Creating ifstream object
    // // std::ifstream in_file;
    // // std::string filename;
    // // std::cin >> filename;
    // // Opening ifstream objects using open method
    // // in_file.open(filename);
    // // in_file.open(filename, std::ios::binary);

    // // Check if file opened successfully
    // // if (in_file.is_open()) {
    //     // read it
    // // } else {
    //     // file couldn't be created or opened
    //     // does it exist ?
    //     // should the program terminate ?
    // // }

    // // if (in_file) {

    // // } else {
    //     // std::cerr << "Problem opening file" << std::endl;
    //     // std::exit(1);
    // // }

    // if (!in_file) {
    //     std::cerr << "File open error" << std::endl;
    //     return 1;                                           // exit the program (main)
    // }
    // std::cout << "File is good to go" << std::endl;   

    // // Reading file using extraction >> operator
    // int num {};
    // double total {};
    // std::string name {};
    
    // in_file >> name;
    // in_file >> num >> total;
    // std::cout << name << std::endl;
    // std::cout << num << std::endl; 
    // std::cout << total << std::endl;

    // // Reading file using getline
    // std::string line {};
    // std::getline(in_file, line);

    // // Reading text file one line at a time
    // while(!in_file.eof()) {
    //     std::getline(in_file, line);
    //     std::cout << line << std::endl;
    // }

    // while(std::getline(in_file, line))              // Read a line
    //     std::cout << line << std::endl;             // Display the line

    // // Reading text file one character at a time
    // char c;
    // while(in_file.get(c))
    //     std::cout << c;

    // // Closing the file
    // in_file.close();            // Always close any open file to flush out any unwritten data


    // // Creating fstream object
    // std::ifstream in_file2 {"test2.txt"};
    // //check if it's open                            
    // if(!in_file2){
    //     std::cerr << "problem opening file" << std::endl;
    //     return 0;
    // }
    // // Read
    // // while(!in_file2.eof()) {
    // //     in_file2 >> name >> num >> total;
    // //     std::cout << std::left << std::setw(10) << name
    // //                            << std::setw(10) << num
    // //                            << std::setw(10) << total
    // //                            << std::endl;
    // // }
    // while(in_file2 >> name >> num >> total) {
        
    //     std::cout << std::left << std::setw(10) << name
    //                            << std::setw(10) << num
    //                            << std::setw(10) << total
    //                            << std::endl;
    // }
    // // Close
    // in_file2.close();


    // // Create ifstream object
    // std::ifstream in_file3;
    // std::string filename {"poem.txt"};
    // // Open file
    // in_file3.open(filename);
    // // Check if it's open
    // if(!in_file3) {
    //     std::cerr << "Error opening file" << std::endl;
    //     return 1;
    // }
    // // Read text file one line at a time
    // // while(std::getline(in_file3, line))                          // Read a line
    // //     std::cout << line << std::endl;                         // Display the line

    // // Unformatted input - No worry about new lines, end of files, fancy characters and different things that could break the way of reading because it's formatted
    // while(in_file3.get(c))
    //     std::cout << c;
    // std::cout << std::endl;
    // // Close  file
    // in_file3.close();

    // // Creating object and opening in output mode / to write to file and not read from it.
    // // By default c++ create file if it does not exist.
    // // Make sure path must exist.

    // // By default, files are opened in text mode.
    // std::fstream out_file {"myfile.txt", std::ios::out};
    // std::fstream out_file {"myfile.txt", std::ios::out | std::ios::binary};                 // binary mode - when we're writing non-text files that contain binary data.
    // // bitwise or operator | (vertical bar or pipe character) - set both output and binary modes to true.

    // std::ofstream out_file {"myfile.txt", std::ios::out};
    // std::ofstream out_file {"myfile.txt"};                          // std::ios::out is optional - already default in ofstream class
    // std::ofstream out_file {"myfile.txt", std::ios::binary};

    // // truncate (discard contents) when opening (default) - gets rid of whatever in there.
    // std::ofstream out_file {"myfile.txt", std::ios::trunc};

    // // append on each write - to add something to file
    // std::ofstream out_file {"myfile.txt", std::ios::app};

    // // seek to end of stream when opening
    // std::ofstream out_file {"myfile.txt", std::ios::ate};               // to set the initial position of th enext right to the end of the existing file.
    // // random access - to move around

    // // creating ofstream object
    // std::ofstream out_file;
    // std::string filename;

    // std::cin >> filename;           // get file name

    // // connect it to file / open file
    // out_file.open(filename);
    // out_file.open(filename, std::ios::binary);

    // if(out_file.is_open()) {
        
    // } else {

    // }

    // // check the stream object - if the stream object was not instantiated, then return false.
    // if(out_file) {

    // } else {

    // }

    // // Always close any open files to flush out any unwritten data
    // // With output files, this is very important since it flushes out any buffers that may not been written out to file yet.
    // out_file.close();

    // // Writing files using insertion operator << for formatted write.

    // int num  {100};
    // double total {255.67};
    // std::string name {"Larry"};

    // out_file << num << "\n"
    //          << total << "\n"
    //          << name << std::endl;

    //          // endline flushes out any unwritten buffers.
    
    

    // // Create ifstream object and initialize to input file.
    // std::ifstream in_file {"myfile.txt"};                   // open file
    // // Create ofstream object and initailize to output file. 
    // // - if the output file does not exist, it will be created - if it does exist, it wiil be truncated.
    // std::ofstream out_file {"copy.txt"};

    // // Check if the files opened successfully
    // if(!in_file) {
    //     std::cerr << "File open error" << std::endl;
    //     return 1;               // exit the program (main)
    // }
    // if(!out_file) {
    //     std::cerr << "File create error" << std::endl;
    //     return 1;
    // }

    // // Input & output files are ready for processing
    // // Copying a text file one line at a time
    // std::string line {};
    // while (std::getline(in_file, line))             // read a line
    //     out_file << line << std::endl;              // write a line

    // in_file.close();
    // out_file.close();

    // // Copy a text file one character at a time(get/put)
    // // Unformatted read and write - one character at a time

    // char c;
    // while(in_file.get(c))       // read a character
    //     out_file.put(c);        // write a character


    // std::ofstream out_file {"output.txt", std::ios::app};
    // if(!out_file) {
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    // std::string line;
    // std::cout << "Enter something to write to the file: ";
    // std::getline(std::cin, line);
    // out_file << line << std::endl;

    // out_file.close();


    // // Instantiating objects
    // std::ifstream in_file {"poem.txt"};
    // std::ofstream out_file {"poem_out.txt"};
    // // Make sure if files are open and ready to read and write
    // if(!in_file) {
    //     std::cerr << "Error opening input file" << std::endl;
    //     return 1;
    // }
    // if(!out_file) {
    //     std::cerr << "Error creating file" << std::endl;
    //     return 1;
    // }

    // // // logic
    // // std::string line{};
    // // while(std::getline(in_file, line))
    // //     out_file << line << std::endl;

    // // std::cout << "File copied" << std::endl;
    // // in_file.close();
    // // out_file.close();

    // // one character at a time
    // char c;
    // while(in_file.get(c))
    //     out_file.put(c);

    // std::cout << "File copied" << std::endl;


    // Using string streams
    // Allows us to read or write from strings in memory much as we would read and write to files
    // Very powerful
    // Very useful for data validation

    // 1. #inclue <sstream>
    // 2. Declare an stringstream, istringstream or ostringstream object
    // 3. Connect it to a std::string
    // 4. Read/write data from/to the string stream using formatted I/O

    // Reading from stringstream
    int num {};
    double total {};
    std::string name {};

    std::string info {"Moe 100 1234.5"};
    std::istringstream iss{info};

    // Exttraction information (connected to an in-memory string)
    iss >> name >> num >> total;
    std::cout << std::setw(10) << std::left << name
              << std::setw(5) << num
              << std::setw(10) << total << std::endl;


    // // Writing to a stringstream
    // int num {100};
    // double total {1234.5};
    // std::string name {"Moe"};

    std::ostringstream oss {};                               // We didn't connect the ostringstream to any string object we could do it. The stringstream has a string buffer that it uses internally, and we can use that.
    oss << std::setw(10) << std::left << name 
        << std::setw(5) << num 
        << std::setw(10) << total << std::endl;
    std::cout << oss.str() << std::endl;

    // // Validating input with stringstream
    int value {};
    std::string entry {};           // Rather tha read directly into  an integer, we're going to rad into a string.
    bool done = false;

    do {
        std::cout << "Please enter an integer: ";
        std::cin >> entry;

        std::stringstream validator {entry};
        if (validator >> value) {
            done = true;
        } else {
            std::cout << "Sorry, that's not an integer" << std::endl;

            // discards the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');                  // 12.38 or 12 Hello delete rest of stuffs
        } 
    } while(!done);

    std::cout << "You entered the integer: " << value << std::endl;
    std::cout << std::endl;

    return 0;

}