#ifndef CONTACT_H
 # define CONTACT_H

#include <ostream>
#include <string>

class Contact {

	private:
		std::string darkest_secret;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		int phone_number;

	public:
		Contact();
		~Contact();
		Contact(
				const std::string& darkest_secret,
				const std::string& first_name,
				const std::string& last_name,
				const std::string& nickname,
				int phone_number);
				std::string getFirstName() const;
    			std::string getLastName() const;
    			std::string getNickname() const;
    			std::string getDarkestSecret() const;
    			int getPhoneNumber() const;

 };
	std::ostream& operator<<(std::ostream &out, const Contact& contact);


 #endif