/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:59:14 by dteruya           #+#    #+#             */
/*   Updated: 2026/03/13 15:50:54 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

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
		template <typename iterator>
		void addNumber(iterator start, iterator end);
		int	shortestSpan();
		int	longestSpan();

		class FullException : public std::FullException
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::NoSpanException
		{
			public:
				const char* what() const throw();
		};
};




#endif