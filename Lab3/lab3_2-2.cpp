#include <stdio.h>

typedef union BytePrinter {
    unsigned long long value;
    unsigned char bytes[sizeof(unsigned long long)]; 
} BytePrinter;

int main() {
    BytePrinter data;
    
    data.value = 0x1122334455667788ULL;

    printf("Full value (HEX): 0x%llx\n", data.value);
    printf("Size of unsigned long long: %zu bytes\n\n", sizeof(unsigned long long));

    printf("--- Byte-by-byte printing ---\n");
    for (size_t i = 0; i < sizeof(unsigned long long); i++) {
        printf("Byte %zu: 0x%02x\n", i, data.bytes[i]);
    }

    return 0;
}