#include "PhoneBook.hpp"

int PhoneBook::index = 0;

PhoneBook::PhoneBook(){};

PhoneBook::~PhoneBook(){};

void	PhoneBook::addContact() {
	if (this->index >= 8) {
		this->contact[7].newContact(this->index);
		return;
	}
	this->contact[index].newContact(this->index);
	index++;
};

void PhoneBook::searchContact() const {
	std::string str;
	if (this->index == 0) {
		std::cout << "0 contact registered" << std::endl;
		return ;
	}
	for (int i = 0; i < index; i++)
	{
		this->contact[i].formatUserInfo();
		std::cout << "------------------" << std::endl;
	}
	
	do
	{
		std::cout << "which contact do you want to display? choose an index" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
	} while (str.empty());
	
	int nbr = std::atoi(str.c_str());
	if (nbr < 0 || nbr >= this->index || (nbr == 0 && str[0] != '0')) {
		std::cout << "Invalid input" << std::endl;
		return;
	}
	this->contact[nbr].displayInfo();
}