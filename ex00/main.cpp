/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:24:59 by dteruya           #+#    #+#             */
/*   Updated: 2026/03/04 10:25:18 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(v, 42);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}