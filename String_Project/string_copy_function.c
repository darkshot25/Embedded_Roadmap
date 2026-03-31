#include <stdio.h>
#include <string.h>

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

int main()
{
    char src[10] = "STRING";
    char dest[50];
    mystrcpy(dest , src);
    printf("%s", dest);

    return 0;
}