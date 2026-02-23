#ifndef CONTACT_H
 # define CONTACT_H

#include <cstdint>
#include <ostream>
#include <string>

class Contact {

	public:
		Contact();
		Contact(
				const std::string& darkest_secret,
				const std::string& first_name,
				const std::string& last_name,
				const std::string& nickname,
				uint32_t phone_number);
		std::string darkest_secret;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		uint32_t phone_number;
 };
	std::ostream& operator<<(std::ostream &out, const Contact& contact);


 #endif