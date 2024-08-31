#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	private:
		int			index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;
		std::string	truncateUserInfo(std::string) const;
		std::string	getprompt(std::string str) const;

	public:
		Contact();
		~Contact();

		void		formatUserInfo() const;
		void	newContact(int nbr);
		void	displayInfo() const;

};

#endif