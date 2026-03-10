
#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::Add(Contact person, int index) {

	this->contacts[index] = person;
}

Contact	PhoneBook::Search(int index) {
	return this->contacts[index];
}

void PhoneBook::Exit() {
	exit(0);
}