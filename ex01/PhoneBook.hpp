#ifndef PHONEBOOK_H
 # define PHONEBOOK_H

#include "Contact.hpp"
#include <stdlib.h>

class PhoneBook {

	private:
		Contact contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void Add(Contact person, int index);
		Contact Search(int index);
		void Exit(void);
};


 #endif