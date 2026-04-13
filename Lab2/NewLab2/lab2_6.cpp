#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 1234567890;
    unsigned char *p;

    p = (unsigned char*) &a;

    for (int i = 0; i < sizeof(a); i++) {
        printf("%u ", *(p + i));
    }

    return 0;
}