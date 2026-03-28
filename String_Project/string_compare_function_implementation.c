#include <string.h>

//this is the standard implementation of strcmp from musl libc
int strcmp(const char *l, const char *r)
{
	for (; *l==*r && *l; l++, r++);
	return *(unsigned char *)l - *(unsigned char *)r;
}

//this is the implementation of strcmp using while loop
int my_strcmp(const char *l, const char *r)
{
	while(*l==*r && *l)
	{
		l++;
		r++;
	}

	return *(unsigned char *)l - *(unsigned char *)r;
}

//while both function will produce same assembly code
//the while loop form can increase readability
//the for loop code have advantage due to lower number of line
//in complex code base, readability should be prioritise
//Both of the code is implemented according to Barr C standard