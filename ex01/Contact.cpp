#include "Contact.hpp"

Contact::Contact()
    : darkest_secret("NO MORE"),
      first_name("whatis"),
      last_name("love"),
      nickname("BABY DONT HURT ME"),
      phone_number(123)
{
}

Contact::Contact(
    const std::string& darkest_secret,
    const std::string& first_name,
    const std::string& last_name,
    const std::string& nickname,
    uint32_t phone_number)
    : darkest_secret(darkest_secret),
      first_name(first_name),
      last_name(last_name),
      nickname(nickname),
      phone_number(phone_number)
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
