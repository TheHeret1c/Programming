#include <stdio.h>

double priceWithDiscount(double price, double discount) {
    return price - price * (discount / 100);
}

typedef struct {
    char name[15];
    double price;
    double discount;
    double (*priceWithDiscountPtr)(double, double);
} itemCard;

int main(void) {
    itemCard appleCard = {"Apple", 110.0, 5.0, &priceWithDiscount};

    printf("Price with discount: %.2f", appleCard.priceWithDiscountPtr(appleCard.price, appleCard.discount));
    return 0;
}