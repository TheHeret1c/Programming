#include <stdio.h>

int main() {
    double a, b;
    printf("Enter a number: ");
    scanf("%lf", &a);
    printf("Enter b number: ");
    scanf("%lf", &b);

    printf("Sum a+b = %.2lf", a+b);
    return 0;
}