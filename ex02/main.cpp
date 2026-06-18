/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:52:34 by dteruya           #+#    #+#             */
/*   Updated: 2026/06/18 19:31:37 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "===== TESTE MUTANTSTACK =====" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "size depois do pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nPercorrendo com iterator:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n===== TESTE COPIA PARA STD::STACK =====" << std::endl;

    std::stack<int> s(mstack);

    std::cout << "top da std::stack copiada: " << s.top() << std::endl;
    std::cout << "size da std::stack copiada: " << s.size() << std::endl;

    std::cout << "\n===== TESTE COM STD::LIST =====" << std::endl;

    std::list<int> lista;

    lista.push_back(5);
    lista.push_back(3);
    lista.push_back(5);
    lista.push_back(737);
    lista.push_back(0);

    std::list<int>::iterator lit = lista.begin();
    std::list<int>::iterator lite = lista.end();

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}