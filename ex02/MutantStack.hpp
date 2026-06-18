/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:56:28 by dteruya           #+#    #+#             */
/*   Updated: 2026/06/18 19:39:00 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }

        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &other) {*this = other}
        MutantStack& operator=(const MutantStack &other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        
};


#endif