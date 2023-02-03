/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:27:40 by olakhdar          #+#    #+#             */
/*   Updated: 2023/01/27 17:01:01 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "./vector/vector.hpp"

int main()
{
    ft::vector<int> t(2, 6);
    std::vector <int> a(2,1);
//    std::vector<int>::iterator b = a.begin();
//    for (auto i = b; i < a.end(); ++i)
//        std::cout << *i << std::endl;
////    std::cout << t[4] << std::endl;
    const int &i = t.at(1);
//    int &i = a.at(6);

    std::cout << i << std::endl;

//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(3);
//    a.push_back(4);
//    a.push_back(5);
//    a.push_back(6);
//    a.push_back(7);
//    a.push_back(8);
//    std::vector <int>::iterator b = a.begin();
//    std::cout << *b[2] << std::endl;
}