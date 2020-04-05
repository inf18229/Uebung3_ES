//
// Created by stefan on 05.04.20.
//
#include <iostream>
#include "../include/PreAllocString.h"
int main()
{
    const char*versuch="Hallo Welt";
    const char*name= "Test";
    PreAllocString *test_string=CREATE(const_cast<char*>(name),12);
    *test_string='F';
    test_string->AddFormat("%d Hallo guten Tag",13);
    std::cout<<**test_string<<std::endl;
    PreAllocString test(const_cast<char*>(name),30);
    test='T';
    test=versuch;
    std::cout<<test.GetLength()<<std::endl;
    std::cout<<*test<<std::endl;
    test.AddFormat("%s\n%d","Hallo Welt",123456);
    test.AddWhiteSpace();
    test+='E';
}