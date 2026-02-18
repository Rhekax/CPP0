

#include "Contact.hpp"
#include <iostream>

int	main(void)
{
	int index;
	Contact contact;
	index = 3;
	if (index > 7 || index < 0) {
		std::cout << "Please enter an index value between 0 and 7\n";
	}

		std::cout << "     index|";
		std::cout << "first name|";
		std::cout << " last name|";
		std::cout << "  nickname";
		std::cout << std::endl;
		std::cout << "         " << index << " " ;
		std::cout << contact << std::endl;
}