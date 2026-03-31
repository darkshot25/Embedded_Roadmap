#include <stdio.h>
#include <string.h>

size_t mystrlen(const char *str)
{
    const char *start = str;

    while(*str)
    {
        str++;
    }

    return str - start;
}

int main()
{
    char str[10] = "FYP";
    printf("%zu\n", mystrlen(str));
    return 0;
}