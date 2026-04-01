#include "mystring.h"

void *mymemset(void *ptr, int x, size_t n)
{
    unsigned char *p = (unsigned char*)ptr;

    while(n--)
    {
        *p = (unsigned char)x;
        p++;
    }

    return ptr;

}