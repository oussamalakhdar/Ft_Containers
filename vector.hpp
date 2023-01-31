/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:05:45 by olakhdar          #+#    #+#             */
/*   Updated: 2023/01/19 11:07:20 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>

//std::vector<int> a;
namespace ft
{
    class vector
    {
        template <class T>
        class iterator
        {
            public:
                typedef T                               value_type;
                typedef T*                              pointer;
                typedef T&                              reference;
                typedef std::ptrdiff_t                  difference_type; //// need ask for it
                typedef std::random_access_iterator_tag iterator_category; //// need ask

                iterator(pointer p): m_ptr(p) {}

                reference operator*() const { return *m_ptr; }
                pointer operator->() const { return m_ptr; }
                iterator& operator++() { ++(*m_ptr); return *this; }
                iterator operator++(int) const { iterator tmp; tmp = *this; ++(*this); return tmp; }
                iterator& operator--() { --(*m_ptr); return *this; }
                iterator operator--(int) const { iterator tmp; tmp = *this; --(*this); return tmp; }
                bool operator==(const iterator& a) { return this->m_ptr == a.m_ptr; }
                bool operator!=(const iterator& a) { return this->m_ptr != a.m_ptr; }

            private:
                value_type *m_ptr;

        };

    };

}

#endif