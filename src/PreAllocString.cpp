/*

//
// Created by stefan on 05.04.20.
//

#include "../include/PreAllocString.h"
#include <iostream>
#include <stdarg.h>
#include <stdio.h>
template<int SIZE>
PreAllocString<SIZE>::PreAllocString():
m_size{SIZE}
{
    std::cout<<&m_realString<<std::endl;
}
template<int SIZE>
PreAllocString<SIZE>::operator const char *() const {
    char * begin=&m_realString[0];
    return begin;
}
template<int SIZE>
PreAllocString<SIZE>::operator const void *() const {
    void * void_ptr= static_cast<void *>(m_realString); //TODO:Was macht das Void hier? Castet man einfach nur den Pointer auf den String als Void pointer oder was soll hier passieren
    return void_ptr;
}
template<int SIZE>
const char &PreAllocString<SIZE>::operator[](const int idx) {
    if(static_cast<int>(idx)>m_index||idx<0)
    {
        return m_realString[0]; //String an der Stelle [0] wird ausgegeben
    }
    else
    {
        return m_realString[idx];
    }

}
template<int SIZE>
std::size_t PreAllocString<SIZE>::GetLength() const {

    return m_index;
}
template<int SIZE>
constexpr size_t PreAllocString<SIZE>::SizeOf() {
    return SIZE;
}
template<int SIZE>
void PreAllocString<SIZE>::Empty() {
m_realString={0};
}

template<int SIZE>
unsigned int PreAllocString<SIZE>::getMSize() const {
    return m_size;
}
template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator=(char rhs) {
    if(m_index< static_cast<int>(m_size))
    {
        m_realString[m_index]=rhs;
        ++m_index;
        return *this;

    }
    else
    {
        return *this;
    }

}
template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator=(const char *rhs) {
    char*tmp= const_cast<char*>(rhs);
    m_index=0;//array should be clear its saver! //TODO: CLEAR ARRAY with function
    while (*tmp!=0)
    {
        if(m_index< static_cast<int>(m_size)) {
            m_realString[m_index] = *tmp;
            ++tmp;
            ++m_index;
        }
    }

    return *this;
}
template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator=(char *const rhs) {
    char*tmp= static_cast<char*>(rhs);
    m_index=0; //array should be clear its saver! //TODO: CLEAR ARRAY with function
    while (*tmp!=0)
    {
        if(m_index< static_cast<int>(m_size)) {
            m_realString[m_index] = *rhs;
            ++tmp;
            ++m_index;
        }
    }

    return *this;
}
template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator+=(char rhs) {
    if(m_index< static_cast<int>(m_size))
    {
        m_realString[m_index]=rhs;
        ++m_index;
        return *this;

    }
    else
    {
        return *this;
    }
}
template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator+=(char const *rhs) {
    char*tmp= const_cast<char*>(rhs);
    while (*tmp!=0)
    {
        if(m_index< static_cast<int>(m_size)) {
            m_realString[m_index] = *tmp;
            ++tmp;
            ++m_index;
        }
    }

    return *this;
}
template<int SIZE>
void PreAllocString<SIZE>::AddFormat(const char *format, ...) {
    //TODO:Muss der Formatstring angehängt werden oder überschreibt dieser den aktuellen String?
    char buffer[m_size];
    int i=0;
    va_list arg;
    va_start(arg,format);
    vsnprintf (buffer, m_size, format, arg);
    va_end(arg);
    while(buffer[i]!='\0')
    {
        if(m_index< static_cast<int>(m_size)) {
            m_realString[m_index] = buffer[i];
            ++i;
            ++m_index;
        }
    }
    std::cout<<m_realString<<std::endl;
}
template<int SIZE>
void PreAllocString<SIZE>::AddWhiteSpace() {
if(m_index< static_cast<int>(m_size))
{
    m_realString[m_index]=' ';
    ++m_index;
}
}
*/
