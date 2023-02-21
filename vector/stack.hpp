/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:19:37 by olakhdar          #+#    #+#             */
/*   Updated: 2023/02/19 16:19:38 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class _Container =  ft::vector <T> >
    class stack
    {
        public:
            typedef _Container                               container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type       size_type;

        protected:
            container_type c;

        public:
            stack() : c() { }
            explicit stack (const container_type& _c) : c(_c) { }
            stack& operator= (const stack& s) { c = s.c; return *this; }
            stack(const stack& s) : c(s.c) { }

            bool empty() const { return c.empty(); };

            size_type size() const      { return c.size(); }

            reference top() { return c.back();}
            const_reference top() const { return c.back(); }

            void push(const value_type& _v) { c.push_back(_v); }

            void pop() { c.pop_back(); }

            template <class T1, class C>
            friend bool operator== (const stack<T1,C>& a, const stack<T1,C>& b) { return  a.c == b.c;}
            template <class T1, class C>
            friend bool operator!= (const stack<T1,C>& a, const stack<T1,C>& b) { return  !(a.c == b.c); }
            template <class T1, class C>
            friend bool operator<  (const stack<T1,C>& a, const stack<T1,C>& b) { return  a.c < b.c; }
            template <class T1, class C>
            friend bool operator<= (const stack<T1,C>& a, const stack<T1,C>& b) { return  !(b.c < a.c); }
            template <class T1, class C>
            friend bool operator>  (const stack<T1,C>& a, const stack<T1,C>& b) { return  b.c < a.c; }
            template <class T1, class C>
            friend bool operator>= (const stack<T1,C>& a, const stack<T1,C>& b) { return !(a.c < b.c); }
            };

}

#endif
