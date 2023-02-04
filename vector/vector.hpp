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
#include <assert.h>
#include <stdexcept>
#include "iterator.hpp"
#include <cmath>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                        value_type;
            typedef Allocator                                allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef ft::iterator<pointer>                    iterator;
            typedef ft::iterator<const_pointer>              const_iterator;
    //        typedef ft::reverse_iterator<iterator>         reverse_iterator;
    //        typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::size_type       size_type;

            allocator_type _alloc;
            pointer _data;
        size_type v_capacity;
        size_type v_size;

        explicit vector (const allocator_type& alloc = allocator_type()) \
                          : _alloc(alloc), v_capacity(0), v_size(0) {}

        explicit vector (size_type n, const value_type& val = value_type(),\
                            const allocator_type& alloc = allocator_type()) : _alloc(alloc)
        {
            _data = _alloc.allocate(sizeof (T) * n);
            for (int i = 0; i < n; ++i)
                _data[i] = val;
            v_capacity = n;
            v_size = n;
        }

        reference operator[] (size_type n) { return _data[n]; }
        const_reference operator[] (size_type n) const { return _data[n]; }

        reference at (size_type n)
        {
            if (n >= v_capacity)
                throw std::out_of_range("vector");
            return _data[n];
        }
        const_reference at (size_type n) const
        {
            if (n >= v_capacity)
                throw std::out_of_range("vector");
            return _data[n];
        }

        reference front() { return _data[0]; }
        const_reference front() const { return _data[0]; }

        bool empty() const{
            if (v_size == 0)
                return true;
            return false;
        }

        size_type capacity() const { return v_capacity;}

        size_type size() const {return v_size;}

        size_type max_size() const{ return static_cast<T>(std::pow(2, sizeof(T) * 8)) / sizeof(T);}

        void push_back (const value_type& val)
        {

        }

        void assign(size_type count, const value_type& value) {}

    };

}

#endif