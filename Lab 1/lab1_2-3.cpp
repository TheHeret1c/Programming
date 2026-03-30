#include <stdio.h>


int main() {
    int p0 = 1;
    int p1 = 1;
    int p2 = 1;
    int pn;
    int m;

    printf("Enter a 'm' number: ");
    scanf("%d", &m);
    if (m > 0){
        printf("The Padovan sequence: %d %d %d ", p0, p1, p2);
    } else {
        printf("Enter a number greater than zero");
        return 0;
    }
    

    for (int i = 3; ; i++) {
        pn = p1 + p0;

        if (pn <= m) {
            printf("%d ", pn);

            p0 = p1;
            p1 = p2;
            p2 = pn;
        }
        else {
            break;
        }
    }

    return 0;
}