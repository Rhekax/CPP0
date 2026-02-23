

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>

enum class Action {
	ADD,
	SEARCH,
	EXIT,
	NONE
};

Action hashString(const std::string& str) {
    if (str == "ADD") return Action::ADD;
    if (str == "SEARCH")  return Action::SEARCH;
    if (str == "EXIT")  return Action::EXIT;
    return Action::NONE;
}

int readIndex()
{
    int i;

    while (true)
    {
        std::cout << "Enter index (0-7): ";
        if (!(std::cin >> i))
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Not a number.\n";
            continue;
        }

        if (i >= 0 && i <= 7)
        {
            std::cin.ignore(1000, '\n');
            return i;
        }

        std::cout << "Index must be between 0 and 7.\n";
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

int	main(void)
{
	int i ;
	int index = 0;
	int pn;
	std::string input;
	std::string ds;
	std::string fn;
	std::string ln;
	std::string nn;
	Contact c;
	Action action = Action::NONE;
	PhoneBook pbook;
	while (1) {
		std::cin >> input ;
		action = hashString(input);
		switch (action) {
			case Action::NONE :
				break;
			case Action::ADD:
			{
			    std::string fn, ln, nn, ds;
			    int pn;
			
			    std::cin.ignore(1000, '\n');
			
			    fn = readNonEmpty("Enter First Name: ");
			    ln = readNonEmpty("Enter Last Name: ");
			    nn = readNonEmpty("Enter Nickname: ");
			    ds = readNonEmpty("Enter Darkest Secret: ");
			
			    while (true)
			    {
			        std::cout << "Enter Phone Number: ";
			        if (!(std::cin >> pn))
			        {
			            std::cin.clear();
			            std::cin.ignore(1000, '\n');
			            std::cout << "Phone number must be numeric.\n";
			            continue;
			        }
			        std::cin.ignore(1000, '\n');
			        break;
			    }
			
			    Contact c(ds, fn, ln, nn, pn);
			    pbook.Add(c, index);
			    index = (index + 1) % 8;
			
			    std::cout << "Contact added.\n";
			    break;
			}
			case Action::SEARCH:
			{
			    std::cout << "     index|first name| last name|  nickname\n";
			
			    for (int c = 0; c < 8; c++)
			        std::cout << "         " << c << "|" << pbook.Search(c) << std::endl;
			
			    int i = readIndex();
			
			    std::cout << "         " << i << "|" << pbook.Search(i) << std::endl;
			    break;
			}
			case Action::EXIT :
				pbook.Exit();
		}
	}
	return 0;
}