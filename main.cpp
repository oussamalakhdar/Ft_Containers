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

    ft::vector<int> t(20);
    std::vector <int> a(20);
    std::cout << "capa : " << t.capacity() << " and size " << t.size() << std::endl;
    std::cout << "capa : " << a.capacity() << " and size " << a.size() << std::endl;
    t.push_back(6);
    a.push_back(6);
//    t.reserve(15);
//    a.reserve(15);
    std::cout << "capa : " << t.capacity() << " and size " << t.size() << std::endl;
    std::cout << "capa : " << a.capacity() << " and size " << a.size() << std::endl;
//    std::vector<int>::iterator b = a.begin();
//    for (auto i = b; i < a.end(); ++i)
//        std::cout << *i << std::endl;
////    std::cout << t[4] << std::endl;
//    const int &i = t.at(1);
//    int &i = a.at(6);

//    std::cout << t.reserve(15) << std::endl;
//    std::cout << a.reserve(15) << std::endl;


//    std::vector <int>::iterator b = a.begin();
//    std::cout << *b[2] << std::endl;
//    system("leaks a.out");
}