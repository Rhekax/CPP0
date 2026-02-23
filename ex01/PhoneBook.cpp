
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdint>
#include <cstdlib>


void	PhoneBook::Add(Contact person, uint32_t index) {

	this->contacts[index].darkest_secret = person.darkest_secret;
	this->contacts[index].first_name = person.first_name;
	this->contacts[index].last_name = person.last_name;
	this->contacts[index].nickname = person.nickname;
	this->contacts[index].phone_number = person.phone_number;
}

Contact	PhoneBook::Search(uint32_t index) {
	return this->contacts[index];
}

void PhoneBook::Exit() {
	exit(0);
}