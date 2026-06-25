#include <stdio.h>
#include <stdlib.h>

long long factorial_cycle(int n) {
    long long fact = 1;

    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    
    return fact;
}

// Обычная рекурсия
long long factorial_recursion(long long n) {
    return n <= 1 ? 1 : n * factorial_recursion(n - 1);
}

// Хвостовая рекурсия
long long factorial_recursion2(int n, long long fact) {
    return n <= 1 ? fact : factorial_recursion2(n - 1, fact * n);
}

int main() {
    int n;
    printf("Enter a 'n' number: ");
    scanf("%d", &n);
    printf("Cycle factorial: %lld\n", factorial_cycle(n));
    printf("Recursion factorial: %lld\n", factorial_recursion(n));
    printf("Recursion 2 factorial: %lld", factorial_recursion2(n, 1));
}