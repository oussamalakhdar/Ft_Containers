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
#include "./vector/is_integral.hpp"


int main()
{
    std::vector<int> myvector;

    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    std::cout << "myvector contains:";
    for (int i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

//    ft::vector<int> foo (10, 6) ;   // three ints with a value of 100
//    std::vector<int> bar (10, 6);   // five ints with a value of 200
//    c
//    std::cout << bar.capacity() <<  ' ' << bar.size()  << ' ' << bar[5]<< std::endl;
//    std::cout << '\n';
////    foo.resize(5);
////    bar.resize(5);
//    std::cout << foo.capacity() <<  ' ' << foo.size()  << ' ' << foo[5] << std::endl;
//    std::cout << bar.capacity() <<  ' ' << bar.size() << ' ' << bar[5] << std::endl;
//    std::cout << "foo contains:";
//    for (unsigned i=0; i<foo.size(); i++)
//        std::cout << ' ' << foo[i];
//    std::cout << '\n';
//
//    std::cout << "bar contains:";
//    for (unsigned i=0; i<bar.size(); i++)
//        std::cout << ' ' << bar[i];
//    std::cout << '\n';

    system("leaks a.out");
    return 0;
//    ft::vector<int> t;
//    std::vector <int> a;

//    std::cout << "capa : " << t.capacity() << " and size " << t.size() << std::endl;
//    std::cout << "*capa : " << a.capacity() << " and size " << a.size() << std::endl <<  std::endl;
//    t.push_back(6);
//    a.push_back(6);
////    t.reserve(15);
////    a.reserve(15);
//    std::cout << "capa : " << t.capacity() << " and size " << t.size() << std::endl;
//    std::cout << "*capa : " << a.capacity() << " and size " << a.size() << std::endl;
//    std::cout << "ola : " << a[0] <<  std::endl <<  std::endl;
//    t.pop_back();
//    a.pop_back();
//    std::cout << "capa : " << t.capacity() << " and size " << t.size() << std::endl;
//    std::cout << "*capa : " << a.capacity() << " and size " << a.size() << std::endl;
//    std::cout << "ola : " << t[0] <<  std::endl;

//    std::vector<int>::iterator b = a.begin();
//    for (auto i = b; i < a.end(); ++i)
//        std::cout << *i << std::endl;
////    std::cout << t[4] << std::endl;
//    const int &i = t.at(1);
//    int &i = a.at(6);

}