#include "mystring.h"

char *mystrcpy(char *dest, const char *src)
{
    char *save = dest;
    while(*src && *src)
    {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return save;
}
