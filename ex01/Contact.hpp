#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>

class Contact {
	private:
		int			index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;
		std::string	truncateUserInfo(std::string) const;
		std::string	getprompt(std::string);
		void		formatUserInfo() const;

	public:
		Contact();
		~Contact();

		void	newContact();
		void	displayInfo() const;

};

#endif