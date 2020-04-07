//
// Created by stefan on 05.04.20.
//
#include <stdarg.h>
#include <stdio.h>
#include "Printf.h"
#include <iostream>
#define CREATE( varName , size ) PreAllocString<size>varName;
#ifndef UEBUNG3_PREALLOCSTRING_H
#define UEBUNG3_PREALLOCSTRING_H

template <int SIZE>
class PreAllocString {
public: PreAllocString();
        operator const char *() const ;
        operator const void *() const ;
        const char & operator [] ( const int idx ) ;

        std::size_t GetLength () const ;
        constexpr size_t SizeOf () ;

        void Empty () ;

        PreAllocString& operator=(char rhs);
        PreAllocString& operator=(const char *rhs);
        PreAllocString& operator=(char * const rhs);

        PreAllocString& operator+=(char rhs);
        PreAllocString& operator+=(char const * rhs);

        void AddFormat( const char * format , ... ) ;

        void AddWhiteSpace () ;



private:
    unsigned int m_size=SIZE;
    unsigned int m_index=0;
    char m_realString[SIZE]={0};
};


//Implementierung



template<int SIZE>
PreAllocString<SIZE>::PreAllocString():
        m_size{SIZE}
{
}
template<int SIZE>
PreAllocString<SIZE>::operator const char *() const {
    const char * begin=m_realString;
    return begin;
}
template<int SIZE>
PreAllocString<SIZE>::operator const void *() const {
    void * void_ptr= static_cast<void *>(m_realString); //TODO:Was macht das Void hier? Castet man einfach nur den Pointer auf den String als Void pointer oder was soll hier passieren
    return void_ptr;
}
template<int SIZE>
const char &PreAllocString<SIZE>::operator[](const int idx) {
    if(static_cast<unsigned int>(idx)>m_index||idx<0)
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
    m_index=0;
    m_realString[0]={0}; //initialize with 0
}


template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator=(char rhs) {
    if(m_index< m_size)
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
    if(rhs!= nullptr)
    {
        char*tmp= const_cast<char*>(rhs);
        //array should be clear its saver! //TODO: CLEAR ARRAY with function
        Empty();
        while (*tmp!=0)
        {
            if(m_index< m_size) {
                m_realString[m_index] = *tmp;
                ++tmp;
                ++m_index;
        }
    }

    return *this;
    }
    else
    {
        return *this; //on nullptr do nothing
    }
}
template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator=(char *const rhs) {
    if(rhs!= nullptr)
    {
        char*tmp= static_cast<char*>(rhs);
        Empty();
        while (*tmp!=0)
        {
            if(m_index< m_size) {
                m_realString[m_index] = *rhs;
                ++tmp;
                ++m_index;
        }
    }

    return *this;
    }
    else
    {
        return *this; //on nullptr do nothing
    }
}
template<int SIZE>
PreAllocString<SIZE> &PreAllocString<SIZE>::operator+=(char rhs) {
    if(m_index< m_size)
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
    if(rhs!= nullptr)
    {
        char*tmp= const_cast<char*>(rhs);
        while (*tmp!=0)
        {
            if(m_index< m_size) {
                m_realString[m_index] = *tmp;
                ++tmp;
                ++m_index;
            }
        }
    }
    else
    {
        return *this;
    }


    return *this;
}
template<int SIZE>
void PreAllocString<SIZE>::AddFormat(const char *format, ...) {
    //TODO:Muss der Formatstring angehängt werden oder überschreibt dieser den aktuellen String?
    if(format!= nullptr)
    {
        char * lastchar=nullptr;
        va_list arg;
        va_start(arg,format);
        lastchar=Printf (&m_realString[m_index], &m_realString[m_size-1], format, arg);
        if(*lastchar!='\0')
        {
            return;
        }
        va_end(arg);
    }
    //else do nothing

}
template<int SIZE>
void PreAllocString<SIZE>::AddWhiteSpace() {
    if(m_index< m_size)
    {
        m_realString[m_index]=' ';
        ++m_index;
    }
}


#endif //UEBUNG3_PREALLOCSTRING_H
