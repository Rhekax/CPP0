
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstddef>
#include <iostream>


enum Action {
	ADD,
	SEARCH,
	EXIT,
	NONE
};

Action hashString(const std::string& str) {
    if (str == "ADD") return ADD;
    if (str == "SEARCH")  return SEARCH;
    if (str == "EXIT")  return EXIT;
    return NONE;
}

int readIndex() {
    std::string line;
    int i;

    while (true) {
        std::cout << "Enter index (0-7): ";
        std::getline(std::cin, line);
        if (line.empty()) continue;

        bool valid = true;
        for (size_t j = 0; j < line.size(); ++j)
            if (!isdigit(line[j])) { valid = false; break; }

        if (!valid) { std::cout << "Must be numeric.\n"; continue; }

        i = atoi(line.c_str());
        if (i < 0 || i > 7) { std::cout << "Index must be 0-7.\n"; continue; }

        return i;
    }
}

std::string readNonEmpty(const std::string &prompt)
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (!std::cin)
        {
            std::cin.clear();
            continue;
        }

        if (!input.empty())
            return input;

        std::cout << "Field cannot be empty. Try again.\n";
    }
}

int main() {
    PhoneBook pbook;
    int index = 0;
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        if (input.empty()) continue;

        Action action = hashString(input);

        switch(action) {
            case NONE:
                break;

            case ADD: {
                std::string fn = readNonEmpty("Enter First Name: ");
                std::string ln = readNonEmpty("Enter Last Name: ");
                std::string nn = readNonEmpty("Enter Nickname: ");
                std::string ds = readNonEmpty("Enter Darkest Secret: ");

                int pn;
                while (true) {
                    std::string line;
                    std::cout << "Enter Phone Number: ";
                    std::getline(std::cin, line);

                    if (line.empty()) { std::cout << "Cannot be empty.\n"; continue; }

                    bool valid = true;
                    for (size_t i = 0; i < line.size(); ++i)
                        if (!isdigit(line[i])) { valid = false; break; }

                    if (!valid) { std::cout << "Must be numeric.\n"; continue; }

                    pn = atoi(line.c_str());
                    break;
                }

                Contact c(ds, fn, ln, nn, pn);
                pbook.Add(c, index);
                index = (index + 1) % 8;

                std::cout << "Contact added.\n";
                break;
            }

            case SEARCH: {
                std::cout << "     index|first name| last name|  nickname\n";
                for (int i = 0; i < 8; i++)
                    std::cout << "         " << i << "|" << pbook.Search(i) << std::endl;

                int i;
                while (true) {
                    i = readIndex();
                    if (i >=0 && i <=7) break;
                    std::cout << "Invalid index. Try again.\n";
                }
                std::cout << "         " << i << "|" << pbook.Search(i) << std::endl;
                break;
            }

            case EXIT:
                pbook.Exit();
                return 0;
        }
    }
}