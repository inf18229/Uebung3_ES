#include "catch.hpp"
#include "PreAllocString.h"

TEST_CASE("Normal Tests to write a string")
{
    const unsigned int size=20;
    char buffer[size]="Hallo Welt!";
    CREATE(test,20);

    //Test const char* write
    const char *versuch="Hallo Welt!";
    test+=versuch;
    for(unsigned int i=0; i<test.GetLength();++i)
    {
        REQUIRE(test[i]==buffer[i]);
    }

    //Test char write
    test+='Y';
    char buffer2[size]="Hallo Welt!Y";
    for(unsigned int i=0; i<test.GetLength();++i)
    {
        REQUIRE(test[i]==buffer2[i]);
    }
}
TEST_CASE("Normal Tests to overwrite a string")
{
    const unsigned int size=20;
    char buffer[size]="Test";
    CREATE(test,20);
    const char *versuch="Hallo Welt!";
    test+=versuch;
    const char *versuch2="Test";
    //Check const char* assignment
    test=versuch2;
    for(unsigned int i=0; i<test.GetLength();++i)
    {
        REQUIRE(test[i]==buffer[i]);
    }
    //Check const char assignment
    test='T';
    REQUIRE(test[0]=='T');

}
TEST_CASE("Normal Tests to get a pointer from string")
{
    const unsigned int size=20;
    char buffer[size]="Hallo Welt!";
    CREATE(test,20);
    const char *versuch="Hallo Welt!";
    test+=versuch;
    REQUIRE(*test==buffer[0]);
}
TEST_CASE("Normal Tests to get length of string")
{
    CREATE(test,20);
    const char *versuch="Hallo Welt!";
    test+=versuch;
    REQUIRE(test.GetLength()==11);
}
TEST_CASE("Normal Tests to get size of string")
{
    CREATE(test,20);
    const char *versuch="Hallo Welt!";
    test+=versuch;
    REQUIRE(test.SizeOf()==20);
}
TEST_CASE("Emty String test")
{
    CREATE(test,20);
    const char *versuch="Hallo Welt!";
    test+=versuch;
    test.Empty();
    REQUIRE(test[0]==0);
}
TEST_CASE("Normal Tests to addFormat a string")
{
    const unsigned int size=30;
    char buffer[size]="Hallo Welt!42 0b101010";
    CREATE(test,30);

    //Test const char* write
    const char *versuch="Hallo Welt!";
    test+=versuch;
    test.AddFormat("%d %b",42,42);
    for(unsigned int i=0; i<test.GetLength();++i)
    {
        REQUIRE(test[i]==buffer[i]);
    }

}
TEST_CASE("Normal Tests to addWhitespace a string")
{
    const unsigned int size=30;
    char buffer[size]="Hallo Welt! ";
    CREATE(test,30);

    //Test const char* write
    const char *versuch="Hallo Welt!";
    test+=versuch;
    test.AddWhiteSpace();
    for(unsigned int i=0; i<test.GetLength();++i)
    {
        REQUIRE(test[i]==buffer[i]);
    }

}

TEST_CASE("Assign/Adding a Nullpointer")
{
    const unsigned int size=30;
    char buffer[size]="Hallo Welt!";
    CREATE(test,30);

    //Test const char* write
    const char *versuch="Hallo Welt!";
    const char *versuch2= nullptr;
    test=versuch;
    test= versuch2;
    test+= nullptr;
    for(unsigned int i=0; i<test.GetLength();++i)
    {
        REQUIRE(test[i]==buffer[i]); //nothing should be changed
    }

}