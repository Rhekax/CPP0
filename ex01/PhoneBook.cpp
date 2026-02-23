
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdint>
#include <cstdlib>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::Add(Contact person, uint32_t index) {

	this->contacts[index] = person;
}

Contact	PhoneBook::Search(uint32_t index) {
	return this->contacts[index];
}

void PhoneBook::Exit() {
	exit(0);
}