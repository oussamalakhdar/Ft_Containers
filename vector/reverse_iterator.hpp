#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "./iterator.hpp"
namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator                                                    value_type;
            typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
            typedef typename ft::iterator_traits<Iterator>::reference           reference;
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;

            reverse_iterator(): _current() {};
            explicit reverse_iterator (value_type it) : _current(it) {}
            template <class _Up>
            reverse_iterator (const reverse_iterator<_Up>& rev_it) \
                                : _current(rev_it.base()) {}
            template <class _Up> reverse_iterator& operator=(const reverse_iterator<_Up>& __u)
                                { _current = __u.base(); return *this; }
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
            reference operator[] (difference_type n) const { return *(*this + n); }

        protected:
           Iterator _current;
    };
           template <class Iter1, class Iter2>
           bool operator== (const reverse_iterator<Iter1>& x,
                            const reverse_iterator<Iter2>& y) {
               return  x.base() == y.base();
           }
           template <class Iter1, class Iter2>
           bool operator!= (const reverse_iterator<Iter1>& x,
                            const reverse_iterator<Iter2>& y) {
               return  x.base() != y.base();
           }
           template <class Iter1, class Iter2>
           bool operator<  (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
               return  x.base() > y.base();
           }
           template <class Iter1, class Iter2>
           bool operator<= (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
                return  x.base() >= y.base();
           }
           template <class Iter1, class Iter2>
           bool operator>  (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
               return  x.base() < y.base();
           }
           template <class Iter1, class Iter2>
           bool operator>= (const reverse_iterator<Iter1>& x,
                             const reverse_iterator<Iter2>& y){
               return  x.base() <= y.base();
           }
           template <class Iter1, class Iter2>
           typename reverse_iterator<Iter1>::difference_type operator- (
                   const reverse_iterator<Iter1>& x,
                   const reverse_iterator<Iter2>& y){
               return  y.base() - x.base();
           }
           template <class Iter>
           reverse_iterator<Iter> operator+ (
                            typename reverse_iterator<Iter>::difference_type n,
                            const reverse_iterator<Iter>& x) {
               return reverse_iterator<Iter> (x.base() - n);
           }
}

#endif
