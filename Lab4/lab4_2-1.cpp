#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MY_SIZE 32
#define BUF_SIZE 64

int main() {
    // Ввод строки
    char my_string[MY_SIZE];
    printf("Enter a string (up to ~10 characters): ");
    fgets(my_string, MY_SIZE, stdin);
    size_t len = strlen(my_string);
    if (len > 0 && my_string[len-1] == '\n') {
        my_string[len-1] = '\0';
    }

    // Ручной подсчёт по индексам
    int len1 = 0;
    for (int i = 0; my_string[i] != '\0'; i++) {
        len1++;
    }
    printf("\n=== Length by index ===\n");
    printf("String length (len1) = %d\n", len1);

    // Ручной подсчёт по указателю
    int len2 = 0;
    char *p = my_string;
    while (*p != '\0') {
        len2++;
        p++;
    }
    printf("\n=== Length by pointer ===\n");
    printf("String length (len2) = %d\n", len2);

    // Функция strlen
    size_t len3 = strlen(my_string);
    printf("\n=== strlen ===\n");
    printf("String length (len3) = %zu\n", len3);
    printf("Check: len1 == len2 == len3 ? %s\n",
           (len1 == (int)len2 && len1 == (int)len3) ? "YES" : "NO");

    // Копирование во второй буфер
    char copy[MY_SIZE];
    int i = 0;
    while (my_string[i] != '\0') {
        copy[i] = my_string[i];
        i++;
    }
    copy[i] = '\0';

    printf("\n=== Copying ===\n");
    printf("Original string: \"%s\"\n", my_string);
    printf("Copy:            \"%s\"\n", copy);

    // Конкатенация двух строк
    char str1[] = "Hello";
    char str2[] = "World";
    char result[BUF_SIZE];

    int idx = 0;
    while (str1[idx] != '\0') {
        result[idx] = str1[idx];
        idx++;
    }
    int j = 0;
    while (str2[j] != '\0') {
        result[idx] = str2[j];
        idx++;
        j++;
    }
    result[idx] = '\0';

    printf("\n=== Concatenation ===\n");
    printf("String1: \"%s\"\n", str1);
    printf("String2: \"%s\"\n", str2);
    printf("Concatenated result: \"%s\"\n", result);

    // Сравнение строк
    int cmp = strcmp(str1, str2);
    printf("\n=== Comparison ===\n");
    printf("Comparing \"%s\" and \"%s\": result = %d\n", str1, str2, cmp);
    if (cmp < 0) {
        printf("Interpretation: \"%s\" is lexicographically less than \"%s\"\n", str1, str2);
    } else if (cmp == 0) {
        printf("Interpretation: strings are equal\n");
    } else {
        printf("Interpretation: \"%s\" is lexicographically greater than \"%s\"\n", str1, str2);
    }

    // Перевод регистра
    char lower[MY_SIZE];
    char upper[MY_SIZE];
    int k = 0;
    while (my_string[k] != '\0') {
        unsigned char ch = (unsigned char)my_string[k];
        lower[k] = tolower(ch);
        upper[k] = toupper(ch);
        k++;
    }
    lower[k] = '\0';
    upper[k] = '\0';

    printf("\n=== Case conversion ===\n");
    printf("Original string:       \"%s\"\n", my_string);
    printf("Lowercase:             \"%s\"\n", lower);
    printf("Uppercase:             \"%s\"\n", upper);

    return 0;
}