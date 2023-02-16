/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:49:03 by olakhdar          #+#    #+#             */
/*   Updated: 2023/02/03 10:49:04 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class iterator
    {
        public:
            typedef T                                                                iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer             pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference           reference;
            typedef typename ft::iterator_traits<iterator_type>::difference_type     difference_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category   iterator_category;

            iterator() : m_ptr() {}
            iterator(iterator_type p) : m_ptr(p) {}
            iterator_type base() const {return m_ptr;}

            reference   operator*() const { return *m_ptr; }
            pointer     operator->() const { return m_ptr; }
            iterator&   operator++() { ++m_ptr; return *this; }
            iterator    operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
            iterator&   operator--() { --m_ptr; return *this; }
            iterator    operator--(int) { iterator tmp = *this; --(*this); return tmp; }
            iterator    operator+(difference_type a) const { iterator tmp = *this; tmp += a; return tmp; }
            iterator&   operator+=(difference_type a) { m_ptr += a; return *this; }
            iterator    operator-(difference_type a) const { return *this + (-a); }
            iterator&   operator-=(difference_type a) { *this += -a; return *this;}
            reference   operator[](difference_type a) const { return m_ptr[a]; }

            friend bool operator==(const iterator &a, const iterator &b) { return a.base() == b.base(); }
            friend bool operator<(const iterator &a, const iterator &b) { return a.base() < b.base(); }
            friend bool operator!=(const iterator &a, const iterator &b) { return !(a == b); }
            friend bool operator>(const iterator &a, const iterator &b) { return b < a; }
            friend bool operator>=(const iterator &a, const iterator &b) { return !(a < b); }
            friend bool operator<=(const iterator &a, const iterator &b) { return !(b < a); }
            friend difference_type operator-(const iterator& a, const iterator& b) { return a.base() - b.base();}

        private:
            iterator_type m_ptr;
    };
}
#endif
