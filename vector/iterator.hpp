#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
    template <class T>
    class iterator
    {
        public:
            typedef T value_type;
            typedef T *pointer;
            typedef T &reference;
            typedef std::ptrdiff_t difference_type; //// need ask for it
            typedef std::random_access_iterator_tag iterator_category; //// need ask

            iterator(pointer p) : m_ptr(p) {}

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


            bool operator==(const iterator &a) { return this->m_ptr == a.m_ptr; }
            bool operator!=(const iterator &a) { return this->m_ptr != a.m_ptr; }

        private:
            value_type *m_ptr;

    };
}
#endif
