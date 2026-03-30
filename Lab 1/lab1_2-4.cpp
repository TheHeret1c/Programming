#include <stdio.h>


int main() {
    int n;
    int sum = 0;
    
    bool check = true;

    while(check) {
        sum = 0;
        printf("Enter a 'n' number: ");
        scanf("%d", &n);
        while (n != 0) {
            sum += n % 10;
            n = n / 10;
        }
        if(sum <= 10){
            check = false;
            printf("The amount is less than 10. Program terminated.");
        }
        else {
            printf("The amount is more than 10\n");
        }
    }

    return 0;
}