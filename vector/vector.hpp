/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:05:45 by olakhdar          #+#    #+#             */
/*   Updated: 2023/02/11 10:21:15 by olakhdar         ###   ########.fr       */
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
            typedef ft::reverse_iterator<iterator>           reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::size_type       size_type;

        private:
            allocator_type _alloc;
            pointer _data;
            size_type v_capacity;
            size_type v_size;
            void freax()
            {
                if (v_capacity > 0 && _data){
                    _alloc.deallocate(_data, v_capacity);
                    _data = NULL;
                    v_capacity = 0;
                    v_size = 0;
                }
            }

        public:
        /* 
        !┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
        !│                       MEMBER FUNCTIONS:                                                                            │
        !└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/        
            explicit vector (const allocator_type& alloc = allocator_type())
                              : _alloc(alloc), _data(NULL), v_capacity(0), v_size(0) {}

            explicit vector (size_type n, const value_type& val = value_type(),
                                const allocator_type& alloc = allocator_type())
                                : _alloc(alloc), _data(NULL), v_capacity(0), v_size(0)
            {
//                freax();
                if (n > 0){
                    _data = _alloc.allocate(n);
                    for (size_t i = 0; i < n; ++i)
                        _alloc.construct(_data + i, val);
                    v_capacity = n;
                    v_size = n;
                }
            }
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),\
                    typename ft::enable_if<ft::is_integral<InputIterator>::value == false, InputIterator>::type = InputIterator())
                    :  _alloc(alloc), _data(NULL), v_capacity(0), v_size(0)
            {
                assign(first, last);
            }
            vector (const vector& x)
            {
                v_capacity = x.capacity();
                v_size = x.size();
                _alloc = x.get_allocator();
                if (x.size() > 0)
                {
                    _data = _alloc.allocate(v_capacity);
                    for (size_t i = 0; i < x.size(); ++i)
                        _alloc.construct(_data + i, x._data[i]);
                }
            }

            ~vector(){
                if (size() > 0)
                    clear();
                if (capacity() > 0)
                    _alloc.deallocate(_data, v_capacity);
            }

            vector& operator= (const vector& x)
            {
                if (this == &x)
                    return *this;
                clear();
                if (_data != NULL)
                    _alloc.deallocate(_data, v_capacity);
                v_capacity = 0;
                _alloc = x.get_allocator();
                _data = _alloc.allocate(x.capacity());
                for (size_t i = 0; i < x.size(); ++i)
                    _alloc.construct(_data + i, x._data[i]);
                v_capacity = x.v_capacity;
                v_size = x.v_size;
                return *this;
            }
            
        /* 
        !┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
        !│                       ELEMENT ACCESS:                                                                              │
        !└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
        
            reference operator[] (size_type n) { return *(_data + n); }
            const_reference operator[] (size_type n) const { return *(_data + n); }

            reference at (size_type n)
            {
                try {
                    if (n >= v_size)
                        throw std::out_of_range("vector");
                }catch(...){
                    throw;
                }
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

            reference back() { return *(_data + ( (v_size - 1))); }
            const_reference back() const { return *(_data + ( (v_size - 1))); }
        /* 
        !┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
        !│                       CAPACITY:                                                                                    │
        !└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
            size_type size() const { return v_size; }
            
            size_type max_size() const { return std::min<size_type>(_alloc.max_size() , std::numeric_limits<difference_type>::max()); }

            void resize (size_type n, value_type val = value_type())
            {
                if (n < v_size)
                {
                    size_type i = n;
                    while (i < v_size) {
//                        if (_data + i != NULL)
                            _alloc.destroy(_data + i);
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
                    while (i < n)
                    {
                        _alloc.construct(_data + ( i), val);
                        i++;
                    }
                    v_size = n;
                }
            }
            
            size_type capacity() const { return v_capacity;}

            bool empty() const {
                if (v_size == 0)
                    return true;
                return false;
            }
            
            void reserve (size_type n)
            {
                if (n <= v_capacity) {
                    return;
                }
                pointer tmp = _alloc.allocate(n);
                for (size_type i = 0; i < v_size; ++i) {
                    _alloc.construct(tmp + i, _data[i]);
                    _alloc.destroy(_data + i);
                }
                if (v_capacity > 0) {
                    _alloc.deallocate(_data, v_capacity);
                }
                _data = tmp;
                v_capacity = n;
            }
        /* 
        !┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
        !│                       ALLOCATOR:                                                                                   │
        !└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
            
            allocator_type get_allocator() const { return _alloc; }
        
        /* 
        !┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
        !│                       ITERATORS:                                                                                   │
        !└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
            
            iterator begin(){  return iterator(_data); }
            const_iterator begin() const { const_iterator a(_data); return a; }

            iterator end() { iterator a(_data + (v_size)); return a;}
            const_iterator end() const { const_iterator a(_data + (v_size)); return a; }

            reverse_iterator rbegin() { reverse_iterator a(end()); return a; }
            const_reverse_iterator rbegin() const { const_reverse_iterator a(end()); return a; }

            reverse_iterator rend() { reverse_iterator a(begin()); return a; }
            const_reverse_iterator rend() const { const_reverse_iterator a(begin()); return a; }
            
            
        /* 
        !┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
        !│                       MODIFIERS:                                                                                   │
        !└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last,
                         typename ft::enable_if<ft::is_integral<InputIterator>::value == false, InputIterator>::type = InputIterator())
            {
                if (std::is_same<typename std::iterator_traits<InputIterator>::iterator_category, std::input_iterator_tag>::value)
                {
                    clear();
                    for (InputIterator it = first; it != last; ++it)
                        push_back(*it);
                    return ;
                }
                InputIterator f = first;
                size_type d = 0;
                while (f != last) {
                    ++d;
                    f++;
                }
                clear();
                if (d > v_capacity)
                    reserve(d);
                size_t i = 0;
                while (first != last)
                {
                    _alloc.construct(_data + i, *first);
                    ++first;
                    ++i;
                }
                    v_size = d;
            }
            void assign(size_type n, const value_type& val)
            {
                clear();
                if (n > v_capacity)
                    reserve(n);
                for (size_type i = 0; i < n; ++i)
                    _alloc.construct(_data + i, val);
                v_size = n;
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
                if (v_size >= 1 )
                    _alloc.destroy(_data + --v_size);
            }

            iterator insert (iterator position, const value_type& val)
            {
//                vector back(*this);
//                try{
//                    if (position < begin() || position >= end())
//                        throw std::out_of_range("Invalid iterator position");
//                    }
//                    std::cout << "(*1)" << std::endl;
                    size_t index = position - begin();

                    if (v_size == v_capacity)
                        reserve(v_size + 1);

                    for (size_t i = v_size; i > index; --i) {
                        _alloc.construct(_data + i, _data[i - 1]);
                        _alloc.destroy(_data + i - 1);
                    }

                    _alloc.construct(_data + index, val);
                    ++v_size;

                    return begin() + index;
//                }
//                catch(const std::out_of_range& e)
//                {
//                    swap(back);
//                    throw e;
//                }
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
//                std::cout << "(*2)" << std::endl;
                size_t index = position - begin();

                if (v_size + n > v_capacity) {
                    reserve(v_size + n);
                }

                for (size_t i = v_size + n - 1; i > index + n - 1; --i) {
                    _alloc.construct(_data + i, _data[i - n]);
                    _alloc.destroy(_data + i - n);
                }

                for (size_t i = 0; i < n; ++i) {
                    _alloc.construct(_data + index + i, val);
                }

                v_size += n;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
                         typename ft::enable_if<ft::is_integral<InputIterator>::value == false, InputIterator>::type = InputIterator())
            {
                vector backup(*this);

                try {
//                    vector<typename iterator_traits<InputIterator>::value_type> tmp(first, last);
                    size_type n = std::distance(first, last);
                    if (n == 0)
                        return;

                    size_type index = std::distance(begin(), position);
                    if (v_size + n > v_capacity)
                        reserve(v_capacity * 2 > v_size + n ? v_capacity * 2 : v_size + n);

                    for (size_type i = v_size; i > index; --i) {
                        _alloc.construct(_data + i + n - 1, _data[i - 1]);
                        _alloc.destroy(_data + i - 1);
                    }
                    for (size_type i = 0; i < n; ++i) {
                        _alloc.construct(_data + index + i, *first);
                        first++;
                    }
                    v_size+=n;
                } catch (...) {
                    swap(backup);
                    throw;
                }


//                vector back(*this);
//                try{
//                    if (position < begin() || position >= end()) {
//                        throw std::out_of_range("Invalid iterator position");
//                    }
//                if (std::is_same<typename std::iterator_traits<InputIterator>::iterator_category, std::input_iterator_tag>::value)
//                {
//                    for (; first != last; ++first) {
//                        insert(position, *first);
//                        ++position;
//                    }
//                    return ;
//                }
//                    size_type n = std::distance(first, last);
//                    if (v_size + n > v_capacity) {
//                        reserve(v_size + n);
//                    }
//
//                    size_type index = 0;
//                    if (!empty())
//                        index = position - begin();
//
//                    for (size_t i = v_size + n - 1; i > index + n - 1; --i) {
//                        _alloc.construct(_data + i, _data[i - n]);
//                            _alloc.destroy(_data + i - n);
//                    }
//
//
//                for (size_type i = 0; i < n; ++i) {
//                        _alloc.construct(_data + index + i, *(first++));
//                    }
//
//                    v_size += n;;
//                }catch(...){
//                    swap(back);
//                    throw;
//                }
            }

            iterator erase (iterator position)
            {
                return erase (position, position + 1);
            }
            iterator erase (iterator first, iterator last)
            {
                size_type f_index = first - begin();
                size_type distance = last - first;

                for (size_type i = f_index; i + distance < v_size; ++i)
                    _data[i] = _data[i + distance];

                for (size_type i = 0; i < distance; ++i)
                    pop_back();

                return first;
            }

            void swap (vector& x)
            {
                pointer t_data;
                size_type t_c;
                size_type t_s;
                allocator_type t_a;

                t_data = this->_data;
                t_c = this->v_capacity;
                t_s = this->v_size;
                t_a  = this->_alloc;

                this->_data = x._data;
                this->v_capacity = x.v_capacity;
                this->v_size = x.v_size;
                this->_alloc = x._alloc;

                x._data = t_data;
                x.v_capacity = t_c;
                x.v_size = t_s;
                x._alloc = t_a;

            }

            void clear()
            {
                if (v_size > 0)
                {
                    for (size_t i = 0; i < v_size; ++i)
                        _alloc.destroy(_data + i);
                    v_size = 0;
                }
            }


        /* 
        !┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
        !│                       RELATIONAL OPERATORS:                                                                                   │
        !└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/ 
        
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

    template<class T, class Alloc>
    void swap(vector<T, Alloc> &v1,vector<T, Alloc> &v2) { v1.swap(v2); }
}



#endif