#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
    char name[10];
} vector;

void printVector(vector a) {
    printf("%.2f, %.2f, %.2f\n", a.x, a.y, a.z);
}

double scalarProduct(vector a, vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector vectorProduct(vector a, vector b) {
    vector c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = -(a.x * b.z - a.z * b.x);
    c.z = a.x * b.y - a.y * b.x;

    return c;
}

double vectorLength(vector a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

int main(void) {
    vector a = {10.0, 1.0, 11.0, "A"};
    vector b = {-5.0, 5.0, -2.0, "B"};

    printf("Scalar product %s * %s: %.2f\n", a.name, b.name, scalarProduct(a, b));
    printf("Vector product %s * %s: ", a.name, b.name);
    printVector(vectorProduct(a, b));
    printf("Length %s: %.2f\nLength %s: %.2f\n", a.name, vectorLength(a), b.name, vectorLength(b));
    printf("Vector %s: ", a.name);
    printVector(a);
    printf("Vector %s: ", b.name);
    printVector(b);
    return 0;
}