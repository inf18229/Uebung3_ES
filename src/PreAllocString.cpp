//
// Created by stefan on 05.04.20.
//

#include "../include/PreAllocString.h"
#include <iostream>
#include <stdarg.h>
#include <stdio.h>

PreAllocString::PreAllocString(char *varName, unsigned int size):
m_stringName{varName}, m_size{size}
{
    m_realString=new char[size];
    std::cout<<&m_realString<<std::endl;
}

PreAllocString::operator const char *() const {
    char * begin=&m_realString[0];
    return begin;
}

PreAllocString::operator const void *() const {
    void * void_ptr= static_cast<void *>(m_realString); //TODO:Was macht das Void hier? Castet man einfach nur den Pointer auf den String als Void pointer oder was soll hier passieren
    return void_ptr;
}

const char &PreAllocString::operator[](const int idx) {
    if(static_cast<int>(idx)>m_index||idx<0)
    {
        return m_realString[m_size-1];
    }
    else
    {
        return m_realString[idx];
    }

}

std::size_t PreAllocString::GetLength() const {

    return m_index;
}

constexpr size_t PreAllocString::SizeOf() {
    return m_size;
}

void PreAllocString::Empty() {
m_realString={0};
}

char *PreAllocString::getMStringName() const {
    return m_stringName;
}

unsigned int PreAllocString::getMSize() const {
    return m_size;
}

PreAllocString &PreAllocString::operator=(char rhs) {
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

PreAllocString &PreAllocString::operator=(const char *rhs) {
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

PreAllocString &PreAllocString::operator=(char *const rhs) {
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

PreAllocString &PreAllocString::operator+=(char rhs) {
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

PreAllocString &PreAllocString::operator+=(char const *rhs) {
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

void PreAllocString::AddFormat(const char *format, ...) {
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

void PreAllocString::AddWhiteSpace() {
if(m_index< static_cast<int>(m_size))
{
    m_realString[m_index]=' ';
    ++m_index;
}
}
