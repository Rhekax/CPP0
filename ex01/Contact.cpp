#include "Contact.hpp"

Contact::Contact()
    : darkest_secret("NO MORE"),
      first_name("whatis"),
      last_name("love"),
      nickname("BABY DONT HURT ME"),
      phone_number(123)
{
}

std::ostream& operator<<(std::ostream& out, const Contact& contact) {
		if (contact.first_name.length() > 10) {
			out << contact.first_name.substr(0,9) << "." << " ";
		}
		else {
			for (int i = 10; i - contact.first_name.length() > 0; i--)
				out << " ";
			out << contact.first_name << " ";
		}
		if (contact.last_name.length() > 10) {
			out << contact.last_name.substr(0,9) << "." << " ";
		}
		else {
			for (int i = 10; i - contact.last_name.length() > 0; i--)
				out << " ";
			out << contact.last_name  << " ";;
		}
		if (contact.nickname.length() > 10) {
			out << contact.nickname.substr(0,9) << ".";
		}
		else {
			for (int i = 10; i - contact.nickname.length() > 0; i--)
				out << " ";
			out << contact.nickname;
		}
		return out;
	}
