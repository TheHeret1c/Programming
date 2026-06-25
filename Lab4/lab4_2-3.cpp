#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 128


void print_char_classification(unsigned char ch, int index) {
    printf("  %2d: '%c' (ASCII %3d) -> ", index, ch, ch);

    int printed = 0;

    if (isdigit(ch)) {
        printf("digit ");
        printed = 1;
    }
    if (isalpha(ch)) {
        printf("letter ");
        printed = 1;
        if (islower(ch))
            printf("(lowercase) ");
        else if (isupper(ch))
            printf("(uppercase) ");
    }
    if (isspace(ch)) {
        printf("space ");
        printed = 1;
    }
    if (ispunct(ch)) {
        printf("punctuation ");
        printed = 1;
    }

    if (isalnum(ch) && !printed) {
        printf("alphanumeric ");
        printed = 1;
    }
    if (iscntrl(ch)) {
        printf("control ");
        printed = 1;
    }
    if (isxdigit(ch) && !isdigit(ch) && !isalpha(ch)) {
    }

    if (!printed) {
        printf("other (or unknown)");
    }
    printf("\n");
}

int main() {
    char input[MAX_LEN];

    printf("Enter a string (10-20 characters, e.g., with digits, letters, spaces, punctuation): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }

    printf("\nCharacter classification for string: \"%s\"\n", input);
    printf("----------------------------------------\n");

    for (int i = 0; i < (int)len; i++) {
        unsigned char ch = (unsigned char)input[i];
        print_char_classification(ch, i);
    }

    return 0;
}