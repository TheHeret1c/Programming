#include <stdio.h>
#include <math.h>

double fun(double x, double a, double b, double c) {
    double left = -((x - a) / (cbrt(x * x + a * a)));
    double right = (4 * sqrt(sqrt(pow((x * x + b * b), 3)))) / (2 + a + b + cbrt(pow(x - c, 2)));
    double res = left - right;
    return res;
}

int main() {
    printf("Result 1 = %lf\n", fun(1.4, 0.12, 3.5, 2.4));
    printf("Result 2 = %lf\n", fun(1.6, 0.12, 3.5, 2.4));
    printf("Result 3 = %lf", fun(1.8, 0.27, 3.9, 2.8));
    return 0;
}