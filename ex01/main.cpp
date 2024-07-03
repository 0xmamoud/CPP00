#include "PhoneBook.hpp"

int main()
{
	std::string str;
	PhoneBook phonebook;
	while (1) {
		do
		{
			std::cout << "prompt ADD SEARCH or EXIT" << std::endl;
			std::getline(std::cin, str);
			if (std::cin.eof())
				exit(EXIT_FAILURE);
		} while (str.empty());
		if (str == "EXIT")
			break;
		if (str == "ADD" )
		{
			phonebook.addContact();
		}
		if (str == "SEARCH")
			phonebook.searchContact();
	}
	return 0;
}
