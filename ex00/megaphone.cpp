/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:26:49 by mamoud            #+#    #+#             */
/*   Updated: 2024/06/11 22:00:07 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cctype>

std::string str_toupper(std::string av)
{
	for (size_t i = 0; i < av.length(); i++)
	{
		av[i] = toupper(av[i]);
	}
	return av;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (size_t i = 1; i < ac; i++)
	{
		std::cout << str_toupper(av[i]);
	}
	std::cout << std::endl;
	return 0;
}
