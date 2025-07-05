#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

struct Room {
    std::string name;
    std::string description;
    std::map<std::string, int> exits;
};

struct Player {
    std::string name;
    int currentRoom;
    int health;
};

std::vector<Room> initializeRooms() {
    std::vector<Room> rooms;

    rooms.push_back({
        "Entrance Hall",
        "You are in a dimly lit entrance hall. Dust covers everything.",
        {{"north", 1}, {"east", 2}}
    });

    rooms.push_back({
        "Kitchen",
        "An old kitchen with rusty utensils.",
        {{"south", 0}}
    });

    rooms.push_back({
        "Library",
        "Rows of books line the walls.",
        {{"west", 0}}
    });

    return rooms;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayRoom(const Room &room) {
    std::cout << "\n=== " << room.name << " ===\n";
    std::cout << room.description << "\n\n";
    std::cout << "Exits: ";
    for (const auto &exit: room.exits) {
        std::cout << exit.first << " ";
    }
    std::cout << "\n";
}

void displayHelp() {
    std::cout << "\nAvailable commands:\n";
    std::cout << "- go <direction>\n";
    std::cout << "- look\n";
    std::cout << "- help\n";
    std::cout << "- quit\n";
}

int main() {
    std::vector<Room> rooms = initializeRooms();
    Player player{"Hero", 0, 100};
    std::string command, direction;
    bool gameRunning = true;

    std::cout << "Welcome to the Text Adventure!\n";

    while (gameRunning) {
        displayRoom(rooms[player.currentRoom]);
        std::cout << "\nWhat would you like to do? ";
        std::cin >> command;

        if (command == "quit") {
            gameRunning = false;
        } else if (command == "look") {
            clearScreen();
            continue;
        } else if (command == "help") {
            displayHelp();
        } else if (command == "go") {
            std::cin >> direction;
            auto &exits = rooms[player.currentRoom].exits;

            if (exits.find(direction) != exits.end()) {
                player.currentRoom = exits[direction];
                clearScreen();
            } else {
                std::cout << "You can't go that way!\n";
            }
        } else {
            std::cout << "I don't understand that command.\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nThanks for playing!\n";
    return 0;
}
