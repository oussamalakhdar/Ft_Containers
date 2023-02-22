/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:41:52 by olakhdar          #+#    #+#             */
/*   Updated: 2023/02/06 10:41:53 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
    template <class T> struct true_type { static const bool value = true; };
    template <class T> struct false_type { static const bool value = false; };

    template<class T> struct is_integral : false_type<T> {};
    template <class T> struct is_integral<const T> : public is_integral<T> {};
    template <class T> struct is_integral<volatile const T> : public is_integral<T>{};
    template <class T> struct is_integral<volatile T> : public is_integral<T>{};

    template<> struct is_integral<bool> : true_type<bool> {};
    template<> struct is_integral<char> : true_type<char> {};
    template<> struct is_integral<char16_t> : true_type<char16_t> {};
    template<> struct is_integral<char32_t> : true_type<char32_t> {};
    template<> struct is_integral<wchar_t> : true_type<wchar_t> {};
    template<> struct is_integral<signed char> : true_type<signed char> {};
    template<> struct is_integral<short int> : true_type<short int> {};
    template<> struct is_integral<int> : true_type<int> {};
    template<> struct is_integral<long int> : true_type<long int> {};
    template<> struct is_integral<long long int> : true_type<long long int> {};
    template<> struct is_integral<unsigned char> : true_type<unsigned char> {};
    template<> struct is_integral<unsigned short int> : true_type<unsigned short int> {};
    template<> struct is_integral<unsigned int> : true_type<unsigned int> {};
    template<> struct is_integral<unsigned long int> : true_type<unsigned long int> {};
    template<> struct is_integral<unsigned long long int> : true_type<unsigned long long int> {};

    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
}

#endif
