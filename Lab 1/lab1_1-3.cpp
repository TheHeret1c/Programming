#include <stdio.h>
#include <math.h>

double fun(double x, double y) {
    double sum = x + y;
    double sin_xy = sin(sum);
    // Числитель
    double numerator = 1 + sin_xy * sin_xy; // Можно использовать pow, но при квадрате не имеет смысла
    // Знаменатель
    double denominator = 2 + fabs(x - (2 * x * x) / (1 + fabs(sin_xy)));

    double res = numerator / denominator;
    return res;
}

int main() {
    double x, y;

    printf("Enter x number: ");
    scanf("%lf", &x);
    printf("Enter y number: ");
    scanf("%lf", &y);

    printf("Result = %lf", fun(x, y));
    return 0;
}