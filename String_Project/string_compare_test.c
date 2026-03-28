#include<stdio.h>
#include<string.h>

//This code is used to to test strcmp function from string.h lib
//strcmp is used to compare two string
//it will return 0 if both strings are equal
//it will return >0 if the 1st non matching char have higher ascii value in s1 than s2
//it will return <0 if the 1st non matching char have lower ascii value in s1 than s2
//the specific value that it will return in the case of mismatch char is compiler dependence and not specified

int main(){

    char s1[] = "Mixue";
    char s2[] = "mixue";

    if(strcmp(s1 , s2) == 0)
    {
        printf("S1 Equal S2\n");
    }
    else if(strcmp(s1 , s2) > 0)
    {
        printf("s1 Higher Than s2\n");
    }
    else if(strcmp(s1 , s2) < 0)
    {
        printf("s1 Lower Than s2\n");
    }
}