/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:05:45 by olakhdar          #+#    #+#             */
/*   Updated: 2023/02/10 18:42:05 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <assert.h>
#include <stdexcept>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "is_integral.hpp"
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
           typedef ft::reverse_iterator<iterator>         reverse_iterator;
           typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::size_type       size_type;

            allocator_type _alloc;
            pointer _data;
            size_type v_capacity;
            size_type v_size;
        /* 
         !┌────────────────────────────────────────────────────────────────────────────┐
         !│               Member functions                                             │
         !└────────────────────────────────────────────────────────────────────────────┘
        */
            explicit vector (const allocator_type& alloc = allocator_type()) \
                              : _alloc(alloc), v_capacity(0), v_size(0), _data(nullptr) {}

            explicit vector (size_type n, const value_type& val = value_type(),\
                                const allocator_type& alloc = allocator_type()) \
                                : _alloc(alloc), v_capacity(n), v_size(n)
            {

                _data = _alloc.allocate(n * sizeof(T));
                for (int i = 0; i < n; ++i)
                   _alloc.construct(_data + (i * sizeof(T)), val);
            }
            ~vector(){
                if (_data) {
                    for (int i = 0; i < v_capacity; ++i)
                        _alloc.destroy(_data + (sizeof(T) * i));
                    _alloc.deallocate(_data, v_capacity);
                }
            }

            reference operator[] (size_type n) { return *(_data + (sizeof(T) * n)); }
            const_reference operator[] (size_type n) const { return *(_data + (sizeof(T) * n)); }
            vector& operator= (const vector& x)
            {
                _alloc = x._alloc;
                _data = x._data;
                v_capacity = x.v_capacity;
                v_size = x.v_size;
                return *this;
            }

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

            reference back() { return *(_data + (sizeof(T) * (v_size - 1))); }
            const_reference back() const { return *(_data + (sizeof(T) * (v_size - 1))); }

            bool empty() const {
                if (v_size == 0)
                    return true;
                return false;
            }

            size_type capacity() const { return v_capacity;}

            size_type size() const { return v_size; }

            size_type max_size() const
            {
                return _alloc.max_size();
            }

            allocator_type get_allocator() const { return _alloc; }

            void swap (vector& x)
            {
                vector tmp;
                tmp = *this;
                *this = x;
                x = tmp;
            }

            void reserve (size_type n)
            {
                if (n > v_capacity)
                {
                    if (!empty())
                    {
                        pointer tmp;
                        tmp = _alloc.allocate(sizeof(T) * n);
                        for (int i = 0; i < v_capacity; ++i) {
                            _alloc.construct(tmp + (sizeof(T) * i), *(_data + (sizeof(T) * i)));
                            _alloc.destroy(_data + (sizeof(T) * i));
                        }
                        _alloc.deallocate(_data, v_capacity);

                        _data = tmp;
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
                    size_type i = n;
                    while (i < v_size) {
                        _alloc.destroy(_data + (sizeof(T) * i));
                        i++;
                    }
                    v_size = n;
                }
                else if (n > v_size)
                {
                    if (n > v_capacity) {
                        if ( n <= v_capacity * 2)
                            reserve(v_capacity * 2);
                        else
                            reserve(n);
                    }
                    size_type i = v_size;
                    while (i < n) {
                        _alloc.destroy(_data + (sizeof(T) * i));
                        _alloc.construct(_data + (sizeof(T) * i), val);
                        i++;
                    }
                    v_size = n;
                }
            }

            iterator begin(){ iterator a(_data); return a; }
            const_iterator begin() const { const_iterator a(_data); return a; }

            iterator end() { iterator a(_data + (v_size * sizeof(T))); return a;}
            const_iterator end() const { const_iterator a(_data + (v_size * sizeof(T))); return a; }

            // void assign(size_type count, const value_type& value) { }

            void assign(size_type n, const value_type& val)
                {
                    if (v_capacity >= n)
                    {
                        size_t i = 0;
                        v_size = n;
                        while (i < n)
                        {
                            _alloc.construct(_data + ( sizeof(T) * i), val);
                            i++;
                        }
                    }
                    else
                    {
                        _alloc.deallocate(_data,v_capacity);
                        v_capacity = n;
                        v_size = n;
                        _data = _alloc.allocate(n * sizeof(T));
                        for (size_t i  = 0 ; i < n ; i++ )
                            _alloc.construct(_data + (sizeof(T) * i),val);
                    }
                }

                 template <class InputIterator>
                void assign(InputIterator first, InputIterator last, typename ft::enable_if<ft::is_integral<InputIterator>::value == false, InputIterator>::type = InputIterator())
                {
                    difference_type diff = std::distance(first, last);

                    if (v_capacity >= static_cast<size_t>(diff))
                    {
                        size_t i = 0;
                        v_size = static_cast<size_t>(diff);
                        while (first != last)
                        {
                            _alloc.construct(_data + ( sizeof(T) * i), *first);
                            first++;
                            i++;
                        }
                    }
                    else
                    {
                        _alloc.deallocate(_data,v_capacity);
                        v_capacity = static_cast<size_t>(diff);
                        v_size = static_cast<size_t>(diff);
                        _data = _alloc.allocate(static_cast<size_t>(diff) * sizeof(T));
                        size_t i = 0;
                        while (first != last)
                        {
                            _alloc.construct(_data + (sizeof(T) * i),*first);
                            first++;
                            i++;
                        }
                    }
                }

                friend bool operator== (const vector& x, const vector& y) {
                    if (x.v_size != y.v_size)
                        return false;
                    for (size_t i = 0; i < x.size(); ++i) {
                        if (x[i] != y[i])
                            return false;
                    }
                    return true;
                }
                friend bool operator!= (const vector& x, const vector& y) { return !(x == y); }
                friend bool operator>  (const vector& x, const vector& y) {
                    for (size_t i = 0; i < x.v_size && i < y.v_size; ++i)
                    {
                        if (x[i] > y[i])
                            return true;
                        else if (x[i] < y[i])
                            return false;
                    }
                    return x.v_size > y.v_size;
                }
                friend bool operator< (const vector& x, const vector& y) { return y > x; }
                friend bool operator<= (const vector& x, const vector& y) { return !( x > y); }
                friend bool operator>= (const vector& x, const vector& y) { return !( x < y); }

    };

}

#endif