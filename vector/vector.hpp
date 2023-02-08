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
                          : _alloc(alloc), v_capacity(0), v_size(0), _data(nullptr) {}

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

        reference back() { return _data[v_size - 1]; }
        const_reference back() const { return _data[v_size - 1]; }

        bool empty() const {
            if (v_size == 0)
                return true;
            return false;
        }

        size_type capacity() const { return v_capacity;}

        size_type size() const { return v_size; }

//        size_type max_size() const {
//            return static_cast<T>(std::pow(2, sizeof(T) * 8)) / sizeof(T);
//        }
        size_type max_size() const
        {
            return _alloc.max_size();
        }

        allocator_type get_allocator() const { return _alloc; }

        void swap (vector& x)
        {
            pointer tmp;
            size_t  c ;
            size_t  s;

            tmp =  _alloc.allocate(sizeof (T) * v_size);
            for (int i = 0; i < v_size; ++i)
               _alloc.construct(tmp + i, _data[i]);
            for (int i = 0; i < v_capacity; ++i)
                _alloc.destroy(_data + i);
            _alloc.deallocate(_data, v_capacity);
            c = v_capacity;
            s = v_size;

            _data = _alloc.allocate(sizeof(T) * x.v_capacity);
            for (int i = 0; i < x.v_size; ++i)
                _alloc.construct(_data + i, x._data[i]);
            for (int i = 0; i < x.v_capacity ; ++i)
                _alloc.destroy(x._data + i);
            _alloc.deallocate(x._data, x.v_capacity);
            v_capacity = x.v_capacity;
            v_size = x.v_size;

            x._data = _alloc.allocate(sizeof(T) * c);
            for (int i = 0; i < s; ++i)
                _alloc.construct(x._data + i, tmp[i]);
            for (int i = 0; i < s ; ++i)
                _alloc.destroy(tmp + i);
            _alloc.deallocate(tmp, s);
            x.v_capacity = c;
            x.v_size = s;
        }

        void reserve (size_type n)
        {
            if (n > v_capacity)
            {
                if (!empty())
                {
                    pointer tmp;
                    tmp = _alloc.allocate(sizeof(T) * v_capacity);
                    for (int i = 0; i < v_capacity; ++i)
                        _alloc.construct(tmp + i, _data[i]);

                    for (int i = 0; i < v_capacity; ++i)
                        _alloc.destroy(_data + i);
                    _alloc.deallocate(_data, v_capacity);

                    _data = _alloc.allocate(sizeof(T) * n);
                    for (int i = 0; i < v_capacity; ++i)
                        _alloc.construct(_data + i, tmp[i]);

                    for (int i = 0; i < v_capacity; ++i)
                        _alloc.destroy(tmp + i);
                    _alloc.deallocate(tmp, v_capacity);
                }
                else
                    _data = _alloc.allocate(sizeof(T) * n);
                v_capacity = n;
            }
        }

        void push_back (const value_type& val)
        {
            if (empty())
                reserve(1);
            else if (v_size == v_capacity)
                reserve(v_capacity * 2);
            _alloc.construct(_data + v_size++,  val);
        }
        void pop_back ()
        {
            if (v_size >=1 )
                _alloc.destroy(_data + --v_size);
        }
        void clear()
        {
            if (!empty())
            {
                for (int i = 0; i < v_size; ++i)
                    _alloc.destroy(_data + i);
                v_size = 0;
            }
        }

        void resize (size_type n, value_type val = value_type())
        {
            if (n < v_size)
            {
                for (int i = n; i < v_size; i++)
                    _alloc.destroy(_data + i);
                v_size = n;
            }
            else if (n > v_size)
            {
                if (n > v_capacity)
                    reserve(n);
                for (int i = v_size; i < n; i++)
                    _alloc.construct(_data + i, val);
                v_size = n;
            }
        }


        void assign(size_type count, const value_type& value) { }

    };

}

#endif