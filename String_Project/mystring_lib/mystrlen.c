#include "mystring.h"

size_t mystrlen(const char *str)
{
    const char *start = str;

    while(*str)
    {
        str++;
    }

    return str - start;
}
