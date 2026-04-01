#include "mystring.h"

char *mystrchr(const char *str, int ch)
{
    unsigned char search = (unsigned char)ch;

    while(*str != search && *str)
    {
        str++;
    }

    if(*str == search){
        return (char*) str;
    }

    return NULL;
}