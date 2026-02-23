#include "Contact.hpp"
#include <string>

Contact::Contact()
    : darkest_secret(),
      first_name(),
      last_name(),
      nickname(),
      phone_number()
{
}

Contact::Contact(
    const std::string& darkest_secret,
    const std::string& first_name,
    const std::string& last_name,
    const std::string& nickname,
    int phone_number)
    : darkest_secret(darkest_secret),
      first_name(first_name),
      last_name(last_name),
      nickname(nickname),
      phone_number(phone_number)
{
}

Contact::~Contact() {}

std::string Contact::getFirstName() const {
	return this->first_name;
}
std::string Contact::getLastName() const {
	return this->last_name;
}
std::string Contact::getNickname() const {
	return this->nickname;
}
std::string Contact::getDarkestSecret() const {
	return this->darkest_secret;
}
int Contact::getPhoneNumber() const {
	return this->phone_number;
}
std::ostream& operator<<(std::ostream& out, const Contact& contact) {

		std::string cur_attr = contact.getFirstName();

		if (cur_attr.length() > 10) {
			out << cur_attr.substr(0,9) << "." << "|";
		}
		else {
			for (int i = 10; i - cur_attr.length() > 0; i--)
				out << " ";
			out << cur_attr << "|";
		}
		cur_attr = contact.getLastName();
		if (cur_attr.length() > 10) {
			out << cur_attr.substr(0,9) << "." << "|";
		}
		else {
			for (int i = 10; i - cur_attr.length() > 0; i--)
				out << " ";
			out << cur_attr  << "|";;
		}
		cur_attr = contact.getNickname();
		if (cur_attr.length() > 10) {
			out << cur_attr.substr(0,9) << ".";
		}
		else {
			for (int i = 10; i - cur_attr.length() > 0; i--)
				out << " ";
			out << cur_attr;
		}
		return out;
	}
