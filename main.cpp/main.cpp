#include "user.h"
#include "string.h"
#include "trip_collection.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>

User regiser_user() {
    String username, password, email;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << "Email: ";
    std::cin >> email;
    User user { username,password,email };

    std::ofstream users_database{ "users.db",std::ios::app };
    assert(users_database);
    users_database <<user;
    String user_filename{ username + ".db" };
    std::ofstream user_db{user_filename.data()};
    return user;
}

User login() {
    String username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    
    std::ifstream users_database{ "users.db" };
    User user;
    while (users_database >> user) {
        if (user.username() == username && user.password() == password) {
            return user;
        }
    }
    bool user_not_found{ false };
    assert(user_not_found);
}

void search_destination(const String& dest) {
    std::ifstream users_db{ "users.db" };
    assert(users_db);
    User user;
    unsigned times_visited = 0;
    double sum_grades = 0;
    while (users_db >> user) {
        TripCollection tripCol = user.load_trips();
        unsigned size = tripCol.size();
        for (unsigned i = 0; i < size; i++) {
            if (tripCol[i].destination() == dest) {
                times_visited++;
                sum_grades += tripCol[i].grade();
                //std::cout << '\n'<<tripCol[i];
                output_without_dest(std::cout, tripCol[i]);
            }
        }
    }
    if (!times_visited) {
        std::cout << "Nobody has visited this destination.";
        return;
    }
    std::cout << "\nAverage grade: " << std::setprecision(2)<< sum_grades / times_visited<<'\n';
}

int main()
{
    User current_user;
    char command;
    std::cout << "Login or Register user:\n";
    std::cout << "(l|r): ";
    std::cin >> command;
    std::cin.ignore();
    assert(command == 'r' || command == 'l' && "Incorrect command");
    if (command == 'r') {
        current_user = regiser_user();
    }
    else if (command == 'l') {
        current_user = login();
    }
    std::cout << "Would you like to see reviews for a destination?\n";
    std::cout << "(y|n): ";
    std::cin >> command;
    std::cin.ignore();
    assert(command == 'y' || command == 'n' && "Incorrect command");
    if (command == 'n') {
        std::cout << "Have a nice day! :)";
        return 0;
    }
    else if (command == 'y') {
        String destination;
        std::cout << "Input destination: ";
        std::cin >> destination;
        search_destination(destination);
    }
    return 0;
}
