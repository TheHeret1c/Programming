#include <stdio.h>

typedef union Data {
    int i;
    float f;
    char c;
} Data;

int main() {
    Data var;             
    Data* ptr = &var;

    ptr->i = 42;
    printf("--- Integer stored ---\n");
    printf("ptr->i: %d\n", ptr->i);
    
    ptr->f = 3.14f;
    printf("\n--- Float stored ---\n");
    printf("ptr->f: %.2f\n", ptr->f);

    ptr->c = 'G';
    printf("\n--- Char stored ---\n");
    printf("ptr->c: %c\n", ptr->c);

    printf("\n--- Memory info ---\n");
    printf("Size of union: %zu bytes\n", sizeof(Data));

    return 0;
}