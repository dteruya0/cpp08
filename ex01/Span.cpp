/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:59:07 by dteruya           #+#    #+#             */
/*   Updated: 2026/03/13 17:45:03 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) , numbers() {}

Span::Span(unsigned int _N): N(_N), number() {}

Span::Span(const Span &other) : N(other.N) , numbers(other.numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return (*this);
}

void Span::addNumber(int nbr)
{
	if (numbers.size() >= this.N)
		throw NoSpanException();
	numbers.push_back(nbr);
}

template <typename Iterator>
void Span::addNumber(Iterator start, Iterator end)
{
	if (numbers.size() + std::distance(start, end) > N)
		throw FullException();
	while (start != end)
	{
		numbers.push_back(*start);
		start++;
	}
}

int	Span::shortestSpan()
{}

int	Span::longestSpan()
{}


const char* Span::FullException::what() const throw()
{
	return ("Exception caught: this span has no space left!");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Exception caught: there is no span present");
}