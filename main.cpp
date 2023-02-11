/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:27:40 by olakhdar          #+#    #+#             */
/*   Updated: 2023/02/10 18:40:54 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "./vector/vector.hpp"



int main()
{
    std::vector<int> first(5,12);
    ft::vector<int> f(5,12);
    std::cout << "Size of first: " << first.size() << ' ' << first.capacity() << '\n';
    std::cout << "Size of first: " << f.size() << ' ' << f.capacity() << '\n';

    first.assign (7,100);             // 7 ints with a value of 100
    f.assign (7,100);             // 7 ints with a value of 100

    std::cout << "Size of first: " << first.size() << ' ' << first.capacity() << '\n';
    std::cout << "Size of first: " << f.size() << ' ' << f.capacity() << '\n';
    return 0;
}