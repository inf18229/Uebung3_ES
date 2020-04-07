//
// Created by stefan on 05.04.20.
//
#include <iostream>
#include "PreAllocString.h"
//#include "PreAllocString.cpp" //TODO:Wie lagert man die Template Implementierungen korrekt aus?
int main()
{
    std::cout<<"Manuelle Instanziierung"<<std::endl;
    PreAllocString<20>test;
    test="GutenTag";
    test.AddFormat("%d %s",24,"Hallo Welt");
    std::cout<<test.GetLength()<<std::endl;
    std::cout<<test.SizeOf()<<std::endl;


    std::cout<<"==================="<<std::endl;

    //Test of Makro
    std::cout<<"Makro Test"<<std::endl;
    CREATE(test1234,30)
    test1234.AddFormat("%s %d","Test123jsdfj\n",24);
    std::cout<<test1234.SizeOf()<<std::endl;

}