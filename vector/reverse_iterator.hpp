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
            template<class U>
            reverse_iterator (const reverse_iterator<U>& rev_it) \
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
            reverse_iterator& operator--() { ++_current; return *this}
            reverse_iterator  operator--(int) {
                reverse_iterator tmp = *this;
                ++_current;
                return tmp;
            }



        private:
            Iterator _current;
    };
}

#endif
