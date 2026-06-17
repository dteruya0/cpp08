/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:59:14 by dteruya           #+#    #+#             */
/*   Updated: 2026/03/17 14:38:36 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <limits>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>


class Span
{
	private:
		unsigned int N;
		std::vector<int> numbers;

	public:
		Span();
		Span(unsigned int _N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void addNumber(int nbr);
		int	shortestSpan();
		int	longestSpan();

		template <typename Iterator>
		void addNumber(Iterator start, Iterator end)
		{
			if (numbers.size() + std::distance(start, end) > N)
				throw FullException();
			while (start != end)
			{
				numbers.push_back(*start);
				start++;
			}
		}

		class FullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};




#endif