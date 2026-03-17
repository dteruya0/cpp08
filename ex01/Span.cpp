/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:59:07 by dteruya           #+#    #+#             */
/*   Updated: 2026/03/17 14:48:45 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) , numbers() {}

Span::Span(unsigned int _N): N(_N), numbers() {}

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
	if (numbers.size() >= N)
		throw FullException();
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
{
	if (numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> temp = numbers;

	std::sort(temp.begin(), temp.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < temp.size() - 1; i++)
	{
		int diff = temp[i + 1] - temp[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int	Span::longestSpan()
{
	if (numbers.size() < 2)
		throw NoSpanException();

	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());

	return max - min;
}


const char* Span::FullException::what() const throw()
{
	return ("Exception caught: this span has no space left!");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Exception caught: there is no span present");
}