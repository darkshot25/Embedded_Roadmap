// These are called "Include Guards". They prevent the compiler from 
// accidentally reading this file twice and throwing an error.
#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>

// Function Prototypes
int mystrcmp(const char *l, const char *r);
char *mystrcpy(char *dest, const char *src);
size_t mystrlen(const char *str);
void *mymemset(void *ptr, int x, size_t n);
char *mystrchr(const char *str, int ch);

#endif


