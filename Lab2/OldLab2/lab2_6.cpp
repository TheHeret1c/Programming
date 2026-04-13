#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 1234567890;
    char *p;

    p = (char*) &a;

    for (int i = 0; i < sizeof(a); i++) {
        printf("%x ", (unsigned char)*(p + i));
    }

    return 0;
}