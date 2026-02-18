#ifndef PHONEBOOK_H
 # define PHONEBOOK_H

#include "Contact.hpp"
#include <cstdint>

class PhoneBook {

	private:
		Contact contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void Add(Contact person, uint32_t index);
		Contact Search(uint32_t index);
		void Exit(void);
		Contact getContact(uint32_t index);
};


 #endif