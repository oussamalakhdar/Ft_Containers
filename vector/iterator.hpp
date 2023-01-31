#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
    template <class T>
    class iterator
    {
        public:
            typedef T                               iterator_type;
            typedef T                               *pointer;
            typedef T&                              reference;
            typedef std::ptrdiff_t                  difference_type; //// need ask for it
            typedef std::random_access_iterator_tag iterator_category; //// need ask

            iterator(iterator_type p) : m_ptr(p) {}
            iterator_type base() const {return m_ptr;}

            reference   operator*() const { return *m_ptr; }
            pointer     operator->() const { return m_ptr; }
            iterator&   operator++() { ++(*m_ptr); return *this; }
            iterator    operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
            iterator&   operator--() { --(*m_ptr); return *this; }
            iterator    operator--(int) { iterator tmp = *this; --(*this); return tmp; }
            iterator    operator+(difference_type a) const { iterator tmp = *this; tmp += a; return tmp; }
            iterator&   operator+=(difference_type a) { m_ptr += a; return *this; }
            iterator    operator-(difference_type a) const { return *this + (-a); }
            iterator&   operator-=(difference_type a) { *this += -a; return *this;}
            reference   operator[](difference_type a) const { return m_ptr[a]; }


            friend bool operator==(const iterator &a, const iterator &b) { return a.base() == b.base(); }
            friend bool operator!=(const iterator &a, const iterator &b) { return !(a == b); }
            friend bool operator<(const iterator &a, const iterator &b) { return a.base() < b.base(); }
            friend bool operator>(const iterator &a, const iterator &b) { return b < a; }
            friend bool operator>=(const iterator &a, const iterator &b) { return !(a < b); }
            friend bool operator<=(const iterator &a, const iterator &b) { return !(b < a); }

        private:
            iterator_type *m_ptr;

    };
}
#endif
