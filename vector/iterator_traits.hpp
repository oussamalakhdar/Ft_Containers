/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:49:00 by olakhdar          #+#    #+#             */
/*   Updated: 2023/02/03 10:49:01 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>

namespace ft
{
    template <class it>
    struct iterator_traits
    {
        typedef typename it::difference_type    difference_type;
        typedef typename it::value_type         iterator_type;
        typedef typename it::pointer            pointer;
        typedef typename it::reference          reference;
        typedef typename it::iterator_category  iterator_category;
    };

    template<class T>
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               iterator_type;
        typedef T*                               pointer;
        typedef T&                               reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<class T>
    struct iterator_traits<const T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               iterator_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
}

#endif
