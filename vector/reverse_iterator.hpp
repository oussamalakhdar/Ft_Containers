#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "./iterator.hpp"
namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator                                                    iterator_type;
            typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
            typedef typename ft::iterator_traits<Iterator>::reference           reference;
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;

            reverse_iterator(): _current() {};
            explicit reverse_iterator (iterator_type it) : _current(it) {}
            reverse_iterator (const reverse_iterator& rev_it) \
                                : _current(rev_it._current) {}

            Iterator base() const { return _current;}
            reference operator*() const { Iterator tmp = _current; return *(--tmp);}
            pointer operator->() const { return &(operator*()); }
            reverse_iterator& operator++() { --_current; return *this;}
            reverse_iterator  operator++(int) {
                reverse_iterator tmp = *this;
                --_current;
                return tmp;
            }
            reverse_iterator& operator--() { ++_current; return *this;}
            reverse_iterator  operator--(int) {
                reverse_iterator tmp = *this;
                ++_current;
                return tmp;
            }

            reverse_iterator operator+ (difference_type n) const { return reverse_iterator(_current - n); }
            reverse_iterator& operator+= (difference_type n) { _current -= n; return *this; }
            reverse_iterator operator- (difference_type n) const { return reverse_iterator (_current + n); }
            reverse_iterator& operator-= (difference_type n) { _current += n; return *this; }
            reference operator[] (difference_type n) const { _current - (n - 1); }

            template <class Iter1, class Iter2>
            friend bool operator== (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y) {
                return  x._current == y._current;
            }
            template <class Iter1, class Iter2>
            friend bool operator!= (const reverse_iterator<Iter1>& x,
                            const reverse_iterator<Iter2>& y) {
                return  x._current != y._current;
            }
            template <class Iter1, class Iter2>
            friend bool operator<  (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
                return  x._current > y._current;
            }
            template <class Iter1, class Iter2>
            friend bool operator<= (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
                return  x._current >= y._current;
            }
            template <class Iter1, class Iter2>
            friend bool operator>  (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
                return  x._current < y._current;
            }
            template <class Iter1, class Iter2>
            friend bool operator>= (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
                return  x._current <= y._current;
            }

            friend typename reverse_iterator<Iterator>::difference_type operator- (
                    const reverse_iterator<Iterator>& x,
                    const reverse_iterator<Iterator>& y){
                return  y._current - x._current;
                }

            friend reverse_iterator<Iterator> operator+ (
                        typename reverse_iterator<Iterator>::difference_type n,
                    const reverse_iterator<Iterator>& x) {
                return reverse_iterator<Iterator> (x._current - n);
            }




        private:
            Iterator _current;
    };
}

#endif
