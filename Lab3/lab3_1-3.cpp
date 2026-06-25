#include <stdio.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} complex;

// Сложение комплексных чисел
complex complex_add(complex a, complex b) {
    complex res;
    res.re = a.re + b.re;
    res.im = a.im + b.im;
    return res;
}

// Умножение комплексных чисел
complex complex_mul(complex a, complex b) {
    complex res;
    res.re = a.re * b.re - a.im * b.im;
    res.im = a.re * b.im + a.im * b.re;
    return res;
}

// Деление комплексного числа на вещественный скаляр
complex complex_div_scalar(complex a, double n) {
    complex res;
    res.re = a.re / n;
    res.im = a.im / n;
    return res;
}

// Модуль комплексного числа
double complex_abs(complex a) {
    return sqrt(a.re * a.re + a.im * a.im);
}

// Вычисление экспоненты комплексного числа через ряд Тейлора
complex complex_exp(complex z) {
    const double eps = 1e-12;   // точность
    const int max_iter = 100;   // защита от бесконечного цикла

    complex sum = {1.0, 0.0};   // начальная сумма = 1
    complex term = {1.0, 0.0};  // текущий член ряда (начинается с 1)

    for (int n = 1; n <= max_iter; ++n) {
        // term = term * z / n
        term = complex_mul(term, z);
        term = complex_div_scalar(term, (double)n);

        sum = complex_add(sum, term);

        // проверка сходимости по модулю очередного члена
        if (complex_abs(term) < eps) {
            break;
        }
    }

    return sum;
}

int main(void) {
    complex z;
    printf("Enter the real and imaginary parts of z: ");
    scanf("%lf %lf", &z.re, &z.im);

    complex result = complex_exp(z);

    printf("exp(z) = %.2lf + %.2lfi\n", result.re, result.im);

    return 0;
}