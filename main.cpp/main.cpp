#include "user.h"
#include "string.h"
#include "trip_collection.h"
#include <iostream>
#include <fstream>
#include <cassert>

User& regiser_user() {
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
    users_database << User{ username,password,email };
    std::ifstream user_db{(username + String{".db"}).data()};
    return user;
}

User& login() {
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

}


int main()
{
    User current_user;
    char command;
    std::cout << "Login or Register user:\n";
    std::cout << "(l|r): ";
    std::cin >> command;
    if (command == 'l') {
        current_user = regiser_user();
    }
    else if (command == 'r') {
        current_user = login();
    }
    std::cout << "Would you like to see reviews for a destinations?\n";
    std::cout << "(y|n)";
    std::cin >> command;
    if (command == 'n') {
        std::cout << "Have a nice day! :)";
        return 0;
    }
    else if (command == 'y') {
        String destination;
        std::cout << "Input destination: ";
        std::cin >> destination;
        void search_destination(destination);
    }
    return 0;
}
