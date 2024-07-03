#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

void Contact::newContact(int nbr)
{
	this->index = nbr;
	this->firstName = getprompt("first name: ");
	this->lastName = getprompt("last name: ");
	this->nickname = getprompt("nick name: ");
	this->phoneNumber = getprompt("phone number: ");
	this->secret = getprompt("darkest secret: ");
};

std::string Contact::getprompt(std::string str) const {
	std::string prompt;

	std::cout << str;
	std::getline(std::cin, prompt);
	while (prompt.empty())
	{
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		std::cout << "can't be empty" << std::endl;
		std::cout << str;
		std::getline(std::cin, prompt);
	}
	
	return prompt;
}

void Contact::displayInfo() const {
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phoneNumber << std::endl;
	std::cout << this->secret << std::endl;
};

void Contact::formatUserInfo() const {
	std::cout << "|" << std::setw(10) << this->index << std::flush;
	std::cout << "|" << std::setw(10) << truncateUserInfo(this->firstName) << std::flush;
	std::cout << "|" << std::setw(10) << truncateUserInfo(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << truncateUserInfo(this->nickname) << std::flush;
	std::cout << "|" << std::endl;
}

std::string Contact::truncateUserInfo(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}


