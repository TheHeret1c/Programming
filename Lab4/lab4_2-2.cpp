#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

// Преобразование в int. При успехе 1, иначе 0
int safe_str_to_int(const char *str, int *out) {
    errno = 0;
    char *endptr;
    long val = strtol(str, &endptr, 10);

    if (endptr == str) {
        printf("Error: no numeric characters found.\n");
        return 0;
    }

    if (errno == ERANGE) {
        printf("Error: value out of range for long.\n");
        return 0;
    }

    if (*endptr != '\0') {
        printf("Error: extra characters after number: \"%s\"\n", endptr);
        return 0;
    }

    if (val < INT_MIN || val > INT_MAX) {
        printf("Error: value out of range for int.\n");
        return 0;
    }

    *out = (int)val;
    return 1;
}

// Преобразование в double. При успехе 1, иначе 0
int safe_str_to_double(const char *str, double *out) {
    errno = 0;
    char *endptr;
    double val = strtod(str, &endptr);

    if (endptr == str) {
        printf("Error: no numeric characters found.\n");
        return 0;
    }

    if (errno == ERANGE) {
        printf("Error: value out of range for double (overflow or underflow).\n");
        return 0;
    }

    if (*endptr != '\0') {
        printf("Error: extra characters after number: \"%s\"\n", endptr);
        return 0;
    }

    *out = val;
    return 1;
}

int main() {
    char input_int[100];
    char input_double[100];

    printf("Enter an integer string: ");
    fgets(input_int, sizeof(input_int), stdin);
    size_t len = strlen(input_int);
    if (len > 0 && input_int[len-1] == '\n') {
        input_int[len-1] = '\0';
    }

    printf("Enter a floating-point string: ");
    fgets(input_double, sizeof(input_double), stdin);
    len = strlen(input_double);
    if (len > 0 && input_double[len-1] == '\n') {
        input_double[len-1] = '\0';
    }

    int int_val;
    int ok_int = safe_str_to_int(input_int, &int_val);
    if (ok_int) {
        printf("Integer conversion successful: %d\n", int_val);
    } else {
        printf("Integer conversion failed.\n");
    }

    double double_val;
    int ok_double = safe_str_to_double(input_double, &double_val);
    if (ok_double) {
        printf("Double conversion successful: %g\n", double_val);
    } else {
        printf("Double conversion failed.\n");
    }

    return 0;
}