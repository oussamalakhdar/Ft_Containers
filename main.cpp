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
    std::vector<int> f;
    ft::vector<int> fpp;
    for (int i = 0; i < 10; ++i)
        fpp.push_back(i);

    for (int i = 0; i < 10; ++i)
        f.push_back(i);

    std::cout << fpp.capacity() << ' ' << fpp.size() << std::endl  ;
    std::cout << f.capacity() << ' ' << f.size() << std::endl  ;

    auto ipp = fpp.begin();
    auto it = f.begin();

    fpp.insert(ipp + 4, 2, 7);
    f.insert( it+ 4, 2, 7);

    for (int i = 0; i < fpp.size(); ++i)
        std::cout << fpp[i] << ' ' ;
    std::cout <<  std::endl;
    for (int i = 0; i < f.size(); ++i)
        std::cout << f[i] << ' ' ;

    std::cout <<std::endl << fpp.capacity() << ' ' << fpp.size() << std::endl  ;
    std::cout<< std::endl   << f.capacity() << ' ' << f.size() << std::endl  ;
}