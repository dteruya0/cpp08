/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:59:10 by dteruya           #+#    #+#             */
/*   Updated: 2026/03/17 14:45:35 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try {
        std::cout << "=== TEST 1: basic ===" << std::endl;

        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "\n=== TEST 2: error (less than 2 elements) ===" << std::endl;

        Span sp2(5);
        sp2.addNumber(42);

        std::cout << sp2.shortestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== TEST 3: overflow ===" << std::endl;

        Span sp3(2);

        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}