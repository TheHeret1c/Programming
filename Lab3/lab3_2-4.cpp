#include <stdio.h>
#include <stdlib.h>

typedef enum DataType {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
} DataType;

typedef union Value {
    int i;
    float f;
    char c;
} Value;

typedef struct TaggedUnion {
    DataType type;
    Value data; 
} TaggedUnion;

int main() {
    int size = 3;
    
    TaggedUnion* array = (TaggedUnion*)malloc(size * sizeof(TaggedUnion));
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        return 1;
    }

    array[0].type = TYPE_INT;
    array[0].data.i = 1024;

    array[1].type = TYPE_FLOAT;
    array[1].data.f = 3.1415f;

    array[2].type = TYPE_CHAR;
    array[2].data.c = 'Z';

    printf("--- Tagged Union Array Output ---\n");
    for (int i = 0; i < size; i++) {
        printf("Element [%d] - ", i);
        
        switch (array[i].type) {
            case TYPE_INT:
                printf("Type: INT, Value: %d\n", array[i].data.i);
                break;
            case TYPE_FLOAT:
                printf("Type: FLOAT, Value: %.4f\n", array[i].data.f);
                break;
            case TYPE_CHAR:
                printf("Type: CHAR, Value: %c\n", array[i].data.c);
                break;
        }
    }

    free(array);

    return 0;
}