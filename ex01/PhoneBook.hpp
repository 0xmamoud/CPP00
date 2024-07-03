#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		static int index;
		Contact contact[8];

	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact() const;
};

#endif