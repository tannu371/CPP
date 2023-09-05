#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

// Song Model (Class)
class Song {
    friend std::ostream &operator<<(std::ostream &os , const Song &s);          // Friend function (overloaded insertion operator)
    std::string name;
    std::string artist;
    int rating;
public : 
    Song() = default;                                                   // Default constructor
    Song(std::string name, std::string artist, int rating)              // Overloaded constructor
    : name{name}, artist{artist}, rating{rating} {}

    std::string get_name () const {return name;}                        // Getters
    std::string get_artist () const {return artist;}
    int get_rating () const {return rating;}

    bool operator<(const Song &rhs) {                                   // Overloading less than operator
        return this->name  < rhs.name;
    }
    bool operator==(const Song &rhs) {                                  // Overloading equality operator
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name << std::setw(30) << std::left << s.artist << std::setw(2) << std::left << s.rating;
    return os;
}

void display_maenu () {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and Play a New Song at current location" << std::endl;
    std::cout << "L - List the current Playlist" << std::endl;
    std::cout << "====================================================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list <Song> &playlist, const Song current_song) {
    for (const Song &song : playlist)
        std::cout << song << std::endl;

    std::cout << "Current Song: " << std::endl;
    std::cout << current_song << std::endl;
}

int main () {
    std::list <Song> playlist {
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend And K.Lamer", 4},
        {"The Middle", "Zedd Maren Morris & Grey", 5},
        {"Wait", "Maroon 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}
    };
    std::list <Song> :: iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);

    char selection {};
    do {
        display_maenu();
        std::cin>>selection;
        selection = std::toupper(selection);
        if (selection == 'F') {
            std::cout << "Playing First Song" << std::endl;
            current_song = playlist.begin();
            play_current_song (*current_song);
        }
        else if (selection == 'N') {
            std::cout << "Playing Next Song" << std::endl;
            current_song++;
            if (current_song == playlist.end()) {
                std::cout << "Wrapping to start of the playlist" << std::endl;
                current_song = playlist.begin();
            }
            play_current_song(*current_song);
        }
        else if (selection == 'P') {
            std::cout << "Playing Previous Song" << std::endl;
            current_song--;
            if (current_song == playlist.begin()) {
                std::cout << "Wrapping to end of the playlist" << std::endl;
                current_song = playlist.end();
            }
            play_current_song(*current_song);
        }
        else if (selection == 'A') {
            std::string name, artist;
            int rating;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            std::cout << "Adding and Playing New";   
            std::cout << "Enter Song Name: ";
            getline(std::cin, name);
            std::cout << "\nEnter Artist Name: ";
            getline(std::cin, artist);
            std::cout << "\nRating for the song: ";
            std::cin>> rating;

            playlist.insert(current_song, Song {name, artist, rating});
            current_song--;
            play_current_song(*current_song);
        }
        else if (selection == 'L') {
            std::cout << "Current Playlist: " << std::endl;
            display_playlist(playlist, *current_song);
        }
        else if (selection == 'Q') {
            std::cout << "Quitting" << std::endl;
        }
        else 
            std::cout << "Illegal choice, try again...." << std::endl;
    } while (selection != 'Q' or 'q');


    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}