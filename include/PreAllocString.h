//
// Created by stefan on 05.04.20.
//
#include <iostream>
#define CREATE( varName , size ) (new PreAllocString(varName,size))
#ifndef UEBUNG3_PREALLOCSTRING_H
#define UEBUNG3_PREALLOCSTRING_H



class PreAllocString {
public: PreAllocString(char* varName, unsigned int size);
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
        char *getMStringName() const;

        unsigned int getMSize() const;

private:
    char* m_stringName;
    const unsigned int m_size;
    int m_index=0;
    char* m_realString={0};
};


#endif //UEBUNG3_PREALLOCSTRING_H
