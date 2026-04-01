#include <stdio.h>
#include "mystring.h" // Include your custom library's header

int main() {
    char src[] = "FIRMWARE";
    char dest[50];
    
    // Test Initialization
    mymemset(dest, 0, 50); 
    
    // Test Copy
    mystrcpy(dest, src);
    
    // Test Measurement
    size_t len = mystrlen(dest);
    
    // Test Search
    char *found = mystrchr(dest, 'W');
    
    printf("Copied String: %s\n", dest);
    printf("Length: %zu\n", len);
    if (found) {
        printf("Found character 'W' at address: %p\n", (void*)found);
    }

    return 0;
}