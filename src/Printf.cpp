#include "Printf.h"
#include <stdio.h>
#include <stdarg.h>

//char *inttobin(unsigned int Zahl);
static char* u_int_printbinary(int x,char* buffer);
static char* s_int_printbinary(int x, char* buffer);
static void endroutine(char* buffer);

char * Printf ( char * dst , const void * end , const char * fmt , va_list arg)
{
    if(dst==nullptr||end==nullptr||fmt==nullptr||dst>end)
    {
      return nullptr;
    }
    const char * current; //For better readability declaration of the current value of fmt
    const char * next;  //For better readability declaration of the next value of fmt

    int counter=0;  //counter for moving the pointer dst back to start so that the return is the start pointer of dst. Because we iterating over the buffer

    //va_list args=arg; //declarate argument list
    //va_start(args,fmt); //initialize the start of the argument list
    while(*fmt != '\0') //we iterating throug fmt as long we dont get the null termination of the char
    {
        current = fmt;  //initialisation of the current value
        if(*fmt+1 != '\0')
        {
            next = fmt+1; //we only initialize next if it is not a null termination
        }

        if(*current=='%' && *next=='d') //make somthing if we read %d from fmt
        {

            int d = va_arg(arg,int); //read the next argument as integer
            char c[32]={0}; //Just lets you add any number with 50 parts
            int i=0;
            sprintf(c,"%d",d); //needed to convert any integer into an character!!!

            while(c[i]!='\0' && i<32)
            {
                if((dst) != end)
                {
                    *dst=c[i];
                    ++i;
                    ++dst;
                    ++counter;
                }
                else
                {
                    endroutine(dst);
                    return dst-=counter;
                }
            }
            ++fmt;//only that else routine will not catch the next %

        }
        else if(*current=='%' && *next=='u') //make somthing if we read %d from fmt
        {

            unsigned int u = va_arg(arg,unsigned int); //read the next argument as integer
            char c[50]={0}; //Just lets you add any number with 50 parts
            int i=0;
            sprintf(c,"%u",u); //needed to convert any integer into an character!!!


            while(c[i]!='\0' && i<50)
            {
                if((dst) != end)
                {
                    *dst=c[i];
                    ++i;
                    ++dst;
                    ++counter;
                }
                else
                {
                    endroutine(dst);
                    return dst;
                }
            }
              ++fmt;//only that else routine will not catch the next %

        }
        else if(*current=='%' && *next=='c')
        {
            char c=va_arg(arg,int);
            if((dst) != end)
            {
                *dst=c;
                ++dst;
                ++counter;
            }
            else
            {
                endroutine(dst);
                return dst;
            }
            ++fmt;
        }
        else if(*current=='%' && *next=='s')
        {
            char * s=va_arg(arg,char*);
            while(*s!='\0')
            {
                if((dst) != end)
                {
                    *dst=*s;
                    ++dst;
                    ++counter;
                }
                else
                {
                    endroutine(dst);
                    return dst;

                }
                s++;
            }

              ++fmt;//only that else routine will not catch the next %
        }
        else if(*current=='%' && *next=='x')
        {
            int x =va_arg(arg,int);
            char c[50]={0}; //TODO könnte noch auf max int definiert werden
            int length=0;
            int i=0;
            sprintf(c,"0x%X",x);

            //calculate true length
            while(c[length]!='\0'&& i<50)
            {
              ++length;
            }
            ++length;
            //TODO hier das while könnte man in eine funktion auslagern!!! wäre sinnvoller
            while(c[i]!='\0' && i<50)
            {
                if((dst) != end)
                {
                    *dst=c[i];
                    ++i;
                    ++dst;
                    ++counter;
                }
                else
                {
                    endroutine(dst);
                    return dst;
                }
            }
          ++fmt;//only that else routine will not catch the next %

        }
        else if(*current=='%' && *next=='b')
        {

          char c[32]={0};
          char*test=nullptr;
          int b =va_arg(arg,int);
          if(b<0)
          {
            test=s_int_printbinary(b,c);
          }
          else
          {
            test=u_int_printbinary(b,c);
          }
          if(test==nullptr)
          {
            return nullptr;
          }
          int i=0;
          *dst='0';
          ++dst;

          *dst='b';
          ++dst;

          counter+=2;

          while(c[i]!='\0' && i<32)
          {
              if((dst) != end)
              {
                  *dst=c[i];
                  ++i;
                  ++dst;
                  ++counter;
              }
              else
              {
                  endroutine(dst);
                  return dst;
              }
          }
          ++fmt;//only that else routine will not catch the next %
        }
        else if(*current=='%' && *next=='%')
        {
          if((dst) != end)
          {
              *dst='%';
              ++dst;

              ++counter;
          }
          else
          {
              endroutine(dst);

              return dst;
          }
          ++fmt;//only that else routine will not catch the next %
        }
        else
        {
          if((dst) != end)
          {
              *dst=*current;
              ++dst;
              ++counter;
          }
          else
          {
              endroutine(dst);
              return dst;
          }
        }
        ++fmt;

    }
    va_end(arg);
    return dst;
}
//for conversion of singed positiv int's with b-Complement
static char* s_int_printbinary(int x, char* buffer)
{
  char str[33]; str[32] = '\0';
  int i = 32;
  while(i){i--; str[i] = (x & 1) + '0'; x>>=1;}
  sprintf(buffer,"%s\n", str);
  return buffer;
}
//for conversion of unsinged positiv int's
static char *u_int_printbinary(int Zahl,char*buffer)
{
	static char BinStr[32]={0};
    int counter=0;
  int bin;
  int zwischenergebnis=Zahl;

  while (zwischenergebnis!=0)
  {
    bin=zwischenergebnis%2;
    if(bin==1)
    {
        BinStr[counter]='1';

    }
    else
    {
      BinStr[counter]='0';
    }
    zwischenergebnis=zwischenergebnis/2;
    ++counter;
  }
  while(counter>0)
  {
      *buffer=BinStr[counter-1];
      ++buffer;
      --counter;
  }
  return buffer;

}

//Endroutine only for giving some hint that the string you want to format is too long for the buffer
static void endroutine(char* buffer)
{
  buffer-=3;
  *buffer='.';
  ++buffer;
  *buffer='.';
  ++buffer;
  *buffer='.';
  ++buffer;
  *buffer='\0';
}
