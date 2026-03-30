#include <stdio.h>
#include <math.h>

double fun(double x) {
    return exp(x + 2);
}

double trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.5 * (fun(a) + fun(b));

    for (double i = a + h; i < b; i += h) {
        integral += fun(i);
    }

    integral *= h;
    return integral;
}

int main() {
    double a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of splits (n): ");
    scanf("%d", &n);

    double trapezoid_res = trapezoid(a, b, n);
    
    printf("The approximate value of the integral by the trapezoid method from %.2f to %.2f: %.6f\n", a, b, trapezoid_res);
    return 0;
}