/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:54:18 by dteruya           #+#    #+#             */
/*   Updated: 2026/03/04 10:24:55 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Value not found in container";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator index;

	index = std::find(container.begin(), container.end(), value);
	if (index == container.end())
		throw NotFoundException();
	return index;
}


#endif